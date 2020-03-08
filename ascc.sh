#!/bin/bash

/usr/bin/screen -d -m /dev/ttyUSB0 9600

fanspeed_state=`cat /tmp/ascc.state | cut -d "," -f1`
r_state=`cat /tmp/ascc.state | cut -d "," -f2`
g_state=`cat /tmp/ascc.state | cut -d "," -f3`
b_state=`cat /tmp/ascc.state | cut -d "," -f4`

case "$1" in
-f)
    echo -e $2,$r_state,$g_state,$b_state > /tmp/servermon.state
    ;;
-c)
    echo -e $fanspeed_state,$2 > /tmp/ascc.state
    ;;
-r)
    echo -e $fanspeed_state,$2,$g_state,$b_state > /tmp/ascc.state
    ;;
-g)
    echo -e $fanspeed_state,$r_state,$2,$b_state > /tmp/ascc.state
    ;;
-b)
    echo -e $fanspeed_state,$r_state,$g_state,$2 > /tmp/ascc.state
    ;;
*)
    echo -e $1 > /tmp/ascc.state
    ;;
esac

/bin/cat /tmp/ascc.state > /dev/ttyUSB0
