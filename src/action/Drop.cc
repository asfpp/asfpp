/**
 * @file	Drop.cc
 * @authors	Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "Drop.h"
#include <stdlib.h>
#include <time.h>


Drop::Drop (double threshold) : Action (DROP) {

    // check consistency of threshold
    if (threshold >= 0.0 && threshold <= 1.0) {
        this->threshold = threshold;    
    }
    else {
        srand (time(NULL));
        this->threshold = ((double)rand())/((double)RAND_MAX);
    }

}


Drop::~Drop () {

}


void Drop::execute(cMessage** packet) const{
    
    // extract a random number
    double draw = ((double)rand())/((double)RAND_MAX);
    
    // drop the packet if the random number is below to the threshold
    if (draw < threshold) {
        delete *packet;
        *packet = nullptr;
    }
	
}
