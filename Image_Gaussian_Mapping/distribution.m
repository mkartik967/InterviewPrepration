function [CDF_im,CDF_id] = distribution (mu_im,sigma_im,mu_id,sigma_id,x)

% Gaussian Probability density for Both Ideal and given case
G_im = gaussmf(x,[sigma_im,mu_im]);
G_id = gaussmf(x,[sigma_id,mu_id]);

temp = G_id / sum( G_id );
CDF_id( 1 ) = temp( 1 );
for i = 2:length( temp )
CDF_id( i ) = CDF_id( i - 1 ) + temp( i );
end 

temp = G_im / sum( G_im );
CDF_im( 1 ) = temp( 1 );
for i = 2:length( temp )
CDF_im( i ) = CDF_im( i - 1 ) + temp( i );
end 
end
