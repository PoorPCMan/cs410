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
int ArrayCheckStacks(creature clist[], int csize) {
    int i = 0;
    int stacks = 0;
    //int maxstack = 0;
    //for (int i = 0; i < csize; i++) {
    //    for(int j = 0; i < csize; j++) {
    //        bool stackable = checkStackable(clist[i], clist[j]);
    //        if(stackable) {
    //            stacks++;
    //        }
    //    }
    //    if(stacks > maxstack) {
    //        maxstack = stacks;
    //    }
    //}
    while(i < csize) {
        bool stackable = checkStackable(clist[i], clist[i+1]); 
        if (stackable) {
            stacks++;
        }
    }
    return stacks;
}
//Helper function to check dimensions 
bool checkStackable(creature a, creature b) {
    int a1 = a.dim1;
    int a2 = a.dim2;
    int b1 = b.dim1;
    int b2 = b.dim2;

    if(a1 >= b1 || a2 >= b2 || b2 >= a2 || b1 >= a1) {
        return true;
    }
    return false;
}
