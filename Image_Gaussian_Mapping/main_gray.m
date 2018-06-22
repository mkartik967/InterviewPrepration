function main_gray
clear All
close All
clc
I = imread('./seed/4.tif');
if size(I,3)==3
        J = rgb2gray(I);
else
    J = I;
end
J = double(J);

[mu_im, sigma_im] = mean_var(J);
% Desired Mean and Variance 
x = 0:255;
mu_id=128;
sigma_id=41.1003;

[CDF_im,CDF_id]=distribution(mu_im,sigma_im,mu_id,sigma_id,x);
xi = measure(sigma_im,mu_im);
final = mapping(J,CDF_im,CDF_id);
[mu_im_final, sigma_im_final] = mean_var(final);
xi_final = measure(sigma_im_final,mu_im_final);
final=uint8(final);
J=uint8(J);
f = figure;
subplot(121)
imshow(J);
string_dummy = ['Orig  ' '\mu=' num2str(mu_im)  '  \sigma = ' num2str(sigma_im)  '  \xi = ' num2str(xi)];
xlabel(string_dummy);
%ax = axes('Parent',f,'position',[0.13 0.39  0.77 0.54]);
subplot(122)
h = imshow(final);
string_dummy = ['\mu=' num2str(mu_im_final) '  \sigma = ' num2str(sigma_im_final)   '  \xi = ' num2str(xi_final)];
xlabel(string_dummy);
b = uicontrol('Parent',f,'Style','slider','Position',[80,60,1200,20],...
              'Value',sigma_id, 'min',1, 'max',100,'Callback', @surfzlim);
 txt = uicontrol('Style','text','Position',[80,80,1200,20],'String','Contrast');
function surfzlim(source,~)
    sigma_id = get(source,'Value');
[CDF_im,CDF_id]=distribution(mu_im,sigma_im,mu_id,sigma_id,x);
xi = measure(sigma_im,mu_im);
final = mapping(J,CDF_im,CDF_id);
[mu_im_final, sigma_im_final] = mean_var(final);
xi_final = measure(sigma_im_final,mu_im_final);
final=uint8(final);
h=imshow(final);
string_dummy = ['\mu=' num2str(mu_im_final) '  \sigma = ' num2str(sigma_im_final)   '  \xi = ' num2str(xi_final)];
xlabel(string_dummy);
end
c = uicontrol('Parent',f,'Style','slider','Position',[80 15 1200 20],...
              'Value',mu_id, 'min',0, 'max',255,'Callback', @surfzlim1);
txt = uicontrol('Style','text','Position',[80 35 1200 20],'String','Brightness');

function surfzlim1(source,~)
    mu_id = get(source,'Value');
[CDF_im,CDF_id]=distribution(mu_im,sigma_im,mu_id,sigma_id,x);
xi = measure(sigma_im,mu_im);
final = mapping(J,CDF_im,CDF_id);
[mu_im_final, sigma_im_final] = mean_var(final);
xi_final = measure(sigma_im_final,mu_im_final);
final=uint8(final);
h=imshow(final);
string_dummy = ['\mu=' num2str(mu_im_final) '  \sigma = ' num2str(sigma_im_final)   '  \xi = ' num2str(xi_final)];
xlabel(string_dummy);
end

btn = uicontrol('Style', 'pushbutton', 'String', 'Save',...
        'Position', [20 20 50 20],...
        'Callback', @surfzlim2);
function surfzlim2(~,~,~)
    imwrite(final,'str1.tiff');
end
end
