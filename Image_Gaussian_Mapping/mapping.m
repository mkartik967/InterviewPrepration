function [step3] = mapping(J,CDF_im,CDF_id)
[r,c] = size(J);
clear step2
clear step1
clear step3
CDF_im(256)=1;
CDF_id(256)=1;
step2(1:r,1:c)=0;
step1=CDF_im(1:256);
for i=1:256
            step2(i)=nearest_pt(step1(i),CDF_id);   
end
step3 = step2(J+1);
end
