/**
 * @file PhysicalAttack.cc
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */


#include "PhysicalAttack.h"

#include "Destroy.h"
#include "Disable.h"
#include "Move.h"


PhysicalAttack::PhysicalAttack () : Attack () {
    
}


PhysicalAttack::~PhysicalAttack () {
    
}

/*
// TODO modify in 'execute()'
void PhysicalAttack::execute(bool& destroyed) {

    // TODO check if the 'for loop' is necessary
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
*/

void PhysicalAttack::execute () {
    
    for (size_t i = 0; i < actions.size(); i++) {
        
        switch (actions[i]->getName()) {

            case MOVE: {
                Move* move = (Move*) actions[i];
                move->execute();
                break;
            }
            
            case DESTROY: {
                Destroy* destroy = (Destroy*) actions[i];
                destroy->execute();
                break;
            }
            
            case DISABLE: {
                Disable* disable = (Disable*) actions[i];
                disable->execute();
                break;
            }
            
            default: {
                opp_error("[void PhysicalAttack::execute()] Error, unexpected type of node action to handle");
            }
        
        }
    
    }
    
}
