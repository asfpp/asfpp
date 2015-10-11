/**
 * @file Drop.cc
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */


#include "Drop.h"
#include <stdlib.h>
#include <time.h>


Drop::Drop(double threshold) : Action(DROP)
{
    // raise error if the threshold is not in the range [0.0, 1.0]
    if ((threshold < 0.0) || (threshold > 1.0)) {
        opp_error("[Drop::Drop(double)] Error, threshold must be in the range [0,1]");  
    }
    // set the threshold
    this->threshold = threshold;
}


Drop::~Drop()
{
}


void Drop::setThreshold(double threshold)
{
    // raise error if the threshold is not in the range [0.0, 1.0]
    if ((threshold < 0.0) || (threshold > 1.0)) {
        opp_error("[void Drop::setThreshold(double)] Error, threshold must be in the range [0,1]");  
    }
    // set the new threshold
    this->threshold = threshold;
}


double Drop::getThreshold() const
{    
    return threshold;
}


void Drop::execute(cMessage** packet) const
{
    // generate a random number between 0.0 and 1.0 inclusive
    double draw = ((double)rand())/((double)RAND_MAX);
    // drop the packet if draw is under the threshold (inclusive)
    if (draw <= threshold) {
        delete *packet;
        *packet = nullptr;
    }
}
