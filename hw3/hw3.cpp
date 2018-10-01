#include <iostream>
#include <cmath>

//PROTOTYPES
int distnext(int iniDist);
int DistOut(int dist);
float findDistance(int x1, int y1, int x2, int y2);
int finishstats(int nick, int home, int lost);
//Declarations
const int numWalk = 250;
const int leftFreq = 7;
const int dMax = 400; //maximum number of decisions to make

//home coordinates: (0,0)
const int homex = 0;
const int homey = 0;

//office coordinates: (1000,1000)
const int officex = 1000;
const int officey = 1000;

//initialDist = 20 //goes up by 1, each walk
//nextDist = initialDist in an equation

//prints out the distance behind the given distance value, if it's over a mile, than not only will it print the amount of feet, it will print the amount of miles
int DistOut(int dist, std::string state) {
    if (dist > 5280) {
        if ((dist % 5280) != 0) {
            float mdist = ((static_cast<float>(dist))/5280); //results in how many miles from the feet given
            std::cout << "   "
                      << state
                      << "                       "
                      << dist
                      << " (~"
                      << mdist
                      <<" miles)"
                      << std::endl;
        }
    } else {
        std::cout << "   "
                  << state
                  << "                       "
                  << dist << std::endl;
    }
    return 0;
}

//method to find the distance from one point to another 
float findDistance(int x1, int y1, int x2, int y2) {
    float dist = std::sqrt(((x2-x1)^2)+((y2-y1)^2)); //distance formula
    return dist;
}

//end of the statistics
int finishstats(int nick, int home, int lost) {
    float nickStat = nick/numWalk;
    float homeStat = home/numWalk;
    float lostStat = lost/numWalk;
    std::cout<< "Run Simulation finished! Here is the simulation's statistics: " << "\n"
             << "Frequency of getting to Nick's: " << nickStat << "\n"
             << "Frequency of hitting home: " << homeStat << "\n"
             << "Frequency of just being completely lost: " << lostStat << std::endl;
    return 0;
}

//helper method to find the next distance
int distnext(int iniDist) {
    int nextDist = ((((iniDist * 124985) + 1367892) % 1654872235) % 300) + 21;
    return nextDist;
}

std::string changeDirection(std::string orientation, std::string dir) {
    if((orientation == "up") && (dir == "right")) { //up and turns right
       return "right"; 
    }
    
    if((orientation == "up") && (dir == "left")) { //up and turns left
        return "left";
    }
    
    if((orientation == "right") && (dir == "right")) { //right and turns right
        return "down";
    }
    
    if((orientation == "right") && (dir == "left")) { //right and turns left
        return "up";
    }
    
    if((orientation == "down") && (dir == "right")) { //down and turns right
        return "left";
    }
    
    if((orientation == "down") && (dir == "left")) { //down and turns left
        return "right";
    }
    
    if((orientation == "left") && (dir == "right")) {
        return "up";
    }
    
    if((orientation == "left") && (dir == "left")) {
        return "down";
    }
    
    return 0;
}

//simulation function
int main(int argc, char **argv)
{
    int office; //counter value for amounts of time to hit nick
    int home; //counter value for amounts of time to hit home
    int lost; //counter value for amounts of time to hit lost
    
    int iniDist = 20; //initial distance
    int nDist; //next distance
    
    std::cout<<"\nEnded walk at          total dist traveled (ft)" <<std::endl;
    for (int i = 0; i < numWalk; i++) { //for loop to run up to 250 times
    //home coordinates
    int cordx = 0;
    int cordy = 0;
    //orientation and distrance travelled
    std::string orientation = "up";
    int disttraveled = iniDist;
    int homepoints = 0; //number of decision points that are near home
        for(int j = 1; j < dMax; j++) { //loop for one walk to make decisions inside of
            nDist = distnext(iniDist);
            
            //turning left or right
            if(j % 7 == 0) {
                //moves left
                 disttraveled += nDist;
                 orientation = changeDirection(orientation, "left");
            } 
            if(j % 7 != 0) {
                //moves right
                disttraveled += nDist;
                orientation = changeDirection(orientation, "right");
            }
            
            //after change in direction, change coordinates
            if((orientation == "up")) {
                cordy += nDist;
            }
            if((orientation == "right")) {
                cordx += nDist;
            }
            if((orientation == "left")) {
                cordx -= nDist;
            }
            if((orientation == "down")) {
                cordy -= nDist;
            }
            
            if(j == dMax) { //checks if it's at the end of the for loop and increments the counter
                lost++;
                DistOut(disttraveled, "lost");
                break;
            }
            
            if((findDistance(cordx, cordy, officex, officey) <= 500)) { //checks if within 500 feet of Nick's office and increment counter
                office++;
                DistOut(disttraveled, "office");
                break;
            }
            
            if((findDistance(cordx, cordy, homex, homey) <= 50)) { //checks if distance from current location to home is within 50
                homepoints++;
                if((findDistance(cordx, cordy, homex, homey) <= 50) && (homepoints >= 5)) {
                    home++;
                    DistOut(disttraveled, "home");
                    break;
                }
            }
        }
        iniDist++;//increment for the next run ex: 21 for 1st walk, 22 for 2nd walk, 23, for 3rd walk...
    }
    finishstats(office, home, lost);
	return 0;
}
