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
int DistOut(float dist, std::string state) {
	if ((static_cast<int>(dist) % 5280) != 0) {
		std::cout << "   "
		          << state
		          << "                 "
		          << dist << std::endl;
    } else {
    	float mdist = (dist/static_cast<float>(5280)); //results in how many miles from the feet given
    	std::cout << "   "
    	          << state
    	          << "                 "
    	          << dist
    	          << " (~"
    	          << mdist
    	          <<" miles)"
    	          << std::endl;
    }
    return 0;
}

//method to find the distance from one point to another 
float findDistance(int x1, int y1, int x2, int y2) {
    int x = (x2-x1)^2;
    int y = (y2-y1)^2;
    int xy = x + y;
    float dist = std::sqrt(xy); //distance formula
    return dist;
}

//end of the statistics
int finishstats(int office, int home, int lost) {
    float officeStat = office/(static_cast<float>(numWalk));
    float homeStat = home/(static_cast<float>(numWalk));
    float lostStat = lost/(static_cast<float>(numWalk));
    std::cout<< "Run Simulation finished! Here is the simulation's statistics: " << "\n"
             << "Frequency of getting to Nick's: " << officeStat << "\n"
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
    if((orientation == "home")) {
        return "right";
    }
    
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
    std::string orientation = "home";
    //int disttraveled = iniDist;
    int homepoints = 0; //number of decision points that are near home
    int lostcheck = 0;
    int dist = iniDist;
        for(int j = 1; j < dMax; j++) { //loop for one walk to make decisions inside of
        
            nDist = distnext(dist);
            dist = nDist;
            
            //turning left or right
            if(j % 7 == 0) {
                //moves left
                 //disttraveled += nDist;
                 orientation = changeDirection(orientation, "left");
            } else {
            	//moves right
            	//disttraveled += nDist;
            	orientation = changeDirection(orientation, "right");

            }
            if(j == dMax) { //checks if it's at the end of the for loop and increments the counter
                lostcheck = 1;
                //DistOut(disttraveled, "lost");
                break;
            }
        }
        //after change in direction, change coordinates based on orientation
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
        
        float disttraveled = findDistance(homex, homey, cordx, cordy);
        if(lostcheck == 1) {
            lost++;
            DistOut(disttraveled, "lost");
            lost = 0;
        }
        if((findDistance(officex, officey, cordx, cordy) <= 500)) { //checks if within 500 feet of Nick's office and increment counter
            office++;
            DistOut(disttraveled, "office");
            //break;
        }
        
        if((findDistance(homex, homey, cordx, cordy)) <= 50) { //checks if distance from current location to home is within 50
            homepoints++;
            if(((findDistance(homex, homey, cordx, cordy)) <= 50) && (homepoints >= 5)) {
                home++;
                DistOut(disttraveled, "home");
                //break;
            }
        }
        
        iniDist++;//increment for the next run ex: 21 for 1st walk, 22 for 2nd walk, 23, for 3rd walk...
    }
    std::cout << office << " " << home << " " << lost << " " << std::endl;
    finishstats(office, home, lost);
	return 0;
}
