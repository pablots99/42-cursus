#!/bin/bash


greenColour="\e[0;32m\033[1m"
endColour="\033[0m\e[0m"
redColour="\e[0;31m\033[1m"
blueColour="\e[0;34m\033[1m"

echo -e "\n${greenColour}Minikube starting...${endColour}"

minikube --vm-driver=docker start

minikube addons enable dashboard

echo "Building Nginx"

docker build -t my_nginx ./srcs/nginx

echo "Deployment of Nginx"


kubectl create -f ./srcs/nginx/nginx.yml --validate=false

echo "Starting dashboard...."

minikube dashboard


