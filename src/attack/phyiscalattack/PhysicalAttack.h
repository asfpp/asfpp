/**
 * @file PhysicalAttack.h
 * @authors Francesco Racciatti <racciatti.francesco@gmai.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * @brief The class PhysicalAttack models a physical attack.
 */


#ifndef PHYSICALATTACK_H
#define PHYSICALATTACK_H


#include "Attack.h"

using namespace std;


class PhysicalAttack : public Attack {

    public:
        /**
         * @brief Constructor.
         */
        PhysicalAttack();
        
        /**
         * @brief Destructor.
         */
        virtual ~PhysicalAttack();

        /**
         * @brief Executes the physical attack.
         */
        void execute(bool& destroyed);
        void execute();

};

#endif
