#! /bin/bash
for ((i=1; i<=50; i++)); do
    rm -rf ~/Documents/毕设/Geant4Work/Pb${i}mm/build/
    cd ~/Documents/毕设/Geant4Work/Pb${i}mm/
    mkdir build
    cd build/
    cmake ..
    make
    cp /home/apricot/Documents/毕设/Geant4Doc/rundemo.mac /home/apricot/Documents/毕设/Geant4Work/Pb${i}mm/build/
    ./exampleB1 rundemo.mac > logPb${i}mm.txt
    cp /home/apricot/Documents/毕设/Geant4Work/Pb${i}mm/build/logPb${i}mm.txt /home/apricot/Documents/毕设/Geant4Work/log/
    echo 'succeed' ${i}
done