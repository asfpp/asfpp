# This software is used to compute the average of different run. It's a beta version and isn't much flexible.
# The output filename is the original one plus "_avg".
#
# Usage: python average.py <filename>

import sys

# It store for each "time" the sum of samples
# It's a dictionary where the key is the time 
times = {} 
samples = {}

filename_in = sys.argv[1]
filename_out = filename_in.replace(".txt","_avg")

print "File Input : "+filename_in
print "File Output : "+filename_out

file_input = open(filename_in, "r")

rows = file_input.readlines()

file_input.close()


for row in rows:
	columns = row.split(' ')
	time = int(columns[0])
	value = 0
	if columns[1] != '-nan\n':
		value = float(columns[1])
		
	# if  value == '-nan\n' it will be set to 0 and decrease the n_runs to compute the average
	# infact we haven't a sample at this time.

	if times.has_key(time):
		times[time] = times[time] + value
		samples[time] = samples[time] + 1
	else:
		samples[time] = 1
		times[time] = value

# the keys are the discrete time like 10,20, etc
keys = times.keys()
keys.sort()

file_output = open(filename_out, "w")



for key in keys:
	if times[key] != 0:
		file_output.write( str(key)+" "+str(times[key]/samples[key])+"\n" )
		#print str(key)+" "+str(times[key])+"/"+str(samples[key])
	else:
		file_output.write( str(key)+" 0\n" )		

file_output.close()
