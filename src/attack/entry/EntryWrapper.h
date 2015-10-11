/**
 * @file EntryWrapper.h
 * @author Francesco Racciatti <racciatti.francesco@gmail.com> 
 * @brief The class EntryWrapper is a wrapper for pointer-to Entry objects.
 * @details It is used into .msg to carry the pointer-to Entry objects.
 */


#ifndef ENTRYWRAPPER_H
#define ENTRYWRAPPER_H


#include <omnetpp.h>
#include "Entry.h"


using namespace std;


class EntryWrapper : public cOwnedObject {

    private:
        Entry* entry;

    public:
        EntryWrapper();
        EntryWrapper(Entry* entry);
        ~EntryWrapper();

        void setEntry(Entry* entry);
        Entry* getEntry() const;

};

#endif
