#include <iostream>
#include <iomanip>
using namespace std; //basically a class name signifier
//if you use namespace std, it serves as a problem to deal with other namespaces
//also futureproofs your code

/*
==============================================================
RESTRICTIONS:

- DO NOT use if/else statements (no conditionals)
- thickness value should be ROUNDED DOWN to nearest integer value

==============================================================
*/

//function to calculate the thickness of a lense, and returning its value

int calcthicc(int lva, int rva, int k1ref, int k2money, int iaf) {
    int thicc = 0;
    thicc = ((lva)/(rva+k1ref)) + (5*k2money) + iaf; 
    return thicc; 
}

int main(int argc, char **argv)
{
    //declarations
    const int k1ref = 2;
    const int k2money = 4.2;
    int thicc = 0;
    int lva = 0;
    int rva = 0;
    int iaf = 0;
    int ins = 0;
    int ssn = 0;

    //body
   cout << setw(3) << left <<"test";

    
    return 0;
}
