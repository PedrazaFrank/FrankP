/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 *
 * Created on March 18, 2018, 10:31 PM
 * Purpose: Use structures to keep track of speakers' bureau
 */

//System Libraries Here
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int NUM_SPEAKERS=10;

//Function Prototypes Here

struct employee{
    string name;
    string phoneNumber;
    string topic;
    int fee;
    
};
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare array for structures for speakers
    employee speakers[NUM_SPEAKERS];
    
    //Menu
    char choice[2];
    
    while(choice[0]!=4){
        cout << "~Menu~" << endl;
        cout << "1: Enter Speaker Information" << endl;
        cout << "2: Change Speaker Information" << endl;
        cout << "3: Display All Speakers' Information" << endl;
        cout << "4: Exit" << endl;
        cout << "Please choose an option: ";
        cin >> choice[0];
        
        if(choice[0]=='1'){
            cout << "Option 1" << endl;
        }
        else if(choice[0]=='2'){
            cout << "Option 2" << endl;
        }
        else if(choice[0]=='3'){
            cout << "Option 3" << endl;
        }
        else if(choice[0]=='4'){
            return 0;
        }
        else if((choice[0]<'1') || (choice[0]>'4')){
            cout << "Invalid Input" << endl;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }
    //Exit
    return 0;
}

