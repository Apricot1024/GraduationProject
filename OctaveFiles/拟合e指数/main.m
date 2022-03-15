xi=2.04:2.04:8.16;
yia1=[799078 667237 552643 451419];
yia2=[780755 610813 478211 374819];
yi1=log(yia1);,yi2=log(yia2);
a1=linefit1(xi,yi1);
a2=linefit1(xi,yi2);
yib1=a1(1)*xi+a1(2);
yic1=exp(yib1);
yib2=a2(1)*xi+a2(2);
yic2=exp(yib2);
figure(1)
plot(xi,yia1,'r+',xi,yic1)
figure(2)
plot(xi,yia2,'r+',xi,yic2)
a1(1)
a1(2)
a2(1)
a2(2)