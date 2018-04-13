/* 
 * File:   Minesweeper.h
 * Author: Frank Pedraza
 *
 * Created on April 12, 2018
 */

#ifndef MINESWEEPER_H
#define MINESWEEPER_H
struct Elements{
    bool mine;
    int distance;
    char k;
};
struct GameBoard{
    int rows;
    int cols;
    char **data;
};

#endif /* MINESWEEPER_H */

