clear all
close all
clc
I = imread('4.1.01.tiff');
if size(I,3)==3
   ycb = rgb2ycbcr(I);
J = ycb(:,:,1);
bool =1;
else
    J = I;
    bool=0;
end
[m,n]=size(J);
N=m*n;
hi=imhist(J);
%hi = smooth(hi,20,'lowess');
mu=mean(J(:));
if mu>=128
    Y=mu/255;
else 
    Y=(255-mu)/255;
end
del = sqrt(var(hi));
for k=1:1:256
    hi(k)=power(hi(k)+del,Y);
end
hi=hi*(N/sum(hi));
[op,T]=he(J,hi);
op = uint8(op);
if bool==1
    ycb_mod = ycb;
ycb_mod(:,:,1) = op;
final = ycbcr2rgb(ycb_mod);
else
    final=op;
end
final=uint8(final);
figure,imshow(I)
figure,imshow(final)
