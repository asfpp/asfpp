set terminal postscript eps enhanced color "Times-New-Roman" 18
set grid
set output "simulation-result.eps"
set xlabel "Time (s)"
set ylabel "Average pollution level (ug/m^3)"
set key right

set style line 1  lt 1 lc rgb 'green' lw 1 ps 0.75
set style line 2  lt 1 lc rgb 'black' lw 1 ps 0.75
set style line 3  lt 1 lc rgb 'gray' lw 1 ps 0.75
set style line 4  lt 1 lc rgb 'blue' lw 1 ps 0.75
set style line 5  lt 1 lc rgb 'purple' lw 1 ps 0.75
set style line 6  lt 1 lc rgb 'red' lw 1 ps 0.75

plot [0:600] [20:50] "cluster5_round_avg_complete" title "S1" with linespoints ls 1, 
"cluster6_round_avg_complete_base" title "S2 - base" with linespoints ls 2 , 
"cluster6_round_avg_complete_clone1" title "S2 - 1 clone" with linespoints ls 3, 
"cluster6_round_avg_complete_clone2" title "S2 - 2 clones" with linespoints ls 4, 
"cluster6_round_avg_complete_clone2" title "S2 - 4 clones" with linespoints ls 5, "threshold" title "Threshold"  with lines  lt 5 lc 1 lw 6
