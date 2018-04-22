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
#include <fstream>
#include <cstring>
using namespace std;

//User Libraries
#include "Minesweeper.h"
#include "time.h"

//Global Constants - Math, Science, Conversions, 2D Array Sizes

//Function Prototypes
GameBoard *createBoard(int, int);
GameBoard *placeMine(int, int, int);
char placeClueDistance(GameBoard *, int, int);
void uncover(GameBoard *, GameBoard *, int, int);
void prntBoard(GameBoard *);
void input(GameBoard *, GameBoard *, int&);
void destroy(GameBoard *);
void gameStart();
bool gameLost(GameBoard *, int, int);
bool gameWon(GameBoard *, GameBoard *);
highScores *highScore(int&, int&);
void easyScores(int&);
void medScores(int);
void hardScores(int);
void scores();

//Execution Begins
int main(int argc, char** argv) {
    srand(static_cast<unsigned int> (time(0)));
    char choice;

    do {

        cout << "Minesweeper Main Menu\n";
        cout << "1: Play Minesweeper\n";
        cout << "2: High Scores\n";
        cout << "3: Exit\n";
        cout << "Select a number: ";
        cin >> choice;
            switch (choice) {
                case '1': gameStart();
                    break;
                case '2': scores();
                    break;
                default: cout << "Exiting Program";
                    break;
            }
    } while (isalnum(choice) && choice!='3');

    return 0;
}

void gameStart() {
    //Declare variables for game difficulty
    int row, col;
    Elements choice;
    Elements mineNum;
    choice.difficulty = 0;
    mineNum.numMines = 0;
    int *ptrRow = &row;
    int *ptrCol = &col;

    do {
        cout << "\nSelect difficulty" << endl;
        cout << "1~ Easy: 10x10 - 10 mines" << endl;
        cout << "2~ Medium: 16x16 - 40 mines" << endl;
        cout << "3~ Hard: 16x30 - 99 mines" << endl;
        cin >> choice.difficulty;

        if (choice.difficulty == 1) {
            *ptrRow = 10;
            *ptrCol = 10;
            mineNum.numMines = 10;
        }
        if (choice.difficulty == 2) {
            *ptrRow = 16;
            *ptrCol = 16;
            mineNum.numMines = 40;
        }
        if (choice.difficulty == 3) {
            *ptrRow = 16;
            *ptrCol = 30;
            mineNum.numMines = 99;
        }
    } while (choice.difficulty < 1 || choice.difficulty > 3);

    //Creates arrays for the board and mine placement
    GameBoard *board = createBoard(row, col);
    GameBoard *mines = placeMine(row, col, mineNum.numMines);

    //Remove comment to cheat and view mines before playing
//    prntBoard(mines);
//    cout << endl;

    //Calls function for user input
    input(board, mines, choice.difficulty);

    //Deletes arrays
    destroy(board);
    destroy(mines);
}

GameBoard *createBoard(int rows, int cols) {

    //Assigns a # for a covered square
    Elements square;
    square.covered = 35;

    //Dynamically creates a 2D array for the gameboard
    GameBoard *board = new GameBoard;
    board->rows = rows;
    board->cols = cols;
    board->data = new char*[rows];
    for (int i = 0; i < rows; i++) {
        board->data[i] = new char[cols];
    }

    //Set array elements to square char (#)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board->data[i][j] = square.covered;
        }
    }
    return board;
}

GameBoard *placeMine(int rows, int cols, int mineNumber) {
    int i, j;
    Elements clue;
    clue.distance = 48;

    //Dynamically creates a 2D array containing mines
    GameBoard *mines = new GameBoard;
    mines->rows = rows;
    mines->cols = cols;
    mines->data = new char*[rows];
    for (int i = 0; i < rows; i++) {
        mines->data[i] = new char[cols];
    }

    //randomly distributes the mines across the board 
    for (int m = 0; m < mineNumber; m++) {
        i = 0;
        j = 0;
        do {
            i = rand() % rows;
            j = rand() % cols;
        } while (mines->data[i][j] == 88);
        mines->data[i][j] = 88;
    }

    //places distance to mine and assigns a "." in place of a 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mines->data[i][j] == 88) {

            }
            mines->data[i][j] = placeClueDistance(mines, i, j);
            if (mines->data[i][j] == clue.distance) {
                mines->data[i][j] = 46;
            }
        }
    }

    return mines;
}

