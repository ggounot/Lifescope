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

/* display the help and exit */
void show_help(char program_name[])
{
	printf("Usage: %s [OPTION]...\n\n", program_name);
	printf("  -X, --width=WIDTH                           set WIDTH columns\n");
	printf("  -Y, --height=HEIGHT                         set HEIGHT rows\n");
	printf("  -S, --size=SIZE                             set SIZE cols and SIZE rows,\n");
	printf("                                              equivalent with -X SIZE -Y\n");
	printf("                                              SIZE\n");
	printf("  -x, --cell-width=CELL_WIDTH                 set CELL_WIDTH pixels as\n");
	printf("                                              cell width\n");
	printf("  -y, --cell-height=CELL_HEIGHT               set CELL_HEIGHT pixels as\n");
	printf("                                              cell height\n");
	printf("  -s, --cell-size=CELL_SIZE                   set SIZE pixels as cell width\n");
	printf("                                              and cell height,\n");
	printf("                                              equivalent with -x CELL_SIZE\n");
	printf("                                              -y CELL_SIZE\n");
	printf("  -e, --vertical-space-between-cells=SPACE    set SPACE pixels as vertical\n");
	printf("                                              space between cells\n");
	printf("  -o, --horizontal-space-between-cells=SPACE  set SPACE pixels as\n");
	printf("                                              horizontal space between\n");
	printf("                                              cells\n");
	printf("  -a, --cell-color=COLOR                      colors the cells with the\n");
	printf("                                              COLOR hexadecimal color code\n");
	printf("  -n, --new-cell-color=COLOR                  colors the new cells with the\n");
	printf("                                              COLOR hexadecimal color code\n");
	printf("  -b, --background-color=COLOR                colors the background with\n");
	printf("                                              the COLOR hexadecimal color\n");
	printf("                                              code\n");
	printf("  -c, --colors                                colors the new cells\n");
	printf("  -d, --delay=DELAY                           set the time between cycles\n");
	printf("                                              to DELAY milliseconds\n");
	printf("  -l, --linked-borders                        link the opposite borders\n");
	printf("  -h, --help                                  show this help\n\n");
	printf("While running the game\n\n");
	printf("  Key N     restart the game with a new random grid\n");
	printf("  Key Up    decrease the time between cycles\n");
	printf("  Key Down  increase the time between cycles\n");
	printf("  Key P     pause\n");
	printf("  Key Q     Close the window\n");
	exit(EXIT_SUCCESS);
}

