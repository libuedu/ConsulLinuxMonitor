#!/usr/bin/env bash

MONITOR_HOME_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"
echo "MONITOR_HOME_DIR is set to: ${MONITOR_HOME_DIR}"
echo "XDG_RUNTIME_DIR is set to: ${XDG_RUNTIME_DIR}"
display=""
if [ -z ${DISPLAY} ];then
    display=":1"
else
    display="${DISPLAY}"
fi

local_host="$(hostname)"
user="${USER}"
uid="$(id -u)"
group="$(id -g -n)"
gid="$(id -g)"


echo "stop and rm docker" 
docker stop linux_monitor_consul > /dev/null
docker rm -v -f linux_monitor_consul > /dev/null

echo "start docker"
docker run -it -d \
--name linux_monitor_consul \
-e DISPLAY=$display \
--privileged=true \
-e DOCKER_USER="${user}" \
-e USER="${user}" \
-e DOCKER_USER_ID="${uid}" \
-e DOCKER_GRP="${group}" \
-e DOCKER_GRP_ID="${gid}" \
-e XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR \
-p 10086:10086 \
-v ${MONITOR_HOME_DIR}:/work \
-v ${XDG_RUNTIME_DIR}:${XDG_RUNTIME_DIR} \
--net host \
linux:monitor_consul_1