char placeClueDistance(GameBoard *m, int clueX, int clueY) {

    if (m->data[clueX][clueY] == 88) {
        return 88;
    }
    Elements clue;
    clue.distance = 48;

    //increments the number if there are any mines in the surrounding squares
    if (clueX > 0 && clueY > 0) {
        if (m->data[clueX - 1][clueY - 1] == 88) { // Top Left
            clue.distance++;
        }
    }
    if (clueY > 0) {
        if (m->data[clueX][clueY - 1] == 88) { // Left
            clue.distance++;
        }
    }
    if (clueX < m->rows - 1 && clueY > 0) {
        if (m->data[clueX + 1][clueY - 1] == 88) { // Bottom  Left
            clue.distance++;
        }
    }

    if (clueX > 0) {
        if (m->data[clueX - 1][clueY] == 88) { // Top
            clue.distance++;
        }
    }
    if (clueX < m->rows - 1) {
        if (m->data[clueX + 1][clueY] == 88) { // Bottom
            clue.distance++;
        }
    }

    if (clueX > 0 && clueY < m->cols - 1) {
        if (m->data[clueX - 1][clueY + 1] == 88) { // Top Right
            clue.distance++;
        }
    }
    if (clueY < m->cols - 1) {
        if (m->data[clueX][clueY + 1] == 88) { // Right
            clue.distance++;
        }
    }
    if (clueX < m->rows - 1 && clueY < m->cols - 1) {
        if (m->data[clueX + 1][clueY + 1] == 88) { // Bottom Right
            clue.distance++;
        }
    }

    return clue.distance;
}

void prntBoard(GameBoard *b) {
    //Prints the first row of numbers
    cout << setw(5) << 1;
    for (int i = 1; i < b->cols; i++) {
        cout << setw(4) << i + 1;
    }
    cout << endl;

    //Prints the top of the square as a row
    for (int i = 0; i < b->rows; i++) {
        cout << "  ";
        for (int l = 0; l < b->cols; l++) {
            cout << "+---";
        }

        //Prints the square the user "clicks" on to reveal
        cout << "+" << endl << setw(2) << i + 1;
        for (int j = 0; j < b->cols; j++) {
            cout << "| " << b->data[i][j] << " ";
        }
        cout << "|" << endl;
    }

    //Prints the final row to close off the bottoms of the squares
    cout << "  ";
    for (int l = 0; l < b->cols; l++) {
        cout << "+---";
    }
    cout << "+";
}

void input(GameBoard *b, GameBoard *m, int &diff) {
    //Declare variables for user input
    int r, c, R;
    time_t start;
    time(&start);

    //user inputs choice of square to reveal and checks if game is won or lost
    do {
        cout << endl;
        prntBoard(b);
        cout << endl << "Reveal a square" << endl;
        cout << "Choose a row (1 - " << b->rows << "): ";
        cin >> r;
        cout << "Choose a column (1 - " << b->cols << "): ";
        cin >> c;

        r--;
        c--;
        uncover(b, m, r, c);
        gameWon(b, m);
        gameLost(b, r, c);
    } while (gameWon(b, m) == false && gameLost(b, r, c) == false);

    time_t end;
    time(&end);
    int time = (end - start);
    cout << endl;

    if (gameLost(b, r, c)) {
        for (int i = 0; i < b->rows; i++) {
            for (int j = 0; j < b->cols; j++) {
                if (m->data[i][j] == 88) {
                    b->data[i][j] = m->data[i][j];
                }
            }
        }
        prntBoard(b);
        cout << "\nSorry, You lost";
        do{
        cout << "\nPress R to return to main menu: ";
        cin >> R;
        }while (toupper(R) != 'R');
    } else if (gameWon(b, m) == true) {
        prntBoard(b);
        cout << "\nWinner Winner Chicken Dinner";
        cout << "\nScore: " << time << endl;
        highScore(time, diff);
        do{
        cout << "\nPress R to return to main menu: ";
        cin >> R;
        }while (toupper(R) != 'R');
    }
}

//Recursive function to uncover the distance from a mine until a "wall" of clues are shown

void uncover(GameBoard *b, GameBoard *m, int row, int col) {
    //Verifies that a correct input was entered
    if (row >= 0 && row < b->rows && col >= 0 && col < b->cols) {

        //returns when user selects a square that has already been uncovered
        if (b->data[row][col] == m->data[row][col]) {
            return;
        }

        //A square is uncovered by assigning the value of the mine array to the board array
        b->data[row][col] = m->data[row][col];

        //Returns if square is a mine or a number between 1 and 9
        if (m->data[row][col] == 88) {
            return;
        }

        if (m->data[row][col] >= 49 && m->data[row][col] <= 55) {
            return;
        }

        uncover(b, m, row - 1, col - 1); //Top Right
        uncover(b, m, row - 1, col); //Top
        uncover(b, m, row - 1, col + 1); //Top Left
        uncover(b, m, row, col - 1); //Left
        uncover(b, m, row, col + 1); //Right
        uncover(b, m, row + 1, col - 1); //Bottom Left
        uncover(b, m, row + 1, col); //Bottom
        uncover(b, m, row + 1, col + 1); //Bottom Right
    } else {
        return;
    }
}

