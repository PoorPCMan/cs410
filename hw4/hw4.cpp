#include <iostream>
#include <cmath>

//declarations
int greeting(); //greeting
int displaymenu();
int asklegs();
int factorial(int n);
int totalSteps(int legs);
int askAnxiety();
int askDay();
int getPills(int anxiety, int day);
int printPills(int numPills);
int askSleep();
int min4Nap(int hours, int steps, int numPills);
int printNaptime(int min); 
int getCalories(int steps);
int printCalories(int calories);

int main(int argc, char **argv)
{
    //info
    int legs = 0;
    int anxiety = 0;
    int dotw = 0;
    greeting();
    
    int quit = 0;
    while(quit == 0) { //loop until the quit lock turns true
    	switch(displaymenu()) {
    	    case 1: //taking a walk
    	        std::cout<<"Case1"<<std::endl;
    	        break;
    	    case 2: //your medications
    	        std::cout<<"Case2"<<std::endl;
    	        break;
    	    case 3: //naptime
    	        std::cout<<"Case3"<<std::endl;
    	        break;
    	    case 4: //caloric intake
    	        std::cout<<"Case4"<<std::endl;
    	        break;
    	    case 5: //quit
    	        std::cout<<"Thank you for using the program. Have a nice day!";
    	        quit = 1;
    	        break;
            default:
                std::cout<<"ERROR! Given option not found! Please give an option from 1-5!" <<std::endl;
                break;
    	}   
    }
}
//Detail 1
int greeting() {
    std::cout<< "Hey, welcome to the program!" << std::endl;
    return 0;
}
//Detail 2
int displaymenu() {
    int state;
    
    std::cout<<"Health-o-Matic Options"<< std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"1. Taking a walk!"<<std::endl;
    std::cout<<"2. Your Medications!"<<std::endl;
    std::cout<<"3. Naptime!!"<<std::endl;
    std::cout<<"4. Caloric Intake!?"<<std::endl;
    std::cout<<"5. Quit???"<<std::endl;
    
    std::cout<<"Please choose an option: ";
    std::cin>>state;
    
    return state;
}

//Detail 3

int asklegs() {
    int legs;
    std::cout<<"Please give the amount of legs you walk with: "<<std::endl;
    std::cin>>legs;
    
    while(legs == 0 && legs < 0) { //input checking/clenasing
        std::cout<<"Please input a positive integer."<<std::endl;
        std::cout<<"Please give the amount of legs you walk with: ";
        std::cin>>legs;
    }
    return static_cast<int>(legs); //kills off floats
}


//helper function that recursively finds the factorial of a number
int factorial(int n) {
    if (n >= 1) {
        return n*factorial(n-1);
    } else {
        return 1;
    }
}
//Detail 4
//function that gives the total steps
int totalSteps(int legs) {
    return factorial(legs);
}

//Detail 5
int askAnxiety() {
    int anxiety;
    std::cout<<"What's your anxiety level? (1-10): "<<std::endl;
    std::cin>>anxiety;
    while(anxiety < 1 || anxiety > 10) {
        std::cout<<"Unexpected reply. Please pick and choose an anxiety level from 1 to 10." <<std::endl;
        std::cout<<"What's your anxiety level? (1-10): "<<std::endl;
        std::cin>>anxiety;
    }
    return anxiety;
}

//Detail 6
int askDay() {
    int day;
    std::cout<<"Please give the day (1-7):"<<std::endl;
    std::cin>>day;
    while(day < 1 || day > 7) {
        std::cout<<"Unexpected reply. Please pick and choose a day from 1(Monday) to 7(Sunday)." <<std::endl;
        std::cout<<"Please give the day (1-7): "<<std::endl;
        std::cin>>day;
    }
    return day;
}

//Detail 7
int getPills(int anxiety, int day) {
    int pills = anxiety - day;
    if(pills >= 0) { //make sure the difference is non-negative
        return pills;
    }
    return 0;
}

//Detail 8
int printPills(int numPills) {
    std::cout<<"The amount of pills you need are "
             <<numPills
             <<" pills." <<std::endl;
    return 0;
}

//Detail 9
int askSleep() {
    int hours;
    std::cout<<"How many hours did you sleep last night?: ";
    std::cin>>hours;
    while(hours < 0) {
        std::cout<<"Can't input a number less than 0! You can't sleep less than nothing. Please put a number that is atleast zero.\n"
                 <<"How many hours did you sleep last night?: ";
        std::cin>>hours;
    }
    return hours;
}

//Detail 10
int min4Nap(int hours, int steps, int numPills) {
    if (numPills == 0) {
        numPills = 1;
    }
    int minutes = (hours + (steps/numPills));
    return minutes;
}

//Detail 11
int printNaptime(int min) {
    std::cout<<"You should take a nap for "
             <<min
             <<" minutes." <<std::endl;
    return 0;
}

//Detail 12
int getCalories(int steps){
    int weight;
    std::cout<<"How much do you weigh? ";
    std::cin>>weight;
    
    while(weight > 800 || weight < 0) {
        std::cout<<"Not accepted weight value. Please put in a proper value! (integer)"<<std::endl;
        std::cout<<"How much do you weigh? ";
        std::cin>>weight;
    }
    
    
    int height;
    std::cout<<"How tall are you?: ";
    std::cin>>height;
    
    //dunno what to measure height in
    //while() {
    //    
    //}
    
    int temp;
    std::cout<<"What temperature is the room at?: ";
    std::cin>>temp;
    
    //temperature can be up and down the range of an integer so don't really need to check
    //while(temperature < 0 || ) {
    //    
    //}
    
    int calories = (6 * weight) + (2 * height) + (1/temp) + (steps);
    return calories;
}

//Detail 13
int printCalories(int calories) {
    std::cout<<"Your calorie limit is "
             <<calories
             <<" calories." <<std::endl;
    return 0;
}
//email TA 
//benjamin.kwapong001@umb.edu

//richard.anarfi001@umb.edu
