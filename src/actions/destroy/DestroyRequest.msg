// Author: Francesco Racciatti <racciatti.francesco@gmail.com>

// DestroyRequest supports the action 'destroy'.
// A local-filter, to schedule its own destruction, sends a DestroyRequest message to the global-filter.


cplusplus {{
#include "EntryWrapper.h"
}}


class EntryWrapper;


message DestroyRequest {

    EntryWrapper entryWrapper;
    
}
