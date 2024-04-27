set yrange [0:10]
set xrange [0:10]

set terminal pdfcairo # size 6, 6
# set terminal dumb # size 6, 6

set key autotitle columnhead # use the first line as title
set datafile separator '	'
set style data points
# plot "plot.tsv" using 1:2:xtic(1) with lines,
set offset 5,5,5,5
plot "plot.tsv" using 2:3:1 with labels point pt 1 offset char 1,1 notitle, "pareto" using 1:2:xtic(1) with lines
plot "plot.tsv" using 2:3:1 with labels point offset char 1,1, "slater" using 1:2:xtic(1) with lines
# set xtics rotate
# plot for [col=2:5] "table.csv" using 1:col:xtic(1) with lines lw 1
