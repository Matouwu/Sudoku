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
        *pos_x = (*pos_x-50)/100 +1;
        *pos_y = (*pos_y-50)/100 +1;
        printf("posx: %d, posy: %d\n",*pos_x, *pos_y);
        *pos_x = *pos_x-1;
        *pos_y = *pos_y-1;
        }
}
void position_small(int *pos_x, int *pos_y){
    if(*pos_x > 50 && *pos_x < 950
          && *pos_y > 1000 && *pos_y < 1100){
        *pos_x = (*pos_x-50)/100 +1;
        *pos_y = 1;
        printf("small -> posx: %d, posy: %d\n",*pos_x, *pos_y);
    } else {
        error_message(2);
    }
}

void graphic_small(Board B){
    MLV_draw_filled_rectangle(48, 998, NUMBER_WIDTH + 4, NUMBER_HEIGHT + 4, MLV_COLOR_WHITE); /* square*/
    MLV_draw_filled_rectangle(50, 1000, NUMBER_WIDTH, NUMBER_HEIGHT,MLV_rgba(255,210,210,MLV_ALPHA_OPAQUE));

    int i;
    for(i=0; i<NUMBER_WIDTH; i++){
      if(i%100 == 0){
        MLV_draw_line(50+i, 1000, 50+i, 1100, MLV_COLOR_WHITE);
      }
    }

    for(i=0; i<9; i++){
        /* change int -> const char* */
        char x [12];
        sprintf(x, "%d", i+1);
        const char* c = x;
        MLV_Font* font = MLV_load_font("data/SinclairLightScript Roman.ttf",50);
        MLV_draw_text_with_font(90+i*100, 1030, c, font, MLV_COLOR_RED);
    }
}

int get_in_number(){
    int posx=0, posy=0;
    while(posx<1 || posx> 10 || posy<1 || posy>10){
        MLV_wait_mouse(&posx, &posy);
        position_small(&posx, &posy);
    }
    return posx;
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
    const char *c;
    switch(code){
        case 1:
            c = "Wrong Input, you have to click on an empty box.";
            break;
        case 2:
            c = "Wrong click, you have to click a number.";
            break;
        case 3:
            c = "Wrong number, you have to click another number.";
            break;
        case 4:
            c = "Same number in the line.";
            break;
        case 5:
            c = "Same number in the colonne.";
            break;
        case 6:
            c = "Same number in the box.";
            break;
    }
    MLV_Font* font = MLV_load_font("data/ARIALBD.TTF",35);
    MLV_draw_text_with_font(50, 1130, c, font, MLV_COLOR_RED);
    MLV_actualise_window();
}




