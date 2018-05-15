map $remote_addr $cache_status {
	127.0.0.1 $upstream_cache_status;
	default "";
}

log_format rt_cache '$remote_addr - $upstream_cache_status [$time_local]  '
	'"$request" $status $body_bytes_sent '
	'"$http_referer" "$http_user_agent"';
access_log /mnt/config/log/nginx-access.log rt_cache;

proxy_cache_path /mnt/config/cache levels=1:2 keys_zone=www_cache:10m max_size=10g inactive=1d use_temp_path=off;
proxy_cache www_cache;
proxy_cache_background_update on;
proxy_cache_key $scheme$host$request_uri;
proxy_cache_lock on;
proxy_cache_revalidate on;
proxy_cache_use_stale error timeout invalid_header updating http_500 http_502 http_503 http_504;
proxy_cache_valid 30m;