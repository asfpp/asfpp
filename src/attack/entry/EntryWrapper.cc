/**
 * @file EntryWrapper.cc
 * @author Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "EntryWrapper.h"


EntryWrapper::EntryWrapper () {

    entry = nullptr;

}


EntryWrapper::EntryWrapper (Entry* entry) {
    
    this->entry = entry;
    
}


EntryWrapper::~EntryWrapper () {

}


void EntryWrapper::setEntry (Entry* entry) {
    
    this->entry = entry;
    
}


Entry* EntryWrapper::getEntry () const {
    
    return entry;
    
}
