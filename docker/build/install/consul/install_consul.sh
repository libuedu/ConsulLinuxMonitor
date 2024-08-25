#!/usr/bin/env bash

set -e

# ��ȡ��ǰ�ű�����Ŀ¼
cd "$(dirname "${BASH_SOURCE[0]}")"

# Consul�汾���ļ���
CONSUL_VERSION="1.19.1"
CONSUL_ZIP="consul_${CONSUL_VERSION}_linux_amd64.zip"

# ��ѹ��Consul�ļ�
unzip "${CONSUL_ZIP}"

# �ƶ��������ļ���/usr/local/bin
mv consul /usr/local/bin/

# ����Ȩ��
chmod +x /usr/local/bin/consul

# ������ʱ�ļ�
rm -f "${CONSUL_ZIP}"