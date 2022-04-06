engy=(0.5 1 2 3 4 8)
cat=(a b)

for ((i=0; i<=5; i++)); do
    for ((j=0; j<=1; j++)); do
        cp 0.5.dat ${engy[i]}${cat[j]}.dat
    done
done