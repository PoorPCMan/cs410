#include <iostream>
#include "Calculator.h"


char displaymenu() {
    char state;
    
    std::cout<<"Options"<< std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"1. Factorial of x"<<std::endl;
    std::cout<<"2. Exponential of x"<<std::endl;
    std::cout<<"3. Cosine of x"<<std::endl;
    std::cout<<"4. Roots of x"<<std::endl;
    std::cout<<"5. Hyperbolic sine of x"<<std::endl;    
    std::cout<<"6. Quit???"<<std::endl;
    
    std::cout<<"Please choose an option: ";
    std::cin>>state;
    
    return state;
}

int askX(int choice) {
    int x;
    std::cout<<"Please choose a value for x: ";
    std::cin >> x;
    
    //check boundaries based on option
    switch(choice) {
        case 1:
            while(x>=10 || x<0) {
                std::cout<<"X value not accepted!"<<std::endl;
                std::cout<<"Please put an X for a value between 0 and 10."<<std::endl;
                std::cout<<"Please choose a value for x: ";
                std::cin >> x;
            }
            break;
        //case 2 allows all X's
        case 3:
            while (x) {
                
            }
            break;
        case 4:
            while (x) {
                
            }
            break;
        //case 5 allows all X's
    }
    return x;
}

//recursive function to find the factorial -- option 1
int factorial(int n) {
    if (n >= 1) {
        return n*factorial(n-1);
    } else {
        return 1;
    }
}

//helper power method --since we cant use cmath make our own
//x = base
//y = exponent
int helppower(int x, int y) {
    int powresult = x;
    for(int i = y - 1; i > 0; i--) {
        powresult *= x;
    }
    return powresult;
}

int expTerms() {
    int terms;
    std::cout<<"Amount of terms for Exponential calculation:";
    std::cin>>terms;
    while(terms <= 0) {
        std::cout<<"Must be a positive integer!"<<std::endl;
        std::cout<<"Amount of terms for Exponential calculation:";
        std::cin>>terms;
    }
    return terms;
}

//option 2 --works now
float exponential(int x, int terms) {
    float sum = 0;

    for(int i = 0; i < terms; i++) {
        //int step1 = x^i; -> CANT USE - in C++ "^" is a bitwise OR usually would use cmath's pow method, but we can just loop it
        int numerator = helppower(x, i);
        std::cout<<numerator<<std::endl;
        int denominator = factorial(i);
        std::cout<<denominator<<std::endl;
        sum += static_cast<float>(numerator/denominator);
    }
    return sum;
}

//option 3
int cosine(int x) {
    int difference = 0;
    
    
    return difference;
}


//option 4

int nroot(int x, int n) {
    if(n == 0) {
        
    } else {
        
    }
}


//option 5
