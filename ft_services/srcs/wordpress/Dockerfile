
FROM alpine:latest

RUN apk update
RUN apk add nginx
RUN apk add openssl ca-certificates
RUN apk add openrc --no-cache
RUN apk add openssh

RUN adduser -D -g  'www' www

RUN mkdir /www

COPY ./www	./www

RUN chown -R www:www /var/lib/nginx & chown -R www:www /www

#configuration nginx && ssl

RUN mkdir -p /run/nginx

COPY	./nginx.conf  /etc/nginx/nginx.conf 

RUN mkdir /etc/nginx/ssl

CMD nginx -g 'daemon off;'

EXPOSE 80
EXPOSE 443 
