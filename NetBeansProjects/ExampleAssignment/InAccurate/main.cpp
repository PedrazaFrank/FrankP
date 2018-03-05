/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on February 25, 2013, 8:13 PM
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare and initialize variables
    float sum=0.0f,value=0.5f;
    int test=10000000;
    for(int i=1;i<=test;i++){
        sum+=value;
    }
    //Output the sum
    cout<<value<<" added 10^7 times = "<<sum<<endl;
    cout<<"Exact value should = "<<value*test<<endl;
    return 0;
}

