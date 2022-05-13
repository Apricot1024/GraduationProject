# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
particleNum = 3000000
exceptNum = 300000
mud = [2,2,2,2,2,2,4,4,4,4,4,4,7,7,7,7,7,7,10,10,10,10,10,10,15,15,15,15,15,15]
enerNum = [0,1,2,3,4,5]

i = 6
while i <= 35:
    j = i % 6
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/Inf0506/Water/log{}mud{}.txt'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[888]='\n'

    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/Inf0506/log.txt', 'a', encoding='utf-8')
    f.write('Water{}mud{}\n'.format(mud[i-6],enerNum[j]))
    for n in range(883,889):
        f.write(new[n])
    f.close()

    i = i + 1

i = 6
while i <= 35:
    j = i % 6
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/Inf0506/Concrete/log{}mud{}.txt'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[888]='\n'

    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/Inf0506/log.txt', 'a', encoding='utf-8')
    f.write('Concrete{}mud{}\n'.format(mud[i-6],enerNum[j]))
    for n in range(883,889):
        f.write(new[n])
    f.close()

    i = i + 1

i = 6
while i <= 35:
    j = i % 6
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/Inf0506/Pb/log{}mud{}.txt'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[888]='\n'

    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/Inf0506/log.txt', 'a', encoding='utf-8')
    f.write('Pb{}mud{}\n'.format(mud[i-6],enerNum[j]))
    for n in range(883,889):
        f.write(new[n])
    f.close()

    i = i + 1