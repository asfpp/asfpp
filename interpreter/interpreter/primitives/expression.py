"""

Expression class handles the expressions.

Authors:
 + Alessandro Pischedda	<alessandro.pischedda@gmail.com>
 + Marco Tiloca			<marco.tiloca84@gmail.com>
 + Francesco Racciatti	<racciatti.francesco@gmail.com>

Maintainer:
 + Francesco Racciatti <racciatti.francesco@gmail.com>

"""


class Expression:
    
    expr = ""
    
    def __init__(self, expression):
        self.expr = expression

    def __str__(self):
        xml = "\n\t\t\t<action>"
        xml += "\n\t\t\t\t<name>Expression</name>"
        xml += self.expr
        xml += "\n\t\t\t</action>"
        
        return xml
