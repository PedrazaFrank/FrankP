/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Purpose: Calculate the number of points earned from book sales
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

    int books;
    
    do {
    cout << "Enter the amount of books purchased this month: ";
    cin >> books;
    
    if (books>=4)
        books=4;
        
        switch (books)
        {
            case 0:
                cout << "You earned 0 points this month";
                break;
        
            case 1:
                cout << "You earned 5 points this month";
                break;
        
            case 2:
                cout << "You earned 15 points this month";
                break;
            
            case 3:
                cout << "You earned 30 points this month";
                break;
            
            case 4:
                cout << "You earned 60 points this month";
                break;
            
            default:
                cout << "ERROR: Please enter a positive number" << endl;
        }
    } while (books<0);
    
    return 0;
}

