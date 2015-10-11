# This is an example of ASL file that contains a set of fakeread actions.
#
# usage: 
#  python ../../interpreter/interpreter.py -i fakeread-simple.asl -o fakeread-simple.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>


function f1 = "sin(2*pi*t) + s"
function f2 = "cos(2*pi*t) + 0.5 * s"

# tampers the sensor 0 of node 1 from time 50
fakeread(1, 50, 0, f1)

# tampers the sensor 0 of node 2 from time 100
fakeread(2, 100, 0, f2)
