#include "hw6_functions.h"

creature creaturelist[] { //14 in this list
    {"Wanda Walrus", 2, 6},
    {"Stanley Sardine", 3, 1},
    {"Sylvia Seahorse", 4, 2},
    {"Janie Jellyfish", 1, 10},
    {"Doris Dolphin", 8, 4},
    {"Bob Blobfish", 1, 5},
    {"Sammy Shark", 8, 4},
    {"Walter Whale", 6, 2},
    {"Stevie Salmon", 2, 3},
    {"Sheila Shellfish", 1, 3},
    {"Daniel Octopus", 3, 7},
    {"Mark Herrings", 9, 5},
    {"Bernie Tuna", 3, 5},
    {"Oscar Tilapia", 5, 3}
};


std::string things_to_say[] = { // 14 in this list
    "Whazzup?",
    "Duuude, totally love the horse head and human body combo!",
    "Looking for a card (shark)?",
    "Are you someone famous?",
    "You look fishy to me; or are you horsing around?"
    "Don't trust the salmon!!!",
    "Here's some advice: the shark wants you to be his chum!",
    "Better take some paper towels if you visit the blobfish",
    "Hey man, got any sea-weed?",
    "Let me give you my card...my phone number is on the back",
    "I'd gladly pay you Tuesday for a lobster roll today.",
    "Don't be so crabby!",
    "Just keep swimming, swimmin, swimming, ...",
    "You just keep sinking, sinking, sinking,..."
};

//int arraysize() {TODO for later
//    int size = 0;
//    size = sizeof(arr)/sizeof(arr[0]);
//    return size;
//}

//resizes an array given the array pointer and its size
int resizeArr(creature oldarr[], int osize) {
    creature newarr[osize*2];
    
    int counter = 0;
    while(counter < osize) { //copy over whatevers in the old array
        newarr[counter] = oldarr[counter];
        counter++;
    }
    //reaching here, means you get a new array with stuff from oldarray +1 empty space
    delete[] oldarr;
    oldarr = newarr;
    return 0;
}

creature generateCreature() {
    int max_limit = (sizeof(creaturelist)/sizeof(creaturelist[0])); //TODO: learn and write a sizeof array operator without using anything C++11 and above
    int min_limit = 0;
    int random_number = rand()%(max_limit-min_limit + 1) + min_limit;
    return creaturelist[random_number];
}

std::string generateSaying() {
    int max_limit = (sizeof(things_to_say)/sizeof(things_to_say[0])); //TODO: learn and write a sizeof array operator without using anything C++11 and above
    int min_limit = 0;
    int random_number = rand()%(max_limit-min_limit + 1) + min_limit;
    return things_to_say[random_number];
}


bool ArrayCheckCreature(creature new_creature, creature visited[], int asize) {
    int i = 0;
    while (i < asize) {
        creature current_creature = visited[i];
        if(current_creature.name == new_creature.name) {
            return true;
        }
        i++;
    }
    return false;
}
//PROBABLY NOT RIGHT VVV
int ArrayCheckStacks(creature clist[], int csize, creature stack[]) {
    int maxstack = 0;
    int i = 0; //counter for 1st loop
    while (i < csize) { //grabs a single creature and compare to the rest
    	creature current_creature = clist[i];
    	int j = 0; // counter for 2nd loop
        stack[0] = current_creature;
        int k = 1; // counter to put in stack array
        int stacks = 1; //assume theres already one in that stack
        while (j < csize) { //loop to compare the rest with the single creature
        	if(j != i) { //avoids the initial entry(the thing we're checking against)
        		creature check_creature = clist[j];
        		if(check_creature.dim1 <= current_creature.dim1 && check_creature.dim2 <= current_creature.dim2) {
        			stacks++;
                    stack[k] = check_creature;
                    k++;
                    current_creature = check_creature; //use the newly found creature's card dimensions as a limit
        		}
        	}
        	j++;  
        }
        if(stacks == 6) { //leave once you get 6 in a stack
            maxstack = stacks;
            break;
        }
        
        if(stacks > maxstack) { // finds the maximum stack # up to 5
            maxstack = stacks;
        }
        i++;
    }
    return maxstack;
}
