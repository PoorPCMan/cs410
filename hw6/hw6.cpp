#include <iostream>
#include <cmath>
#include <string>
#include 'hw6_functions.h'

int main(int argc, char **argv)
{
	//data to hold his leave conditions
    int stacked_cards = 0;
    int different_creatures = 0;
    
    //uses 37 as the seed to generate numbers due to hw requirement
    std::srand(37);
    
    //main loop
    std::cout<<"Hans is starting his trip to Atlantis!"<<std::endl;
    while(stacked_cards != 6 || different_creatures != 14) {
        //generate a random creature BEFORE generating a random saying
        creature c = generateCreature();
        std::cout<<"Han just encountered a " << c.name << "!" <<std::endl;
        generatureSaying();
        if() {
            
        }
    }
}
