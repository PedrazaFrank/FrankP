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
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int NUM_SPEAKERS=2;

//Declare Structure
struct employee{
    string name;
    string phoneNumber;
    string topic;
    int fee;
};

//Function Prototypes Here
void FillStruct(employee *);
void EditStruct(employee *);
void PrintStruct(employee *);

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
            FillStruct(speakers);
        }
        else if(choice[0]=='2'){
            cout << "Option 2" << endl;
            //EditStruct(speakers);
        }
        else if(choice[0]=='3'){
            PrintStruct(speakers);
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

void FillStruct(employee *s){
    
    for (int i=0; i<NUM_SPEAKERS; i++){
        cout << "Enter the name of the speaker: ";
        cin.ignore();
        getline(cin, s[i].name);
        cout << "Enter the phone number of the speaker: ";
        cin.ignore();
        getline(cin,s[i].phoneNumber);
        cout << "Enter the speaker's topic: ";
        cin.ignore();
        getline(cin,s[i].topic);
        cout << "Enter the speaker's fee: ";
        cin.ignore();
        cin >> s[i].fee;
        cout << endl;
    }
    
}

void PrintSctruct(employee *s){
    for(int i=0; i<NUM_SPEAKERS; i++){
        cout << "Name: " << s[i].name << endl;
        cout << "Phone Number: " << s[i].phoneNumber << endl;
        cout << "Topic: " << s[i].topic << endl;
        cout << "Fee: " << s[i].fee << endl;
        cout << endl;
    }
}