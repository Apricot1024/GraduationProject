# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
i = 6
mud = [2,2,2,2,2,2,4,4,4,4,4,4,7,7,7,7,7,7,10,10,10,10,10,10,15,15,15,15,15,15]
hou = [206.462269,
282.8054299,
404.6944557,
503.9052658,
587.7167205,
823.3841087,
412.924538,
565.6108597,
809.3889114,
1007.810532,
1175.433441,
1646.768217,
722.6179416,
989.8190045,
1416.430595,
1763.66843,
2057.008522,
2881.84438,
1032.311345,
1414.027149,
2023.472278,
2519.526329,
2938.583603,
4116.920543,
1548.467018,
2121.040724,
3035.208418,
3779.289494,
4407.875404,
6175.380815,
]
enerNum = [0,1,2,3,4,5]
energy = [0.5,1,2,3,4,8]
while i <= 35:
    j = i % 6
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/WaterInf/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[63]='  G4double mudh = {};\n'.format(hou[i-6])
    new[138]='  G4Material* shape1_mat = nist->FindOrBuildMaterial("G4_WATER");\n'
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/WaterInf/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new:
        f.write(n)
    f.close()

    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/WaterInf/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new1=[]
    for line in f1:
        new1.append(line)
    f1.close()
    new1[13]='/gun/energy {} MeV\n'.format(energy[j])
    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/WaterInf/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new1:
        f1.write(n)
    f1.close()

    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/WaterInf/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    # new3=[]
    # for line in f3:
    #     new3.append(line)
    # f3.close()
    # new3[83]='  G4double mudh = {};\n'.format(hou[i-6])
    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/WaterInf/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    # for n in new3:
    #     f3.write(n)
    # f3.close()

    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/WaterInf/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new4=[]
    for line in f4:
        new4.append(line)
    f4.close()
    new4[87]='      if (E == {})\n'.format(energy[j])
    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/WaterInf/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new4:
        f4.write(n)
    f4.close()


    i = i + 1
