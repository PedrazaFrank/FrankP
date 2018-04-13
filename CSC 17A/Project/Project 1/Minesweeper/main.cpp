/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 *
 * Created on April 12, 2018
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "Minesweeper.h"
//Global Constants - Math, Science, Conversions, 2D Array Sizes

//Function Prototypes
GameBoard *createBoard(int,int);
void prntBoard(GameBoard *);
void destroy(GameBoard *);
//Execution Begins
int main(int argc, char** argv) {
    
    int row=10, col=10;
    GameBoard *board = createBoard(row, col);
    
    prntBoard(board);
    
    destroy(board);
    
}

GameBoard *createBoard(int rows,int cols){
    Elements square;
    square.k = 35;
    GameBoard *board = new GameBoard;
    board->rows=rows;
    board->cols=cols;
    board->data=new char*[rows];
    for(int i=0;i<rows;i++){
        board->data[i]=new char[cols];
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            board->data[i][j]= square.k;
        }
    }
    return board;
}

void prntBoard(GameBoard *b){
    cout << setw(5) << 1;
    for(int i=1; i<10; i++){
        cout << setw(4) << i+1;
    }
    
    cout << endl;
    
    for(int i=0; i<b->rows; i++){
        cout << "  +---+---+---+---+---+---+---+---+---+---+"<< endl << setw(2) <<i+1;
        for(int j=0; j<b->cols; j++){
            cout <<"| " << b->data[i][j] << " ";
        }
        cout << "|"<<endl;
    }cout << "  +---+---+---+---+---+---+---+---+---+---+"<< endl;
}

void destroy(GameBoard *b){
    if(!b)return;
    for(int i=0;i<b->rows;i++){
        delete []b->data[i];
    }
    delete []b->data;
    delete b;
}