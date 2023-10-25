# SPDX-FileCopyrightText: 2018 - 2023 Daniel Wolf <nephatrine@gmail.com>
#
# SPDX-License-Identifier: ISC

#NOSSL:listen 80;
#NOSSL:listen [::]:80;
#SSL:listen 443 quic;
#SSL:listen 443 ssl;
#SSL:listen [::]:443 quic;
#SSL:listen [::]:443 ssl;

#SSL:http2 on;
#SSL:http3 on;

#SSL:ssl_certificate /mnt/config/ssl/live/example.net/fullchain.pem;
#SSL:ssl_certificate_key /mnt/config/ssl/live/example.net/privkey.pem;
#SSL:ssl_trusted_certificate /mnt/config/ssl/live/example.net/chain.pem;
#SSL:add_header Strict-Transport-Security "max-age=63072000; includeSubDomains; preload";
#SSL:add_header Alt-Svc 'h3=":$server_port"; ma=86400';
add_header X-Cache-Status $cache_status;

proxy_set_header Host $host;
proxy_set_header X-Real-IP $remote_addr;
proxy_set_header X-Forwarded-Host $host:$server_port;
proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
proxy_set_header X-Forwarded-Port $server_port;
proxy_set_header X-Forwarded-Proto $scheme;