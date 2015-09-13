#include "PhysicalAttack.h"

/* This function performs the physical attack. The parameter "destroyed" is set to true if the node is destroyed during the attack.
 * More specifically, the node is not actually destroyed, but it will drop every received/created packet, thus appearing to be destroyed.
 */

void PhysicalAttack::execute(bool& destroyed, vector< vector<Noise> >& theNoises, vector< vector< vector<double> > >& theNoisesParams, vector< vector<double> >& theNoisesValues, vector< vector<double> >& theSensorsValues) { // <F.R.>

	/* Execute all actions composing the attack */
	for(int i=0; i < actions.size(); i++ ) {

		switch( actions[i]->getName() ) {
		  
			// <F.R.>
			case FAKEREAD:{
				Fakeread* fakeread = (Fakeread *)actions[i];
				fakeread->execute(theNoises, theNoisesParams, theNoisesValues, theSensorsValues);
				break;
			}

			case MOVE:{
				Move* move = (Move *)actions[i];
				move->execute();
				break;
			}

			case DESTROY:{
				Destroy *destroy = (Destroy *)(actions[i]);
				destroy->execute(destroyed);
				break;
			}

		} // END SWITCH

	}// END FOR

}


void PhysicalAttack::execute() {
    
    Disable* disable = (Disable*)(actions[0]);
    disable->execute();
    
}
