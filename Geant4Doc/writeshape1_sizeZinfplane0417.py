# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
particleNum = 1000000
i = 6
mud = [2,2,2,2,2,2,4,4,4,4,4,4,7,7,7,7,7,7,10,10,10,10,10,10,15,15,15,15,15,15]
hou = [10.91768611,
24.81152545,
38.25693742,
41.61819881,
41.98509739,
37.69228957,
21.83537221,
49.6230509,
76.51387483,
83.23639761,
83.97019478,
75.38457914,
38.21190137,
86.84033907,
133.899281,
145.6636958,
146.9478409,
131.9230135,
54.58843053,
124.0576272,
191.2846871,
208.090994,
209.9254869,
188.4614479,
81.88264579,
186.0864409,
286.9270306,
312.136491,
314.8882304,
282.6921718,
]
enerNum = [0,1,2,3,4,5]
energy = [0.5,1,2,3,4,8]

while i <= 35:
    j = i % 6
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infplanePb0417/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[63]='  G4double mudh = {};\n'.format(hou[i-6])
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infplanePb0417/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new:
        f.write(n)
    f.close()

    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infplanePb0417/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new1=[]
    for line in f1:
        new1.append(line)
    f1.close()
    new1[13]='/gun/energy {} MeV\n'.format(energy[j])
    new1[15]='/run/beamOn {}\n'.format(particleNum)
    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infplanePb0417/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new1:
        f1.write(n)
    f1.close()

    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infplanePb0417/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    # new3=[]
    # for line in f3:
    #     new3.append(line)
    # f3.close()
    # new3[83]='  G4double mudh = {};\n'.format(hou[i-6])
    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infplanePb0417/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    # for n in new3:
    #     f3.write(n)
    # f3.close()

    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infplanePb0417/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new4=[]
    for line in f4:
        new4.append(line)
    f4.close()
    new4[55]='int eventIDflag[{}] = {{{}}};  //重复计数排除数组\n'.format(particleNum,particleNum+1)
    new4[56]='int eventIDconvflag[{}] = {{{}}};  // 对发生电子对效应的粒子进行统计\n'.format(particleNum,particleNum+1)
    new4[97]='      if (E == {})\n'.format(energy[j])
    new4[101]='      for (int k = 0; k < {}; k++)\n'.format(particleNum)
    new4[112]='      for (int k = 0; k < {}; k++)\n'.format(particleNum)
    new4[148]='    if ((eventID == {}) & (outputcode == 10))\n'.format(particleNum-1)
    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/infplanePb0417/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new4:
        f4.write(n)
    f4.close()

    i = i + 1