# SPDX-FileCopyrightText: 2026 Daniel Wolf <nephatrine@gmail.com>
# SPDX-License-Identifier: CC0-1.0

listen 443 quic;
listen 443 ssl;
listen [::]:443 quic;
listen [::]:443 ssl;

# HTTP/2
http2 on;

# HTTP/3, QUIC
http3 on;
http3_hq on;
add_header Alt-Svc 'h3=":443"; ma=86400' always;

# HSTS
add_header Strict-Transport-Security "max-age=63072000; includeSubDomains" always;

# Locations
ssl_certificate /mnt/config/ssl/live/example.net/fullchain.pem;
ssl_certificate_key /mnt/config/ssl/live/example.net/privkey.pem;
ssl_trusted_certificate /mnt/config/ssl/live/example.net/chain.pem;

# vim:ft=nginx
