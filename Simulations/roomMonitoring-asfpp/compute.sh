#!/bin/bash

python multiple10.py cluster1.txt
python multiple10.py cluster2.txt
python multiple10.py cluster3.txt
#python multiple10.py Scenario.txt

#rm cluster1.txt cluster2.txt cluster3.txt

python media.py cluster1_round.txt
python media.py cluster2_round.txt
python media.py cluster3_round.txt
#python media.py Scenario_round.txt

cp cluster1_round_avg plot/cluster1_round_avg
cp cluster2_round_avg plot/cluster2_round_avg
cp cluster3_round_avg plot/cluster3_round_avg
rm *.txt
rm *_avg

