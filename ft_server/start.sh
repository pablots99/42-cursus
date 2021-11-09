#|/bin/bash

docker build -t wp .
docker run -p 80:80 -p 443:443 wp
