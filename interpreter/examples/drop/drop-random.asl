# This is an example of ASL file that contains drop actions.
# It drops the intercepted (original) packet with a random chance.
#
# usage: 
#  python ../interpreter/interpreter.py -i drop-random.asl -o drop-random.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list targetList = {1}

# conditional attack statement (starts at 100 and it refers nodes in targetList)
from 100 nodes in targetList do {

	# packet filter, it filters all packets having the field 'sourcePort' of the layer 'NET' equals to 1000
	filter("NET.sourcePort" == "1000")

		# drop the original intercepted packet with a random chance
    	drop(original, rnd)

}
