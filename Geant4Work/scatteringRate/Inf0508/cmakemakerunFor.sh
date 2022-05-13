#! /bin/bash

mud=(2 2 2 2 2 2 4 4 4 4 4 4 7 7 7 7 7 7 10 10 10 10 10 10 15 15 15 15 15 15)
for ((i=6; i<=35; i++)); do
    b=$(( $i % 6 ))
    cd /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Pb/${mud[i-6]}mud${b}/build
    rm CMakeCache.txt
    rm log*
    cmake ..
    make
    ./exampleB1 rundemo.mac > log${mud[i-6]}mud${b}.txt
    cp log${mud[i-6]}mud${b}.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/Inf/Pb/
    echo 'succeed' ${mud[i-6]}'mud'${b}
done

for ((i=6; i<=35; i++)); do
    b=$(( $i % 6 ))
    cd /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Water/${mud[i-6]}mud${b}/build
    rm CMakeCache.txt
    rm log*
    cmake ..
    make
    ./exampleB1 rundemo.mac > log${mud[i-6]}mud${b}.txt
    cp log${mud[i-6]}mud${b}.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/Inf/Water/
    echo 'succeed' ${mud[i-6]}'mud'${b}
done

for ((i=6; i<=35; i++)); do
    b=$(( $i % 6 ))
    cd /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Concrete/${mud[i-6]}mud${b}/build
    rm CMakeCache.txt
    rm log*
    cmake ..
    make
    ./exampleB1 rundemo.mac > log${mud[i-6]}mud${b}.txt
    cp log${mud[i-6]}mud${b}.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/Inf/Concrete/
    echo 'succeed' ${mud[i-6]}'mud'${b}
done

# for ((i=6; i<=35; i++)); do
#     b=$(( $i % 6 ))
#     cd /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infPlane0506/Pb/${mud[i-6]}mud${b}/build
#     rm CMakeCache.txt
#     rm log*
#     cmake ..
#     make
#     ./exampleB1 rundemo.mac > log${mud[i-6]}mud${b}.txt
#     cp log${mud[i-6]}mud${b}.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0506/infPlane/Pb/
#     echo 'succeed' ${mud[i-6]}'mud'${b}
# done

# for ((i=6; i<=35; i++)); do
#     b=$(( $i % 6 ))
#     cd /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infPlane0506/Water/${mud[i-6]}mud${b}/build
#     rm CMakeCache.txt
#     rm log*
#     cmake ..
#     make
#     ./exampleB1 rundemo.mac > log${mud[i-6]}mud${b}.txt
#     cp log${mud[i-6]}mud${b}.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0506/infPlane/Water/
#     echo 'succeed' ${mud[i-6]}'mud'${b}
# done

# for ((i=6; i<=35; i++)); do
#     b=$(( $i % 6 ))
#     cd /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infPlane0506/Concrete/${mud[i-6]}mud${b}/build
#     rm CMakeCache.txt
#     rm log*
#     cmake ..
#     make
#     ./exampleB1 rundemo.mac > log${mud[i-6]}mud${b}.txt
#     cp log${mud[i-6]}mud${b}.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0506/infPlane/Concrete/
#     echo 'succeed' ${mud[i-6]}'mud'${b}
# done