#include <iostream>
#include <iomanip>
#include "hw6_functions.h"

creatures creaturelist { 
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

std::String things_to_say = {
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
}

int arraysize() {
    
}

creature generateCreature() {
    int max_limit = 14; //TODO: learn and write a sizeof array operator without using anything C++11 and above
    int min_limit = 0;
    int random_number = rand()%(max-min + 1) + min;
    return creaturelist[random_number];
}

String generateSaying() {
    int max_limit = 14 //TODO: learn and write a sizeof array operator without using anything C++11 and above
    int min_limit = 0;
    int random_number = rand()%(max-min + 1) + min;
    return things_to_say[random_number];
}
