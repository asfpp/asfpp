/* 
 * This class represents an attack Entry object.
 * 
 * It contains the actual attack object and time information about its occurrence.
 *
 * Author : Alessandro Pischedda
 * E-mail : alessandro.pischedda@gmail.com
 */


#ifndef ENTRY_H
#define ENTRY_H

#include "Attack.h"

class Entry {

	SimTime time;	// Either occurrence time (physical attacks) or first occurrence time (logical attacks)
	Attack* attack;	// The attack to be performed

	public:
	  
	Entry(Attack* att, const SimTime t);
	virtual ~Entry() { delete attack; }
	
	SimTime getTime() const { return time; }
	Attack* getAttack() const { return attack; }

};

#endif
