/**
 * @file PhysicalAttackWrapper.h
 * @author Francesco Racciatti <racciatti.francesco@gmail.com> 
 * @brief The class PhysicalAttackWrapper is a wrapper for pointer-to PhysicalAttack objects.
 * @details It is used into .msg to carry the pointer-to PhysicalAttack objects.
 */


#ifndef PHYSICALATTACKWRAPPER_H
#define PHYSICALATTACKWRAPPER_H


#include <omnetpp.h>
#include "PhysicalAttack.h"


using namespace std;


class PhysicalAttackWrapper : public cOwnedObject{

    private:
        PhysicalAttack* physicalAttack;

    public:
        PhysicalAttackWrapper();
        PhysicalAttackWrapper(PhysicalAttack* physicalAttack);
        ~PhysicalAttackWrapper();

        void setPhysicalAttack(PhysicalAttack* physicalAttack);
        PhysicalAttack* getPhysicalAttack() const;

};

#endif
