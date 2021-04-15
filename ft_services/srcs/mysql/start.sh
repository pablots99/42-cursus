rc-status
/etc/init.d/mariadb setup 
/etc/init.d/mariadb start 
mariadb -u root  < wp.sql 
while true; do sleep 30; done;

