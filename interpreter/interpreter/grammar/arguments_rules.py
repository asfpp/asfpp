"""

Grammar rules for (ASL) arguments of primitives.

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
from engine.utilities import check_layer_name

# Import global variables
from config import *


# List members
def p_listMembers(p):
    "listMembers : listMembers COMMA listMembers"
    
    p[0] = str(p[1]) + "|" + str(p[3])


# Member of a list
def p_listMember(p):
    "listMembers : INTEGER"
    
    p[0] = str(p[1])


# Number
def p_arg_number(p):
    """
    arg_number : REAL
               | INTEGER
    """
    
    p[0] = str(p[1])


# Signed number
def p_arg_signed_number(p):
    """arg_signed_number : REAL
                         | SIGNED_REAL
                         | INTEGER
                         | SIGNED_INTEGER
    """
    
    p[0] = str(p[1])


# Multi-type
def p_arg_multiType(p):
    """
    arg_multiType : REAL
                  | INTEGER
                  | STRING
                  | ID
    """
    
    p[0] =  str(p[1])


# Boolean
def p_arg_boolean(p):
    """
    arg_boolean : TRUE
                | FALSE
    """
    
    p[0] = str(p[1]).lower()


# Direction (of the transmission)
def p_arg_direction(p):
    """
    arg_direction : TX
                  | RX
    """
    
    p[0] = str(p[1])


# Identifier
def p_arg_id(p):
    """
    arg_id : ID
           | ORIGINAL
    """
    
    # Check if the ID is present in the global symbol dictionary (i.e. it refers to a list)
    if str(p[1]) in global_symbol_table.keys():
        if global_symbol_table[str(p[1])] == "LIST":
            #p[0] = str(lists[str(p[1])])
            p[0] = str(p[1])
    
    # Check if the ID is present in the local symbol dictionary
    elif str(p[1]) in symbol_table.keys():
        p[0] = str(p[1])
    
    # It is a string/number constant or an undefined variable identifier
    else:
        p[0] = str(p[1])


# List of arguments (for the primitive 'create')
def p_args_create(p):
    "args_create : args_create COMMA args_create"
    
    p[0] = str(p[1]) + ":" + str(p[3])


# Argument pair (for the primitive 'create': <layer.field, value>)
def p_argsPair_create(p):
    "args_create : STRING COMMA arg_multiType"
    
    if check_layer_name(p[1]) == False:
        print_error("Error: layer name unknown, you can use only: APP or NET or MAC", str(p.lineno(1)))
    
    p[0] = str(p[1]) + ":" + str(p[3])

