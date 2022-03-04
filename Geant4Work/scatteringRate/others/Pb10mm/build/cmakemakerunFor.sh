#rm -rf ./build/
#mkdir build
#cd build/
for ((i=1; i<=40; i++)); do
#cmake ..
#make
#cp ~/Documents/GraduationProject/Geant4Doc/rundemo1.mac ./
    ./exampleB1 rundemo${i}.mac > log${i}.txt
    echo 'succeed' ${i}
done
