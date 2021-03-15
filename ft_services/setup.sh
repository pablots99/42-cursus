#!/bin/bash

Black='\033[0;30m'        
Red='\033[0;31m'         
Green='\033[0;32m'      
Yellow='\033[0;33m'    
Blue='\033[0;34m'     
Purple='\033[0;35m'
Cyan='\033[0;36m'
White='\033[0;37m'
endColour='\033[0m'

<<<<<<< HEAD

echo "\n${Green}Deleting previous minikube...${endColour}"
#delete previous minikube
minikube stop
minikube delete
rm -rf ~/.minikube

#start minikube

echo "\n${Green}Minikube starting...${endColour}"
minikube start --cpus=2 --disk-size 11000 --vm-driver virtualbox 
minikube addons enable metrics-server
=======
#delete previous minikube
echo "\n${Green}Deleting previous minikube...${endColour}"
#minikube stop
minikube delete
rm -rf ~/.minikube


#start minikube
echo "\n${Green}Starting Minikube...${endColour}"
minikube start 
>>>>>>> e3c6c445707464786619b696469b758e7fd9e7f5
minikube addons enable dashboard
minikube addons enable metallb

#metalLB instalation && preparation 
#kubectl get configmap kube-proxy -n kube-system -o yaml | \
#sed -e "s/strictARP: false/strictARP: true/" | \
#kubectl apply -f - -n kube-system

eval $(minikube docker-env)

<<<<<<< HEAD
=======
eval $(minikube -p minikube docker-env)

#metalLB instalation && preparation 
# kubectl get configmap kube-proxy -n kube-system -o yaml | \
# sed -e "s/strictARP: false/strictARP: true/" | \
# kubectl apply -f - -n kube-system

>>>>>>> e3c6c445707464786619b696469b758e7fd9e7f5

echo "\n${Green}Installing metalLB...${endColour}"
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
kubectl apply -f srcs/loadbalancer/metallb-config.yml
kubectl apply -f srcs/loadbalancer/service.yml

#building docker images
echo "${Green}Building Docker images${endColour}"
docker build -t my_nginx ./srcs/nginx --network host



#Deployment and Services
echo "${Green}Minikube Deployment and Services${endColour}"
kubectl apply -f srcs/nginx/nginx.yml
kubectl apply -f srcs/loadbalancer/metallb-config.yml


<<<<<<< HEAD
#configuration file load balancer 
#kubectl apply -f srcs/loadbalancer/service.yml

=======
>>>>>>> e3c6c445707464786619b696469b758e7fd9e7f5

#open k8s dashboard
echo "\n${Green}Starting dashboard....${endColour}"
#minikube dashboard

