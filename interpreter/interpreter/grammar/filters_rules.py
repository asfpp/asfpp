"""

Grammar rules for (ASL) packet filter (conditional attack).
 
Author:
 + Alessandro Pischedda	<alessandro.pischedda@gmail.com>
 + Marco Tiloca	        <marco.tiloca84@gmail.com>
 + Francesco Racciatti  <racciatti.francesco@gmail.com> 
 
Maintainer:
 + Francesco Racciatti  <racciatti.francesco@gmail.com>

"""


# Import the lexer for ASL
from lexer.asllexer import *

# Import global variables
from config import *


# Filter definition
def p_filter(p):
    "filter_code : FILTER LPAREN filter_content RPAREN"
    
    global packetFilter
    global packetFilterOperator
    # remove quotes
    packetFilter = p[3].replace("\"","")
    #packetFilter = packetFilter + packetFilterOperator
    
    p[0] = p[3]


def p_filter_content_mono(p):
    "filter_content : filter_elem"
    
    # in case of a single condition, the AND operator is appended by default
    p[0] = p[1].replace("\"","")


def p_filter_content_generic(p):
    "filter_content : filter_elem logic_operator filter_content"
    
    # Admitted only AND or OR (are appendend at the end)
    p[0] = p[1] + ":" + p[3] + ":" + p[2]
    

# Handle condition contained between two paren
def p_filter_content_paren(p):
    "filter_content : LPAREN filter_content RPAREN"
    
    p[0] = p[2]


def p_filter_elem(p):
    "filter_elem : operand comp_operator operand"
    
    p[0] = str(p[1]) + ":" + str(p[2]) + ":" + str(p[3])


# Right operand
def p_right_operand(p):
    """
    operand : ID
            | STRING
            | INTEGER
            | REAL
            | SELF
    """
    
    p[0] = str(p[1])


# Comparison operator
def p_comp_operator(p):
    """
    comp_operator : EQUAL
                  | DIFFERENT
                  | GRTHAN
                  | LESSTHAN
                  | GREQTHAN
                  | LEQTHAN
    """
    
    p[0] = p[1]


# Logic operator
def p_logic_operator(p):
    """
    logic_operator : AND
                   | OR
    """
    
    global packetFilterOperator
    packetFilterOperator = str(p[1]).upper()
    p[0] = str(p[1]).upper()
