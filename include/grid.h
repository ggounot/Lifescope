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

typedef struct Grid {
	int **grid1;
	int **grid2;
	int **grid;
	int num_grid;
} Grid;

Grid init_grid(Configuration *);
void refresh_grid(Grid *, Configuration *);
void refresh_grid1(Grid *, Configuration *);
void refresh_grid2(Grid *, Configuration *);
void link_borders(Configuration *, int *, int *);
int count_neighbors(Grid *, Configuration *, int, int);
int count_neighbors_with_linked_borders(Grid *, Configuration *, int, int);
void free_memory(Grid *);
void random_grid_filling(Grid *, Configuration *);

