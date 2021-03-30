FROM alpine:3.11.6

RUN apk update && apk add libc6-compat



RUN wget https://dl.grafana.com/oss/release/grafana-7.4.5.linux-amd64.tar.gz
RUN tar -zxvf grafana-7.4.5.linux-amd64.tar.gz
RUN rm -rf grafana-7.4.5.linux-amd64.tar.gz
RUN mkdir -p  /var/lib/grafana/dashboards
COPY provisioning/dashboards /var/lib/grafana/dashboards/
COPY provisioning/influx-db.yml/ grafana-7.4.5/conf/provisioning/datasources/
COPY provisioning/dashboards.yml/ /grafana-7.4.5/conf/provisioning/dashboards/

CMD cd grafana-7.4.5 && ./bin/grafana-server web > /dev/null



EXPOSE 3000