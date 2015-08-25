# This is an example of ASL file that contains move actions.
#
# usage: 
#  python ../../interpreter/interpreter.py -i move-lots.asl -o move-lots.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# move nodes 1,2,3 to (20,20,20) at time 100
move(1, 100, 20, 20, 20)
move(2, 100, 20, 20, 20)
move(3, 100, 20, 20, 20)

# move nodes 1,2,3 to (50,50,50) (60,60,60) (70,70,70) respectively at time 200
move(1, 200, 50, 50, 50)
move(2, 200, 60, 60, 60)
move(3, 300, 70, 70, 70)
