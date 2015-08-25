set terminal postscript eps enhanced color "Times-New-Roman" 18
set grid

set style fill solid 1 noborder
set output "Throughput.eps"
set xlabel "Cluster ID"
set ylabel "Byte/s"

# Select histogram mode.
set style data histograms 

# center the histograms
set style histogram rowstacked

set boxwidth 0.5 relative


set key off

#xtic(i) mean "use the i column as axis X"
plot [] [0:6] 'Throughputs.dat' using 2:xtic(1)
