#!/bin/bash

Maze_CPPVAR_NAME=$1
MazeUI_PREFIX=$2
for (( i=0; i < 9; i++)) {
    for (( j=0; j < 9; j++)) {
        echo "${Maze_CPPVAR_NAME}[$i][$j] = ${MazeUI_PREFIX}${i}${j};"
    }
}
