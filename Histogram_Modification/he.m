function [op,T] = he (J,hi)
[m,n]=size(J);
N=m*n;
c(1:256)=0;
for k=1:1:256
        c(k)= sum(hi(1:k));
end
c = c./c(256);
T=floor(255.*c+0.5);
clear op;
op = T(J+1);
end
