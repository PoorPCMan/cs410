#include <iostream>
#include <string>


//helper function to check if answer is ok
char getInput() {
    char input;
    std::cin >> input;
    while((input != 'y') || (input != 'n')) {
        std::cout << "The entered answer is not y(yes) or n(no). Please enter (y/n)." << std::endl;
        std::cin >> input;
    }
    return input;
}

//yes branch
void branchA() {
    std::cout << "test1";
}
//no branch
void branchB(){
    std::cout << "test2";
}

int startPrompt() {
    std::string name;
	std::cout << "Hi! Welcome to the Bone/Muscular Issues Program!\n"
              << "What's your name?" << std::endl;
    std::cin >> name; 
    std::cout << "Hello " << name << std::endl;
    std::cout << "Is your pain..." << std::endl;
    char uinput;
    std::cout << "Muscle tendon related? (y/n): " << std::endl;
    uinput = getInput();
    if (uinput == 'y') {
        branchA();
    } else { // user input is n (NO)
        branchB();
    }
    return 0;
}

int rePrompt() {
    std::cout << "You've reached the end of the program!"
              << "Would you like to start over? (y/n): " << std::endl;
    char uinput = getInput();
    if (uinput == 'y') {
        startPrompt();
    } else {
        std::cout<< "Good bye! Come again!" << std::endl;
    }
    return 0;
}

int main(int argc, char **argv)
{
    startPrompt();
    rePrompt();
	return 0;
}
