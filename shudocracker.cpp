#include "shudocracker.h"
#include<cstring>

const std::vector<std::string> ShudoCracker::mazeTypes = {
    "Standard Type",
    "X Type",
    "Color Type",
    "Hyper Type",
    "Percent Type"
};
/*
 *   +-----------------> x
 *   | [0, 0]
 *   | [0, 1]
 *   |
 *   |
 *   v
 *
 *   y
 *
 *   x means index of vertical direction
 *   y means index of horisontal direction
 *
 */
bool ShudoCracker::isPositionValid(const int (&maze)[9][9],
        const int y, const int x, const int value,
        const int mazeType) {
    for(int i = 0; i < 9; ++i) {
        /* check whether in the same vertical line */
        if(maze[y][i] == value)
            return false;
    }

    for(int i = 0; i < 9; ++i)
        /* check whether in the same horisontal line */
        if(maze[i][x] == value)
            return false;

    /* check whether in the small maze is valid */
    for(int i_x = 0; i_x < 3; i_x++)
        for(int i_y = 0; i_y < 3; i_y++)
            if(maze[3*(y/3) + i_y][3*(x/3) + i_x] == value)
                return false;

    /*
     * each case means mazeType
     * 1. when is valid, break then return true;
     * 2. when is inValid, return false;
     */
    switch(mazeType) {
        case mazeTypeStd:
            break;
        case mazeTypeX:
            /* a special shudu */
            if((x+y) == 8){
                for(int i_y = 0, i_x = 8; i_y < 9; i_y++, i_x--)
                    if(maze[i_y][i_x] == value)
                        return false;
            } else if(x == y){
                for(int i_x = 0; i_x < 9; i_x++)
                    if(maze[i_x][i_x] == value)
                        return false;
            }
            break;
        case mazeTypeColor:
            /* a special kind of shudu */
            for(int i_x = 0; i_x < 7; i_x = i_x + 3)
                for(int i_y = 0; i_y < 7; i_y = i_y + 3)
                    if(maze[y%3 + i_y][x%3 + i_x] == value)
                        return false;
            break;
        case mazeTypeHyper:
            /* a special kind of shudu */
            /* 4 hyper small maze have been embeded in */
            if((x != 0) && (x != 4) && (x != 8) \
                    && (y != 0) && (y != 4) && (y != 8))
                if(((x - 1)/3 == 0) || ((x + 1)/3 == 2) \
                        || ((y - 1)/3 == 0) || ((y + 1)/3 == 2))
                    for(int i_y = 1; i_y < 4; i_y++)
                        for(int i_x = 1; i_x < 4; i_x++)
                            if(maze[(y/4)*4+i_y][(x/4)*4+i_x] == value)
                                return false;

            break;
        case mazeTypePercent:
            /*a special kind of shudu */
            /*half hyper and half X ==> Percent */
            if((x+y) == 8){
                for(int i_y = 0, i_x = 8; i_y < 9; i_y++, i_x--)
                    if(maze[i_y][i_x] == value)
                        return false;
            } else if((x != 0) && (x != 4) && (x != 8) \
                    && (y != 0) && (y != 4) && (y != 8))
                if((((x - 1)/3 == 0) && ((y - 1)/3 == 0)) \
                        || (((x + 1)/3 == 2) && ((y + 1)/3 == 2)))
                    for(int i_y = 1; i_y < 4; i_y++)
                        for(int i_x = 1; i_x < 4; i_x++)
                            if(maze[(y/4)*4+i_y][(x/4)*4+i_x] == value)
                                return false;
            break;
        default:
            return false;
    }
    return true;
}

/* recursive method */
void ShudoCracker::coreCrack(
        const int (&src_maze)[9][9],
        int (&dst_maze)[9][9],
        const int y, const int x,
        const int mazeType,
        bool & isSolved) {
    if(src_maze[y][x] != 0){
        /* the position  is non-zero at the beginning*/
        if(x != 8)
            coreCrack(src_maze, dst_maze, y, x+1, mazeType, isSolved);
        else if(y != 8) // x == 8, at the end of a row, begin next row
            coreCrack(src_maze, dst_maze, y+1, 0, mazeType, isSolved);
        else{
            /* x == 8, y == 8, reach the end,
             * the answer is solved out, exit */
            isSolved = true;
            return;
        }
    } else{
        for(int test_value = 1; test_value < 10; test_value++) {
            if(isPositionValid(dst_maze, y, x, test_value, mazeType)){
                dst_maze[y][x] = test_value; /* give the value to the maze */
                if((x == 8) && (y == 8)){
                    /* when answer is solved out, exit */
                    isSolved = true;
                    return;
                }
                if(x != 8)
                    coreCrack(src_maze, dst_maze, y, x+1, mazeType, isSolved);
                else if(y != 8)
                    coreCrack(src_maze, dst_maze, y+1, 0, mazeType, isSolved);
            }
        }
        if(isSolved == false)
            dst_maze[y][x] = 0; /* can't reach the answer, return to zero */
        else
            return;
    }
}

bool ShudoCracker::crack(const int (&src_maze)[9][9],
        int (&dst_maze)[9][9],
        const int mazeType) {
    bool isSolved = false;

    if(!isMazeValid(src_maze))
        return false;

    memcpy(dst_maze, src_maze, 9*9*sizeof(int));
    coreCrack(src_maze, dst_maze, 0, 0, mazeType, isSolved);

    return isSolved;
}

bool ShudoCracker::isMazeValid(const int (&maze)[9][9]) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(maze[i][j] < 0 || maze[i][j] > 9)
                return false;
        }
    }
}
