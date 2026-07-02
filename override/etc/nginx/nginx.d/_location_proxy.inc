# SPDX-FileCopyrightText: 2026 Daniel Wolf <nephatrine@gmail.com>
# SPDX-License-Identifier: CC0-1.0

# This should be included in proxied location blocks.

proxy_set_header Host $host;
proxy_set_header X-Real-IP $remote_addr;
#proxy_set_header X-Forwarded-Host $host;
proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
#proxy_set_header X-Forwarded-Port $server_port;
proxy_set_header X-Forwarded-Proto $scheme;

proxy_no_cache $no_cache;
proxy_cache_bypass $no_cache;

expires off;

# vim:ft=nginx
