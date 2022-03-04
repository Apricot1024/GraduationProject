f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Pb10mm/build/log.txt', 'r', encoding='utf-8') 
new=[]
for line in f:
    new.append(line)
f.close()

i = 0
while i < len(new):
    if new[i][8:26] == 'BeginOfEventAction':
        threadNum = line[0:6]

    
    if new[i][9:27] == 'BeginOfEventAction':
        threadNum = line[0:7]
# i = 1
# while i <= 9:
#     f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Pb10mm/build/log/log{}.txt'.format(i), 'w', encoding='utf-8') 
#     for line in new:
#         if line[0:6] == 'G4WT{} '.format(i):
#             f.write(line)
#     f.close()
#     i = i + 1

# i = 10
# while i <= 11:
#     f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Pb10mm/build/log/log{}.txt'.format(i), 'w', encoding='utf-8') 
#     for line in new:
#         if line[0:6] == 'G4WT{}'.format(i):
#             f.write(line)
#     f.close()
#     i = i + 1