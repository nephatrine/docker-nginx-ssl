[Git Repo](https://code.nephatrine.net/nephatrine/docker-nginx-ssl) |
[DockerHub](https://hub.docker.com/r/nephatrine/nginx-ssl/) |
[unRAID Template](https://github.com/nephatrine/unraid-docker-templates)

# NGINX Application Container

This docker container manages the NGINX application, a lightweight web server and reverse proxy.

- [docker-base-alpine](https://code.nephatrine.net/nephatrine/docker-base-alpine)
- [CertBot](https://certbot.eff.org/)
- [NGINX](https://www.nginx.com/)

## Configuration

- ``{config}/etc/crontab``: Crontab Entries
- ``{config}/etc/logrotate.conf``: Logrotate General Configuration
- ``{config}/etc/logrotate.d/*``: Logrotate Per-Application Configuration
- ``{config}/etc/mime.types``: NGINX MIME Types
- ``{config}/etc/nginx.conf``: NGINX General Configuration
- ``{config}/etc/nginx.d/*``: NGINX Per-Site Configuration
- ``{config}/ssl/live/{site}/``: SSL/TLS certificates

This container is primarily intended to be used as a reverse proxy/cache to access other dockers. You can certainly serve static content, but tools like PHP or MySQL are not included.

Certbot is installed and can request SSL certificats from LetsEncrypt on your behalf assuming you have entered the appropriate values. DNS challenges are not supported until I can come up with a good way to automate it. Unfortunately, that means wildcard certificates cannot be requested at this time.

**NOTE:** If you have trouble connecting from an older device or browser when using HTTPS, you may need to change the ciphers allowed in ``{config}/etc/nginx.d/_ssl.inc`` to be more permissive.

## Ports

- **80/tcp:** HTTP Port
- **443/tcp:** HTTPS Port

## Variables

- **PUID:** Owner UID (*1000*)
- **PGID:** Owner GID (*100*)
- **TZ:** Time Zone (*"America/New_York"*)

- **DNSADDR:** Resolver IPs ("8.8.8.8 8.8.4.4") (IGNORED AFTER INITIAL RUN) (SPACE-DELIMITED)

- **ADMINIP**: Administrator IP ("127.0.0.1") (IGNORED AFTER INITIAL RUN)
- **TRUSTSN:** Trusted Subnet ("192.168.0.0/16") (IGNORED AFTER INITIAL RUN)

- **SSLEMAIL:** LetsEncrypt Email ("")
- **SSLDOMAINS:** LetsEncrypt Domains ("") (COMMA-DELIMITED)

## Mount Points

- **/mnt/config:** Configuration/Logs