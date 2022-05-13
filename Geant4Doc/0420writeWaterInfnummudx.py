# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
particleNum = 3000000
exceptNum = 300000
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
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0506/Water/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[63]='  G4double mudh = {};\n'.format(hou[i-6])
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0506/Water/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new:
        f.write(n)
    f.close()

    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0506/Water/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new1=[]
    for line in f1:
        new1.append(line)
    f1.close()
    new1[8]='#/tracking/verbose 1\n'
    new1[13]='/gun/energy {} MeV\n'.format(energy[j])
    new1[15]='/run/beamOn {}\n'.format(particleNum)
    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0506/Water/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new1:
        f1.write(n)
    f1.close()

    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0506/Water/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    # new3=[]
    # for line in f3:
    #     new3.append(line)
    # f3.close()
    # new3[83]='  G4double mudh = {};\n'.format(hou[i-6])
    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0506/Water/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    # for n in new3:
    #     f3.write(n)
    # f3.close()

    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0506/Water/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new4=[]
    for line in f4:
        new4.append(line)
    f4.close()
    new4[58]='int eventIDflag[{}] = {{{}}};  //重复计数排除数组\n'.format(particleNum,particleNum+1)
    new4[59]='int eventIDconvflag[{}] = {{{}}};  // 对发生电子对效应的粒子进行统计\n'.format(particleNum,particleNum+1)
    new4[99]='      if (E == {})\n'.format(energy[j])
    new4[119]='            if (E == {})\n'.format(energy[j])
    new4[130]='    if ((eventID == {}) & (outputcode == 10))\n'.format(particleNum-1)
    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0506/Water/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new4:
        f4.write(n)
    f4.close()

    i = i + 1