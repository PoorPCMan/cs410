#include <iostream>
#include <cmath>

//PROTOTYPES
int distnext(int iniDist);
int route1();
int route2();
int route3();
int DistOut();
//

//prints out the distance behind the given distance value, if it's over a mile, than not only will it print the amount of feet, it will print the amount of miles
int DistOut(int dist) {
    if (dist > 5280) {
        if ((dist % 5280) != 0) {
            double mdist = ((static_cast<double>(dist))/5280) //results in how many miles from the feet given
            std::cout << dist
                      << " "
                      << "(~"
                      << mdist
                      <<" miles)"
                      <<std::endl;
        }
    } else {
        std::cout << dist << std::endl;
    }
    return 0;
}

int distnext(int iniDist) {
    int nextDist = ((((iniDist * 124985) + 1367892) % 1654872235) % 300) + 21;
    return nextDist;
}


int main(int argc, char **argv)
{
    //20 ft at the beginning. we're gonna fuck this up later
    for(int iniDist = 20; i < 270; i++) { //theres 250 walks, so have it look that many times
        
    }
	printf("hello world\n");
	return 0;
}
