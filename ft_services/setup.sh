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




#start minikube
echo "\n${Green}Minikube starting...${endColour}"
minikube --vm-driver=docker start
minikube addons enable dashboard
minikube addons enable metallb



#metalLB instalation
echo "\n${Green}Installing metalLB...${endColour}"
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

#configuration file load balancer 
kubectl apply -f srcs/metalLB.yml

#link local docker images with minikube
eval $(minikube docker-env)

#building docker images
echo "${Green}Building images${endColour}"
docker build -t my_nginx ./srcs/nginx

#Deployment and Services
echo "${Green}Minikube Deployment and Services${endColour}"
kubectl apply -f ./srcs/nginx/nginx.yml


#open k8s dashboard
echo "\n${Green}Starting dashboard....${endColour}"
#minikube dashboard



