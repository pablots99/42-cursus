FROM alpine:3.11.6

RUN apk update

RUN apk add mysql mysql-client

RUN apk add openrc

COPY wp.sql ./



#CMD mysql -u root  mysql < wp.sql

EXPOSE 3306