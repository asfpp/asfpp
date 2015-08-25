#include "Drop.h"

void Drop::execute(cMessage** packet) const {

	delete *packet;
	*packet = NULL;

}