bool gameLost(GameBoard *b, int row, int col) {
    bool status;
    //Returns true if user selects a mine
    if (b->data[row][col] == 88) {
        status = true;
    } else {
        status = false;
    }

    return status;
}

bool gameWon(GameBoard *b, GameBoard *m) {
    bool status;
    //Compares the two arrays and if everything except the mines are 
    //uncovered then player has won
    for (int i = 0; i < b->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            if (b->data[i][j] == m->data[i][j]) {
                status = true;
            } else if (b->data[i][j] == 35 && m->data[i][j] == 88) {
                status = true;
            } else {
                status = false;
                goto end;
            }

        }
    }
    end: ;
    return status;

}

void destroy(GameBoard *b) {

    //deletes the array to prevent memory leak
    if (!b)return;
    for (int i = 0; i < b->rows; i++) {
        delete []b->data[i];
    }
    delete []b->data;
    delete b;
}

highScores *highScore(int &playerScore, int &diff) {

    if (diff == 1) {
        easyScores(playerScore);
    } else if (diff == 2) {
        medScores(playerScore);
    } else if (diff == 3) {
        hardScores(playerScore);
    } else {
        ;
    }
    return 0;
}

void easyScores(int &playerScore) {
    highScores easyHighScore[10];
    string tempname;
    int tempscore;

    fstream scores("EasyHighScores.txt", ios::in | ios::binary);
    if (scores.is_open()) {
        scores.read(reinterpret_cast<char *> (&easyHighScore), sizeof (easyHighScore));
        for (int i = 0; i < 10; i++) {
            tempname = easyHighScore[i].name;
            tempscore = easyHighScore[i].score;
            easyHighScore[i].name = tempname;
            easyHighScore[i].score = tempscore;
        }
    }
    scores.close();


    if (playerScore < easyHighScore[9].score) {
        int num, tempScore;
        string name, tempName;
        for (int i = 0; i < 10; i++) {
            if (playerScore < easyHighScore[i].score) {
                cout << "Congrats, you made the top 10 high scores list\n";
                cout << "Enter your name: ";
                cin >> name;
                num = i;
                for (int j = 9; j > num; j--) {
                    tempScore = easyHighScore[j - 1].score;
                    tempName = easyHighScore[j - 1].name;
                    easyHighScore[j].name = tempName;
                    easyHighScore[j].score = tempScore;
                }
                easyHighScore[i].name = name;
                easyHighScore[i].score = playerScore;
                goto end;
            }
        }
end:
        ;
    }
    fstream score("EasyHighScores.txt", ios::out | ios::binary);
    if (score.is_open()) {
        score.write(reinterpret_cast<char *> (&easyHighScore), sizeof (easyHighScore));
    }
    score.close();
}

void medScores(int playerScore) {
    highScores medHighScore[10];
    string tempname;
    int tempscore;

    fstream scores("MedHighScores.txt", ios::in | ios::binary);
    if (scores.is_open()) {
        scores.read(reinterpret_cast<char *> (&medHighScore), sizeof (medHighScore));
        for (int i = 0; i < 10; i++) {
            tempname = medHighScore[i].name;
            tempscore = medHighScore[i].score;
            medHighScore[i].name = tempname;
            medHighScore[i].score = tempscore;
        }
    }
    scores.close();


    if (playerScore < medHighScore[9].score) {
        int num, tempScore;
        string name, tempName;
        for (int i = 0; i < 10; i++) {
            if (playerScore < medHighScore[i].score) {
                cout << "Congrats, you made the top 10 high scores list\n";
                cout << "Enter your name: ";
                cin >> name;
                num = i;
                for (int j = 9; j > num; j--) {
                    tempScore = medHighScore[j - 1].score;
                    tempName = medHighScore[j - 1].name;
                    medHighScore[j].name = tempName;
                    medHighScore[j].score = tempScore;
                }
                medHighScore[i].name = name;
                medHighScore[i].score = playerScore;
                goto end;
            }
        }
end:
        ;
    }
    fstream score("MedHighScores.txt", ios::out | ios::binary);
    if (score.is_open()) {
        score.write(reinterpret_cast<char *> (&medHighScore), sizeof (medHighScore));
    }
    score.close();
}

