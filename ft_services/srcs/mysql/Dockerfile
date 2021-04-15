FROM alpine:3.11.6

RUN apk update

RUN apk add  mariadb mariadb-client openrc

COPY wp.sql ./

COPY start.sh ./

COPY  my.cnf /etc/my.cnf


RUN mkdir /run/openrc && touch /run/openrc/softlevel


CMD  sh start.sh

EXPOSE 3306