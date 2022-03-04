#! /bin/bash

cd /home/apricot/Documents/GraduationProject/Geant4Work/Shape1Material/Fe10mm/
mkdir build
cd build/
cmake ..
make
cp /home/apricot/Documents/GraduationProject/Geant4Doc/rundemo.mac /home/apricot/Documents/GraduationProject/Geant4Work/Shape1Material/Fe10mm/build/
./exampleB1 rundemo.mac > logFe10mm.txt
cp /home/apricot/Documents/GraduationProject/Geant4Work/Shape1Material/Fe10mm/build/logFe10mm.txt /home/apricot/Documents/GraduationProject/Geant4Work/log/
echo 'succeed'
