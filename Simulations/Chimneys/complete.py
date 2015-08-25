#!/usr/bin/env python
""" This script is a support to clusterAggregator application, it scroll the 
    file report in order to find some entry missing and replace it with the
    previous value.
"""

import sys
import os





# entry point
if __name__ == '__main__':


	if len(sys.argv) < 3:
		print "Usage : python <input file> <step>"
		sys.exit(-1)

	i_filename = sys.argv[1]

	try:
		step = int(sys.argv[2])
	except ValueError:
		print "The argument must be a integer."
		sys.exit(-1)

	
	try:
		i_file = open(i_filename, 'r')
	except :
		print "Impossible open the file "+i_filename
		sys.exit(-1)


	o_filename = i_filename+"_completed"
	
	try:
		o_file = open( o_filename,'w')
	except :
		print "Impossible create the file "+o_filename
		i_file.close()
		sys.exit(-1)

	current_line = i_file.readline()
	previous_time = 0
	previous_value = 0

	# retrieve TIME and VALUE from the current_line
	ret = current_line.split(' ')
	current_time = int(ret[0])
	current_value = float(ret[1])

	while(1):
			

		# line missing, so use the previous value
		if current_time != (previous_time + step) :

			previous_time += step
			o_file.write( str(int(previous_time))+" "+str(previous_value)+"\n")
			continue

		else :
			o_file.write( str( int(current_time) )+" "+str(current_value)+"\n")

			# update the "previous" variables
			previous_time = current_time
			previous_value = current_value

			# next row			
			current_line = i_file.readline()

			# eof
			if current_line == "" or current_line == "\n":
				break;

			# retrieve TIME and VALUE from the current_line
			ret = current_line.split(' ')
			current_time = float(ret[0])
			current_value = float(ret[1])

			

	i_file.close()
	o_file.close()

