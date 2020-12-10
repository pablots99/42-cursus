FROM debian:buster


RUN apt-get update

RUN apt-get upgrade -y

RUN apt-get install -y nginx

RUN apt-get install -y mariadb-server mariadb-client

RUN apt-get install -y php php-fpm php-mysql

COPY ./SRCS/startserv.sh ./

COPY ./SRCS/nginx.config /etc/nginx/sites-available/localhost

CMD bash startserv.sh


