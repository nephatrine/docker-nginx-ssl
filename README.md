[Git](https://code.nephatrine.net/nephatrine/docker-nginx-ssl) |
[Docker](https://hub.docker.com/r/nephatrine/nginx-ssl/) |
[unRAID](https://code.nephatrine.net/nephatrine/unraid-containers)

[![Build Status](https://ci.nephatrine.net/api/badges/nephatrine/docker-nginx-ssl/status.svg?ref=refs/heads/master)](https://ci.nephatrine.net/nephatrine/docker-nginx-ssl)

# NGINX HTTP(S) Server/Proxy

This docker container manages the NGINX application, a lightweight web server
and reverse proxy.

- [CertBot](https://certbot.eff.org/)
- [NGINX](https://www.nginx.com/)

You can spin up a quick temporary test container like this:

~~~
docker run --rm -p 80:80 -it nephatrine/nginx-ssl:latest /bin/bash
~~~

This container is primarily intended to be used as a reverse proxy/cache to
access other containers. You can certainly serve static content, but tools like
PHP or MySQL are not included.

## Docker Tags

- **nephatrine/nginx-ssl:testing**: NGINX Master
- **nephatrine/nginx-ssl:latest**: NGINX Default
- **nephatrine/nginx-ssl:mainline**: NGINX Default
- **nephatrine/nginx-ssl:stable**: NGINX 1.20
- **nephatrine/nginx-ssl:1.20**: NGINX 1.20

## Configuration Variables

You can set these parameters using the syntax ``-e "VARNAME=VALUE"`` on your
``docker run`` command. Some of these may only be used during initial
configuration and further changes may need to be made in the generated
configuration files.

- ``ADMINIP``: Administrator IP (*127.0.0.1*) (INITIAL CONFIG)
- ``B_MODULI``: Default DH Params Size (*4096*)
- ``B_RSA``: Default RSA Key Size (*4096*)
- ``B_ECDSA``: Default ECDSA Key Size (*384*)
- ``DNSADDR``: Resolver IPs (*8.8.8.8 8.8.4.4*) (INITIAL CONFIG)
- ``PUID``: Mount Owner UID (*1000*)
- ``PGID``: Mount Owner GID (*100*)
- ``SSLEMAIL``: LetsEncrypt Email (**)
- ``SSLDOMAINS``: LetsEncrypt Domains (**) (COMMA-DELIMITED)
- ``TRUSTSN``: Trusted Subnet (*192.168.0.0/16*) (INITIAL CONFIG)
- ``TZ``: System Timezone (*America/New_York*)

## Persistent Mounts

You can provide a persistent mountpoint using the ``-v /host/path:/container/path``
syntax. These mountpoints are intended to house important configuration files,
logs, and application state (e.g. databases) so they are not lost on image
update.

- ``/mnt/config``: Persistent Data.

Do not share ``/mnt/config`` volumes between multiple containers as they may
interfere with the operation of one another.

You can perform some basic configuration of the container using the files and
directories listed below.

- ``/mnt/config/etc/crontabs/<user>``: User Crontabs.
- ``/mnt/config/etc/logrotate.conf``: Logrotate Global Configuration.
- ``/mnt/config/etc/logrotate.d/``: Logrotate Additional Configuration.
- ``/mnt/config/etc/mime.type``: NGINX MIME Types.
- ``/mnt/config/etc/nginx.conf``: NGINX Configuration.
- ``/mnt/config/etc/nginx.d/``: NGINX Configuration.
- ``/mnt/config/www/default/``: Default HTML Location.

**[*] Changes to some configuration files may require service restart to take
immediate effect.**

## Network Services

This container runs network services that are intended to be exposed outside
the container. You can map these to host ports using the ``-p HOST:CONTAINER``
or ``-p HOST:CONTAINER/PROTOCOL`` syntax.

- ``80/tcp``: HTTP Server. This is the default insecure web server.
- ``443/tcp``: HTTPS Server. This is the optional secured web server.
