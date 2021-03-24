mkdir /run/openrc
touch /run/openrc/softlevel
rc-status
mysql_install_db --user=mysql --datadir=/var/lib/mysql 
cp my.cnf /etc/my.cnf
/etc/init.d/mariadb setup 
/etc/init.d/mariadb start 
mariadb -u root  < wp.sql 
top
