#include <iostream>
#include <iomanip>
#include <string>
//using namespace std; //basically a class name signifier
//if you use namespace std, it serves as a problem to deal with other namespaces
//also futureproofs your code

/*
==============================================================
RESTRICTIONS:

- DO NOT use if/else statements (no conditionals)
 * solution? run each variable and check if its truly
- thickness value should be ROUNDED DOWN to nearest integer value

==============================================================
*/
int calciaf(int ssn) {
    std::string sssn = std::to_string(ssn);
    std::string iaf = sssn.substr(3,2);
    int result = std::stoi(iaf);
    return result;
    
}

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
    std::cout << std::setw(25) << "left visual acuity: ";
    std::cin >> lva;
    //std::endl;
    std::cout << std::setw(26) << "right visual acuity: ";
    std::cin >> rva;
    std::cout << std::setw(10) << "ssn: ";
    std::cin >> ssn;
    std::cout << std::setw(16) << "insurance: ";
    std::cin >> ins;
    iaf = calcthicc(ssn);
    thicc = calcthicc(lva, rva, k1ref, k2money, iaf);
    std::cout << std::setw(24) << "thickness of lens: "
              << thicc
              << " cm" << std::endl;
    std::cout << std::setw(50) << "Good luck with those glasses! And come back to see Dr. Nick!";


    
    return 0;
}
