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
//arrays passed to functions are decayed to pointers
int resizeArr(creature oldarr[], int osize);
//tried to implement a resize function with a template but the linker told me to fuck off
//decided to just make a 'creature' specific method
// TODO - lookup why i got cucked by it - id say just use vectors over arrays in most cases but thats just me
creature generateCreature();
std::string generateSaying();
bool ArrayCheckCreature(creature new_creature, creature visited[], int asize);
int ArrayCheckStacks(creature clist[], int csize);
bool checkStackable(creature a, creature b);

#endif
