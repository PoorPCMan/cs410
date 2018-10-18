#ifndef HW6FUNCTIONS_H
#define HW6FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <string>

//Declarations


//structs

struct creature {
    std::String name;
    // card specs are dim1 x dim2
    int dim1;
    int dim2;
    
    creature(std::String n, int a, int b) {
        name = n;
        dim1 = a;
        dim2 = b;
    }
}


#endif
