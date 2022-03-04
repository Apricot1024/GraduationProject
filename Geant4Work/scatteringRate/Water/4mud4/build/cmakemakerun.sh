rm CMakeCache.txt
#mkdir build
#cd build/]
cmake ..
make
./exampleB1 rundemo.mac > log.txt
# for ((i=1; i<=40; i++)); do
# #cp ~/Documents/GraduationProject/Geant4Doc/rundemo1.mac ./
#     ./exampleB1 rundemo${i}.mac > log${i}.txt
#     echo 'succeed' ${i}
# done
