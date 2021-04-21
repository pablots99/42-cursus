FROM alpine:3.11.6


RUN apk update && apk add influxdb  libc6-compat

RUN cd etc && mkdir telegraf && cd ..

COPY telegraf.conf etc/telegraf/



RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.0_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.0_linux_amd64.tar.gz
RUN rm -rf telegraf-1.18.0_linux_amd64.tar.gz
EXPOSE 8086


CMD cd /telegraf-1.18.0/usr && ./bin/telegraf & influxd run -config /etc/influxdb.conf 