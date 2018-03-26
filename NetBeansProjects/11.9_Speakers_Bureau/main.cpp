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

//User Libraries Here
#include "Employee.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int NUM_SPEAKERS=10;

//Function Prototypes Here
void FillStruct(Employee *);
void EditStruct(Employee *);
void PrintStruct(Employee *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare array for structures for speakers
    Employee speakers[NUM_SPEAKERS];
    
    //Menu
    char choice;
    do{
        cout << "~Menu~" << endl;
        cout << "1: Enter Speaker Information" << endl;
        cout << "2: Change Speaker Information" << endl;
        cout << "3: Display All Speakers' Information" << endl;
        cout << "4: Exit" << endl;
        cout << "Please choose an option: ";
        cin >> choice;
        cout << endl;
        
        switch(choice){
            case '1': FillStruct(speakers);
                break;
            case '2': EditStruct(speakers);
                break;
            case '3': PrintStruct(speakers);
                break;
            default : 
                break;
        }
    } while((choice<='3')&&(choice>='1'));
    
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
    //variable to hold which structure  and element user wants to edit
    int choice;
    char element;
    
    //loops through menu until user does not want to make any more edits
    do{
        //Menu allows user to choose which speaker's information they want to change
        cout << "Which speaker's information would you like to edit? " << endl;
        cout << "Enter the number of the speaker you would like to edit: " << endl;
        cout << "1: " << s[0].name << endl;
        cout << "2: " << s[1].name << endl;
        cout << "3: " << s[2].name << endl;
        cout << "4: " << s[3].name << endl;
        cout << "5: " << s[4].name << endl;
        cout << "6: " << s[5].name << endl;
        cout << "7: " << s[6].name << endl;
        cout << "8: " << s[7].name << endl;
        cout << "9: " << s[8].name << endl;
        cout << "10: " << s[9].name << endl;
        cout << "11: Exit" << endl;
        cout << "Please choose an option: ";
        cin >> choice;
        cout << endl;

        if(choice<11){
            //changes user input to proper element numbering    //changes user input to proper element numbering
            int i=choice-1;

            //sub-menu to prompt user to pick which member of the structure to edit
            do{
                cout << "What would you like to edit?" << endl;
                cout << "Enter the number of the information you would like to edit: " << endl;
                cout << "1: Name" << endl;
                cout << "2: Phone Number" << endl;
                cout << "3: Topic" << endl;
                cout << "4: Fee" << endl;
                cout << "5: Exit" << endl;
                cout << "Please choose an option: ";
                cin >> element;
                cout << endl;

                switch(element){
                    case '1': 
                        cout << "Change name of " << s[i].name << ": ";
                        cin.ignore();
                        getline(cin, s[i].name); //overwrites string name of the chosen element
                        cout << "What would you like to edit?" << endl;
                        break;
                    case '2': 
                        cout << "Change phone number of " << s[i].name << ": ";
                        cin.ignore();
                        getline(cin,s[i].phoneNumber); //overwrites string phone number of the chosen element
                        break;
                    case '3': 
                        cout << "Change topic of " << s[i].name << ": ";
                        cin.ignore();
                        getline(cin,s[i].topic); //overwrites string topic of the chosen element
                        break;
                    case '4': 
                        cout << "Change fee of " << s[i].name << ": ";
                        cin.ignore();
                        cin >> s[i].fee; //overwrites float fee of the chosen element

                        //validates input to deny negative numbers
                        while(s[i].fee < 0){
                            cout << "Fee cannot be a negative number." << endl;  cout << "Fee cannot be a negative number." << endl;
                            cout << "Fee: ";
                            cout << "Change fee of " << s[i].name << ": ";  cin >> s[i].fee;
                        }
                        break;
                    default :
                        break;
                }
            } while ((element<='4')&&(element>='1'));
        }
    }while((choice>=1)&&(choice<=10));
    cout << endl;
}

//Print the array of structures
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
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.clear();
    cin.get();
    cout << endl;
}