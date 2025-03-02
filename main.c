#include <stdio.h>
#include "in_out.h"
#include "graphic.h"
#include "game.h"



int main(int argc, char* argv[]){
    /* Create the window */
    MLV_create_window("SUDOKU", "Sudoku", WINDOW_WIDTH, WINDOW_HEIGHT);
    MLV_draw_filled_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, MLV_COLOR_WHITE);
    MLV_actualise_window();

    /* Add sudoku in the grid */
    Board B;
    fread_board(argv[1], B);

    /* Initialize the graphic */
    graphic_init(B);


    while(1){
        int pos_x, pos_y;
        MLV_wait_mouse(&pos_x, &pos_y);
        MLV_draw_filled_rectangle(40, 1100, 1000, 300, MLV_COLOR_WHITE); /* erase error message */

        position_big(&pos_x, &pos_y);
        if(B[pos_y][pos_x] == 0){
            int add = add_board(B, &pos_x, &pos_y);
            if(add != 1){
              printf("add_board failed\n");
            }

            /* Update graphic */
            graphic_init(B);
        } else {
            error_message(1);
            MLV_actualise_window();
            MLV_wait_seconds(2);
        }
    }

    return EXIT_SUCCESS;
}