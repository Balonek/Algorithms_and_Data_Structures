#!/bin/bash

export TIME='%U'

sorts_x="bubblesort.x selectionsort.x insertionsort.x"
sorts="bubblesort selectionsort insertionsort"
output_file="results.tsv"
min_size=10
max_size=21

g++ -O2 -o Generator.x Generator.cpp
for sort in $sorts; do
    g++ -O2 -o "$sort.x" "$sort.cpp"
done

output_file="results.tsv"
echo -n "n" > "$output_file"
printf '\t%s' $sorts_x >> "$output_file"
echo >> "$output_file"

for i in $(seq $min_size $max_size); do
    let size=2**$i
    echo -n "$size" >> "$output_file"
    ./Generator.x $size $size >/dev/shm/$$ 
    for sort in $sorts_x; do
        time=$(/usr/bin/time ./$sort </dev/shm/$$ 2>&1 1>/dev/null)
        printf '\t%s' "$time" >> "$output_file"
    done
    echo >> "$output_file"
done

rm /dev/shm/$$

gnuplot <<EOF
set terminal png size 1200,800
set output "sort_times_with_inset.png"

# Main plot configuration
set title "Czas sortowania vs rozmiar danych"
set xlabel "Rozmiar danych (n)"
set ylabel "Czas (s)"
set logscale x 2
set grid

f1(x) = a1 * x**2
f2(x) = a2 * x**2
f3(x) = a3 * x**2

fit f1(x) "results.tsv" using 1:2 via a1
fit f2(x) "results.tsv" using 1:3 via a2
fit f3(x) "results.tsv" using 1:4 via a3

set multiplot

set size 1,1
set origin 0,0
set title "Czas sortowania vs rozmiar danych (Main Graph)"
plot "results.tsv" using 1:2 title "BubbleSort.x" with linespoints lt 1, \
     "results.tsv" using 1:3 title "SelectionSort.x" with linespoints lt 2, \
     "results.tsv" using 1:4 title "InsertionSort.x" with linespoints lt 3, \
     f1(x) title sprintf("Teoretyczna O(n^2) (a1=%.2f)", a1) with lines lt 4, \
     f2(x) title sprintf("Teoretyczna O(n^2) (a2=%.2f)", a2) with lines lt 5, \
     f3(x) title sprintf("Teoretyczna O(n^2) (a3=%.2f)", a3) with lines lt 6

set size 0.4,0.4  # Inset size
set origin 0.05,0.55 
set title "Zoom"
set xlabel ""
set ylabel ""
set logscale x 2  
set logscale y   
unset key
set xrange [1024:65536]
set yrange [0.01:20] 

fit f1(x) "results.tsv" using 1:2 via a1
fit f2(x) "results.tsv" using 1:3 via a2
fit f3(x) "results.tsv" using 1:4 via a3

plot "results.tsv" using 1:2 with linespoints lt 1, \
     "results.tsv" using 1:3 with linespoints lt 2, \
     "results.tsv" using 1:4 with linespoints lt 3 \
	 f1(x) title sprintf("Teoretyczna O(n^2) (a1=%.2f)", a1) with lines lt 4, \
     f2(x) title sprintf("Teoretyczna O(n^2) (a2=%.2f)", a2) with lines lt 5, \
     f3(x) title sprintf("Teoretyczna O(n^2) (a3=%.2f)", a3) with lines lt 6
unset multiplot
EOF