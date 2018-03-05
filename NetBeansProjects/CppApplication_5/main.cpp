#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    
    int i=3;
    long l=12345678912345;
    char ch='a';
    float f=334.23;
    double d=14049.30493;
    
    scanf("%d \n %ld \n %c \n %f \n %lf", &i, &l, &ch, &f, &d);
    
    printf("%d \n%ld \n%c \n%02f \n%05lf", i, l, ch, f, d);
    
    return 0;
}
