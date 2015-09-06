"""

Grammar rules for (ASL) primitives.
 
Author:
 + Alessandro Pischedda	<alessandro.pischedda@gmail.com>
 + Marco Tiloca	        <marco.tiloca84@gmail.com>
 + Francesco Racciatti  <racciatti.francesco@gmail.com> 
 
Maintainer:
 + Francesco Racciatti  <racciatti.francesco@gmail.com>

"""

# Import the lexer for ASL
from lexer.asllexer import *

# Import utilities
from engine.utilities import print_error
from engine.utilities import packet_check
from engine.utilities import check_layer_name

# Import classes to model primitives
from primitives.destroy import Destroy
from primitives.disable import Disable
from primitives.move import Move
from primitives.fakeread import Fakeread
from primitives.drop import Drop
from primitives.send import Send
from primitives.clone import Clone
from primitives.create import Create
from primitives.change import Change
from primitives.retrieve import Retrieve
from primitives.put import Put

# Import global variables
from config import *


# destroy(int nodeID, double occurrence_time)
def p_statement_destroy(p):
    "physical_statement : DESTROY LPAREN INTEGER COMMA arg_number RPAREN"
    
    # 'destroy' invocations are grouped according to their occurrence time
    if not p[5] in destroy_actions.keys():
        destroy_actions[p[5]] = "" + str(p[3])
    
    else:
        destroy_actions[p[5]] = destroy_actions[p[5]] + ":" + str(p[3])


# disable(int nodeID, double occurrence_time)
def p_statement_disable(p):
    "physical_statement : DISABLE LPAREN INTEGER COMMA arg_number RPAREN"
    
    # 'disable' invocations are grouped according to their occurrence time
    if not p[5] in disable_actions.keys():
        disable_actions[p[5]] = "" + str(p[3])
    
    else:
        disable_actions[p[5]] = disable_actions[p[5]] + ":" + str(p[3])


# move(int nodeID, double occurrence_time, double coord_x, double coord_y, double coord_z)
def p_statement_move(p):
    "physical_statement : MOVE LPAREN INTEGER COMMA arg_number COMMA arg_number COMMA arg_number COMMA arg_number RPAREN"
    
    # 'move' invocations are grouped according to their occurrence time. They are also further sub-grouped according to specified coordinates
    moveArgs = "" + str(p[7]) + ":" + str(p[9]) + ":" + str(p[11])

    if not p[5] in move_actions.keys():
        move_actions[p[5]] = {}
    
    if not moveArgs in move_actions[p[5]].keys():
        move_actions[p[5]][moveArgs] = "" + str(p[3])
    
    else:
        move_actions[p[5]][moveArgs] = move_actions[p[5]][moveArgs] + ":" + str(p[3])


# 'fakeread' is an overloaded primitive
def p_statement_fakeread(p):
    """
    physical_statement : FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA CON COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA FIX COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA SEN COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA SAT COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA MIN COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA MAX COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA AVG COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA INF COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA SUP COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA MED COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA SGN COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA RND COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA LIN COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA SYM COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA SHP COMMA arg_signed_number COMMA arg_signed_number COMMA arg_number COMMA arg_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA SIN COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA SQR COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA SAW COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
                       | FAKEREAD LPAREN INTEGER COMMA arg_number COMMA INTEGER COMMA TRI COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number COMMA arg_signed_number RPAREN
    """
    
    if p[9] in Fakeread.argc4noises:
        fakeread_args = "" + str(p[7]) + ":" + str(p[9]) + ":" + str(p[11]) + ":" + str(p[13])
        if not p[5] in fakeread_argc4_actions.keys():
            fakeread_argc4_actions[p[5]] = {}
        if not fakeread_args in fakeread_argc4_actions[p[5]].keys():
            fakeread_argc4_actions[p[5]][fakeread_args] = "" + str(p[3])
        else:
            fakeread_argc4_actions[p[5]][fakeread_args] = fakeread_argc4_actions[p[5]][fakeread_args] + ":" + str(p[3])
    
    if p[9] in Fakeread.argc5noises:
        fakeread_args = "" + str(p[7]) + ":" + str(p[9]) + ":" + str(p[11]) + ":" + str(p[13]) + ":" + str(p[15])
        if not p[5] in fakeread_argc5_actions.keys():
            fakeread_argc5_actions[p[5]] = {}
        if not fakeread_args in fakeread_argc5_actions[p[5]].keys():
            fakeread_argc5_actions[p[5]][fakeread_args] = "" + str(p[3])
        else:
            fakeread_argc5_actions[p[5]][fakeread_args] = fakeread_argc5_actions[p[5]][fakeread_args] + ":" + str(p[3])
    
    if p[9] in Fakeread.argc6noises:
        fakeread_args = "" + str(p[7]) + ":" + str(p[9]) + ":" +str(p[11]) + ":" + str(p[13]) + ":" + str(p[15]) + ":" + str(p[17])
        if not p[5] in fakeread_argc6_actions.keys():
            fakeread_argc6_actions[p[5]] = {}
        if not fakeread_args in fakeread_argc6_actions[p[5]].keys():
            fakeread_argc6_actions[p[5]][fakeread_args] = "" + str(p[3])
        else:
            fakeread_argc6_actions[p[5]][fakeread_args] = fakeread_argc6_actions[p[5]][fakeread_args] + ":" + str(p[3])
    
    if p[9] in Fakeread.argc7noises:
        fakeread_args = "" + str(p[7]) + ":" + str(p[9]) + ":" +str(p[11]) + ":" + str(p[13]) + ":" + str(p[15]) + ":" + str(p[17]) + ":" + str(p[19])
        if not p[5] in fakeread_argc7_actions.keys():
            fakeread_argc7_actions[p[5]] = {}
        if not fakeread_args in fakeread_argc7_actions[p[5]].keys():
            fakeread_argc7_actions[p[5]][fakeread_args] = "" + str(p[3])
        else:
            fakeread_argc7_actions[p[5]][fakeread_args] = fakeread_argc7_actions[p[5]][fakeread_args] + ":" + str(p[3])


