#!/usr/bin/env bash

set -e

# 获取当前脚本所在目录
cd "$(dirname "${BASH_SOURCE[0]}")"

# Consul版本和文件名
CONSUL_VERSION="1.19.1"
CONSUL_ZIP="consul_${CONSUL_VERSION}_linux_amd64.zip"

# 解压缩Consul文件
unzip "${CONSUL_ZIP}"

# 移动二进制文件到/usr/local/bin
mv consul /usr/local/bin/

# 设置权限
chmod +x /usr/local/bin/consul

# 清理临时文件
rm -f "${CONSUL_ZIP}"