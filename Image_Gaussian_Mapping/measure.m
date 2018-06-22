function [xi]=measure(sigma,mu)
sigma_id = 41.1003;
mu_id = 128;
x=0:255;
G_im = gaussmf(x,[sigma,mu]);
G_id = gaussmf(x,[sigma_id,mu_id]);
% Implementation of Kullbak-Leibler Divergence
k=0;
e=1e-6;
for q=1:1:256
   k=k+G_im(q).*log10((G_im(q)+e)./(G_id(q)+e));
end

% Calculation of k_max for normalisation
del_white=zeros(1,length(G_im));
del_white(256) = sum(G_id);
k_max=0;
for q=1:1:256
k_max=k_max+del_white(q)*log10((del_white(q)+e)./(G_id(q)+e));
end

k_bar = k/k_max;
%final Measure as per Paper

xi = sgn(sigma-sigma_id)*(sgn(mu-mu_id)*abs(k_bar/2)+0.5);
