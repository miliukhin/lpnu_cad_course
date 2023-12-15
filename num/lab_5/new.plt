# set terminal pdfcairo # size 6, 6
set key autotitle columnhead # use the first line as title
set datafile separator ','
plot "new.csv" using 1:4:xtic(1) with lines, '' using 1:5 with lines
# set xtics rotate
