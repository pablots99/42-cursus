FROM alpine

RUN apk update

RUN apk add nginx

RUN apk add openssl ca-certificates

RUN apk add openrc --no-cache

RUN adduser -D -g  'www' www

RUN mkdir www

COPY ./www	./www

RUN chown -R www:www /var/lib/nginx

RUN chown -R www:www /www

COPY	./nginx.conf  /etc/nginx/default.conf 

RUN mkdir /etc/nginx/ssl

RUN openssl req -x509 -nodes -newkey rsa:4096 -days 365  -out /etc/nginx/ssl/local.pem -keyout /etc/nginx/ssl/local-key.pem -subj "/C=ES/"


EXPOSE 80
EXPOSE 443 
