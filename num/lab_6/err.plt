# set terminal pdfcairo # size 6, 6
set yrange[0.002:0.007]
set logscale y
# set ytics 1e-3, 10, 1
# set format y "10^{%L}"

set key autotitle columnhead # use the first line as title
set datafile separator ','
plot "err.csv" using 4:1:xtic(4) with lines, '' using 4:2 with lines, '' using 4:3 with lines
# set xtics rotate
