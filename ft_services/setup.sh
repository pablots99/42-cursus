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


echo "\n${Green}Deleting previous minikube...${endColour}"
#delete previous minikube
minikube stop
minikube delete
rm -rf ~/.minikube

#start minikube

echo "\n${Green}Minikube starting...${endColour}"
minikube start --cpus=2 --disk-size 20000 --vm-driver virtualbox 
minikube addons enable metrics-server
minikube addons enable dashboard
minikube addons enable metallb


eval $(minikube docker-env)


echo "\n${Green}Installing metalLB...${endColour}"
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

#building docker images
echo "${Green}Building Docker images${endColour}"
docker build -t my_nginx ./srcs/nginx --network host 
docker build -t my_ftps  ./srcs/ftps  --network host 
docker build -t my_wordpress  ./srcs/wordpress  --network host
docker build -t my_mysql  ./srcs/mysql   --network host 
docker build -t my_phpmyadmin  ./srcs/phpMyAdmin   --network host 
docker build -t my_grafana  ./srcs/grafana   --network host 
docker build -t my_influxdb  ./srcs/influxdb   --network host 







#Deployment and Services
echo "${Green}Minikube Deployment and Services${endColour}"
kubectl apply -f srcs/nginx/nginx.yml
kubectl apply -f srcs/ftps/ftps.yml
kubectl apply -f srcs/wordpress/wordpress.yml
kubectl apply -f srcs/mysql/mysql.yml
kubectl apply -f srcs/phpMyAdmin/phpmyadmin.yml
#kubectl apply -f srcs/influxdb/influxdb-secrets.yml
kubectl apply -f srcs/grafana/grafana.yml

kubectl apply -f srcs/influxdb/influxdb.yml


kubectl apply -f srcs/loadbalancer/metallb-config.yml
kubectl apply -f srcs/loadbalancer/service.yml


#configuration file load balancer 


#open k8s dashboard
echo "\n${Green}Starting dashboard....${endColour}"
#minikube dashboard

