FROM alpine:3.11.6

RUN apk update

RUN apk add  mariadb mariadb-client openrc

COPY wp.sql ./

COPY my.cnf /etc/

RUN mkdir /run/openrc && touch /run/openrc/softlevel

#RUN rc-status

#RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql 

RUN rc-status && /etc/init.d/mariadb setup 
RUN  rc-status && /etc/init.d/mariadb start && mariadb -u root  < wp.sql
CMD  while true; do sleep 30; done;

EXPOSE 3306