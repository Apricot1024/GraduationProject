rm -rf ./build/
mkdir build
cd build/
cmake ..
make
cp ~/Documents/GraduationProject/Geant4Doc/rundemo1.mac ./
./exampleB1 rundemo1.mac > log.txt
echo 'succeed'
