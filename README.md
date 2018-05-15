[GitHub](https://github.com/nephatrine/docker-nginx-ssl) |
[DockerHub](https://hub.docker.com/r/nephatrine/nginx-ssl/) |
[unRAID](https://github.com/nephatrine/unraid-docker-templates)

# NGINX+SSL (Certbot/LetsEncrypt) Docker

This docker is intended to be used as a forwarding proxy to access other dockers. You can certainly
serve static content, but tools like PHP or MySQL are not included.

Certbot is installed and can request SSL certificats from LetsEncrypt on your behalf assuming you
have entered the appropriate values. DNS challenges are not supported until I can come up with a
good way to automate it. Unfortunately, that means wildcard certificates cannot be requested at
this time.

## Settings

- **ADMINIP:** Administrative Access IP
- **DNSADDR:** Resolver IPs (Space-Delimited)
- **PUID:** Volume Owner UID
- **PGID:** Volume Owner GID
- **SSLEMAIL:** LetsEncrypt Email Address
- **SSLDOMAINS:** LetsEncrypt (Sub)domains (comma-delimited)
- **TZ:** Time Zone

## Mount Points

- **/mnt/config:** Configuration Volume