#!/bin/bash
# ----------------------------------------------------------------
# Shell script scripts to start server program
# Copyright(c)2016-2017 Chaoyang Liu <http://fibird.me>
# This script is licensed under GNU GPL version 3 or above
# ----------------------------------------------------------------

# Usage info
show_help() {
cat << EOF

Usage: ${0##*/} [-i IP_ADDR] [-p PORT]...

To start server program according to your need.

      -l or --local     run server locally just for test
      -p or --port      specify port for server
      -h or --help      display help info

EOF
}

# get ip from system
ip_add=$(ip route get 8.8.8.8 | awk '/8.8.8.8/ {print $NF}')
# get port from config file
port=$(grep -Po "(?<=^port ).*" config/config.cfg)

getopt --test > /dev/null
if [[ $? -ne 4 ]]
then
  echo "Error:`getopt --test` failed in this environment."
  exit 1
fi

# Options of this tool
SHORT=lhp:
LONG=local,help,port:

# Use getopt tool to parse options from users
PARSED=$(getopt --options $SHORT --longoptions $LONG --name "$0" -- "$@")
if [[ $? -ne 0 ]]
then
  show_help
  exit 2
fi

eval set -- "$PARSED"


# Process the options from users
# Inspired by this question from stackoverflow:
# http://stackoverflow.com/questions/192249/how-do-i-parse-command-line-arguments-in-bash/14203146#14203146
while true; do
  case "$1" in
    -h|--help)
      show_help
      shift
      ;;
    -l|--local)
      ip_add="127.0.0.1"
      shift
      ;;
    -p|--port)
      port=$2
      shift 2
      ;;
    --)       # End of all options
      shift
      break
      ;;
    *)
      exit 3
      ;;
  esac
done

#echo "ip address: $ip_add"
#echo "port: $port"

# start server
./server $ip_add $port

exit 0
