#include <stdio.h>
#include <stdlib.h>
#include "game.h"


int test_number(Board B, int *row, int *col, int x){
    /*Test row and col*/
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (B[*row][j] == x && j != *col) {
                return 0;
            }
            if (B[i][*col] == x && i != *row) {
                return 0;
            }
        }
    }
    /*Test cube 3x3*/
    i = (*row/3)*3;
    j = (*col/3)*3;
    int n, m;
    for (n = i; n < i+3; n++) {
        for (m = j; m < j+3; m++) {
            if (B[n][m] == x) {
                return 0;
            }
        }
    }
    return 1;
}

int add_board(Board B, int *pos_x, int *pos_y){
    graphic_small(B);
    MLV_actualise_window();

    int number = get_in_number();
    printf("Number: %d\n", number);
    int test = test_number(B, pos_x, pos_y, number);
    if(test == 1){
      B[*pos_y][*pos_x] = number;
      return 1;
    }
    return 0;
}