# This is an example of ASL file that contains a set of fakeread actions.
# It shows the overwrite property of fakeread, i.e. it is possible to redefine 
# the parameters of a noise function.
#
# usage: 
#  python ../../interpreter/interpreter.py -i fakeread-overwrite.asl -o fakeread-overwrite.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# tampers the sensor 0 of node 1 from time 50, it applies the noise 'rnd'
fakeread(1, 50, 0, rnd, 0, 2, 25)

# overwrite the old parameters from 100
fakeread(1, 50, 0, rnd, 1, 2, 50)
