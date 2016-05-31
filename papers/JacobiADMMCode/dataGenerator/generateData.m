% create randn matrix for LASSO problem
clc;clear;
clc;clear;
seed = 2012;
addpath('l1testpack');
fprintf('Seed = %d\n',seed);
RandStream.setGlobalStream(RandStream('mt19937ar','seed',seed));


%% generate random matrix data
n = 1024; % solution length
m = 300;  % number of measurements
k = 60;   % sparsity

sigma = 0*1e-3;
A = randn(m,n);
xs = zeros(n,1); % ground truth
p = randperm(n);
xs(p(1:k)) = randn(k,1);
b = A*xs + sigma*randn(m,1);

mkdir Gaussian;
idx = [1 2 4 8 16 32 64];
for i = 1:7;
    nBlock = idx(i);
    mkdir('Gaussian',num2str(nBlock));
    for i=1:nBlock
        str1 = strcat(['Gaussian/',num2str(nBlock),'/A', num2str(i), '.dat']);
        str2 = strcat(['Gaussian/',num2str(nBlock),'/xs', num2str(i), '.dat']);
        mmwrite(str1,A( :,(i-1)*n/nBlock+1: i*n/nBlock));
        mmwrite(str2,xs((i-1)*n/nBlock+1: i*n/nBlock,:));
    end
    str3 = strcat(['Gaussian/',num2str(nBlock),'/b.dat']);
    mmwrite(str3, b);
end


