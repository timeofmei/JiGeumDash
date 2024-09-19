#!/bin/sh
if [ $# -lt 1 ]; then
  echo "Usage: $0 [debug|release] ..."
  exit 1
fi

case $1 in
  debug|release)
    cd build/$1
    ./JiGeumDash $2 $3 $4
    ;;
esac