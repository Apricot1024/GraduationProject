#! /bin/bash

mud=(2 2 2 2 2 2 2 4 4 4 4 4 4 4 7 7 7 7 7 7 7 10 10 10 10 10 10 10 15 15 15 15 15 15 15)
num=(0 1 2 3 4 6 8)
for ((i=7; i<=41; i++)); do
    b=$(( $i % 7 ))
    cd /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0503/Pb/${mud[i-6]}mud${num[b]}/build
    rm CMakeCache.txt
    rm log*
    cmake ..
    make
    ./exampleB1 rundemo.mac > log${mud[i-6]}mud${num[b]}.txt
    cp log${mud[i-6]}mud${num[b]}.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/Inf0503/Pb/
    echo 'succeed' ${mud[i-6]}'mud'${num[b]}
done