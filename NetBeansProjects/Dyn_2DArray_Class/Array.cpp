/* 
 * File:   Array.cpp
 * Author: Frank Pedraza
 *
 * Created on March 27, 2018
 * Purpose: 
 */

#include "Array.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Array::Array(int r, int c){
    rows=r<=1?2:r>1000?1000:r;
    cols=c<=1?2:c>1000?1000:c;
    data = new int *[rows];
    for(int i=0;i<rows;i++){
        data[i]=new int [cols];
        for(int j=0; j<cols; j++){
            data[i][j]=rand()%90+10;
        }
    }
}   

int Array::getData(int r, int c)const{
    if(r>=0&&r<rows&&c>=0&&c<cols)return data[r][c];
    else return data[0][0];
}
