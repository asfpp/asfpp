set terminal postscript eps enhanced color "Times-New-Roman" 18
set grid
set output "test.eps"
set xlabel "Time (s)"
set ylabel "Celsius"
set key left


plot   [0:700]  [] "cluster1_round_avg" title "Cluster 1" with lines  lt 1 lc 5 lw 3 , "cluster2_round_avg" title "Cluster 2" with lines  lt 1 lc 2 lw 3 , "cluster3_round_avg" title "Cluster 3" with lines  lt 1 lc 3 lw 3
