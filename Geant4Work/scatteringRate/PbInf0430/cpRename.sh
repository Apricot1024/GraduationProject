#! /bin/bash
for ((i=1; i<=5; i++)); do
    cp -R 2mud0/ 2mud${i}
done
echo 'succeed 2'

for ((i=0; i<=5; i++)); do
    cp -R 2mud0/ 4mud${i}
done
echo 'succeed 4'

for ((j=7; j<=10; j=j+3));do
    for ((i=0; i<=5; i++)); do
        cp -R 2mud0/ ${j}mud${i}
    done
    echo 'succeed' ${j}
done

for ((i=0; i<=5; i++)); do
    cp -R 2mud0/ 15mud${i}
done
echo 'succeed 15'