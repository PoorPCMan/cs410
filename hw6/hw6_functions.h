#ifndef HW6_FUNCTIONS_H
#define HW6_FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <array>

//structs

struct creature {
    std::string name;
    // card specs are dim1 x dim2
    int dim1;
    int dim2;
    
    creature(std::string n, int a, int b) {
        name = n;
        dim1 = a;
        dim2 = b;
    }
    
    creature() {
        name = "";
        dim1 = 0;
        dim2 = 0;
    }
};

//Declarations
int arraysize();
int add2Array();
creature generateCreature();
std::string generateSaying();
bool ArrayCheckCreature(creature new_creature);
int ArrayCheckStacks(creature clist[]);
bool checkStackable(creature a, creature b);

#endif
