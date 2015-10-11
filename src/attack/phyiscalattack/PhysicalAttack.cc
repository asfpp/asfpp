/**
 * @file PhysicalAttack.cc
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */


#include "PhysicalAttack.h"
#include "Destroy.h"
#include "Move.h"



PhysicalAttack::PhysicalAttack () : Attack () {
    
}


PhysicalAttack::~PhysicalAttack () {
    
    // TODO destroy all actions composing the attack
    
}


// TODO modify in 'execute()'
void PhysicalAttack::execute(bool& destroyed) {

    // TODO check if for loop is necessary
    // execute all actions composing the attack
    for (size_t i = 0; i < actions.size(); i++) {

        switch (actions[i]->getName()) {

            case MOVE: {
                Move* move = (Move*) actions[i];
                move->execute();
                break;
            }


        }

    }

}


// TODO remove
void PhysicalAttack::execute () {
    
    for (size_t i = 0; i < actions.size(); i++) {
        
        switch (actions[i]->getName()) {

            case DESTROY: {
                Destroy* destroy = (Destroy*)actions[i];
                destroy->execute();
                break;
            }
            
        
        }
    
    }
    
}
