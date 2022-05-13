# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
particleNum = 10000000
# exceptNum = 300000
i = 7
mud = [2,2,2,2,2,2,2,4,4,4,4,4,4,4,7,7,7,7,7,7,7,10,10,10,10,10,10,10,15,15,15,15,15,15,15]
hou = [87.74602615,
120.5686936,
171.3726158,
209.2672101,
238.5753995,
279.1017668,
304.0686052,
175.4920523,
241.1373872,
342.7452316,
418.5344201,
477.150799,
558.2035336,
608.1372103,
307.1110915,
421.9904276,
599.8041554,
732.4352352,
835.0138982,
976.8561837,
1064.240118,
438.7301307,
602.843468,
856.8630791,
1046.33605,
1192.876997,
1395.508834,
1520.343026,
658.0951961,
904.2652019,
1285.294619,
1569.504075,
1789.315496,
2093.263251,
2280.514539
]
enerNum = [0,1,2,3,4,6,8]
energy = [0.5,1,2,3,4,6,8]
muenrho = [0.02966,0.02789,0.02345,0.02057,0.01870,0.01647,0.01525]

while i <= 41:
    j = i % 7
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Al/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-7],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[63]='  G4double mudh = {};\n'.format(hou[i-7])
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Al/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-7],enerNum[j]), 'w', encoding='utf-8')
    for n in new:
        f.write(n)
    f.close()

    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Al/{}mud{}/build/rundemo.mac'.format(mud[i-7],enerNum[j]), 'r', encoding='utf-8')
    new1=[]
    for line in f1:
        new1.append(line)
    f1.close()
    new1[8]='#/tracking/verbose 1\n'
    new1[13]='/gun/energy {} MeV\n'.format(energy[j])
    new1[15]='/run/beamOn {}\n'.format(particleNum)
    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Al/{}mud{}/build/rundemo.mac'.format(mud[i-7],enerNum[j]), 'w', encoding='utf-8')
    for n in new1:
        f1.write(n)
    f1.close()

    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Al/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-7],enerNum[j]), 'r', encoding='utf-8')
    # new3=[]
    # for line in f3:
    #     new3.append(line)
    # f3.close()
    # new3[83]='  G4double mudh = {};\n'.format(hou[i-7])
    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Al/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-7],enerNum[j]), 'w', encoding='utf-8')
    # for n in new3:
    #     f3.write(n)
    # f3.close()

    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Al/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-7],enerNum[j]), 'r', encoding='utf-8')
    new4=[]
    for line in f4:
        new4.append(line)
    f4.close()
    new4[62]='G4double muenrho11 = {};\n'.format(muenrho[j])
    new4[101]='        if (E == {})\n'.format(energy[j])
    new4[217]='    if ((eventID == {}) & (outputcode == 10))\n'.format(particleNum-1)
    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Al/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-7],enerNum[j]), 'w', encoding='utf-8')
    for n in new4:
        f4.write(n)
    f4.close()

    i = i + 1