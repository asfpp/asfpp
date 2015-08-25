/* <M.T.> This module is currently not used by the attack simuulator */

#include "Adversary.h"

Define_Module(Adversary);

Adversary::~Adversary()
{
  adversaryAttacks.clear();
}

void Adversary::initialize()
{
  
	readIniFileParameters();
	
	/* Initialize the evaluation of attacks */
	
	attacksEvaluation = getParentModule() -> par("attacksEvaluation");
	
	/* Parse attack to be evaluated */
	
	trace() << "Adversary::initialize()" << " attacks " << attacksEvaluation;
}

void Adversary::handleMessage(cMessage* msg)
{
	/* TBD */
}

void Adversary::finishSpecific()
{
	/* TBD */
}

void Adversary::readIniFileParameters()
{
	/* TBD */
}
