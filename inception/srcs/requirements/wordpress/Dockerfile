FROM debian:buster

RUN apt update -y && apt upgrade -y && apt install mariadb-server -y

RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz

RUN chown -R root:root /var/www/wordpress