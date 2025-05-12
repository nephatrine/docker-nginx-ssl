<!--
SPDX-FileCopyrightText: 2018-2025 Daniel Wolf <nephatrine@gmail.com>
SPDX-License-Identifier: ISC
-->

# NGINX Reverse Proxy

[![NephCode](https://img.shields.io/static/v1?label=Git&message=NephCode&color=teal)](https://code.nephatrine.net/NephNET/docker-nginx-ssl)
[![GitHub](https://img.shields.io/static/v1?label=Git&message=GitHub&color=teal)](https://github.com/nephatrine/docker-nginx-ssl)
[![Registry](https://img.shields.io/static/v1?label=OCI&message=NephCode&color=blue)](https://code.nephatrine.net/NephNET/-/packages/container/nginx-ssl/latest)
[![DockerHub](https://img.shields.io/static/v1?label=OCI&message=DockerHub&color=blue)](https://hub.docker.com/repository/docker/nephatrine/nginx-ssl/general)
[![unRAID](https://img.shields.io/static/v1?label=unRAID&message=template&color=orange)](https://code.nephatrine.net/NephNET/unraid-containers)

This is an Alpine-based container hosting NGINX to act as a reverse proxy
allowing access to other containerized web applications and centralizing SSL
configuration. You can also serve simple HTML websites with it, of course. It
includes certbot/letsencrypt to handle SSL certificates and renewal.

## Supported Tags

- `nginx-ssl:1.27.5`: NGINX 1.27.5

## Software

- [Alpine Linux](https://alpinelinux.org/)
- [Skarnet S6](https://skarnet.org/software/s6/)
- [s6-overlay](https://github.com/just-containers/s6-overlay)
- [NGINX](https://nginx.org/)
- [Certbot](https://certbot.eff.org/)

## Configuration

These are the configuration and data files you will likely need to be aware of
and potentially customize.

- `/mnt/config/etc/mime.type`
- `/mnt/config/etc/nginx.conf`
- `/mnt/config/etc/nginx.d/*`
- `/mnt/config/www/default/*`

Modifications to some of these may require a service restart to pull in the
changes made.

### Container Variables

- `TZ`: Time Zone (i.e. `America/New_York`)
- `PUID`: Mounted File Owner User ID
- `PGID`: Mounted File Owner Group ID
- `ADMINIP`: Administrator IP
- `TRUSTSN`: Trusted Subnet (i.e. `192.168.0.0/16`)
- `DNSADDR`: DNS Servers (i.e. `8.8.8.8 8.8.4.4`)
- `SSLEMAIL`: LetsEncrypt Email
- `SSLDOMAINS`: LetsEncrypt Domains
- `B_MODULI`: `dhparam.pem` Key Sizes
- `B_RSA`: RSA SSL Key Size
- `B_ECDSA`: Use ECDSA SSL Keys (0 for RSA)

## Testing

### docker-compose

```yaml
services:
  nginx-ssl:
    image: nephatrine/nginx-ssl:latest
    container_name: nginx-ssl
    environment:
      TZ: America/New_York
      PUID: 1000
      PGID: 1000
    ports:
      - "80:80/tcp"
      - "443:443/tcp"
      - "443:443/udp"
    volumes:
      - /mnt/containers/nginx-ssl:/mnt/config
```

### docker run

```bash
docker run --rm -ti code.nephatrine.net/nephnet/nginx-ssl:latest /bin/bash
```
