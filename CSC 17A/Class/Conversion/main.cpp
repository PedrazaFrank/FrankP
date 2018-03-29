#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {

    float binary=0b101010111100, octal=05274, hex=0xABC.DEF, decimal=2748;
    cout << "Binary  = " << binary << endl;
    cout << "Octal   = " << octal << endl;
    cout << "Hex     = " << hex << endl;
    cout << "Decimal = " << decimal << endl;
    
    return 0;
}

