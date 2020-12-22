if  grep -q "autoindex on" /etc/nginx/sites-available/nginx_config; then
    echo "\e[31m autoindex turned OFF \e[0m"
    cat nginx_auto_off > /etc/nginx/sites-available/nginx_config
else 
    echo "\e[32m autoindex turned ON \e[0m"
   cat nginx_auto_on > /etc/nginx/sites-available/nginx_config
fi
service nginx restart