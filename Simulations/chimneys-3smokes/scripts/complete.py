#!/usr/bin/env python

""" 
This script supports the clusterAggregator application.
It scrolls report files in order to find missing entries and replace them 
with the value of the previous entry.
    
Usage:
$ python average.py <filename>
 
Authors:
 + Alessandro Pischedda <alessandro.pischedda@gmail.com>
 + Francesco Racciatti <racciatti.francesco@gmail.com>
"""


import sys
import os


if __name__ == '__main__':

    if len(sys.argv) < 3:
        print "Usage: python <input file> <step>"
        sys.exit(-1)

    input_filename = sys.argv[1]

    try:
        step = int(sys.argv[2])
    except ValueError:
        print "Error: the argument must be a integer."
        sys.exit(-1)

    try:
        input_file = open(input_filename, 'r')
    except :
        print "Error: cannot open the file " + input_filename
        sys.exit(-1)

    output_filename = input_filename + "_complete"
    
    try:
        output_file = open(output_filename,'w')
    except :
        print "Error: cannot create the file " + output_filename
        input_file.close()
        sys.exit(-1)

    current_line = input_file.readline()
    previous_time = 0
    previous_value = 0

    # retrieve TIME and VALUE from the current_line
    ret = current_line.split(' ')
    current_time = int(ret[0])
    current_value = float(ret[1])

    while(1):
	
        # line missing, so use the previous value
        if current_time != (previous_time + step):

            previous_time += step
            output_file.write(str(int(previous_time)) + " " + str(previous_value) + "\n")
            continue

        else:
            output_file.write(str(int(current_time)) + " " + str(current_value) + "\n")

            # update the "previous" variables
            previous_time = current_time
            previous_value = current_value

            # next row			
            current_line = input_file.readline()

            # eof
            if current_line == "" or current_line == "\n":
                break;

            # retrieve TIME and VALUE from the current_line
            ret = current_line.split(' ')
            current_time = float(ret[0])
            current_value = float(ret[1])

    input_file.close()
    output_file.close()

