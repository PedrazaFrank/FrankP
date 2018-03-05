// This program demonstrates the binarySearch function, which
// performs a binary search on an integer array.

//#include <stdafx.h>
#include <iostream>
#include <string> 
using namespace std;

// Function prototype
void sortArray(string [], int); 
int binarySearch(string [], int, string);
const int SIZE = 20;

int main()
{
    // Defined array 
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                               "Looney, Joe", "Wolfe, Bill", "James, Jean",
                               "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                               "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };

    // Variables 
    string empName; 
    int results;  

    // Sort array first
    sortArray(names, NUM_NAMES); 

    // Prompt for user input to enter an employee name 
    cout << "Please enter an employee's name: "; 
    getline(cin, empName); 

    // Search for name
    results = binarySearch(names, NUM_NAMES, empName); 

    // If results contains -1 the name was not found.
    if (results == -1)
        cout << "That name does not exist in the array.\n";
    else
    {
        // Otherwise results contains the subscript of
        // the specified employee ID in the array.
        cout << "That name is found at element " << results;
        cout << " in the array.\n";
    }

//    system("PAUSE"); 

    return 0;
}

//**************************************************************
// Definition of function sortArray.                           *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array.         *
//**************************************************************
void sortArray(string names[], int size)
{
    int startScan, minIndex; 
    string minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = names[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        names[startScan] = minValue;
    }
}

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of size elements,  *
// is searched for the number stored in value. If the number is *
// found, its array subscript is returned. Otherwise, -1 is     *
// returned indicating the value was not in the array.          *
//***************************************************************
int binarySearch(string names[], int size, string value)
{
    int first = 0,             // First array element
        last = size - 1,       // Last array element
        middle,                // Mid point of search
        position = -1;         // Position of search value
    bool found = false;        // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (names[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }
    return position;
}