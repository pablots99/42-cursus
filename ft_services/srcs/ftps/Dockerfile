FROM alpine:3.11.6

RUN apk update
RUN apk add vsftpd
RUN apk add openssl
RUN apk add shadow

RUN printf 'ptorres\n' > /etc/vsftpd.chroot_list

RUN mkdir - /home/ptorres
RUN useradd -p $(openssl passwd -1 1234) ptorres
RUN chown ptorres:ptorres /home/ptorres

RUN echo "welcome to ptorres ftp" >  /home/ptorres/welcome.txt
RUN chown -R ptorres  /home/ptorres/welcome.txt

COPY ./start.sh ./
COPY vsftpd.conf etc/vsftpd/vsftpd.conf

RUN openssl req -x509 -nodes -newkey rsa:4096 -days 365  -out /etc/ssl/local.pem -keyout /etc/ssl/local-key.pem -subj '/CN=localhost'

CMD sh start.sh

EXPOSE 20
EXPOSE 21
EXPOSE 2020

