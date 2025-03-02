#include <stdio.h>
#include "graphic.h"



void graphic_init(Board B){
    MLV_draw_filled_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, MLV_COLOR_WHITE);
    /* Draw the sudoku grid */
    MLV_draw_filled_rectangle(47, 47, SUDOKU_WIDTH +6 , SUDOKU_HEIGHT +6 ,MLV_COLOR_RED); /* squares */
    MLV_draw_filled_rectangle(50, 50, SUDOKU_WIDTH, SUDOKU_HEIGHT,MLV_COLOR_WHITE);
    MLV_draw_filled_rectangle(50, 349, SUDOKU_WIDTH, SUDOKU_HEIGHT/3+2,MLV_COLOR_RED);
    MLV_draw_filled_rectangle(50, 351, SUDOKU_WIDTH, SUDOKU_HEIGHT/3-2,MLV_COLOR_WHITE);
    MLV_draw_filled_rectangle(349, 50, SUDOKU_WIDTH/3+2, SUDOKU_HEIGHT,MLV_COLOR_RED);
    MLV_draw_filled_rectangle(351, 50, SUDOKU_WIDTH/3-2, SUDOKU_HEIGHT/3-1,MLV_COLOR_WHITE);
    MLV_draw_filled_rectangle(351, 351, SUDOKU_WIDTH/3-2, SUDOKU_HEIGHT/3-2,MLV_COLOR_WHITE);
    MLV_draw_filled_rectangle(351, 651, SUDOKU_WIDTH/3-2, SUDOKU_HEIGHT/3-1,MLV_COLOR_WHITE);
    int i;
    for(i=0; i<SUDOKU_WIDTH; i++){ /* lines */
        if(i%100 == 0){
            MLV_draw_line(50, 50+i, 950, 50+i, MLV_COLOR_RED);   /* row */
            MLV_draw_line(50+i, 50, 50+i, 950, MLV_COLOR_RED);   /* col */
        }
    }

    /* Add Board number */
    graphic_number(B);
    MLV_actualise_window();
}
void graphic_number(Board B){
    int i,j;
    for (i=0; i<9; i++){
        for(j=0; j<9; j++){
            /* change int -> const char* */
            int n = B[j][i];
            char x [12];
            sprintf(x, "%d", n);
            const char* c = x;
            if(n!=0){
                MLV_Font* font = MLV_load_font("data/SinclairLightScript Roman.ttf",50);
                MLV_draw_text_with_font((i)*100+90, (j)*100+90, c, font, MLV_COLOR_RED);
            }
        }
    }
}

void position_big(int *pos_x, int *pos_y){
    if(*pos_x > 50 && *pos_x < SUDOKU_WIDTH+50
            && *pos_y > 50 && *pos_y < SUDOKU_HEIGHT+50){
        *pos_x = (*pos_x-50)/100 +1 ;
        *pos_y = (*pos_y-50)/100 +1 ;
        printf("posx: %d, posy: %d\n",*pos_x, *pos_y);
        *pos_x = *pos_x-1;
        *pos_y = *pos_y-1;
        }
}
void position_small(int *pos_x, int *pos_y){
    if(*pos_x > 1000 && *pos_x < 1300
          && *pos_y > 250 && *pos_y < 550){
        *pos_x = (*pos_x-1000)/100 +1 ;
        *pos_y = (*pos_y-250)/100 +1 ;
        printf("small -> posx: %d, posy: %d\n",*pos_x, *pos_y);
          }
}

void graphic_small(Board B){
    MLV_draw_filled_rectangle(997, 247, 306, 306, MLV_COLOR_RED); /* square*/
    MLV_draw_filled_rectangle(1000, 250, 300, 300,MLV_COLOR_WHITE);

    MLV_draw_line(1000, 350, 1300, 350, MLV_COLOR_RED);   /* row */
    MLV_draw_line(1000, 450, 1300, 450, MLV_COLOR_RED);
    MLV_draw_line(1100, 250, 1100, 550, MLV_COLOR_RED);   /* col */
    MLV_draw_line(1200, 250, 1200, 550, MLV_COLOR_RED);

    int i, j, n=0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            /* change int -> const char* */
            n++;
            char x [12];
            sprintf(x, "%d", n);
            const char* c = x;

            MLV_Font* font = MLV_load_font("data/SinclairLightScript Roman.ttf",50);
            MLV_draw_text_with_font((j)*100+1040, (i)*100+285, c, font, MLV_COLOR_RED);
        }
    }
}

int get_in_number(){
    int posx, posy;
    MLV_wait_mouse(&posx, &posy);
    position_small(&posx, &posy);
    return ((posx-1)*3)+posy;
}

/*void graphic_update(Board B, int *pos_x, int *pos_y){
//    graphic_small(B);
//    MLV_actualise_window();
//
//    int number = get_in_number();
//    int test = test_number(B, pos_x, pos_y, number);
//    if(test == 1){
//      B[*pos_x][*pos_y] = number;
//        printf("number: %d\n", number);
//    }
//
//
//    MLV_actualise_window();
//}*/

void error_message(int code){
    switch(code){
        case 1:
            const char* c = "Wrong Input";
                MLV_Font* font = MLV_load_font("data/SinclairLightScript Roman.ttf",50);
                MLV_draw_text_with_font(1200+90, 400+90, c, font, MLV_COLOR_RED);
            break;

    }

}




