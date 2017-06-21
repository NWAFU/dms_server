#!/bin/bash

# TODO: select mode of server
# ...

# TODO: get ip and port
# read config file to get ip and port
# ...

# get ip from system
p_add=$(ip route get 8.8.8.8 | awk '/8.8.8.8/ {print $NF}')  
# TODO: start server
# ...


exit 0
