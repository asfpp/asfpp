# This is an example of ASL file that contains a set of fakeread actions.
# It shows the aggregation property of fakeread, i.e. if two or more
# fakeread actions are applied on the same node and on the same sensor,
# them are added up.
#
# usage: 
#  python ../../interpreter/interpreter.py -i fakeread-aggregation.asl -o fakeread-aggregation.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# tampers the sensor 0 of node 1 from time 50, it applies the noise 'rnd'
fakeread(1, 50, 0, rnd, 0, 2, 25)

# tampers the sensor 0 of node 1 from time 100, it applies the noise 'sin'
# since this action is defined on the same sensor and on the same node of the previous fakeread action,
# from 100 the two fakeread actions are added up
fakeread(1, 100, 0, sin, 0.1, 5, 100, 0, 0)