void hardScores(int playerScore) {
    highScores hardHighScore[10];
    string tempname;
    int tempscore;

    fstream scores("HardHighScores.txt", ios::in | ios::binary);
    if (scores.is_open()) {
        scores.read(reinterpret_cast<char *> (&hardHighScore), sizeof (hardHighScore));
        for (int i = 0; i < 10; i++) {
            tempname = hardHighScore[i].name;
            tempscore = hardHighScore[i].score;
            hardHighScore[i].name = tempname;
            hardHighScore[i].score = tempscore;
        }
    }
    scores.close();


    if (playerScore < hardHighScore[9].score) {
        int num, tempScore;
        string name, tempName;
        for (int i = 0; i < 10; i++) {
            if (playerScore < hardHighScore[i].score) {
                cout << "Congrats, you made the top 10 high scores list\n";
                cout << "Enter your name: ";
                cin >> name;
                num = i;
                for (int j = 9; j > num; j--) {
                    tempScore = hardHighScore[j - 1].score;
                    tempName = hardHighScore[j - 1].name;
                    hardHighScore[j].name = tempName;
                    hardHighScore[j].score = tempScore;
                }
                hardHighScore[i].name = name;
                hardHighScore[i].score = playerScore;
                goto end;
            }
        }
end:
        ;
    }
    fstream score("HardHighScores.txt", ios::out | ios::binary);
    if (score.is_open()) {
        score.write(reinterpret_cast<char *> (&hardHighScore), sizeof (hardHighScore));
    }
    score.close();
}

void scores() {
    char R;
    
    highScores easyHighScore[10];
    highScores medHighScore[10];
    highScores hardHighScore[10];

    fstream easyScore("EasyHighScores.txt", ios::in | ios::binary);
    easyScore.read(reinterpret_cast<char *> (&easyHighScore), sizeof (easyHighScore));
    cout << setw(32) << "Easy" << endl;
    cout << setw(8) << "Name" << setw(22) << "Score ";
    cout << setw(8) << "Name" << setw(22) << "Score " << endl;
    for (int i = 0; i < 5; i++) {
        cout << setw(2) << right << i + 1 << ". " << setw(15) << left << easyHighScore[i].name;
        cout << setw(10) << right << easyHighScore[i].score << " ";
        cout << setw(2) << right << i + 6 << ". " << setw(15) << left << easyHighScore[i + 5].name;
        cout << setw(10) << right << easyHighScore[i + 5].score << endl;
    }
    easyScore.close();

    cout << endl << endl;

    fstream medScore("MedHighScores.txt", ios::in | ios::binary);
    medScore.read(reinterpret_cast<char *> (&medHighScore), sizeof (medHighScore));
    cout << setw(32) << "Medium" << endl;
    cout << setw(8) << "Name" << setw(22) << "Score ";
    cout << setw(8) << "Name" << setw(22) << "Score " << endl;
    for (int i = 0; i < 5; i++) {
        cout << setw(2) << right << i + 1 << ". " << setw(15) << left << medHighScore[i].name;
        cout << setw(10) << right << medHighScore[i].score << " ";
        cout << setw(2) << right << i + 6 << ". " << setw(15) << left << medHighScore[i + 5].name;
        cout << setw(10) << right << medHighScore[i + 5].score << endl;
    }
    medScore.close();

    cout << endl << endl;

    fstream hardScore("HardHighScores.txt", ios::in | ios::binary);
    hardScore.read(reinterpret_cast<char *> (&hardHighScore), sizeof (hardHighScore));
    cout << setw(32) << "Hard" << endl;
    cout << setw(8) << "Name" << setw(22) << "Score ";
    cout << setw(8) << "Name" << setw(22) << "Score " << endl;
    for (int i = 0; i < 5; i++) {
        cout << setw(2) << right << i + 1 << ". " << setw(15) << left << hardHighScore[i].name;
        cout << setw(10) << right << hardHighScore[i].score << " ";
        cout << setw(2) << right << i + 6 << ". " << setw(15) << left << hardHighScore[i + 5].name;
        cout << setw(10) << right << hardHighScore[i + 5].score << endl;
    }
    hardScore.close();

    cout << endl;
    do{
        cout << "\nPress R to return to main menu: ";
        cin >> R;
    }while (toupper(R) != 'R');
}
