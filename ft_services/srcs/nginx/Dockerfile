FROM alpine

RUN apk update

RUN apk add nginx

RUN apk add openrc

RUN adduser -D -g  'www' www

RUN mkdir /www

RUN chown -R www:www /var/lib/nginx

RUN chown -R www:www /www

COPY	./nginx.conf  /etc/nginx/nginx.conf 


RUN mkdir -p /run/nginx

