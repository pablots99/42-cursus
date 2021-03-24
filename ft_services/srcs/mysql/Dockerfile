FROM alpine:3.11.6

RUN apk update

RUN apk add mariadb  mariadb-common mariadb-client

RUN apk add openrc


COPY wp.sql ./

COPY my.cnf ./

COPY start.sh ./

CMD sh start.sh

EXPOSE 3306