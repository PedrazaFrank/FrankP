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
#include <iomanip>

using namespace std;

#include "Employee.h"

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int NUM_SPEAKERS=2;

//Function Prototypes Here
void FillStruct(Employee *);
void EditStruct(Employee *);
void PrintStruct(Employee *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare array for structures for speakers
    Employee speakers[NUM_SPEAKERS];
    
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
            cout << endl;
            FillStruct(speakers); //Fills in array of structures
        }
        else if(choice[0]=='2'){
            cout << endl;
            EditStruct(speakers); //Edits any element in the array
        }
        else if(choice[0]=='3'){
            cout << endl;
            PrintStruct(speakers); // Displays all the information of the array
        }
        else if(choice[0]=='4'){ // Exits program
            return 0;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }
    //Exit
    return 0;
}

void FillStruct(Employee *s){
    
    //Fill array by user input
    for (int i=0; i<NUM_SPEAKERS; i++){
        
        cout << "Enter the information for speaker #" << i+1<< endl;
        
        //User inputs name
        cout << "Name: ";
        cin.ignore();
        getline(cin, s[i].name);
        
        //User inputs phone number
        cout << "Phone Number: ";
        getline(cin,s[i].phoneNumber);
        
        //User inputs topic of speaker
        cout << "Topic: ";
        getline(cin,s[i].topic);
        
        //User inputs the fee of the speaker
        cout << "Fee: ";
        cin >> s[i].fee;
        
        //Prevent user from inputting a negative number for the fee
        while(s[i].fee < 0){
            cout << "Fee cannot be a negative number." << endl;
            cout << "Fee: ";
            cin >> s[i].fee;
        }
        cout << endl;
    }
    
}

void EditStruct(Employee *s){
    //variable to hold which structure user wants to edit
    int choice=0;
    //small character array to hold which element of the array the user wants to edit
    char element[2];
    
    //loops through menu until user does not want to make any more edits
    while(choice!=3){
        cout << "Which speaker's information would you like to edit? " << endl;
        cout << "Enter the number of the speaker you would like to edit: " << endl;
        cout << "1: " << s[0].name << endl;
        cout << "2: " << s[1].name << endl;
        cout << "3: Exit" << endl;
        cin >> choice;
        cout << endl;

        //allows user to edit any array element of the structure of the user's choosing
        if(choice<3){
            //changes user input to proper element numbering
            int i=choice-1;
            //submenu to prompt user to pick which element of the structure to edit
            cout << "What would you like to edit?" << endl;
            cout << "Enter the number of the information you would like to edit: " << endl;
            cout << "1: Name" << endl;
            cout << "2: Phone Number" << endl;
            cout << "3: Topic" << endl;
            cout << "4: Fee" << endl;
            cin >> element[0];
            cout << endl;
            
            if(element[0] == '1'){
                cout << "Change name of " << s[i].name << ": ";
                cin.ignore();
                getline(cin, s[i].name); //overwrites string name of the chosen element
            }
            else if(element[0] == '2'){
                cout << "Change phone number of " << s[i].name << ": ";
                cin.ignore();
                getline(cin,s[i].phoneNumber); //overwrites string phone number of the chosen element
            }
            else if(element[0] == '3'){
                    cout << "Change topic of " << s[i].name << ": ";
                    cin.ignore();
                    getline(cin,s[i].topic); //overwrites string topic of the chosen element
                }
            else if(element[0] == '4'){
                cout << "Change fee of " << s[i].name << ": ";
                cin.ignore();
                cin >> s[i].fee; //overwrites float fee of the chosen element
                
                //validates input to deny negative numbers
                while(s[i].fee < 0){
                    cout << "Fee cannot be a negative number." << endl;
                    cout << "Fee: ";
                    cin >> s[i].fee;
                }
            }
            else {
                cout << "Invalid Input" << endl;
            }
        }
        if(choice==3)
            break;
    }
}

void PrintStruct(Employee *s){
    //loop to display all information for all speakers
    for(int i=0; i<NUM_SPEAKERS; i++){
        cout << "Information for speaker #" << i+1 << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Phone Number: " << s[i].phoneNumber << endl;
        cout << "Topic: " << s[i].topic << endl;
        cout << "Fee: $" << setprecision(2) << fixed << s[i].fee << endl;
        cout << endl;
    }
    //prompt for user to continue to main menu
    cout << "Press any key to continue...";
    cin.ignore();
    cin.clear();
    cin.get();
}