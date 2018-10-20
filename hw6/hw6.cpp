#include <iostream>
#include <cmath>
#include <string>
#include "hw6_functions.h"

int main(int argc, char **argv)
{
	//data to hold his leave conditions
    int stacked_cards = 0;
    int different_creatures = 0;
    int visited = 0;
    creature visitedcreatures[14];
    creature diffcreatures[14];
    
    //data per visit
    creature c;
    std::string saying = "Blah blah blah";
    //uses 37 as the seed to generate numbers due to hw requirement
    std::srand(37);
    
    //program start greeting
    std::cout<<"Hans is starting his trip to Atlantis!"<<std::endl;
    //main loop
    while(stacked_cards != 6 || different_creatures != 14) {
        //spacer
        std::cout<<"--------------------------------------"<<std::endl;
        //generate a random creature BEFORE generating a random saying
        c = generateCreature();
        std::cout<<"Hans just encountered a " << c.name << "!" <<std::endl;
        saying = generateSaying();
        std::cout<< c.name << ": " << saying <<std::endl;
        std::cout<<"Hans gets a "<<c.dim1<<"x"<<c.dim2<<" business card."<<std::endl;
        
        visited++;
        
        std::cout<<"Hit check1"<<std::endl;
        
        //check if array is full, if it is give it viagra
        if(visited == (sizeof(visitedcreatures)/sizeof(visitedcreatures[0]))) {
            resizeArr(visitedcreatures, visited); //changes array size(+1)
        }
        std::cout<<"Hit check1.5"<<std::endl;
        
        std::cout<<"visited = " << visited <<std::endl;
        std::cout<<"stacked_cards = " << stacked_cards <<std::endl;
        std::cout<<"different_creatures = " << different_creatures <<std::endl;
        
        visitedcreatures[visited-1] = c;
        
        std::cout<<"Hit check2"<<std::endl;
        
        if(ArrayCheckCreature(c, diffcreatures, 14) == false) {
            if(different_creatures != (sizeof(diffcreatures)/sizeof(diffcreatures[0]))) {
                different_creatures++;
                diffcreatures[different_creatures-1] = c;                
            } 
        }
        
        std::cout<<"Hit check3"<<std::endl;

        //stacked_cards == ArrayCheckStacks(&visitedcreatures, visited);
        //TODO For stacked cards have nested for loop to check for stackable cards
        // and then use the maximum value of stacked_cards in those nested for loops as stacked
    }
    //stats
    std::cout<<"visited creatures = " << visited <<std::endl;
    std::cout<<"stacked_cards = " << stacked_cards <<std::endl;
    std::cout<<"different_creatures = " << different_creatures <<std::endl;
    
    //End Print
    if(different_creatures == 14) {
        std::cout<<"Hans has escaped Atlantis by collecting 14 different cards!"<<std::endl;
    }
    
    if(stacked_cards == 6) {
        std::cout<<"Hans has escaped Atlantis by stacking 6 cards!"<<std::endl;
    }
    
    return 0;
}
