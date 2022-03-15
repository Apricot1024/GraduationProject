function a=linefit1(xi,yi)
  %a(1)=k,a(2)=b
  x=mean(xi);,y=mean(yi);
  xy=mean(xi.*yi);,x2=mean(x1.*xi);
  a(1)=(xy-x*y)/(x2-x*x);
  a(2)=y-a(1)*x;