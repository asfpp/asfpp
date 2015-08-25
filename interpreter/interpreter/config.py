"""

Global variables shared between interpreter's modules.

Authors:
 + Alessandro Pischedda <alessandro.pischedda@gmail.com>
 + Marco Tiloca         <marco.tiloca84@gmail.com>
 + Francesco Racciatti  <racciatti.francesco@gmail.com>

Maintainer:
 + Francesco Racciatti  <racciatti.francesco@gmail.com>
 
"""


# List of reserved names
reserved_name = ["RANDOM"]

# List of the layer names
layer_names = ["APP", "NET", "MAC"]


# Dictionary of the global IDs and their types (i.e. VAR, PACKET, LIST)
global_symbol_table = {}

# Dictionary of the local IDs and their types (i.e. VAR, PACKET, LIST)
symbol_table = {}

# Dictionary of variables used within an attack; entry format is <name, XML string>
variables = {}

# Dictionary of the node lists; entry format is <list_name, list_of_nodes>
lists = {}


# List of action composing an attack
actions = []


# List of physical attacks
physical_attacks = []

# List of conditional attacks
conditional_attacks = []

# List of unconditional attacks
unconditional_attacks = []


# Dictionary of 'destroy' actions. Entry format is <time, list_of_nodes>
destroy_actions = {}

# Dictionary of 'move' actions; entry format is <time, <position, list_nodes> >
move_actions = {} 

# Dictionary of 'fakeread' actions having 4 args
fakeread_argc4_actions = {}

# Dictionary of 'fakeread' actions having 5 args
fakeread_argc5_actions = {}

# Dictionary of 'fakeread' actions having 6 args
fakeread_argc6_actions = {}

# Dictionary of 'fakeread' actions having 7 args
fakeread_argc7_actions = {}


# Packet filter boolean expression
packetFilter = ""

# Boolean operator used in the packet filter expression ('AND' by default)
packetFilterOperator = "AND"



