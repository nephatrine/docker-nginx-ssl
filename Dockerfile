FROM nephatrine/nxbuilder:alpine AS builder

RUN echo "====== INSTALL LIBRARIES ======" \
 && apk add --no-cache gd-dev geoip-dev libatomic_ops-dev libxslt-dev pcre-dev

ARG NGINX_VERSION=release-1.25.2
RUN git -C /root clone -b "$NGINX_VERSION" --single-branch --depth=1 https://github.com/nginx/nginx.git

RUN echo "====== COMPILE NGINX ======" \
 && cd /root/nginx \
 && ./auto/configure \
  --prefix=/var/www \
  --sbin-path=/usr/sbin/nginx \
  --modules-path=/usr/lib/nginx/modules \
  --conf-path=/etc/nginx/nginx.conf \
  --error-log-path=/var/log/nginx/error.log \
  --pid-path=/var/run/nginx.pid \
  --lock-path=/var/run/nginx.lock \
  --user=guardian \
  --group=users \
  --with-threads \
  --with-file-aio \
  --with-http_ssl_module \
  --with-http_v2_module \
  --with-http_v3_module \
  --with-http_realip_module \
  --with-http_addition_module \
  --with-http_xslt_module=dynamic \
  --with-http_image_filter_module=dynamic \
  --with-http_geoip_module=dynamic \
  --with-http_sub_module \
  --with-http_dav_module \
  --with-http_mp4_module \
  --with-http_gunzip_module \
  --with-http_gzip_static_module \
  --with-http_auth_request_module \
  --with-http_random_index_module \
  --with-http_secure_link_module \
  --with-http_slice_module \
  --http-log-path=/var/log/nginx/access.log \
  --http-client-body-temp-path=/var/cache/nginx/client_body \
  --http-proxy-temp-path=/var/cache/nginx/proxy \
  --http-fastcgi-temp-path=/var/cache/nginx/fastcgi \
  --http-uwsgi-temp-path=/var/cache/nginx/uwsgi \
  --http-scgi-temp-path=/var/cache/nginx/scgi \
  --with-mail=dynamic \
  --with-mail_ssl_module \
  --with-stream=dynamic \
  --with-stream_ssl_module \
  --with-stream_realip_module \
  --with-stream_geoip_module=dynamic \
  --with-stream_ssl_preread_module \
  --with-compat \
  --with-pcre \
  --with-pcre-jit \
  --with-libatomic \
 && make -j$(( $(getconf _NPROCESSORS_ONLN) / 2 + 1 )) \
 && make -j$(( $(getconf _NPROCESSORS_ONLN) / 2 + 1 )) install

FROM nephatrine/alpine-s6:latest
LABEL maintainer="Daniel Wolf <nephatrine@gmail.com>"

RUN echo "====== INSTALL PACKAGES ======" \
 && if [ "$(uname -m)" = "riscv64" ]; then apk add --no-cache certbot geoip libgd libxslt pcre pipx \
  && pipx install zope.component; else apk add --no-cache certbot geoip libgd libxslt pcre py3-pip \
  && pip3 install zope.component; fi \
 && mkdir -p /etc/nginx /usr/lib/nginx /var/cache/nginx /var/log/nginx /var/www

COPY --from=builder /etc/nginx/ /etc/nginx/
COPY --from=builder /usr/lib/nginx/ /usr/lib/nginx/
COPY --from=builder /usr/sbin/nginx /usr/sbin/
COPY --from=builder /var/www/ /var/www/
COPY override /

EXPOSE 80/tcp 443/tcp 443/udp
