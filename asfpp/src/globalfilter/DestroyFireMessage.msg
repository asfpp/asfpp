// Author: Francesco Racciatti <racciatti.francesco@gmail.com>

// DestroyMessage supports the action 'destroy'.
// The global-filter, to schedule the destruction of a node (requested by a DestroyRequest message), uses a DestoryMessage.


cplusplus {{
#include "PhysicalAttackWrapper.h"
}}


class PhysicalAttackWrapper;


message DestroyFireMessage {
	
    PhysicalAttackWrapper physicalAttackWrapper;

}
