function main_colored_HSV
clear All
close All
clc
I = imread('./data_set/4.2.03.tiff');
if size(I,3)==1
      I = gray2rgb(I);
end
HSV = rgb2hsv(I);
J = round(HSV(:,:,3).*255);
[mu_im, sigma_im] = mean_var(J);
% Desired Mean and Variance 
mu_id=128;
sigma_id=41.1003;
x = 0:255;
[CDF_im,CDF_id]=distribution(mu_im,sigma_im,mu_id,sigma_id,x);
xi = measure(sigma_im,mu_im);
final = mapping(J,CDF_im,CDF_id);
[mu_im_final, sigma_im_final] = mean_var(final);
xi_final = measure(sigma_im_final,mu_im_final);
HSV_mod = HSV;
HSV_mod(:,:,3) = final;
final = hsv2rgb(HSV_mod);
final=uint8(final);
f = figure;
subplot(121)
imshow(I);
string_dummy = ['Orig  ' '\mu=' num2str(mu_im)  '  \sigma = ' num2str(sigma_im)];
xlabel(string_dummy);
%ax = axes('Parent',f,'position',[0.13 0.39  0.77 0.54]);
subplot(122)
h = imshow(final);
string_dummy = ['\mu=' num2str(mu_im_final) '  \sigma = ' num2str(sigma_im_final)];
xlabel(string_dummy);
b = uicontrol('Parent',f,'Style','slider','Position',[120,40,1150,20],...
              'Value',sigma_id, 'min',1, 'max',255,'Callback', @surfzlim);
          txt = uicontrol('Style','text','Position',[20,40,80,20],'String','Contrast');
function surfzlim(source,~)
    sigma_id = get(source,'Value');
[CDF_im,CDF_id]=distribution(mu_im,sigma_im,mu_id,sigma_id,x);
final = mapping(J,CDF_im,CDF_id);
[mu_im_final, sigma_im_final] = mean_var(final);
xi_final = measure(sigma_im_final,mu_im_final);
HSV_mod = HSV;
HSV_mod(:,:,3) = final;
final = hsv2rgb(HSV_mod);
final=uint8(final);
h=imshow(final);
string_dummy = ['\mu=' num2str(mu_im_final) '  \sigma = ' num2str(sigma_im_final)];
xlabel(string_dummy);
end
c = uicontrol('Parent',f,'Style','slider','Position',[120 15 1150 20],...
              'Value',mu_id, 'min',1, 'max',255,'Callback', @surfzlim1);
          txt = uicontrol('Style','text','Position',[20 15 80 20],'String','Brightness');
function surfzlim1(source,~)
    mu_id = get(source,'Value');
[CDF_im,CDF_id]=distribution(mu_im,sigma_im,mu_id,sigma_id,x);
final = mapping(J,CDF_im,CDF_id);
[mu_im_final, sigma_im_final] = mean_var(final);
xi_final = measure(sigma_im_final,mu_im_final);
HSV_mod = HSV;
HSV_mod(:,:,3) = final;
final = hsv2rgb(HSV_mod);
final=uint8(final);
h=imshow(final);
string_dummy = ['\mu=' num2str(mu_im_final) '  \sigma = ' num2str(sigma_im_final)   ];
xlabel(string_dummy);
end
btn = uicontrol('Style', 'pushbutton', 'String', 'Save',...
        'Position', [20 80 50 20],...
        'Callback', @surfzlim2);
function surfzlim2(~,~,~)
    imwrite(final,'str11.tiff');
end
end
