/*
* Copyright 2008, 2009 Gerald Gounot
*
* This file is part of Lifescope.
*
* Lifescope is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* Lifescope is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <stdio.h>
#include <SDL.h>
#include "conf.h"
#include "grid.h"
#include "display.h"
#include "events.h"

/* main loop */
void main_loop(Display *display, Grid *grid, Configuration *conf)
{
	SDL_Event event;

	conf->stop = conf->pause = 0;
	while (!conf->stop) {
		SDL_PollEvent(&event);
		switch (event.type) {
			case SDL_QUIT:
				conf->stop = 1;
				break;
			case SDL_KEYDOWN:
				keydown_event(grid, conf, event.key.keysym.sym);
				break;
			case SDL_KEYUP:
				keyup_event(conf, event.key.keysym.sym);
				break;
			default:
				break;
		}
		if (!conf->pause) {
			refresh_grid(grid, conf);
			refresh_display(display, conf, grid);
		}
		SDL_Delay(conf->delay);
	}
}

/* handle a keydown event */
void keydown_event(Grid *grid, Configuration *conf, SDLKey key)
{
	switch (key) {
		case SDLK_n: /* refill the grid */
			random_grid_filling(grid, conf);
			break;
		case SDLK_UP: /* increase the speed */
			conf->delay = (conf->delay <= 1) ?
			1 : conf->delay - DELAY_STEP;
			break;
		case SDLK_DOWN: /* decrease the speed */
			conf->delay += DELAY_STEP;
			break;
		case SDLK_p: /* set or unset the pause */
			conf->pause = (conf->pause) ? 0 : 1;
			break;
		default:
			break;
	}

	return ;
}

/* handle a keyup event */
void keyup_event(Configuration *conf, SDLKey key)
{
	switch (key) {
		case SDLK_q: /* stop the game */
			conf->stop = 1;
			break;
		default:
			break;
	}

	return ;
}

