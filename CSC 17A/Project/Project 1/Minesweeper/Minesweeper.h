/* 
 * File:   Minesweeper.h
 * Author: Frank Pedraza
 *
 * Created on April 12, 2018
 */

#ifndef MINESWEEPER_H
#define MINESWEEPER_H
struct Elements{
    char mine;
    char distance;
    char covered;
    int numMines;
    int difficulty;
};
struct GameBoard{
    int rows;
    int cols;
    char **data;
};
struct highScores{
    string name;
    int score;
};

#endif /* MINESWEEPER_H */

