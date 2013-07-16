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

#define WINDOW_COLORS 32
#define DEFAULT_COLS 150
#define DEFAULT_ROWS 150
#define DEFAULT_CELL_COLOR_RED 0
#define DEFAULT_CELL_COLOR_GREEN 0
#define DEFAULT_CELL_COLOR_BLUE 255
#define DEFAULT_NEW_CELL_COLOR_RED 0
#define DEFAULT_NEW_CELL_COLOR_GREEN 255
#define DEFAULT_NEW_CELL_COLOR_BLUE 0
#define DEFAULT_BACKGROUND_COLOR_RED 0
#define DEFAULT_BACKGROUND_COLOR_GREEN 0
#define DEFAULT_BACKGROUND_COLOR_BLUE 0
#define DEFAULT_DELAY 100
#define DEFAULT_CELL_WIDTH 4
#define DEFAULT_CELL_HEIGHT 4
#define DEFAULT_VERTICAL_SPACE_BETWEEN_CELLS 1
#define DEFAULT_HORIZONTAL_SPACE_BETWEEN_CELLS 1
#define DELAY_STEP 10
#define TITLE "Lifescope"

enum {DEAD, NEW, ALIVE};

typedef struct Configuration {
	int rows;
	int cols;
	int size;
	int cell_width;
	int cell_height;
	int cell_size;
	int cell_color_red;
	int cell_color_green;
	int cell_color_blue;
	int new_cell_color_red;
	int new_cell_color_green;
	int new_cell_color_blue;
	int background_color_red;
	int background_color_green;
	int background_color_blue;
	int vertical_space_between_cells;
	int horizontal_space_between_cells;
	int colors;
	int delay;
	int linked_borders;
	int stop;
	int pause;
} Configuration;

Configuration init_conf(int, char **);
void set_default_conf(Configuration *);
void set_conf_from_args(Configuration *, int, char **);
void show_help(char *);
void set_cell_color(Configuration *, unsigned int);
void set_new_cell_color(Configuration *, unsigned int);
void set_background_color(Configuration *, unsigned int);

