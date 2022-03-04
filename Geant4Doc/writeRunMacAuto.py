# 本py脚本用于自动写用于给G4执行的mac文件
# 本脚本都为在文件末尾添加
# 本脚本书写的文件为txt文件，执行前需先自行创建文件，在脚本中修改文件路径和编写参数
i = 0.50
f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Waterinf/build/rundemo.mac'.format(2*i), 'w', encoding='utf-8') 

while i < 20.001:                                                                                   # 1,101指i从1循环到100,
    # f = open('/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/Pb10mm/build/rundemo{:.0f}.mac'.format(2*i), 'w', encoding='utf-8')     # 将/home/apricot/Geant4Work/B1/build/runUserzmhalpha100.txt修改为自身txt文件的路径
    f.write('\n# Initialize kernel')                                                                
    f.write('\n/run/initialize')                                                                    # 初始化，加载内核
    f.write('\n#/change particle')                                                                  
    f.write('\n/gun/particle gamma')                                                                # 修改粒子，将alpha改为自己需要的粒子。

    # f.write('\n')                                                                                   # 输出水平
    # f.write('\n/control/verbose 2')
    # f.write('\n/run/verbose 2')
    # f.write('\n/event/verbose 0')
    # f.write('\n/tracking/verbose 2')
    # f.write('\n')


    f.write('\n#change energy')                                                            
    f.write('\n/gun/energy {:.2f} MeV'.format(i))                                              # 修改momentumAmp为iMeV,单位可自行修改momentumAmp为其他量，注意匹配单位
    f.write('\n#launch 10000 particles')                                                          
    f.write('\n/run/beamOn 10000')                                                                # 发射100个粒子，粒子数可修改
    f.write('\n')
    # f.close()
    i = i + 0.50