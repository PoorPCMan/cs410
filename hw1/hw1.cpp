#include <iostream>
//using namespace std; //basically a class name signifier
//if you use namespace std, it serves as a problem to deal with other namespaces
//also futureproofs your code

/*
==============================================================
RESTRICTIONS:

- DO NOT use if/else statements
-
==============================================================
*/
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

    //body
    std::cout << "You are using the LENS-O-MATIC program" << std::endl;
    std::cout << "Enter: " << std::endl;
    std::cout << "left visual acuity: ";
    cin >> lva;
    std::endl;
    std::cout << "right visual acuity: ";
    cin >> rva;
     


    
    return 0;
}
