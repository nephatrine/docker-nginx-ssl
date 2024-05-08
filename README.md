<!--
SPDX-FileCopyrightText: 2018 - 2024 Daniel Wolf <nephatrine@gmail.com>

SPDX-License-Identifier: ISC
-->

[Git](https://code.nephatrine.net/NephNET/docker-nginx-ssl/src/branch/master) |
[Docker](https://hub.docker.com/r/nephatrine/nginx-ssl/) |
[unRAID](https://code.nephatrine.net/NephNET/unraid-containers)

# NGINX Reverse Proxy/Web Server

This docker container manages the NGINX application, a lightweight web server
and reverse proxy. It includes certbot/letsencrypt for easily obtaining TLS
certificates if your server is publicly accessible.

The `latest` tag points to version `1.26.0` and this is the only image actively
being updated. There are tags for older versions, but these may no longer be
using the latest Alpine version and packages.

This container is primarily intended to be used as a reverse proxy/cache to
access other containers. You can certainly serve static content, but tools like
PHP or MySQL are not included.

## Docker-Compose

This is an example docker-compose file:

```yaml
services:
  nginx:
    image: nephatrine/nginx-ssl:latest
    container_name: nginx
    environment:
      TZ: America/New_York
      PUID: 1000
      PGID: 1000
      ADMINIP: 127.0.0.1
      TRUSTSN: 192.168.0.0/16
      DNSADDR: "8.8.8.8 8.8.4.4"
      SSLEMAIL: 
      SSLDOMAINS: 
      B_MODULI: 4096
      B_RSA: 4096
      B_ECDSA: 384
    ports:
      - "80:80/tcp"
      - "443:443/tcp"
      - "443:443/udp"
    volumes:
      - /mnt/containers/nginx:/mnt/config
```

## Server Configuration

These are the configuration and data files you will likely need to be aware of
and potentially customize.

- `/mnt/config/etc/mime.type`
- `/mnt/config/etc/nginx.conf`
- `/mnt/config/etc/nginx.d/*`
- `/mnt/config/www/default/*`

Modifications to some of these may require a service restart to pull in the
changes made.
