FROM debian:buster

RUN apt-get update

RUN apt-get upgrade -y

RUN apt-get install -y nginx

RUN apt-get install -y mariadb-server mariadb-client

RUN apt-get install -y php php-fpm php-mysql

RUN apt-get install -y php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip

RUN apt-get install -y wget

RUN apt-get install -y openssl ca-certificates

RUN apt-get install -y openssl


# mysql

COPY ./srcs/setup.sql ./

RUN service mysql start && mysql -u root  mysql < setup.sql


# nginx

RUN mkdir /var/www/php

RUN touch index.php && echo "<?php	phpinfo(); ?>" > /var/www/php/index.php

COPY ./srcs/nginx_auto_on ./


COPY ./srcs/autoindex.sh ./

COPY ./srcs/nginx_auto_off ./

RUN touch /etc/nginx/sites-available/nginx_config && cat nginx_auto_on > /etc/nginx/sites-available/nginx_config

RUN ln -s /etc/nginx/sites-available/nginx_config /etc/nginx/sites-enabled/

# phpmyadmin


RUN wget  https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz

RUN tar xvf phpMyAdmin-latest-all-languages.tar.gz

RUN rm -rf phpMyAdmin-latest-all-languages.tar.gz

RUN mv phpMyAdmin-*/ /var/www/phpmyadmin

RUN chown -R www-data:www-data /var/www/phpmyadmin

COPY ./srcs/config.inc.php  /var/www/phpmyadmin


# php star

RUN /etc/init.d/php7.3-fpm start

# ssl

RUN mkdir /etc/nginx/ssl

RUN openssl req -x509 -nodes -newkey rsa:4096 -days 365  -out /etc/nginx/ssl/local.pem -keyout /etc/nginx/ssl/local-key.pem -subj "/C=ES/"


# workpress

RUN wget https://wordpress.org/latest.tar.gz

RUN tar xvf latest.tar.gz && rm -rf latest.tar.gz

RUN mv wordpress*/ /var/www/wordpress

RUN chown -R www-data:www-data /var/www/wordpress

COPY ./srcs/wp-config.php /var/www/wordpress

#start

COPY ./srcs/startserv.sh ./

CMD bash startserv.sh 







