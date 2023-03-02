#!/bin/sh

# Exit if any command fails
set -ex

# Check whether wordpress is already setup or not
if [ ! -f $WP_PATH/wp-config.php ]
then
	# Move to /var/www/html/wordpress
	cd $WP_PATH

	# Download core files
	wp core download --allow-root

	# Create wp-config.php
	wp config create --dbname=$DB_NAME \
					--dbuser=$MARIADB_USER \
					--dbpass=$MARIADB_PWD \
					--dbhost=$DB_HOST \
					--allow-root
	
	# Create database based on wp-config.php
	wp db create

	# Create WordPress table in the database
	wp core install --url=$DOMAIN_NAME \
					--title="WordPress for Inception" \
					--admin_user=$WP_ADMIN_USER \
					--admin_password=$WP_ADMIN_PWD \
					--admin_email=$WP_ADMIN_MAIL \
					--skip-email \
					--allow-root
	
	# Create user
	wp user create $WP_USER_USER $WP_USER_MAIL \
					--role=editor \
					--user_pass=$WP_USER_PWD \
					--allow-root
	
	# Install WordPress theme
	wp theme install twentysixteen --activate

	echo "WordPress setup has done successfully."
else
	echo "Wordpress is already set up.";
fi

# Run php-fpm server as foreground process
exec "$@";
