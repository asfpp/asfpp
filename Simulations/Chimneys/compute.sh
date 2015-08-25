#!/bin/bash

python multiple5.py cluster5.txt
python multiple5.py cluster6.txt

python media.py cluster5_round.txt
python media.py cluster6_round.txt

rm cluster5_round.txt cluster6_round.txt

python complete.py cluster5_round_avg 5
python complete.py cluster6_round_avg 5

python ScenarioAVG.py cluster5_round_avg_completed cluster6_round_avg_completed

gnuplot stacks.plt

epstopdf Simulation.eps
