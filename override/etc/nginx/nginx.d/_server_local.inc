# SPDX-FileCopyrightText: 2018-2025 Daniel Wolf <nephatrine@gmail.com>
# SPDX-License-Identifier: CC0-1.0

#NOSSL:listen 80 reuseport;
#NOSSL:listen [::]:80 reuseport;
#SSL:listen 443 quic reuseport;
#SSL:listen 443 ssl reuseport;
#SSL:listen [::]:443 quic reuseport;
#SSL:listen [::]:443 ssl reuseport;

#SSL:http2 on;
#SSL:http3 on;
#SSL:http3_hq on;

#SSL:ssl_certificate /mnt/config/ssl/live/example.net/fullchain.pem;
#SSL:ssl_certificate_key /mnt/config/ssl/live/example.net/privkey.pem;
#SSL:ssl_trusted_certificate /mnt/config/ssl/live/example.net/chain.pem;
#SSL:add_header Strict-Transport-Security "max-age=63072000; includeSubDomains; preload";
#SSL:add_header Alt-Svc 'h3=":$server_port"; ma=86400';
add_header X-Cache-Status $cache_status;

autoindex off;
add_header X-Content-Type-Options nosniff;
add_header X-Frame-Options SAMEORIGIN;
add_header X-Robots-Tag noarchive;
add_header X-XSS-Protection "1; mode=block";
expires $expires;

set_real_ip_from 192.168.0.0/16;
real_ip_header X-Real-IP;
real_ip_recursive on;

location ~ /\. {
	deny all;
}