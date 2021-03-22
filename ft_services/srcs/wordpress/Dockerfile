FROM alpine:3.11.6

RUN apk update
RUN apk add nginx
RUN apk add openssl ca-certificates
RUN apk add php7 php7-fpm php7-opcache
RUN apk add php7-gd php7-mysqli php7-zlib php7-curl
RUN adduser -D -g  'www' www


RUN mkdir /www


#configuration nginx
RUN mkdir -p /run/nginx

COPY	./nginx.conf  /etc/nginx/nginx.conf 

#configuration wordpress
RUN wget https://wordpress.org/latest.tar.gz

RUN tar xvf latest.tar.gz && rm -rf latest.tar.gz

RUN mv wordpress*/ /www/


COPY wp-config.php www/wordpress

RUN chown -R www:www /var/lib/nginx & chown -R www:www /www/wordpress

CMD nginx -g 'daemon off;'

EXPOSE 5050
