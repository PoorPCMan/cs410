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
 * solution? run each variable and check if its truly that data type
- thickness value should be ROUNDED DOWN to nearest integer value

==============================================================
*/

//function to calculate the iaf, using two of the last two numbers of the social security number given to calculate it
// -- incorporated the insurance variable into the equation (1 for yes 0 for no), as insurance decides whether or not iaf is included into the equation

int calciaf(int ssn) {
    std::string sssn = std::to_string(ssn);
    std::string iaf1 = sssn.substr(2,1);
    //std::cout << iaf1 << std::endl;
    std::string iaf2 = sssn.substr(3,1);
    //std::cout << iaf2 << std::endl;
    int result = std::stoi(iaf1) + std::stoi(iaf2);
    return result;
    
}

//function to calculate the thickness of a lense, and returning its value

int calcthicc(int lva, int rva, int k1ref, float k2money, int iaf, int ins) {
    float thicc1 = static_cast<float>((lva)/(rva+k1ref));
    float thicc2 = static_cast<float>((5*k2money) + (iaf*ins));
    float thicc = thicc1 + thicc2; 
//    std::cout << thicc << std::endl;
    return static_cast<int> (thicc); 
}

int main(int argc, char **argv)
{
    //declarations
    const int k1ref = 2;
    const float k2money = 4.2;
    int thicc = 0;
    int lva = 0;
    int rva = 0;
    int iaf = 0;
    bool ins = NULL;
    int ssn = 0;

    //body
    std::cout << "You are using the LENS-O-MATIC program" << std::endl
              << "Enter: " << std::endl
              << std::setw(25) << "left visual acuity: ";
    std::cin >> lva;
    //std::endl;
    std::cout << std::setw(26) << "right visual acuity: ";
    std::cin >> rva;
    std::cout << std::setw(10) << "ssn: ";
    std::cin >> ssn;
    std::cout << std::setw(33) << "insurance? (1=yes, 0 = no): ";
    std::cin >> ins;
    iaf = calciaf(ssn);
    thicc = calcthicc(lva, rva, k1ref, k2money, iaf, ins);
    std::cout << std::setw(24) << "thickness of lens: "
              << thicc
              << " cm" << std::endl;
    std::cout << "Good luck with those glasses! And come back to see Dr. Nick!" << std::endl;
    
    return 0;
}
