# set terminal pdfcairo # size 6, 6
set key autotitle columnhead # use the first line as title
set datafile separator ','
plot "fun.csv" using 2:3:xtic(2) with lines, '' using 2:1 with lines, '' using 2:4 with lines, '' using 2:5 with lines
# set xtics rotate
