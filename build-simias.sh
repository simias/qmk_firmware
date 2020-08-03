#!/bin/sh

cd $(dirname $0)

util/docker_build.sh ergodox_ez:simias
