#!/bin/bash

#
# Automates the execution of simulations and the plotting of the related 
# results.
#
# Author: Francesco Racciatti
#

# Interprets all the attacks
echo "Interpreting the attacks contained in the folder attacks ..."
./scripts/interprets-attacks.sh

# Prints the available configurations
../../bin/Castalia

# Reads the input file
input=omnetpp.ini

# Checks if input file exists
if [ -f $input ];
then
    echo "Using input file '$input'"
else
    echo "Input file '$input' not found"
    exit
fi

# Reads the configuration file
echo -n "Enter the 'Config' to run: "
read config

# Checks if the current configuration is 'General'
if [ "$config" != "General" ];
then
    # Checks if the input file contains the configuration
    pattern="^\s*\[\s*Config\s*$config\s*\]"
    if egrep -q $pattern $input
    then
        echo "Using configuration '$config'"
    else
        echo "Configuration $config not found"
        exit
    fi
fi

# Reads the number of repetitions
echo -n "Enter the number of repetitions: "
read repetitions

# Gets the date and time
now=$(date +"%G%m%d-%H%M%S")
now_text=$(date +"%G-%m-%d %H:%M:%S")

# Creates the main simulation folder
simulation="$config-$now"
mkdir $simulation

# Creates the info file describing the current simulation
echo "Auto-generated file">info.txt
echo "-------------------">>info.txt
echo "">>info.txt
echo "Configuration: $config">>info.txt
echo "Time: $now_text">>info.txt
echo "Command: ../../bin/Castalia -i $input -c $config -r $repetitions">>info.txt

# Moves info.txt in the main simulation folder
mv info.txt $simulation
if [ "$config" != "General" ];
then
    # Gets the configuration group and store it in a temp file    
    pattern="^\s*\[\s*Config\s*$config\s*\][^\[]*"
    pcregrep -M $pattern $input > temp.txt
    # Gets the path of the .xml file
    pattern="SN\.configurationFile\s*=\s*\".*\""
    xml=$(pcregrep -M $pattern temp.txt | sed "s/^\s*SN.configurationFile\s*=\s*\"\(.*\)\"/\1/")
    # Removes the temp file
    rm temp.txt
    if [ -a "$xml" ]
    then
        # Creates the 'attack' folder and fills with the adl and xml files
        mkdir -p attack
        attack_name_adl="$config.adl" 
        attack_name_xml="$config-$now.xml" 
        cp $xml attack/$attack_name
        cp attacks/$attack_name_adl attack/$attack_name_adl
        # Moves the 'attack' folder into the main simulation folder
        mv attack $simulation
    fi
fi

# Launches the simulation
../../bin/Castalia -i $input -c $config -r $repetitions

# Runs the py scripts to round data
python scripts/round.py cluster5.txt
python scripts/round.py cluster6.txt

# Runs the py scripts to compute the average values
python scripts/average.py cluster5_round.txt
python scripts/average.py cluster6_round.txt

# Runs the py scripts to complete the average files
python scripts/complete.py cluster5_round_avg 5
python scripts/complete.py cluster6_round_avg 5

# Compute the average values of the entire scenario
python scripts/scenario_average.py cluster5_round_avg_complete cluster6_round_avg_complete

# Copies the plot script in the main folder
cp scripts/plot.plt plot.plt
cp scripts/threshold threshold

# Plots the simulation results (.eps)
gnuplot plot.plt
result="$config-$now.eps"
mv simulation-result.eps $result

# Makes the 'plot' folder and fills it with the related files
mkdir -p plot
mv $result plot
mv plot.plt plot
mv threshold plot
cp cluster5_round_avg_complete plot
cp cluster6_round_avg_complete plot

# Mobes the 'plot' folder into the main simulation folder
mv plot $simulation

# Makes the 'raw' folder and fills it with the related files
mkdir -p raw
mv *.txt raw
mv *_avg raw
mv *_complete raw

# Moves the 'plot' folder in the main simulation folder
mv raw $simulation

# Moves the main simulation folder in 'results'
mv $simulation results

echo "All simulation related files was moved in the folder '$simulation' (into 'results')"
