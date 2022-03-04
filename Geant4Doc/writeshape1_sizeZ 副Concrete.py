# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
i = 6
mud = [2,2,2,2,2,2,4,4,4,4,4,4,7,7,7,7,7,7,10,10,10,10,10,10,15,15,15,15,15,15]
hou = [93.47541597,
128.3038235,
182.8688465,
225.16437,
259.0405139,
342.6535088,
186.9508319,
256.6076469,
365.7376929,
450.32874,
518.0810279,
685.3070175,
327.1639559,
449.0633821,
640.0409626,
788.075295,
906.6417988,
1199.287281,
467.3770798,
641.5191173,
914.3442323,
1125.82185,
1295.20257,
1713.267544,
701.0656197,
962.2786759,
1371.516348,
1688.732775,
1942.803855,
2569.901316,
]
enerNum = [0,1,2,3,4,5]
energy = [0.5,1,2,3,4,8]
while i <= 35:
    j = i % 6
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/ConcreteInf/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[63]='  G4double mudh = {};\n'.format(hou[i-6])
    new[138]='  G4Material* shape1_mat = nist->FindOrBuildMaterial("G4_CONCRETE");\n'
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/ConcreteInf/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new:
        f.write(n)
    f.close()

    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/ConcreteInf/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new1=[]
    for line in f1:
        new1.append(line)
    f1.close()
    new1[13]='/gun/energy {} MeV\n'.format(energy[j])
    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/ConcreteInf/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new1:
        f1.write(n)
    f1.close()

    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/ConcreteInf/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    # new3=[]
    # for line in f3:
    #     new3.append(line)
    # f3.close()
    # new3[83]='  G4double mudh = {};\n'.format(hou[i-6])
    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/ConcreteInf/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    # for n in new3:
    #     f3.write(n)
    # f3.close()

    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/ConcreteInf/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new4=[]
    for line in f4:
        new4.append(line)
    f4.close()
    new4[86]='        if (E == {})\n'.format(energy[j])
    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/ConcreteInf/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new4:
        f4.write(n)
    f4.close()

    i = i + 1
