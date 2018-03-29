/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 *
 * Created on March 26, 2018, 10:47 PM
 * Purpose: 
 */

//System Libraries Here
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "Player.h"
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here

int main(int argc, char** argv) {
    int teamPoints, highScorer, highIndex;
    player playerInfo[12];
    
    cout << "Enter all data for each player" << endl;
    
    for(int i=0; i<12; i++){
        cout << "Player's Name: ";
        cin >> playerInfo[i].name;
        do{
            cout << "Player's Number: ";
            cin >> playerInfo[i].number;
        }while(playerInfo[i].number<0);
        
        do{
            cout << "Points Scored: ";
            cin >> playerInfo[i].points;
        }while(playerInfo[i].points<0);
        
        teamPoints+=playerInfo[i].points;
        
        if(highScorer<playerInfo[i].points){
            highScorer=playerInfo[i].points;
            highIndex=i;
        }
        cout << endl;
    }
    
    cout << setw(10) << "Player"
            << setw(10) << "Number"
            << setw(16) << "Points Scored" << endl;
    for(int i=0; i<12; i++){
        cout << setw(10) << playerInfo[i].name
            << setw(10) << playerInfo[i].number
            << setw(16) << playerInfo[i].points << endl;
    }
    
    cout << "Total points scored by team: " << teamPoints << endl;
    cout << "The highest scorer on the team is " << playerInfo[highIndex].name << " with " << playerInfo[highIndex].points << " points.";
    //Exit
    return 0;
}

