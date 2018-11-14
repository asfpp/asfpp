/**
 * @file PhysicalAttackWrapper.cc
 * @author Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "PhysicalAttackWrapper.h"


PhysicalAttackWrapper::PhysicalAttackWrapper () {

    physicalAttack = nullptr;

}


PhysicalAttackWrapper::PhysicalAttackWrapper (PhysicalAttack* physicalAttack) {
    
    this->physicalAttack = physicalAttack;
    
}


PhysicalAttackWrapper::~PhysicalAttackWrapper () {

}


void PhysicalAttackWrapper::setPhysicalAttack (PhysicalAttack* physicalAttack) {
    
    this->physicalAttack = physicalAttack;
    
}


PhysicalAttack* PhysicalAttackWrapper::getPhysicalAttack () const {
    
    return physicalAttack;
    
}
