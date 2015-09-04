""" Questo script serve per arrottondare i tempi della simulazione al multiplo di 10 piu' vicino. Ad esempio se abbiamo 99 dara' 100
 mentre se abbiamo 234 dara' 230 """

import sys

filename_in = sys.argv[1]
filename_out = filename_in.replace(".txt","_round.txt")

print "File Input : "+filename_in
print "File Output : "+filename_out

file_input = open(filename_in, "r")

rows = file_input.readlines()

file_input.close()
file_output = open(filename_out, "w")


for row in rows:
	columns = row.split(' ')
	time = int(columns[0])
	value = 0
	if columns[1] != '-nan\n':
		value = float(columns[1])
		
	# if  value == '-nan\n' it will be set to 0 and decrease the n_runs to compute the average
	# infact we haven't a sample at this time.
	
	# we need an output like 10,20, 30 etc
	s_time = columns[0]
	if int(s_time[-1]) < 5 :
		s_time = str( time - int(s_time[-1]) )
	else :
		s_time = str( time + 10 - int(s_time[-1]) )

	file_output.write( s_time+" "+columns[1] )

file_output.close()
