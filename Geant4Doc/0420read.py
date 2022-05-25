# 本py脚本用于自动改写B1DetectorConstruction.cc中屏蔽板的厚度
particleNum = 3000000
exceptNum = 300000
mud = [2,2,2,2,2,2,4,4,4,4,4,4,7,7,7,7,7,7,10,10,10,10,10,10,15,15,15,15,15,15]
mud1 = [2,2,2,2,2,2,2,4,4,4,4,4,4,4,7,7,7,7,7,7,7,10,10,10,10,10,10,10,15,15,15,15,15,15,15]
enerNum = [0,1,2,3,4,5]
enerNum1 = [0,1,2,3,4,6,8]

i = 7
while i <= 41:
    j = i % 7
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/Al/log{}mud{}.txt'.format(mud1[i-7],enerNum1[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[888]='\n'

    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/log.txt', 'a', encoding='utf-8')
    f.write('Al{}mud{}\n'.format(mud1[i-7],enerNum1[j]))
    for n in range(883,889):
        f.write(new[n])
    f.close()

    i = i + 1

i = 7
while i <= 41:
    j = i % 7
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/Fe/log{}mud{}.txt'.format(mud1[i-7],enerNum1[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[888]='\n'

    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/log.txt', 'a', encoding='utf-8')
    f.write('Fe{}mud{}\n'.format(mud1[i-7],enerNum1[j]))
    for n in range(883,889):
        f.write(new[n])
    f.close()

    i = i + 1

i = 6
while i <= 35:
    j = i % 6
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/Water/log{}mud{}.txt'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[888]='\n'

    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/log.txt', 'a', encoding='utf-8')
    f.write('Water{}mud{}\n'.format(mud[i-6],enerNum[j]))
    for n in range(883,889):
        f.write(new[n])
    f.close()

    i = i + 1

i = 6
while i <= 35:
    j = i % 6
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/Concrete/log{}mud{}.txt'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[888]='\n'

    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/log.txt', 'a', encoding='utf-8')
    f.write('Concrete{}mud{}\n'.format(mud[i-6],enerNum[j]))
    for n in range(883,889):
        f.write(new[n])
    f.close()

    i = i + 1

i = 6
while i <= 35:
    j = i % 6
    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/Pb/log{}mud{}.txt'.format(mud[i-6],enerNum[j]), 'r', encoding='utf-8')
    new=[]
    for line in f:
        new.append(line)
    f.close()
    new[888]='\n'

    f = open('/home/apricot/Documents/GraduationProject/Geant4Work/log/scatteringRate/0508/infPlane/log.txt', 'a', encoding='utf-8')
    f.write('Pb{}mud{}\n'.format(mud[i-6],enerNum[j]))
    for n in range(883,889):
        f.write(new[n])
    f.close()

    i = i + 1