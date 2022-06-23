function a=linefit1(xi,yi)
  %a(1)=k,a(2)=b
  x=mean(xi);,y=mean(yi);
  xy=mean(xi.*yi);,x2=mean(xi.*xi);
  a(1)=(xy-x*y)/(x2-x*x);
  a(2)=y-a(1)*x;
  sum_x = 0;
  sum_y = 0;
  size = length(xi);
  for i = 1:size
      sum_x = (yi(i)-y)^2+sum_x;
      sum_y = (xi(i)-y)^2+sum_y;
  end
