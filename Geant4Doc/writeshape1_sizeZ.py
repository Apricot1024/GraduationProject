# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
i = 1
while i <= 50:
    fstr1 = '/home/apricot/Documents/毕设/Geant4Work/Pb'
    fstr2 = str(i)
    fstr3 = 'mm/src/B1DetectorConstruction.cc'
    fstr = fstr1 + fstr2 +fstr3
    f = open(fstr, 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    str1 = '  G4double shape1_sizeZ  = '
    str3 = '*mm;\n'
    str157 = str1 + fstr2 + str3
    new[157]=str157
    f = open(fstr, 'w', encoding='utf-8')
    for n in new:
        f.write(n)
    f.close()
    i = i + 1
