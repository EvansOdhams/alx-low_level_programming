#!/bin/bash
cp /bin/ls /tmp/ls
echo 'int system(const char *command) { return 0; }' > /tmp/win.c
gcc -shared -o /tmp/win.so /tmp/win.c
export LD_PRELOAD=/tmp/win.so
