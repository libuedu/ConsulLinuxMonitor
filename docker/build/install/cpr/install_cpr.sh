#!/usr/bin/env bash

set -e

# ��ȡ��ǰ�ű�����Ŀ¼
cd "$(dirname "${BASH_SOURCE[0]}")"

# ��ȡ�����߳���
THREAD_NUM=$(nproc)

# cprѹ���ļ���
CPR_TAR="cpr.tar.xz"

# ��ѹcprѹ���ļ�
tar xvf "${CPR_TAR}"
pushd cpr

# ��������Ŀ¼
mkdir build && cd build

# ����CMake���й���
cmake .. \
    -DBUILD_SHARED_LIBS=ON \
    -DCPR_BUILD_TESTS=OFF \
    -DCMAKE_INSTALL_PREFIX:PATH="/usr/local" \
    -DCMAKE_BUILD_TYPE=Release

# ���벢��װ
make -j${THREAD_NUM}
make install

# ���¶�̬���ӿ⻺��
ldconfig

# �ص��ϼ�Ŀ¼
popd

# ɾ����ʱ�ļ�
rm -rf "${CPR_TAR}" cpr
