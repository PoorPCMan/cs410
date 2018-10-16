#include <iostream>
#include <iomanip>
#include "Calculator.h"
//#include <cmath> --not allowed to use

int main(int argc, char **argv) {
    
    //Data
    int running = 1;
    int x;
    int terms, acc, root;
    int c1;
    float c2, c3, c4, c5;
    float e1, e2;
    //main menu
    while(running) {
        std::cout<<" "<<std::endl;
        std::cout<<"------------------------"<<std::endl;
        char userchoice = displaymenu();
    	switch(userchoice) {
    	    case '1': // Factorial of x
                x = askX();
                if(x>10 || x<0) {
                    std::cout<<"X value not accepted!"<<std::endl;
                    std::cout<<"Please put an X for a value between 0 and 10."<<std::endl;
                    break;
                } else {
                    c1 = factorial(x);
                    std::cout<<"Factorial of "
                             <<x
                             <<" is "
                             <<c1
                             <<std::endl;
                }
                break;
    	    case '2': // Exponential of x
                x = askX();
                terms = expTerms();
                c2 = exponential(x, terms);
                std::cout<<"Exponential of "
                         <<x
                         <<" is "
                         <<c2 <<std::endl;
                break;
    	    case '3': // Cosine of x
                x = askX();
                acc = cosAcc();
                if(acc > 5 || acc < 1) {
                    std::cout<<"X value not accepted!"<<std::endl;
                    std::cout<<"Must be a number from 1 and 5!"<<std::endl;
                } else {
                    c3 = cosine(x, acc);
                    std::cout<<"Cosine of "
                             <<x
                             <<" is "
                             << std::setprecision(8)
                             <<c3
                             <<std::endl;
                }
                break;
    	    case '4': // Roots of x
                x = askX();
                root = findRoot();
                c4 = getRoot(x, root);
                std::cout<<"the "
                         <<root
                         <<"th root of "
                         <<x
                         <<" is "
                         <<c4 <<std::endl;
                break;
    	    case '5': // Hyperbolic sine of x
                x = askX();
                terms = 8;
                
                e1 = exponential(x, terms);
                e2 = 1/e1;
                c5 = (e1 + e2)/2;
                std::cout<<"Hyperbolic sine of "
                         <<x
                         <<" is "
                         <<std::setprecision(8)
                         <<c5 <<std::endl;
                break;
    	    case '6': // Quit
                std::cout<<"Quitting the program! See you next time!"<<std::endl;
    	        running = 0;
                break;
    	    default:
    	        std::cout<<"That's not an option! Please enter an option from 1-6."<<std::endl;
    	        break;
    	}
        x = 0;
    }
    return 0;
}
