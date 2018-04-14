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
GameBoard *placeMine(int,int);
void prntBoard(GameBoard *);
void destroy(GameBoard *);
//Execution Begins
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    int row=10, col=10;
    GameBoard *board = createBoard(row, col);
    GameBoard *mines = placeMine(row, col);
    
    cout << "Before placing mines" << endl;
    prntBoard(board);
    
//    placeMine(mines);
    cout << endl << "After placing mines" << endl;
    prntBoard(board);
    
    cout << endl << "Mines Array" << endl;
    prntBoard(mines);
    
    destroy(board);
    destroy(mines);
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
            board->data[i][j]= 46;
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

GameBoard *placeMine(int rows, int cols){
    int i,j;
    Elements clue;
    clue.distance = 49;
    
    GameBoard *mines = new GameBoard;
    mines->rows=rows;
    mines->cols=cols;
    mines->data=new char*[rows];
    for(int i=0;i<rows;i++){
        mines->data[i]=new char[cols];
    }
    
    for(int m=0;m<10;m++){
        i=0;
        j=0;
        do{
            i=rand()%10;
            j=rand()%10;
        }while(mines->data[i][j]==35);
        mines->data[i][j]= 35;
        }
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if((i>-1)&&(j>-1)){
            if(mines->data[i][j]==35){
                mines->data[i-1][j-1]=clue.distance;
                mines->data[i-1][j]=clue.distance;
                mines->data[i-1][j+1]=clue.distance;
                mines->data[i][j-1]=clue.distance;
                mines->data[i][j+1]=clue.distance;
                mines->data[i+1][j-1]=clue.distance;
                mines->data[i+1][j]=clue.distance;
                mines->data[i+1][j+1]=clue.distance;
            }
            }
            clue.distance++;
        }
    }
    
    return mines;
}

