#include "Move.h"

Move::Move(VirtualMobilityManager* mob, const NodeLocation_type coordinates) : Action(MOVE) {

	mobility = mob;
	nodeLocation = coordinates;

}

/* Force the new position in space */
void Move::execute() const {

	mobility-> setLocationWrapper(nodeLocation);
	
}
