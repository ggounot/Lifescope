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
#include "SDL.h"
#include "conf.h"
#include "grid.h"
#include "display.h"
#include "events.h"

int main(int argc, char *argv[])
{
	Configuration conf;
	Grid grid;
	Display display;

	conf = init_conf(argc, argv);
	srandom(time(NULL));
	grid = init_grid(&conf);
	display = init_display(&conf);
	main_loop(&display, &grid, &conf);
	free_memory(&grid);

	return EXIT_SUCCESS;
}

