CREATE DATABASE wordpress;
CREATE USER 'ptorres'@'%' IDENTIFIED BY 'ptorres';
GRANT ALL PRIVILEGES ON wordpress.* TO 'ptorres'@'%';
FLUSH PRIVILEGES;