# drop (packet p, signed_double likelyhood)
def p_statement_drop(p):
    "logical_statement : DROP LPAREN arg_id COMMA arg_number RPAREN"
    
    if p[3] != "original":
        packet_check(p[3], p.lineno(1))
    
    args = str(p[3]) + ":" + str(p[5])
    action = Drop(args)
    actions.append(action)


# send (packet p, double delay)
def p_statement_send(p):
    "logical_statement : SEND LPAREN arg_id COMMA arg_number RPAREN"
    
    if p[3] != "original":
        packet_check(p[3], p.lineno(1))
    
    args = str(p[3]) + ":" + str(p[5])
    action = Send(args)
    actions.append(action)


# clone (srcPacket p1, dstPacket p2)
def p_statement_clone(p):
    "logical_statement : CLONE LPAREN arg_id COMMA arg_id RPAREN"
    
    if p[3] != "original":
        packet_check(p[3], p.lineno(1))
    packet_check(p[5], p.lineno(1))
    
    args = str(p[3]) + ":" + str(p[5])
    action = Clone(args)
    actions.append(action)


# create (packet p, string layer1.type, type_t content1, string layer2.type, type_t content2, ...)
def p_statement_create(p):
    "logical_statement : CREATE LPAREN arg_id COMMA args_create RPAREN"
    
    packet_check(p[3], p.lineno(1))
    
    args = str(p[3]) + ":" + str(p[5])
    
    action = Create(args)
    actions.append(action)


# change (packet p, string layer.field, type_t content)
def p_statement_change(p):
    "logical_statement : CHANGE LPAREN arg_id COMMA STRING COMMA arg_multiType RPAREN"
    
    # Check the third argument
    if p[3] != "original":
        packet_check(p[3], p.lineno(1))
    
    # p[7] is multiType (NUMBER, STRING, ID) 
    if p[7] not in reserved_name and p[7] not in symbol_table.keys():
        
        re_pattern = r"^[0-9]"
        pattern = re.compile(re_pattern)
        
        # Add an entry in the variable table if STRING is not present in it
        if p[7][0] == "\"" and p[7][-1] == "\"":
            symbol_table[p[7]] = "VAR"
            variables[p[7]] = "<value>" + p[7][1:-1] + "</value><type>STRING</type>"
        
        # Add an entry in the variable table if NUMBER is not present in it
        elif re.match(pattern, p[7]):
            symbol_table[p[7]] = "VAR"
            variables[p[7]] = "<value>" + p[7] + "</value><type>NUMBER</type>"
		
        # Return error if the ID is not declared
        else:
            print_error("Error: '" + p[7] + "' undefined variable identifier", str(p.lineno(1)) )

    # Check if the variable is initialized
    if p[7] not in reserved_name:
        
        value = variables[p[7]][7]
     
        # Variable not initialized if its first char is '<'
        if value == "<":
            print_error("Error: variable '" + p[7] + "' must be initialized", str(p.lineno(1)) )
    
    # Check layer name
    if check_layer_name(p[5]) == False:
        print_error("Error: layer name unknown, you can use only: APP or NET or MAC", str(p.lineno(1)))
    
    args = str(p[3]) + ":" + str(p[5]) + ":" + str(p[7])
    action = Change(args)
    actions.append(action)


# retrieve (packet p, string layer.field, ID content)
def p_statement_retrieve(p):
    "logical_statement : RETRIEVE LPAREN arg_id COMMA STRING COMMA arg_id RPAREN"
    
    if p[3] != "original":
        packet_check(p[3], p.lineno(1))
    
    # Check if the variable is reserved  
 	if p[7] in reserved_name:
		print_error("Error: '" + p[7] + "' is a reserved name", str(p.lineno(1)) )
      
    # Check if the variable has been previously declared
    if p[7] not in symbol_table.keys():
        print_error("Error: '" + p[7] + "' undefined variable identifier", str(p.lineno(1)) )
      
	# Check if the name has been previously used to declare a packet
    if p[7] in symbol_table.keys() and symbol_table[p[7]] != "VAR":
        print_error("Error: ID overloading is not allowed", str(p.lineno(1)) )
    
    # Check if the layer name is valid
    if check_layer_name(p[5]) == False:
        print_error("Error: layer name unknown, you can use only: APP or NET or MAC", str(p.lineno(1)))
    
    args = str(p[3]) + ":" + str(p[5]) + ":" + str(p[7])
    action = Retrieve(args)
    actions.append(action)


# put (packet p, list dstNodes, direction dir, bool updateStat, double delay)
def p_statement_put(p):
    "logical_statement : PUT LPAREN arg_id COMMA arg_id COMMA arg_direction COMMA arg_boolean COMMA arg_number RPAREN"
    
    if p[3] != "original":
        packet_check(p[3], p.lineno(1))
    
    # Check if the list has been already declared
    if p[5] not in lists.keys():
        print_error("Error: list '" + p[5] + "' is not declared", str(p.lineno(1)) )
    
    # Replace the second argument with the list content
    p[5] = str(lists[str(p[5])])
    args = str(p[3]) + ":" + str(p[5]) + ":" + str(p[7]) + ":" + str(p[9]) + ":" + str(p[11])
    
    action = Put(args)
    actions.append(action)
