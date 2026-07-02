# SPDX-FileCopyrightText: 2026 Daniel Wolf <nephatrine@gmail.com>
# SPDX-License-Identifier: CC0-1.0

# This should be included in server blocks with local location blocks.

autoindex off;

location ~ /\. {
        deny all;
}

# vim:ft=nginx
