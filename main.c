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

    while(1){
          /* Initialize the graphic */
        graphic_init(B);

        int pos_x, pos_y;
        MLV_wait_mouse(&pos_x, &pos_y);

        position_big(&pos_x, &pos_y);
        if(B[pos_y][pos_x] == 0){
            int add = add_board(B, &pos_x, &pos_y);
            if(add != 1){
              printf("Non c'est pas possible\n");
            }
        } else {
            const char* c = "ça compte GRAVE PASSSSSSSSSSSSSSSS";
            MLV_Font* font = MLV_load_font("data/SinclairLightScript Roman.ttf",30);
            MLV_draw_text_with_font(1150, 690, c, font, MLV_COLOR_RED);
            MLV_actualise_window();
            printf("ça compte GRAVE PASSSSSSSSSSSSSSSS\n");
        }
    }


    return EXIT_SUCCESS;
}