FROM debian:buster


RUN apt-get update

RUN apt-get upgrade -y

RUN apt-get install -y nginx

RUN apt-get install -y mariadb-server mariadb-client

RUN apt-get install -y php php-fpm php-mysql

RUN apt-get install -y php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip

RUN apt-get install -y vim

COPY ./SRCS/startserv.sh ./

COPY ./SRCS/nginx_config /etc/nginx/sites-available/server

RUN ln -s /etc/nginx/sites-available/server /etc/nginx/sites-enabled/

COPY ./SRCS/setup.sql	./

CMD bash startserv.sh

CMD mysql -u root -p 






