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
#include <time.h>
#include "conf.h"
#include "grid.h"

/* create the two grids */
Grid init_grid(Configuration *conf)
{
	int i;
	Grid grid;

	grid.grid1 = (int **) calloc(conf->rows, sizeof (int *));
	grid.grid2 = (int **) calloc(conf->rows, sizeof (int *));

	for (i = 0; i < conf->rows; i++) {
		grid.grid1[i] = (int *) calloc(conf->cols, sizeof (int));
		grid.grid2[i] = (int *) calloc(conf->cols, sizeof (int));
	}

	grid.num_grid = 1;
	grid.grid = grid.grid1;

	random_grid_filling(&grid, conf);

	return grid;
}

/* call the right function which will refresh the right grid */
void refresh_grid(Grid *grid, Configuration *conf)
{
	if (grid->num_grid == 1)
		refresh_grid1(grid, conf);
	else
		refresh_grid2(grid, conf);

	return ;
}

/* refresh grid1 */
void refresh_grid1(Grid *grid, Configuration *conf)
{
	int x, y, neighbors;

	for (x = 0; x < conf->rows; x++) {
		for (y = 0; y < conf->cols; y++) {
			neighbors = count_neighbors(grid, conf, x, y);
			if (neighbors == 3)
				grid->grid2[x][y] = (grid->grid1[x][y] == DEAD) ?
				NEW : ALIVE;
			else if (neighbors == 2)
				grid->grid2[x][y] = (grid->grid1[x][y] == NEW) ?
				ALIVE : grid->grid1[x][y];
			else
				grid->grid2[x][y] = DEAD;
		}
	}
	grid->num_grid = 2;
	grid->grid = grid->grid2;

	return ;
}

/* refresh grid2 */
void refresh_grid2(Grid *grid, Configuration *conf)
{
	int x, y, neighbors;

	for (x = 0; x < conf->rows; x++) {
		for (y = 0; y < conf->cols; y++) {
			neighbors = count_neighbors(grid, conf, x, y);
			if (neighbors == 3)
				grid->grid1[x][y] = (grid->grid2[x][y] == DEAD) ?
				NEW : ALIVE;
			else if (neighbors == 2)
				grid->grid1[x][y] = (grid->grid2[x][y] == NEW) ?
				ALIVE : grid->grid2[x][y];
			else
				grid->grid1[x][y] = DEAD;
		}
	}
	grid->num_grid = 1;
	grid->grid = grid->grid1;

	return ;
}

/* link the opposite borders */
void link_borders(Configuration *conf, int *cell_x, int *cell_y)
{
	if (*cell_x == -1)
		*cell_x = conf->rows - 1;
	if (*cell_y == -1)
		*cell_y = conf->cols - 1;
	if (*cell_x == conf->rows)
		*cell_x = 0;
	if (*cell_x == conf->cols)
		*cell_y = 0;

	return ;
}

/* count the neighbors of a cell */
int count_neighbors(Grid *grid, Configuration *conf, int x, int y)
{
	int i, j, cell_x, cell_y, count;

	count = 0;
	for (i = -1; i <= 1; i++)
		for (j = -1; j <= 1; j++) {
			cell_x = x + i;
			cell_y = y + j;
			if (conf->linked_borders)
				link_borders(conf, &cell_x, &cell_y);
			if (!(i == 0 && j == 0) && cell_x >= 0 && cell_y >= 0 &&
					cell_x < conf->rows && cell_y <
					conf->cols)
				if (grid->grid[cell_x][cell_y])
					count++;
		}

	return count;
}

/* free calloced grids */
void free_memory(Grid *grid)
{
	free(grid->grid1);
	free(grid->grid2);

	return ;
}

/* initialize randomly the grid */
void random_grid_filling(Grid *grid, Configuration *conf)
{
	int i, j;

	for (i = 0; i < conf->rows; i++)
		for (j = 0; j < conf->cols; j++)
			grid->grid[i][j] = random() % 2;

	return ;
}

