# This is an example of ASL file that contains a set of fakeread actions.
# It shows the annulment property of fakeread (a particular case of the overwrite property).
#
# usage: 
#  python ../../interpreter/interpreter.py -i fakeread-annulment.asl -o fakeread-annulment.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# tampers the sensor 0 of node 1 from time 50, it applies the noise 'rnd'
fakeread(1, 50, 0, rnd, 0, 2, 25)

# annull the previous fakeread action from 100
fakeread(1, 100, 0, rnd, 1, 0, 0)
