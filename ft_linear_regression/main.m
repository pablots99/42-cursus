


%%main(89000, 5000, [0 0 ]', 0.01)


function price = main(km,iter,theta,alpha)
 
data = dlmread ("data.csv",",",1,0);
s  = size(data);

X =  data(:,1);
X1 = X;
[X mu sigma] = featureNormalize(X);

X= [ones(s(1),1)  X];
X1= [ones(s(1),1)  X1];

y = data(:,2);

m=s(1);

for  i = 1:iter
  theta -=  alpha *( 1/m * X' * ((X*theta) - y));
  J_history(i) = (1 / (2 *m) ) * sum(((X * theta)-y) .^2);
end

theta1 = (pinv(X1'*X1))*X1'*y
theta2 = (pinv(X'*X))*X'*y
theta 

figure(1); plot(J_history)
figure(2);
plot(data(:,1),data(:,2),'+')
hold on;

a = [3000; 80000; 250000];
[X mu sigma] = featureNormalize(a);
prize = theta(1) + theta(2)  *X
plot(a,prize,'-')

end