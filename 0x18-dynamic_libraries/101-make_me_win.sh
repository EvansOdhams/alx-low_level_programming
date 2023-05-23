#!/bin/bash
gcc -shared -o /tmp/libhax.so /home/user/101-win/libhax.c
export LD_PRELOAD=/tmp/libhax.so
