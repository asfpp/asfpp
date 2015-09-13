""" 
Round data to the nearest multiple of 10.

Authors:
 + Alessandro Pischedda <alessandro.pischedda@gmail.com>
 + Francesco Racciatti <racciatti.francesco@gmail.com>
"""

import sys

filename_in = sys.argv[1]
filename_out = filename_in.replace(".txt","_round.txt")

print "File Input : " + filename_in
print "File Output : " + filename_out

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
    
    # we need an output like 10, 20, 30, ...
    s_time = columns[0]
    if int(s_time[-1]) < 5 :
        s_time = str( time - int(s_time[-1]) )
    else:
        s_time = str( time + 10 - int(s_time[-1]) )
    
    file_output.write( s_time+" "+columns[1] )

file_output.close()
