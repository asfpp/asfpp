# This is an example of ASL file that contains a set of destroy actions.
#
# usage: 
#  python ../../interpreter/interpreter.py -i destroy-lots.asl -o destroy-lots.xml
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# destroy the nodes 1,2,3 at time 50 and the nodes 4,5,6 at time 200, 300, 400 respectively
destroy(1, 50)
destroy(2, 50)
destroy(3, 50)
destroy(4, 200)
destroy(5, 300)
destroy(6, 400)
