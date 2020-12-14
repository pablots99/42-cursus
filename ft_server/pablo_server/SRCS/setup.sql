create database demo;
create user demouser@localhost identified by '1084';
grant all privileges on kifarunixdemo.* to demouser@localhost;
flush privileges;
quit