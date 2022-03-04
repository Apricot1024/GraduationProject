# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
mat = []
mat.append('Water')
mat.append('Fe')
mat.append('Concrete')
mat.append('Pb')
for i in mat:
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/log{}10mm.txt'.format(i), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    
    n = 0
    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/data/Mat/{}10mm.dat'.format(i), 'w', encoding='utf-8')
    while n < 49:
        f1.write('{} '.format(n + 2))
        str1 = new[963 + 86 * n]
        f1.write(str1[45:52])
        f1.write('\n')
        n = n + 1
    f1.close()
