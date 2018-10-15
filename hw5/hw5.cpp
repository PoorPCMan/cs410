#include <iostream>
#include "Calculator.h"
//#include <cmath> --not allowed to use

int main(int argc, char **argv) {
    
    //Data
    int running = 1;
    int x;
    int terms;
    int c1;
    float c2, c3, c4, c5;
    float e1, e2;
    //main menu
    while(running) {
        std::cout<<"------------------------"<<std::endl;
        char userchoice = displaymenu();
    	switch(userchoice) {
    	    case '1': // Factorial of x
                x = askX(1);
                c1 = factorial(x);
                std::cout<<"Factorial of "
                         <<x
                         <<" is "
                         <<c1 <<std::endl;
                break;
    	    case '2': // Exponential of x
                x = askX(2);
                terms = expTerms();
                c2 = exponential(x, terms);
                std::cout<<"Exponential of "
                         <<x
                         <<" is "
                         <<c2 <<std::endl;
                break;
    	    case '3': // Cosine of x
                x = askX(3);

                std::cout<<"Cosine of "
                         <<x
                         <<" is "
                         <<c3 <<std::endl;
                break;
    	    case '4': // Roots of x
                x = askX(4);

                std::cout<<"Roots of "
                         <<x
                         <<" is "
                         <<c4 <<std::endl;
                break;
    	    case '5': // Hyperbolic sine of x
                x = askX(5);
                terms = expTerms();
                
                e1 = exponential(x, terms);
                e2 = 1/e1;
                c5 = (e1 + e2)/2;
                std::cout<<"Hyperbolic sine of "
                         <<x
                         <<" is "
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
