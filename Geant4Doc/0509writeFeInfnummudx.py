# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
particleNum = 10000000
# exceptNum = 300000
i = 7
mud = [2,2,2,2,2,2,2,4,4,4,4,4,4,4,7,7,7,7,7,7,7,10,10,10,10,10,10,10,15,15,15,15,15,15,15]
hou = [30.18784264,
42.36872527,
58.19026529,
70.1465087,
76.69097464,
83.08816094,
84.9216008,
60.37568529,
84.73745054,
116.3805306,
140.2930174,
153.3819493,
166.1763219,
169.8432016,
105.6574493,
148.2905384,
203.6659285,
245.5127804,
268.4184112,
290.8085633,
297.2256028,
150.9392132,
211.8436264,
290.9513265,
350.7325435,
383.4548732,
415.4408047,
424.608004,
226.4088198,
317.7654395,
436.4269897,
526.0988152,
575.1823098,
623.1612071,
636.912006
]
enerNum = [0,1,2,3,4,6,8]
energy = [0.5,1,2,3,4,6,8]
muenrho = [0.02966,0.02789,0.02345,0.02057,0.01870,0.01647,0.01525]

while i <= 41:
    j = i % 7
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Fe/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-7],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[63]='  G4double mudh = {};\n'.format(hou[i-7])
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Fe/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-7],enerNum[j]), 'w', encoding='utf-8')
    for n in new:
        f.write(n)
    f.close()

    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Fe/{}mud{}/build/rundemo.mac'.format(mud[i-7],enerNum[j]), 'r', encoding='utf-8')
    new1=[]
    for line in f1:
        new1.append(line)
    f1.close()
    new1[8]='#/tracking/verbose 1\n'
    new1[13]='/gun/energy {} MeV\n'.format(energy[j])
    new1[15]='/run/beamOn {}\n'.format(particleNum)
    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Fe/{}mud{}/build/rundemo.mac'.format(mud[i-7],enerNum[j]), 'w', encoding='utf-8')
    for n in new1:
        f1.write(n)
    f1.close()

    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Fe/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-7],enerNum[j]), 'r', encoding='utf-8')
    # new3=[]
    # for line in f3:
    #     new3.append(line)
    # f3.close()
    # new3[83]='  G4double mudh = {};\n'.format(hou[i-7])
    # f3 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Fe/{}mud{}/src/B1PrimaryGeneratorAction.cc'.format(mud[i-7],enerNum[j]), 'w', encoding='utf-8')
    # for n in new3:
    #     f3.write(n)
    # f3.close()

    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Fe/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-7],enerNum[j]), 'r', encoding='utf-8')
    new4=[]
    for line in f4:
        new4.append(line)
    f4.close()
    new4[62]='G4double muenrho11 = {};\n'.format(muenrho[j])
    new4[101]='        if (E == {})\n'.format(energy[j])
    new4[217]='    if ((eventID == {}) & (outputcode == 10))\n'.format(particleNum-1)
    f4 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Inf0508/Fe/{}mud{}/src/B1SteppingAction.cc'.format(mud[i-7],enerNum[j]), 'w', encoding='utf-8')
    for n in new4:
        f4.write(n)
    f4.close()

    i = i + 1