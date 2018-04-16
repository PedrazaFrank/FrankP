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
GameBoard *placeMine(int,int, int);
char placeClueDistance(GameBoard *,int,int,int,int);
void uncover(GameBoard *,GameBoard *,int,int);
void prntBoard(GameBoard *);
void input(GameBoard *,GameBoard *,int,int);
void destroy(GameBoard *);
void gameStart();
bool gameLost(GameBoard *,int,int);
bool gameWon(GameBoard *,GameBoard *,int,int);

//Execution Begins
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    gameStart();
    
    return 0;
}

GameBoard *createBoard(int rows,int cols){
    
    //Assigns a # for a covered square
    Elements square;
    square.covered = 35;
    
    //Dynamically creates a 2D array for the gameboard
    GameBoard *board = new GameBoard;
    board->rows=rows;
    board->cols=cols;
    board->data=new char*[rows];
    for(int i=0;i<rows;i++){
        board->data[i]=new char[cols];
    }
    
    //Set array elements to square char (#)
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            board->data[i][j]= square.covered;
        }
    }
    return board;
}

void prntBoard(GameBoard *b){
    //Prints the first row of numbers
    cout << setw(5) << 1;                                   
    for(int i=1; i<b->cols; i++){
        cout << setw(4) << i+1;
    }
    cout << endl;
    
    //Prints the top of the square as a row
    for(int i=0; i<b->rows; i++){
        cout << "  ";
        for(int l=0; l<b->cols; l++){
            cout << "+---";
        }
        
        //Prints the square the user "clicks" on to reveal
        cout << "+" << endl << setw(2) <<i+1;
        for(int j=0; j<b->cols; j++){
                cout <<"| " << b->data[i][j] << " ";
            }
        cout << "|"<<endl;
        }

    //Prints the final row to close off the bottoms of the squares
    cout << "  ";
    for(int l=0; l<b->cols; l++){
        cout << "+---";
    }
    cout << "+";
}

void destroy(GameBoard *b){
    
    //deletes the array to prevent memory leak
    if(!b)return;
    for(int i=0;i<b->rows;i++){
        delete []b->data[i];
    }
    delete []b->data;
    delete b;
}

GameBoard *placeMine(int rows, int cols, int mineNumber){
    int i,j;
    Elements clue;
    clue.distance = 48;
    
    //Dynamically creates a 2D array containing mines
    GameBoard *mines = new GameBoard;
    mines->rows=rows;
    mines->cols=cols;
    mines->data=new char*[rows];
    for(int i=0;i<rows;i++){
        mines->data[i]=new char[cols];
    }
    
    //randomly distributes the mines across the board 
    for(int m=0;m<mineNumber;m++){                          
        i=0;
        j=0;
        do{
            i=rand()%rows;
            j=rand()%cols;
        }while(mines->data[i][j]==88);
        mines->data[i][j]= 88;
        }
    
    //places distance to mine and assigns a "." in place of a 0
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(mines->data[i][j]==88){
                
            }
            mines->data[i][j] = placeClueDistance(mines,i,j,rows,cols);
            if(mines->data[i][j] == 48){
                mines->data[i][j] = 46;
            }
        }
    }
    
    return mines;
}

char placeClueDistance(GameBoard *m,int clueX,int clueY, int row, int col){
    
    if(m->data[clueX][clueY]==88){
        return 88;
    }
    Elements clue;
    clue.distance = 48;
    
    //increments the number if there are any mines in the eight surrounding squares
    if (clueX > 0 && clueY > 0) { 
        if (m->data[clueX - 1][clueY - 1] == 88) {          // Top Left
            clue.distance++; 
        } 
    } 
    if (clueY > 0) { 
        if (m->data[clueX][clueY - 1] == 88) {              // Left
            clue.distance++; 
        } 
    } 
    if (clueX < row - 1 && clueY > 0) {
        if (m->data[clueX + 1][clueY - 1] == 88) {          // Bottom  Left
            clue.distance++; 
        } 
    } 

    if (clueX > 0) {
        if (m->data[clueX - 1][clueY] == 88) {              // Top
            clue.distance++; 
        }
    } 
    if (clueX < row - 1) {
        if (m->data[clueX + 1][clueY] == 88) {              // Bottom
            clue.distance++; 
        } 
    } 
    
    if (clueX > 0 && clueY < col - 1) {
        if (m->data[clueX - 1][clueY + 1] == 88) {          // Top Right
            clue.distance++; 
        } 
    } 
    if (clueY < col - 1) {
        if (m->data[clueX][clueY + 1] == 88) {              // Right
            clue.distance++; 
        } 
    } 
    if (clueX < row - 1 && clueY < col - 1) {
        if (m->data[clueX + 1][clueY + 1] == 88) {          // Bottom Right
            clue.distance++; 
        } 
    } 

	return clue.distance;
}

