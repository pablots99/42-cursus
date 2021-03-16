FROM alpine:3.11.6

RUN apk update

RUN apk add vsftpd

RUN apk add openrc --no-cache


COPY vsftpd.conf etc/vsftpd/vsftpd.conf

CMD /usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf


EXPOSE 21

