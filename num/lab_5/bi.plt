# set terminal pdfcairo # size 6, 6
set key autotitle columnhead # use the first line as title
set datafile separator ','
# plot "bi.csv" using 1:2:xtic(1) with lines, '' using 1:3 with lines, '' using 1:4 with lines, '' using 1:5 with lines, '' using 1:6 with lines, '' using 1:7 with lines
plot "bi.csv" using 1:2:xtic(1) with lines, '' using 1:4 with lines, '' using 1:6 with lines, '' using 1:8 with lines
# set xtics rotate
# plot for [col=2:5] "table.csv" using 1:col:xtic(1) with lines lw 1
