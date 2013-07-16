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
#include <stdlib.h>
#include <SDL.h>
#include "conf.h"
#include "grid.h"
#include "display.h"

/* create the window and the cells. Disables unused SDL events */
Display init_display(Configuration *conf)
{
	Display display;
	create_window(&display, conf);
	create_cells(&display, conf);

	/* ignore certain unused events */
	SDL_EventState(SDL_MOUSEMOTION , SDL_IGNORE);
	SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
	SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);

	return display;
}

/* create the screen */
void create_window(Display *display, Configuration *conf)
{
	/* screen */
	display->screen = SDL_SetVideoMode(conf->cols * (conf->cell_width +
				conf->horizontal_space_between_cells) -
			conf->horizontal_space_between_cells, conf->rows *
			(conf->cell_height + conf->vertical_space_between_cells)
			- conf->vertical_space_between_cells, WINDOW_COLORS,
			SDL_HWSURFACE | SDL_DOUBLEBUF);

	/* title */
	SDL_WM_SetCaption(TITLE, NULL);
}

/* creates the cells */
void create_cells(Display *display, Configuration *conf)
{
	/* alive cell */
	display->cell[ALIVE] = SDL_CreateRGBSurface(SDL_HWSURFACE,
	conf->cell_width, conf->cell_height, WINDOW_COLORS, 0, 0, 0, 0);
	SDL_FillRect(display->cell[ALIVE], NULL, SDL_MapRGB(
	display->cell[ALIVE]->format, conf->cell_color_red,
	conf->cell_color_green, conf->cell_color_blue));

	/* new cell */
	display->cell[NEW] = SDL_CreateRGBSurface(SDL_HWSURFACE,
	conf->cell_width, conf->cell_height, WINDOW_COLORS, 0, 0, 0, 0);
	SDL_FillRect(display->cell[NEW], NULL, SDL_MapRGB(
	display->cell[NEW]->format, conf->new_cell_color_red,
	conf->new_cell_color_green, conf->new_cell_color_blue));

	/* dead cell (background) */
	display->cell[DEAD] = SDL_CreateRGBSurface(SDL_HWSURFACE,
	conf->cell_width, conf->cell_height, WINDOW_COLORS, 0, 0, 0, 0);
	SDL_FillRect(display->cell[DEAD], NULL, SDL_MapRGB(
	display->cell[DEAD]->format, conf->background_color_red,
	conf->background_color_green, conf->background_color_blue));
}

/* refresh the display according to the data grid */
void refresh_display(Display *display, Configuration *conf, Grid *grid)
{
	int i, j;

	for (i = 0; i < conf->rows; i++) {
		for (j = 0; j < conf->cols; j++) {
			display->cell_position.x = j * (conf->cell_width + (j >
						0 ?
						conf->horizontal_space_between_cells
						: 0));
			display->cell_position.y = i * (conf->cell_height + (i >
						0 ?
						conf->vertical_space_between_cells
						: 0));
			if (conf->colors)
				SDL_BlitSurface(display->cell[grid->grid[i][j]],
				NULL, display->screen,
				&(display->cell_position));
			else
				SDL_BlitSurface((grid->grid[i][j]) ?
				display->cell[ALIVE] : display->cell[DEAD],
				NULL, display->screen,
				&(display->cell_position));
		}
	}
	SDL_Flip(display->screen);

	return ;
}

