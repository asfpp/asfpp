# This is an example of ASL file that contains a set of fakeread actions.
#
# usage: 
#  python ../../interpreter/interpreter.py -i fakeread.asl -o fakeread.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# tampers the sensor 0 of node 1 from time 50, it applies the noise 'rnd'
fakeread(1, 50, 0, rnd, 0, 2, 25)

# tampers the sensor 0 of node 2 from time 100, it applies the noise 'sin'
fakeread(2, 100, 0, sin, 0.1, 5, 100, 0, 0)

# tampers the sensor 0 of node 3 from time 200, it applies the noise 'lin'
fakeread(3, 200, 0, lin, 0, 0.05, -25)
