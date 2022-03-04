# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
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
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Pb/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    # new[177]='  G4Material* shape1_mat = nist->FindOrBuildMaterial("G4_Pb");\n'
    # new[236]='  G4Material* shape2_mat = nist->FindOrBuildMaterial("Galactic"); //NaI\n'
    new[182]='  G4double shape1_sizeZ  = {}*mm;\n'.format(hou[i-6])
    new[241]='  G4double shape2_sizeZ  = (env_sizeZ - shape1_sizeZ) / 3;\n'
    new[289]='  fScoringVolume = logicShape2;\n'
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Pb/{}mud{}/src/B1DetectorConstruction.cc'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new:
        f.write(n)
    f.close()

    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Pb/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new1=[]
    for line in f1:
        new1.append(line)
    f1.close()
    new1[12]='/gun/energy {} MeV\n'.format(energy[j])
    # new1[13]='#launch 10000 particles\n'
    # new1[14]='/run/beamOn 100000'
    f1 = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Pb/{}mud{}/build/rundemo.mac'.format(mud[i-6],enerNum[j]), 'w', encoding='utf-8')
    for n in new1:
        f1.write(n)
    f1.close()
    i = i + 1
