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

typedef struct Display {
	SDL_Surface *screen;
	SDL_Surface *cell[3];
	SDL_Rect cell_position;
} Display;

Display init_display(Configuration *);
void create_window(Display *, Configuration *);
void create_cells(Display *, Configuration *);
void refresh_display(Display *, Configuration *, Grid *);

