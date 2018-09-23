#include <iostream>
#include <string>


//helper function to check if answer is ok also grab the input
std::string getInput() {
    std::string input;
    std::cin >> input;
    while(!(input == "y" || input == "n")) {
        std::cout << input <<std::endl;
        std::cout << "The entered answer is not y(yes) or n(no). Please enter (y/n)." << std::endl;
        std::cin >> input;
    }
    return input;
}

int startPrompt() {
    std::string name;
	std::cout << "Hi! Welcome to the Bone/Muscular Issues Program!\n"
              << "What's your name?" << std::endl;
    std::cin >> name; 
    std::cout << "Hello " << name << std::endl;
    std::cout << "Is your pain..." << std::endl;
    std::string input;
    std::cout << "Muscle tendon related? (y/n): " << std::endl;
    input = getInput();
    if (uinput == "y") {
    	input = getInput();
    	if (input == "y") { //yes to achilles
    	    std::cout<< "Pad heel of sneaker, ice and heat for inflammation" << std::endl;
    	}
    	//defaulting to a separate if statement instead of an else is neater
    	if(input == "n") { //no to achilles
    	    std::cout<< "Shin splints?" << std::endl;
    	    input = getInput();
    	    if(input == "y") { //yes to shin splints
    	        std::cout<< "Balance muscles, stretching, pace, sneakers."<<std::endl;
    	    } else { // no to shin splints
    	        std::cout<<"Cramping Calves?"<<std::endl;
    	        input = getInput();
    	        if(input == "y") {//no to calves
    	            std::cout<<"Hydration, nutrition, overuse, sneakers too soft, running style"<<std::endl;
    	        } else {
    	            std::cout<<"Muscle fatigue?"<<std::endl;
    	            input = getInput();
    	            if(input == "y") { //yes to muscle fatigue
    	                std::cout<<"Time of day, general overwork, diet, stress, illness"<<std::endl;
    	            } else { // no to muscle fatigue
    	                std::cout<<"Full leg spasm?"<<std::endl;
    	                input = getInput();
    	                if(input == "n") { // no to leg spasm
    	                    std::cout<<"Foot (arch) cramps?"<<std::endl;
    	                    input = getInput();
    	                    if(input == "n") { // no to foot arch cramps
    	                        std::cout<<"Groin strain?"<<std::endl;
    	                        input = getInput();
    	                        if(input == "y") { //yes to groin strain
    	                            std::cout<<"Rest, then stretching"<<std::endl;
    	                        } else { // no to groin strain
    	                            std::cout<<"Stretching and floor exercises. Might have luck with a chiropractor if it's a sharp pain on touching toes."<<std::endl;
    	                        }
    	                    } else { // yes to foot arch cramps
    	                        std::cout<<"Sneakers, running style, hydration, non-running foot propping"<<std::endl;
    	                    }
    	                } else { // yes to leg spasm
    	                    std::cout<<"Muscles splinting stress fracture, groin pull, hamstring"<<std::endl;
    	                }
    	            }
    	        }
    	    }
    	}
    } else { // user input is n (NO)
        branchB();
    }
    return 0;
}

int rePrompt() {
    std::cout << "You've reached the end of the program!"
              << "Would you like to start over? (y/n): " << std::endl;
    std::string uinput = getInput();
    if (uinput == "y") {
        startPrompt();
    } else {
        std::cout<< "Good bye! Come again!" << std::endl;
    }
    return 0;
}

int main(int argc, char **argv)
{
    startPrompt();
	return 0;
}
