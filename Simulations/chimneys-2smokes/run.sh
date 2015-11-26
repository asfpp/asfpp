# author: Francesco Racciatti <racciatti.francesco@gmail.com>

#!/bin/bash

# print available configurations
../../bin/Castalia

# read input file
#echo -n "Enter the input '.ini' file: "
#read input
input=omnetpp.ini

# check if input file exists
if [ -f $input ];
then
    echo "Using input file '$input'"
else
    echo "Input file '$input' not found"
    exit
fi

# read configuration file
echo -n "Enter the 'Config' to run: "
read config

# check if 'General'
if [ "$config" != "General" ];
    then
        # check if the input file contains the configuration
        pattern="^\s*\[\s*Config\s*$config\s*\]"
        if egrep -q $pattern $input
        then
            echo "Using configuration '$config'"
        else
            echo "Configuration $config not found"
            exit
        fi
fi

# read number of repetitions
echo -n "Enter the number of repetitions: "
read repetitions

# take the acutal time
now=$(date +"%G%m%d-%H%M%S")
now_text=$(date +"%G-%m-%d %H:%M:%S")

# make a main simulation folder
simulation="$config-$now"
mkdir $simulation

# write actual info on file
echo "Auto-generated file">info.txt
echo "-------------------">>info.txt
echo "">>info.txt
echo "Configuration: $config">>info.txt
echo "Time: $now_text">>info.txt
echo "Command: ../../bin/Castalia -i $input -c $config -r $repetitions">>info.txt
# move info.txt in the main simulation folder
mv info.txt $simulation
if [ "$config" != "General" ];
then
    # get the configuration group and store it in a temp file    
    pattern="^\s*\[\s*Config\s*$config\s*\][^\[]*"
    pcregrep -M $pattern $input > temp.txt
    # get the path of the .xml file
    pattern="SN\.configurationFile\s*=\s*\".*\""
    xml=$(pcregrep -M $pattern temp.txt | sed "s/^\s*SN.configurationFile\s*=\s*\"\(.*\)\"/\1/")
    # remove temp file
    rm temp.txt
    if [ -a "$xml" ]
    then
        # make 'attack' folder, retrieve the .xml file and copy them in it
        mkdir -p attack
        attack_name="$config-$now.xml" 
        cp $xml attack/$attack_name
        # move the 'attack' folder in the main simulation folder
        mv attack $simulation
    fi
fi

# launch the simulation
../../bin/Castalia -i $input -c $config -r $repetitions

# run py scripts to round data
python scripts/round.py cluster5.txt
python scripts/round.py cluster6.txt

# run py scripts to compute average values
python scripts/average.py cluster5_round.txt
python scripts/average.py cluster6_round.txt

# run py scripts to complete average files
python scripts/complete.py cluster5_round_avg 5
python scripts/complete.py cluster6_round_avg 5

# compute average values of the entire scenario
python scripts/scenario_average.py cluster5_round_avg_complete cluster6_round_avg_complete

# copy the plot script in the main folder
cp scripts/plot.plt plot.plt
cp scripts/threshold threshold
# plot simulation results (.eps)
gnuplot plot.plt
# change .eps  file name
result="$config-$now.eps"
mv simulation-result.eps $result
# make plot folder and move in it all plot related files
mkdir -p plot
mv $result plot
mv plot.plt plot
mv threshold plot
cp cluster5_round_avg_complete plot
cp cluster6_round_avg_complete plot
# move 'plot' folder in the main simulation folder
mv plot $simulation

# make raw folder and move in it all raw data files
mkdir -p raw
mv *.txt raw
mv *_avg raw
mv *_complete raw
# move 'plot' folder in the main simulation folder
mv raw $simulation

# move the main simulation folder in 'results'
mv $simulation results

echo "All simulation related files was moved in the folder '$simulation' (into 'results')"
