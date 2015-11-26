set terminal postscript eps enhanced color "Times-New-Roman" 18
set grid
set output "simulation-result.eps"
set xlabel "Time (s)"
set ylabel "Average pollution level (ug/m^3)"
set key right

set style line 1  lt 1 lc rgb 'green' lw 1 ps 0.75
set style line 2  lt 1 lc rgb 'black' lw 1 ps 0.75
set style line 3  lt 1 lc rgb 'blue' lw 1 ps 0.75
set style line 4  lt 1 lc rgb 'red' lw 1 ps 0.75

plot [0:600] [20:50] "cluster5_round_avg_complete" title "Smokestack 1" with linespoints ls 1, "cluster6_round_avg_complete" title "Smokestack 2" with linespoints ls 2 , "threshold" title "Threshold"  with lines  lt 5 lc 1 lw 4
