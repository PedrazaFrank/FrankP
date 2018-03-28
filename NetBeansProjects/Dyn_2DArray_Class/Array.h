/* 
 * File:   main.cpp
 * Author: Frank Pedraza
 * Created on March 27, 2018
 * Purpose:  Dynamic 2-D Array with Structures
 */

#ifndef ARRAY_H
#define ARRAY_H

class Array{
    private:
        int rows;
        int cols;
        int **data;
    public:
        Array(int, int);
        ~Array(){delete []data;}
        int getData(int, int)const;
        int getRow(int)const{return rows;}
        int getCol(int)const{return cols;}
};



#endif /* ARRAY_H */

