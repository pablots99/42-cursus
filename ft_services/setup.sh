#!/bin/bash

Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m' 
endColour='\033[0m'

echo "\n${Green}Minikube starting...${endColour}"

minikube --vm-driver=docker start

minikube addons enable dashboard

echo "Building Nginx"

docker build -t my_nginx ./srcs/nginx

echo "Deployment of Nginx"


kubectl create -f ./srcs/nginx/nginx.yml --validate=false

echo "Starting dashboard...."

minikube dashboard


