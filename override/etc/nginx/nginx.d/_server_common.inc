# SPDX-FileCopyrightText: 2026 Daniel Wolf <nephatrine@gmail.com>
# SPDX-License-Identifier: CC0-1.0

# This should be included in most of your server blocks.

add_header X-Cache-Status $cache_status;
add_header X-Robots-Tag "noarchive" always;
add_header X-XSS-Protection "0" always;

# These will depend on your applications.
#add_header Referrer-Policy "strict-origin-when-cross-origin" always;
#add_header X-Content-Type-Options "nosniff" always;
#limit_req zone=general burst=50 nodelay;
#limit_conn addr 20;

# vim:ft=nginx
