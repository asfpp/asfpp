# This is an example of ASL file that contains physical attacks
# A physical attack is composed by a single physical primitive.
# In this example there are 4 physical primitive (i.e. 4 physical attacks)
#
# usage: 
#  python ../../interpreter/interpreter.py -i physical-attacks.asl -o physical-attacks.xml
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# destroy the node 1 at time 50
destroy(1, 50)

# disable the node 2 at time 50
disable(2, 50)

# move the node 1 at time 50 to <10,10,10>
move(1, 50, 10, 10, 10)

# tamper the sensor 0 of node 1 from time 50, it applies the noise 'rnd'
fakeread(1, 50, 0, rnd, 0, 2, 25)
