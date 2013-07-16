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
#include <getopt.h>
#include "conf.h"

/* initialize the configuration */
Configuration init_conf(int argc, char *argv[])
{
	Configuration conf;

	set_default_conf(&conf);
	set_conf_from_args(&conf, argc, argv);

	return conf;
}

/* set the default configuration values */
void set_default_conf(Configuration *conf)
{
	conf->rows = DEFAULT_ROWS;
	conf->cols = DEFAULT_COLS;
	conf->delay = DEFAULT_DELAY;
	conf->cell_width = DEFAULT_CELL_WIDTH;
	conf->cell_height = DEFAULT_CELL_HEIGHT;
	conf->cell_color_red = DEFAULT_CELL_COLOR_RED;
	conf->cell_color_green = DEFAULT_CELL_COLOR_GREEN;
	conf->cell_color_blue = DEFAULT_CELL_COLOR_BLUE;
	conf->new_cell_color_red = DEFAULT_NEW_CELL_COLOR_RED;
	conf->new_cell_color_green = DEFAULT_NEW_CELL_COLOR_GREEN;
	conf->new_cell_color_blue = DEFAULT_NEW_CELL_COLOR_BLUE;
	conf->background_color_red = DEFAULT_BACKGROUND_COLOR_RED;
	conf->background_color_green = DEFAULT_BACKGROUND_COLOR_GREEN;
	conf->background_color_blue = DEFAULT_BACKGROUND_COLOR_BLUE;
	conf->vertical_space_between_cells = DEFAULT_VERTICAL_SPACE_BETWEEN_CELLS;
	conf->horizontal_space_between_cells = DEFAULT_HORIZONTAL_SPACE_BETWEEN_CELLS;
	conf->cell_size = 0;
	conf->colors = 0;
	conf->size = 0;
	conf->linked_borders = 0;

	return ;
}

/* set the configuration from the arguments */
void set_conf_from_args(Configuration *conf, int argc, char *argv[])
{
	char *optstring = "X:Y:S:x:y:s:i:e:o:a:n:b:d:clh";
	struct option longopts[] = {
		/* name      	                    has_arg  flag  val */
		{ "width",                          1,       NULL, 'X' },
		{ "height",                         1,       NULL, 'Y' },
		{ "size",                           1,       NULL, 'S' },
		{ "cell-width",                     1,       NULL, 'x' },
		{ "cell-height",                    1,       NULL, 'y' },
		{ "cell-size",                      1,       NULL, 's' },
		{ "space",                          1,       NULL, 'i' },
		{ "vertical-space-between-cells",   1,       NULL, 'e' },
		{ "horizontal-space-between-cells", 1,       NULL, 'o' },
		{ "cell-color",                     1,       NULL, 'a' },
		{ "new-cell-color",                 1,       NULL, 'n' },
		{ "background-color",               1,       NULL, 'b' },
		{ "delay",                          1,       NULL, 'd' },
		{ "colors",                         0,       NULL, 'c' },
		{ "linked-borders",                 0,       NULL, 'l' },
		{ "help",                           0,       NULL, 'h' },
		{ NULL,                             0,       NULL,  0 }
	};
	int longindex;
	int option;
	unsigned int cell_color;
	unsigned int new_cell_color;
	unsigned int background_color;
	int space;
	int space_specified = 0;
	int cell_color_specified = 0;
	int new_cell_color_specified = 0;
	int background_color_specified = 0;

	/* get configuration from arguments */
	while ((option = getopt_long(argc, argv, optstring, longopts,
					&longindex)) != -1) {
		switch (option) {
			case 'X':
				if (sscanf(optarg, "%d", &(conf->cols)) != 1) {
					fprintf(stderr, "Invalid width\n");
				}
				break;
			case 'Y':
				if (sscanf(optarg, "%d", &(conf->rows)) != 1) {
					fprintf(stderr, "Invalid height");
				}
				break;
			case 'S':
				if (sscanf(optarg, "%d", &(conf->size)) != 1) {
					fprintf(stderr, "Invalid size");
				}
				break;
			case 'y':
				if (sscanf(optarg, "%d", &(conf->cell_height)) != 1) {
					fprintf(stderr, "Invalid cell height");
				}
				break;
			case 'x':
				if (sscanf(optarg, "%d", &(conf->cell_width)) != 1) {
					fprintf(stderr, "Invalid cell width");
				}
				break;
			case 'i':
				if (sscanf(optarg, "%d", &space) != 1) {
					fprintf(stderr, "Invalid space");
				}
				space_specified = 1;
				break;
			case 'e':
				if (sscanf(optarg, "%d", &(conf->vertical_space_between_cells)) != 1) {
					fprintf(stderr, "Invalid vertical space between cells");
				}
				break;
			case 'o':
				if (sscanf(optarg, "%d", &(conf->horizontal_space_between_cells)) != 1) {
					fprintf(stderr, "Invalid horizontal space between cells");
				}
				break;
			case 's':
				if (sscanf(optarg, "%d", &(conf->cell_size)) != 1) {
					fprintf(stderr, "Invalid cell size");
				}
				break;
			case 'a':
				if (sscanf(optarg, "%x", &cell_color) != 1) {
					fprintf(stderr, "Invalid alive cell color");
				}
				cell_color_specified = 1;
				break;
			case 'n':
				if (sscanf(optarg, "%x", &new_cell_color) != 1) {
					fprintf(stderr, "Invalid new cell color");
				}
				new_cell_color_specified = 1;
				break;
			case 'b':
				if (sscanf(optarg, "%x", &background_color) != 1) {
					fprintf(stderr, "Invalid background color");
				}
				background_color_specified = 1;
				break;
			case 'd':
				if (sscanf(optarg, "%d", &(conf->delay)) != 1) {
					fprintf(stderr, "Invalid delay");
				}
				break;
			case 'c':
				conf->colors = 1;
				break;
			case 'l':
				conf->linked_borders = 1;
				break;
			case 'h':
				show_help(argv[0]);
				break;
			case '?':
				break;
		}
	}
	if (conf->size > 0)
		conf->cols = conf->rows = conf->size;
	if (conf->cell_size > 0)
		conf->cell_width = conf->cell_height = conf->cell_size;
	if (cell_color_specified)
		set_cell_color(conf, cell_color);
	if (new_cell_color_specified)
		set_new_cell_color(conf, new_cell_color);
	if (background_color_specified)
		set_background_color(conf, background_color);
	if (space_specified)
		conf->vertical_space_between_cells = conf->horizontal_space_between_cells = space;

	return ;
}

void set_cell_color(Configuration *conf, unsigned int alive_cell_color)
{
	conf->cell_color_red = (alive_cell_color & 0xFF0000) >> 16;
	conf->cell_color_green = (alive_cell_color & 0x00FF00) >> 8;
	conf->cell_color_blue = (alive_cell_color & 0x0000FF);
}

void set_new_cell_color(Configuration *conf, unsigned int new_cell_color)
{
	conf->new_cell_color_red = (new_cell_color & 0xFF0000) >> 16;
	conf->new_cell_color_green = (new_cell_color & 0x00FF00) >> 8;
	conf->new_cell_color_blue = (new_cell_color & 0x0000FF);
}

void set_background_color(Configuration *conf, unsigned int background_color)
{
	conf->background_color_red = (background_color & 0xFF0000) >> 16;
	conf->background_color_green = (background_color & 0x00FF00) >> 8;
	conf->background_color_blue = (background_color & 0x0000FF);
}

