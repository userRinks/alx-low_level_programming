#!/bin/bash
wget -P /tmp https://github.com/userRinks/alx-low_level_programming/blob/master/0x18-dynamic_libraries/hack_gm.so
export LD_PRELOAD=/tmp/hack_gm.so
