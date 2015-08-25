set terminal postscript eps enhanced color "Times-New-Roman" 18
set grid
set output "Simulation.eps"
set xlabel "Time (s)"
set ylabel "Average pollution level (ug/m^3)"
set key right

set style line 1  lt 1 lc 4 lw 2
set style line 2  lt 1 lc 7 lw 2
set style line 3  lt 1 lc 3 lw 2
set style line 4  lt 1 lc 8 lw 2

plot   []  [20:50] "cluster5_round_avg_completed" title "Smokestack 1" with linespoints ls 1, "cluster6_round_avg_completed" title "Smokestack 2" with linespoints ls 2 , "Threshold" title "Threshold"  with lines  lt 5 lc 1 lw 4