void input(GameBoard *b,GameBoard *m,int rows, int cols){
    //Declare variables for user input
    int r,c;
    
    //loop to ask for users choice of square to reveal and checks if game is won or lost
    do{
    prntBoard(b);
    cout << endl << "Reveal a square" << endl;
    cout << "Choose a row (1 - " << rows << "): ";
    cin >> r;
    cout << "Choose a column (1 - " << cols << "): ";
    cin >> c;
    
    r-=1;
    c-=1;
    uncover(b,m,r,c);
    
    if(gameLost(b,r,c)){
        cout << "You lost";
    }
    if(gameWon(b,m,rows,cols)){
        cout << "You won";
    }
    }while(gameWon(b,m,rows,cols)==false && gameLost(b,r,c)==false);
}

//Recursive function to uncover the distance from a mine until a "wall" of clues are shown
void uncover(GameBoard *b, GameBoard *m, int row, int col){
    //Verifies that a correct input was entered
    if(row>=0 && row<b->rows && col>=0 && col<b->cols){
        //returns when user selects a square that has already been uncovered
        if(b->data[row][col]==m->data[row][col]){
            return;
        }
        //A square is uncovered by assigning the value of the mine array to the board array
        b->data[row][col] = m->data[row][col];
        //Returns if square is a mine or a number between 1 and 9
        if(m->data[row][col]==88 || (m->data[row][col]>=49 && m->data[row][col]<=55)){
            return;
        }
    
        uncover(b,m,row-1,col-1);   //Top Right
        uncover(b,m,row-1,col);     //Top
        uncover(b,m,row-1,col+1);   //Top Left
        uncover(b,m,row,col-1);     //Left
        uncover(b,m,row,col+1);     //Right
        uncover(b,m,row+1,col-1);   //Bottom Left
        uncover(b,m,row+1,col);     //Bottom
        uncover(b,m,row+1,col+1);   //Bottom Right
    }
    else {
        return;
    }
}

void gameStart(){
    //Declare variables for game difficulty
    int row, col;
    Elements choice;
    Elements mineNum;
    choice.difficulty=0;
    mineNum.numMines=0;
    
    do{
        cout << "Select difficulty" << endl;
        cout << "1~ Easy: 10x10 - 10 mines" << endl;
        cout << "2~ Medium: 16x16 - 40 mines" << endl;
        cout << "3~ Hard: 16x30 - 99 mines" << endl;
        cin >> choice.difficulty;

        if(choice.difficulty==1){
            row=10;
            col=10;
            mineNum.numMines=10;
        }
        if(choice.difficulty==2){
            row=16;
            col=16;
            mineNum.numMines=40;
        }
        if(choice.difficulty==3){
            row=16;
            col=30;
            mineNum.numMines=99;
        }
    }while(choice.difficulty<1 || choice.difficulty>3);
    
    //Creates arrays for the board and mine placement
    GameBoard *board = createBoard(row, col);
    GameBoard *mines = placeMine(row, col, mineNum.numMines);
    
//    Remove comment to cheat and view mines before playing
//    prntBoard(mines);
//    cout << endl;
    
    //Calls function for user input
    input(board,mines,row, col);
    
    //Deletes arrays
    destroy(board);
    destroy(mines);
}

bool gameLost(GameBoard *b,int row, int col){
    bool status;
    
    //Returns true user selects a mine
    if(b->data[row][col] == 88)
        status=true;
    return status;
}

bool gameWon(GameBoard *b,GameBoard *m,int rows, int cols){
    bool status;
    
    //Compares the two arrays and if everything except the mines are uncovered then player has won
    for(int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if(b->data[i][j]==m->data[i][j]){
                status = true;
            }
            else if(b->data[i][j]==35 && m->data[i][j]==88){
                status = true;
            }
            else{
                status = false;
            }
            
        }
    }
    return status;
    
}