/**
 * @file Entry.h
 * @authors Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 * @brief The class Entry couples an attack (physical, conditional or unconditional)
 *        with its occurrence time.
 */


#ifndef ENTRY_H
#define ENTRY_H


#include "Attack.h"


class Entry {
private:    
    // occurrence time of the related attack
    SimTime occurrenceTime;
    // pointer-to the attack
    Attack* attack;

public:
    /**
     * @brief Constructor.
     * @par attack Is the pointer-to the attack.
     * @par occurrenceTime Is the occurrence time of the related attack.
     */
    Entry(Attack* attack, const SimTime occurrenceTime);
    
    /**
     * @brief Destructor.
     */
    virtual ~Entry();

    /**
     * @brief Getter method for the occurrenceTime.
     * @return occurreceTime stored in the object.
     */
    SimTime getOccurrenceTime() const;
    // TODO remove and use 'getOccurrenceTime' instead     
    SimTime getTime() const;
    
    /**
     * @brief Getter method for the attack.
     * @return pointer-to the attack stored in the object.
     */
    Attack* getAttack() const;
};

#endif
