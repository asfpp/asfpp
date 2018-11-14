// Author: Francesco Racciatti <racciatti.francesco@gmail.com>

// UnconditionalFireMessage supports the firing mechanism of unconditional attacks in the global-filter.
// To schedule an unconditional attack, the global-filter schedules an UnconditionalFireMessage (self-message).


message UnconditionalFireMessage {
	
    int index;

}
