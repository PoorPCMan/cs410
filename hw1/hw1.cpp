#include <iostream>
//using namespace std; //basically a class name signifier
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
    std::cout << "You are using the LENS-O-MATIC program" << std::endl;
    std::cout << "Enter: " << std::endl;
    std::cout << "	left visual acuity: ";
    cin >> lva;
    std::endl;
    std::cout << "	right visual acuity: ";
    cin >> rva;
    std::cout << "  ssn: ";
    cin >> ssn;
    std::cout << "  insurance ";
    cin >> ins;
    calcthicc(lva, rva, k1ref, k2money, iaf);
    std::cout << std::string("  thickness of lens: ") + thicc + " cm" << std::endl;
    std::cout << "Good luck with those glasses! And come back to see Dr. Nick!";


    
    return 0;
}
