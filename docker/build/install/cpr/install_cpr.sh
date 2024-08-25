#!/usr/bin/env bash

set -e

# 获取当前脚本所在目录
cd "$(dirname "${BASH_SOURCE[0]}")"

# 获取可用线程数
THREAD_NUM=$(nproc)

# cpr压缩文件名
CPR_TAR="cpr.tar.xz"

# 解压cpr压缩文件
tar xvf "${CPR_TAR}"
pushd cpr

# 创建构建目录
mkdir build && cd build

# 运行CMake进行构建
cmake .. \
    -DBUILD_SHARED_LIBS=ON \
    -DCPR_BUILD_TESTS=OFF \
    -DCMAKE_INSTALL_PREFIX:PATH="/usr/local" \
    -DCMAKE_BUILD_TYPE=Release

# 编译并安装
make -j${THREAD_NUM}
make install

# 更新动态链接库缓存
ldconfig

# 回到上级目录
popd

# 删除临时文件
rm -rf "${CPR_TAR}" cpr
