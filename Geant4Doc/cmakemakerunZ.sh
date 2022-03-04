#! /bin/bash
for ((i=1; i<=50; i++)); do
    rm -rf /home/apricot/Documents/GraduationProject/Geant4Work/Shape1SizeZ/Pb${i}mm/build/
    cd /home/apricot/Documents/GraduationProject/Geant4Work/Shape1SizeZ/Pb${i}mm/
    mkdir build
    cd build/
    cmake ..
    make
    cp /home/apricot/Documents/GraduationProject/Geant4Doc/rundemo.mac /home/apricot/Documents/GraduationProject/Geant4Work/Shape1SizeZ/Pb${i}mm/build/
    ./exampleB1 rundemo.mac > logPb${i}mm.txt
    cp /home/apricot/Documents/GraduationProject/Geant4Work/Shape1SizeZ/Pb${i}mm/build/logPb${i}mm.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/Shape1SizeZ/
    echo 'succeed' ${i}
done