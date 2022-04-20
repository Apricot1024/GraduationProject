#! /bin/bash
#rm -rf ./build/
#mkdir build
#cd build/
mud=(2 2 2 2 2 2 4 4 4 4 4 4 7 7 7 7 7 7 10 10 10 10 10 10 15 15 15 15 15 15)
for ((i=6; i<=35; i++)); do
#cmake ..
#make
#cp ~/Documents/GraduationProject/Geant4Doc/rundemo1.mac ./
    b=$(( $i % 6 ))
    cd /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/ConcreteInf0418/${mud[i-6]}mud${b}/build
    rm CMakeCache.txt
    rm log*
    cmake ..
    make
    ./exampleB1 rundemo.mac > log${mud[i-6]}mud${b}.txt
    cp log${mud[i-6]}mud${b}.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/ConcreteInf0418/
    echo 'succeed' ${mud[i-6]}'mud'${b}
done