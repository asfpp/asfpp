"""

General grammar rules for ASL.

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

# Import global variables
from config import *


# Parsing precedence
precedence = (
    ("left","PLUS",'MINUS'),
    ('left','TIMES','DIVIDE'),
    ('left', 'EXP'),
    ('right','UMINUS', 'EQUALS'),
)


# Program
def p_program(p):
    "program : global_entries"
    #print "program: " + str(p[1])


# Global entries
def p_global_entries(p):
    """
    global_entries  : attack
                    | list_statement
                    | global_entries global_entries
    """
    #print "global_entries: " + str(p[1])


# List definition
def p_statement_list(p):
    "list_statement : LIST ID EQUALS LCBRACKET listMembers RCBRACKET"
    
    # Check if the list identifier is already declared
    if (str(p[2]) in global_symbol_table.keys() or str(p[2]) in symbol_table.keys()):
        print_error("Error: ID '" + str(p[2]) + "' is already declared ", str(p.lineno(2)))
    
    else:
        # Add the list identifier to the global symbol table
        global_symbol_table[str(p[2])] = "LIST"
        lists[str(p[2])] = p[5]


# Occurrence time
def p_time(p):
    """
    number : INTEGER
           | REAL
    """
    
    p[0] = str(p[1])


# Filter codeblock
def p_filter_codeblock(p):
    "filter_codeblock : filter_code codeblock"

    p[0] = p[1]
    #print "filter_codeblock: " + str(p[0])
    #print "filter_code: " + str(p[1])
    #print "codeblock: " + str(p[2])
    
# Codeblock
def p_codeblock(p):
    "codeblock : statements"
    #print "codeblock " + str(p[1])
    

# Statements (logical primitives; variable declaration-initialization; packet declaration)
def p_statements(p):
    """statements : statement
                  | logical_statement
                  | statements statements
    """
    #print "statements: " + str(p[1])
    

# Variable initialization
def p_statement_varinit(p):
    "statement : VAR ID EQUALS init"
    
    # Check if the name is a reserved one (e.g. RANDOM)
    if str(p[2]) in reserved_name:
        print_error("Error: '" + str(p[2]) + "' is a reserved name", str(p.lineno(2)))
    
    # Check if this identifier has been already declared for the current attack
    elif str(p[2]) in symbol_table.keys():
        print_error("Error : '" + str(p[2]) + "' is already declared", str(p.lineno(2)))
    
    else:
        # Add the identifier to the symbol and variable table
        symbol_table[str(p[2])] = "VAR"
        variables[str(p[2])] = str(p[4])


# Variable declaration
def p_statement_vardef(p):
    "statement : VAR ID"
    
    # Check if the name is a reserved one (e.g. RANDOM)
    if str(p[2]) in reserved_name:
        print_error("Error : '" + str(p[2]) + "' is a reserved name", str(p.lineno(2)) )
    
    # Check if this identifier has been already declared for this attack
    elif str(p[2]) in symbol_table.keys():
        print_error("Error : '" + str(p[2]) + "' is already declared", str(p.lineno(2)) )
    
    else:
        # Add the identifier to the symbol and variable table (the type is NONE)
        symbol_table[str(p[2])] = "VAR"
        variables[str(p[2])] = "<value></value><type>NONE</type>"


# String initialization
def p_init_string(p):
    "init : STRING"
    
    # Remove quotes
    value = str(p[1]).replace("\"", "")
    p[0] = "<value>" + value + "</value><type>STRING</type>"


# Real initialization
def p_init_real(p):
    """
    init : REAL
         | INTEGER
    """
    
    p[0] = "<value>" + str(p[1]) + "</value><type>NUMBER</type>"


# Packet declaration
def p_statement_packetdef(p):
    "statement : PACKET ID"
    
    if str(p[2]) == "original":
        print_error("Error: '" + str(p[2]) + "' is a reserved name", str(p.lineno(1)))
    
    # Check if this identifier has been already declared for this attack
    if str(p[2]) in symbol_table.keys():
        print_error("Error: '" + str(p[2]) + "' is already declared", str(p.lineno(1)))
    
    else :
        # Add the identifier to the symbol table
        if str(p[2]) != "original":
            symbol_table[str(p[2])] = "PACKET"


# List of arguments seprated by ','
def p_argslist(p):
    "args : args COMMA args"
    
    p[0] = str(p[1]) + ":" + str(p[3])


# Argument is the keyword "original" (used for intercepted packets)
def p_args_original(p):
    "args : ORIGINAL"
    
    p[0] = "original"
	

# Argument is the keyword "rnd"
def p_arg_rnd(p):
    "args : RND"
    
    p[0] = "rnd"


# Argument
def p_args_simple(p):
    """
    args : REAL
         | INTEGER
         | STRING
         | TX
         | RX
         | SELF
         | ID
    """
    
    p[0] =  str(p[1])


# Argument is a boolean constant
def p_args_simple_boolean(p):
    """
    args : TRUE
         | FALSE
    """
    
    p[0] =  str(p[1]).lower()

