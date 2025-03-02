#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <MLV/MLV_all.h>

/* window */
#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 1250
#define MLV_Color COLOR

/* Sudoku Grid */
#define SUDOKU_WIDTH 900
#define SUDOKU_HEIGHT 900

/* Number Grid */
#define NUMBER_WIDTH 900
#define NUMBER_HEIGHT 100


typedef int Board[9][9];

void graphic_init(Board B);   /* Draw the board */
void graphic_number(Board B); /* Complete board number */
void position_big(int *pos_x, int *pos_y); /* Show the position inside the big grid */
void position_small(int *pos_x, int *pos_y); /* Show the position inside the small grid */
void graphic_small(Board B); /* Draw the small board */
int get_in_number(); /* Get the selected number to change */
void graphic_update(Board B, int *pos_x, int *pos_y);


void error_message(int code); /* Error message */


#endif /*GRAPHIC_H*/
