#include "Action.h"

Action::Action(const ActionName name_action) {
	
	name = name_action;
	
	/* Actions as 'Destroy', 'Move', 'Fakeread' and 'Disable' do not deal with packets, thus do not need the following parameters */
	packetName = "";
	layer = NONE;

}
