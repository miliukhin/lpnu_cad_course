set yrange [-10:200]
set xrange [-100:200]

# set tics scale 100
set xtics 20
set ytics 20

set terminal pdfcairo size 6,6 # size 6, 6
# set terminal dumb # size 6, 6
# plot 'data' with filledcurves fc "cyan" fs solid 0.5 border lc "blue"
# set

set key autotitle columnhead # use the first line as title
set datafile separator '	'
set style data points
# plot "plot.tsv" using 1:2:xtic(1) with lines,
# set offset 5,5,5,5

# set arrow 1 from 50, graph 0 to 50, graph 1 nohead lc rgb "blue"

# set arrow 1 from 0,0 to -10,30 nohead lc rgb "red"
# plot [-15:5] -3*x title "-3x", \
#      0 title "y-axis"

# set object 1 polygon from 50, graph 50 to 50, graph 1 to graph 0, graph 0 fillstyle solid 0.2 noborder
# set object 2 polygon from 50, graph 0 to 50, graph 1 to graph 0, graph 0 fillstyle solid 0.2 noborder

set style fill transparent solid 0.3 border
# set samples 11
# set style fill transparent pattern 0.1 noborder
# 50;80
set xlabel "x1"
set ylabel "x2"
# set xrange [0:200]
# set yrange [0:200]
set key

set arrow from 0,0 to 55,12 lc rgb "black" lw 3
# set arrow from 0,0 to 30,10 lc rgb "black" lw 3

set arrow from 50,-10 to 50,800

plot 80 with lines title "x_2 <= 80",  \
	240-4*x with lines title "4x_1 + x_2 <= 240",  \
	3*x with lines title "-3x_1 + x_2 <= 0", \
	50+2*x with lines title "-2x_1+x_2 <= 50", \
	-3*x with lines title "цільова функція" lw 5
	# 2*x with lines lw 2

# set xrange [0:60]
# set yrange [0:300]

# plot 240 - 4*x with lines, \
#      '+' using 1:(240 - 4*$1) with filledcurves below lc 'blue'

# f(x) = 240 - 4*x

# plot f(x) with lines, \
#      '+' using 1:(f($1)):(0) with lines fill transparent solid 0.5 noborder
