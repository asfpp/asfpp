/**
 * @file Entry.cc
 * @authors Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "Entry.h"


Entry::Entry (Attack* attack, const SimTime occurrenceTime)
{    
    this->attack = attack;
    this->occurrenceTime = occurrenceTime;
}


Entry::~Entry ()
{
}


SimTime Entry::getOccurrenceTime () const
{
    return occurrenceTime;
}


// TODO remove
SimTime Entry::getTime () const
{    
    return occurrenceTime;
}


Attack* Entry::getAttack () const
{    
    return attack;
}
