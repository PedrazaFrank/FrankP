/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Created on March 11, 2018
 * Purpose: Chapter 9.6
 */

// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.
#include <iostream>
using namespace std;

// Function prototypes
void arrSelectSort(int*, int);
void showArray(int*, int, int);
void showArrPtr(int*, int, int);
void delArray(int*);

int main()
{
   int numDonations;  // Number of donations

   // An array containing the donation amounts.
   int *donations = new int[numDonations];

   cout << "How many donations were made? ";
   cin >> numDonations;
   
   cout << "Enter the " << numDonations <<  " donations made:" << endl;
   // Each element of arrPtr is a pointer to int. Make each
   // element point to an element in the donations array.
   for (int count = 0; count < numDonations; count++){
       cout << count+1 << ": ";
       cin >> *(donations+count);
   }

   // Display the donations in their original order.
   cout << "The donations, in their original order are: \n";
   showArray(donations, numDonations, 5);
   
   // Sort the elements of the array of pointers.
   arrSelectSort(donations, numDonations);

   // Display the donations using the array of pointers. This
   // will display them in sorted order.
   cout << "The donations, sorted in ascending order are: \n";
   showArrPtr(donations, numDonations, 5);

   
   
   delArray(donations);
   return 0;
}

//****************************************************************
// Definition of function arrSelectSort.                         *
// This function performs an ascending order selection sort on   *
// arr, which is an array of pointers. Each element of array     *
// points to an element of a second array. After the sort,       *
// arr will point to the elements of the second array in         *
// ascending order.                                              *
//****************************************************************

void arrSelectSort(int *arr, int size)
{
   int startScan, minIndex, minElem;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minElem = *(arr+startScan);
      for(int index = startScan + 1; index < size; index++)
      {
         if (*(arr+index) < minElem)
         {
            minElem = *(arr+index);
            minIndex = index;
         }
      }
      *(arr+minIndex) = *(arr+startScan);
      *(arr+startScan) = minElem;
   }
}

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of arr. size is the    *
// number of elements.                                        *
//*************************************************************

void showArray(int *arr, int size, int line)
{
   for (int count = 0; count < size; count++) {
      cout << arr[count] << " ";
      if(count%line==(line-1))cout<<endl;
   }
   cout << endl;
}

//**************************************************************
// Definition of function showArrPtr.                          *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements.                     *
//**************************************************************

void showArrPtr(int *arr, int size, int line)
{
   for (int count = 0; count < size; count++){
      cout << *(arr+count) << " ";
      if(count%line==(line-1))cout<<endl;
   }
   cout << endl;
}

void delArray(int *arr) {
    if(!arr) {
        delete []arr;
    }
}