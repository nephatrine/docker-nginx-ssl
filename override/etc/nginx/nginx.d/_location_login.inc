# SPDX-FileCopyrightText: 2026 Daniel Wolf <nephatrine@gmail.com>
# SPDX-License-Identifier: CC0-1.0

# This should be included in sensitive location blocks.

limit_req zone=login burst=5 nodelay;

# vim:ft=nginx
