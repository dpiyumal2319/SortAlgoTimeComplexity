set term png size 1000,600
set output 'sorting_algorithms.png'

set title "Sorting Algorithms Performance"
set xlabel "Number of Elements in Array"
set ylabel "Time (nanoseconds)"
set key top left

plot \
    'data.txt' using 1:2 with lines title 'Selection Sort', \
    '' using 1:3 with lines title 'Insertion Sort', \
    '' using 1:4 with lines title 'Bubble Sort', \
    '' using 1:5 with lines title 'Bubble Sort Optimised', \
    '' using 1:6 with lines title 'Quick Sort', \
    '' using 1:7 with lines title 'Quick Sort(Iterative)', \
    '' using 1:8 with lines title 'Merge Sort', \
    '' using 1:9 with lines title 'Merge Sort(Iterative)'
