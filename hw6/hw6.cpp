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
    creature visitedcreatures[1000];
    creature diffcreatures[14];
    creature stacked[6];
    
    //data per visit
    creature c;
    std::string saying = "Blah blah blah";
    
    int seed;
    std::cout<<"Please give a random seed: ";
    std::cin>>seed;
    //hw requirement uses 37 as seed
    std::srand(seed);
    
    //program start greeting
    std::cout<<"Hans is starting his trip to Atlantis!"<<std::endl;
    //main loop
    while(!(stacked_cards == 6) && !(different_creatures == 14)) {
        //spacer
        std::cout<<"--------------------------------------"<<std::endl;
        //generate a random creature BEFORE generating a random saying
        c = generateCreature();
        std::cout<<"Hans just encountered a " << c.name << "!" <<std::endl;
        saying = generateSaying();
        std::cout<< c.name << ": " << saying <<std::endl;
        std::cout<<"Hans gets a "<<c.dim1<<"x"<<c.dim2<<" business card."<<std::endl;
        //used as a manual counter, to keep track
        visited++;
        
        //check if array is full, if it is give it viagra
        if(visited == (sizeof(visitedcreatures)/sizeof(visitedcreatures[0]))) {
            resizeArr(visitedcreatures, visited); //changes array size(*2)
        }
        //stuff the creature generated into an array
        visitedcreatures[visited-1] = c;
        
        //check if you hit 14 different creatures, if not look for more
        if(ArrayCheckCreature(c, diffcreatures, 14) == false) {
            if(different_creatures != (sizeof(diffcreatures)/sizeof(diffcreatures[0]))) {
                different_creatures++;
                diffcreatures[different_creatures-1] = c;                
            } 
        }
        //check if you got enough cards
        stacked_cards = ArrayCheckStacks(visitedcreatures, visited, stacked);
    }
    //spacer
    std::cout<<"--------------------------------------"<<std::endl;
    std::cout<<"!!!--------------DONE--------------!!!"<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl;
    //stats
    std::cout<<"Generated with random seed: " << seed <<std::endl;
    std::cout<<"visited creatures = " << visited <<std::endl;
    std::cout<<"stacked_cards = " << stacked_cards <<std::endl;
    std::cout<<"different_creatures = " << different_creatures <<std::endl;
    
    //End Print
    if(different_creatures == 14) {
        std::cout<<"Hans has escaped Atlantis by collecting 14 different cards!"<<std::endl;
    }
    
    if(stacked_cards == 6) {
        std::cout<<"Hans has escaped Atlantis by stacking 6 cards!"<<std::endl;
        std::cout<<"----"<<std::endl;
        for(int i = 0; i < 6; i++) {
            std::cout<<stacked[i].dim1<<"x"<<stacked[i].dim2<<std::endl;
        }
        std::cout<<"----"<<std::endl;
    }
    
    return 0;
}
