#!/bin/bash
cd C-JuliaSets
make clean
make
./julia -2. 2. -2. 2. 5000 5000 -1.56 -.04 > ../juliaset_-1.56_-.04.csv
cd -
cd Cpp-Mandelbrot
make clean
make
./mandelbrot -.42 -.35 -.67 -.6 5000 5000 > ../mandelbrot_-.42_-.35_-.67_-.6.csv
cd -
mv *.csv Datasets
cd Datasets
python plot_data.py "juliaset_-1.56_-.04" "mandelbrot_-.42_-.35_-.67_-.6"





