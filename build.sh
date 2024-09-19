#!/bin/sh
if [ $# -lt 1 ]; then
  echo "Usage: $0 [debug|release] ..."
  exit 1
fi

capitalize() {
    local input="$1"
    local first_char=$(echo "${input:0:1}" | tr '[:lower:]' '[:upper:]')
    local rest="${input:1}"
    echo "${first_char}${rest}"
}

case $1 in
  debug|release)
    cmake -DCMAKE_BUILD_TYPE=$(capitalize $1) -S src -B build/$1
    ninja -v -C build/$1
    cp resources/7za.exe build/$1/7za.exe
    cp resources/music.zip build/$1/music.zip
    cp resources/resource.zip build/$1/resource.zip
    ./run.sh $1 $2 $3 $4
    ;;
esac