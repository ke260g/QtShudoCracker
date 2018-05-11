#include "shudocracker.h"
#include <cstdio>

void show(const int (&maze)[9][9]) {
    /*
       printf("+-------+-------+-------+\n")
       | 1 2 3 | 4 5 6 | 7 8 9 |\n"
       printf("+-------+-------+-------+\n")
       */
    for(int y = 0; y < 9; y++) {
        if((y == 0) || (y == 3) || (y == 6))
            printf("+-------+-------+-------+\n");
        for(int x = 0; x < 9; x++) {
            if((x == 0) || (x == 3) || (x == 6)) 
                printf("| ");
            printf("%d ", maze[y][x]);
        }
        printf("|\n");
    }
    printf("+-------+-------+-------+\n");
    printf("*************************\n\n");
}

int main(int argc, char **argv) {
    int maze[9][9] = {
        {4, 0, 9, 5, 0, 8, 7, 0, 3},
        {5, 6, 0, 0, 9, 1, 0, 8, 4},
        {0, 0, 8, 6, 0, 0, 0, 0, 0},
        {9, 0, 0, 4, 0, 6, 8, 0, 0},
        {2, 8, 0, 0, 0, 0, 0, 1, 9},
        {0, 0, 1, 2, 0, 9, 0, 0, 5},
        {0, 0, 0, 0, 0, 5, 4, 0, 0},
        {1, 4, 0, 8, 3, 0, 0, 9, 6},
        {8, 0, 6, 9, 0, 4, 1, 0, 2},
    };

    int res[9][9];
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            res[i][j] = 0;
        }
    }

    bool retval;
    retval = ShudoCracker::crack(maze, res, ShudoCracker::mazeTypeStd);
    if(retval == true)
        show(res);

    return 0;
}
