#include <iostream>
#include <cmath>
#include <string>
#include "hw6_functions.h"

int main(int argc, char **argv)
{
	//data to hold his leave conditions
    int stacked_cards = 0;
    int different_creatures = 0;
    creature visited[15];
    creature diffcreatures[14];
    
    //uses 37 as the seed to generate numbers due to hw requirement
    std::srand(37);
    
    //main loop
    std::cout<<"Hans is starting his trip to Atlantis!"<<std::endl;
    while(stacked_cards != 6 || different_creatures != 14) {
        //generate a random creature BEFORE generating a random saying
        creature c = generateCreature();
        std::cout<<"Han just encountered a " << c.name << "!" <<std::endl;
        std::string saying = generatureSaying();
        std::cout<< c.name << ": " << saying <<std:endl;
        std::cout<<"Han gets a "<<c.dim1<<"x"<<c.dim2<<" business card."<<std::endl;

        if(ArrayCheckCreature(visited) == false) {
            different_creatures++;
        }
        
        stacked_cards == ArrayCheckStacks(visited);
    }
}
