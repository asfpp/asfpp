set terminal postscript eps enhanced color "Times-New-Roman" 18
set grid
set output "WormholeAttack1.eps"
set xlabel "Time (s)"
set ylabel "ug/(m^3)"
set key left


plot   []  [48:60] "cluster1_round_avg" title "Smokestack 1" with lines  lt 1 lc 5 lw 3 , "cluster2_round_avg" title "Smokestack 2" with lines  lt 1 lc 2 lw 3 , "cluster3_round_avg" title "Smokestack 3" with lines  lt 1 lc 3 lw 3 , "Threshold" title "Threshold"  with lines  lt 2 lc 1 lw 3
