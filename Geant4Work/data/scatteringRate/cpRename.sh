#! /bin/bash
mud=(2 4 7 10 15)
for ((i=0; i<=4; i++)); do
    cp Pb2muda.dat Pb${mud[i]}mudf.dat
done
echo 'succeed'