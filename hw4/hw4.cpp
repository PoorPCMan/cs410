#include <iostream>
#include <cmath>

//declarations
int greeting(); //greeting
int getuinput(); //display menu and read character response from user and return to main -- DOES NOT input cleanse
int promptlegs();
int menuDisplay();
//

int main(int argc, char **argv)
{
    //info
    int legs = 0;
    int anxiety = 0;
    int dotw = 0;
    menu(0);
}

int greeting() {
    std::cout<< "Hey, welcome to the program!" << std::endl;
    return 0;
}

int displaymenu() {
    int state;
    
    std::cout<<"Health-o-Matic Options"<< std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"1. Taking a walk!"<<std::endl;
    std::cout<<"2. Your Medications!"<<std::endl;
    std::cout<<"3. Naptime!!"<<std::endl;
    std::cout<<"4. Caloric Intake!?"<<std::endl;
    std::cout<<"5.Quit???"<<std::endl;
    
    std::cout<<"Please choose an option: "<<
    std::cin>>state;
    
    return state;
}

int readlegs() {
    int legs;
    std::cout<<"Please give the amount of legs you walk with: "<<std::endl;
    std::cin>>legs;
    
    while(legs == 0 && legs < 0) { //input checking/clenasing
        std::cout<<"Please input a positive integer."<<std::endl;
        std::cout<<"Please give the amount of legs you walk with: ";
        std::cin>>legs;
    }
    return static_cast<int>legs; //kills off floats
}

int walk() {
    
    return 0;
}

int option3() {
    
    return 0;
}

int option4() {
    
    return 0;
}

int option5() {
    
    return 0;
}


//email TA 
//benjamin.kwapong001@umb.edu

//richard.anarfi001@umb.edu