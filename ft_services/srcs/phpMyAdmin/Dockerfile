FROM alpine:3.11.6

RUN apk update
RUN apk add nginx
RUN apk add openssl ca-certificates
RUN apk add php7 php7-fpm php7-opcache
RUN apk add php7-gd php7-mysqli php7-zlib php7-curl php7-json php7-ctype php7-iconv php7-xml  php7-mbstring php7-gettext php7-session
RUN adduser -D -g  'www' www
RUN mkdir /www

#configuration nginx

RUN mkdir -p /run/nginx

COPY	./nginx.conf  /etc/nginx/nginx.conf 

RUN mkdir /etc/nginx/ssl

RUN openssl req -x509 -nodes -newkey rsa:4096 -days 365  -out /etc/nginx/ssl/local.pem -keyout /etc/nginx/ssl/local-key.pem -subj '/CN=localhost'

RUN wget  https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz

RUN tar xvf phpMyAdmin-latest-all-languages.tar.gz

RUN rm -rf phpMyAdmin-latest-all-languages.tar.gz

RUN mv phpMyAdmin-*/ /www/phpmyadmin

RUN chown -R www:www /www/phpmyadmin

COPY config.inc.php  /www/phpmyadmin



CMD php-fpm7 -R && nginx -g 'daemon off;'

EXPOSE 5000