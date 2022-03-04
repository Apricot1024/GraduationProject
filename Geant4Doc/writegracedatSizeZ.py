# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
i = 0
while i < 50:
    f = open('/home/apricot/Documents/毕设/Geant4Work/log/logPb{}mm.txt'.format(i+1), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    
    n = 0
    f1 = open('/home/apricot/Documents/毕设/Geant4Work/data/Pb{}mm.dat'.format(i+1), 'w', encoding='utf-8')
    while n < 49:
        f1.write('{} '.format(n + 2))
        str1 = new[963 + 86 * n]
        f1.write(str1[45:52])
        f1.write('\n')
        n = n + 1
    f1.close()
    i = i + 1
