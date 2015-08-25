# Usage: python metric.py <cluster1_file> <scenario_file>

import sys
import math

correct_c1uster1 = "0cluster1_round_avg"
correct_scenario = "0Scenario_avg"
wrong_cluster1 = sys.argv[1]
wrong_scenario = sys.argv[2]
filename_out = "metric"

correct_cluster_samples = 0
correct_scenario_samples = 0
correct_cluster_averages = []
correct_scenario_averages = []

wrong_cluster_samples = 0
wrong_scenario_samples = 0
wrong_cluster_averages = []
wrong_scenario_averages = []

partial_sum = 0
metric_cluster1 = 0
metric_scenario = 0
metric_overall = 0 # it refers to both to cluster1 (ClusterHead1) and the whole scenario (sink)

# Retrieve input information

# Cluster1 correct data

file_input = open(correct_c1uster1, "r")
lines = file_input.readlines()
file_input.close()

for line in lines:
	content = line.split(' ')
	correct_cluster_averages.append(content[1]) # retrieve the average value
	correct_cluster_samples = correct_cluster_samples + 1

# Scenario correct data

file_input = open(correct_scenario, "r")
lines = file_input.readlines()
file_input.close()

for line in lines:
	content = line.split(' ')
	correct_scenario_averages.append(content[1]) # retrieve the average value
	correct_scenario_samples = correct_scenario_samples + 1

# Cluster1 wrong data

file_input = open(wrong_cluster1, "r")
lines = file_input.readlines()
file_input.close()

for line in lines:
	if (line == ""): break
	content = line.split(' ')
	wrong_cluster_averages.append(content[1]) # retrieve the average value
	wrong_cluster_samples = wrong_cluster_samples + 1

# Scenario wrong data

file_input = open(wrong_scenario, "r")
lines = file_input.readlines()
file_input.close()

for line in lines:
	content = line.split(' ')
	wrong_scenario_averages.append(content[1]) # retrieve the average value
	wrong_scenario_samples = wrong_scenario_samples + 1

# Compute metrics

# This should not happen
if (correct_scenario_samples != wrong_scenario_samples):
	#print correct_scenario_samples, wrong_scenario_samples
	print "Uncorrect amount of samples! Exiting..."
	exit()

# Metric for the cluster
for i in range(0, correct_cluster_samples):
	aux = (float)(correct_cluster_averages[i]) - (float)(wrong_cluster_averages[i])
	aux = abs(aux)
	aux = aux * aux
	metric_cluster1 = metric_cluster1 + aux

metric_cluster1 = metric_cluster1 / correct_cluster_samples

# Metric for whole system
for i in range(0, correct_scenario_samples):
	aux = (float)(correct_scenario_averages[i]) - (float)(wrong_scenario_averages[i])
	aux = abs(aux)
	aux = aux * aux
	metric_scenario = metric_scenario + aux

metric_scenario = metric_scenario / correct_scenario_samples

# Combined metric (cluster + whole system)

metric_overall = (metric_cluster1 + metric_scenario) / 2

# Produce output
	
file_output = open(filename_out, "a")

file_output.write("cluster"+" "+str(metric_cluster1)+"\n")
file_output.write("scenario"+" "+str(metric_scenario)+"\n")
file_output.write("overall"+" "+str(metric_overall)+"\n")

file_output.close()
