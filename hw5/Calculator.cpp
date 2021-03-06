#include <iostream>
#include <iomanip>
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

int askX() {
    int x;
    std::cout<<"Please choose a value for x: ";
    std::cin >> x;
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
    float sum = 1.0;

    for(int i = 1; i <= terms; i++) {
        //int step1 = x^i; -> CANT USE - in C++ "^" is a bitwise OR usually would use cmath's pow method, but we can just loop it
        int numerator = helppower(x, i);
        //std::cout<<numerator<<std::endl;
        int denominator = factorial(i);
        //std::cout<<denominator<<std::endl;
        sum += static_cast<float>(numerator)/static_cast<float>(denominator);
    }
    return sum;
}

int cosAcc(){
    int terms;
    std::cout<<"Accuracy of the computation (1-5): ";
    std::cin>>terms;
    return terms;
}

//option 3
float cosine(int x, int accuracy) {
    float difference = 0;
    for(int i = 1; i <= accuracy; i++) { //TODO: Refactor this for loop boundary
        if (i == 1) { 
            difference += 1;
        } else {
            int exponent = 2 * i;
            int numerator = helppower(x, exponent);
            int denominator = factorial(2*i);
            if(i % 2 == 0) { 
                difference -= static_cast<float>(numerator)/static_cast<float>(denominator);
            } else {
                difference += static_cast<float>(numerator)/static_cast<float>(denominator);
            }
        }
    }
    return difference;
}

int findRoot() {
    int root;
    std::cout<<"Find the root(2-5): ";
    std::cin>>root;
    while(root < 2 || root > 5) {
        std::cout<<"Must be between 2 and 5!"<<std::endl;
        std::cout<<"Find the root(2-5): ";
        std::cin>>root;
    }
    return root;
}

//option 4

float getRoot(int x, int n) {
	int a = x; //the base that we're finding the root of
	float xn = x; //use given x as initial value -- "Use A as first initial value"
	int k = n; //the root we're trying to find
	int counter = 0; //curently at x0
	while(counter < k) {
		float p = (static_cast<float>(k)-1)*xn;
		float q = static_cast<float>(a)/(helppower(xn,(k-1)));
		float r = p+q/static_cast<float>(k);
		xn = r;
		counter++; 
	}
	return xn;
}


//option 5 - handled by main switch case 5
