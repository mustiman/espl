#!/bin/sh

count=0

if [ $# -ne 2 ] ; then
  echo "$0: number of args is incorrect" >&2
  exit 1
fi

filename=$1
count=$2

while [ "$count" -gt 0 ] ; do 
  if [ ! -r ${filename}.$(( $count - 1 )) ] ; then
    echo "file ${filename}.$(( $count - 1 )) not found"
   else
    cp ${filename}.$(( $count - 1 )) ${filename}.$count
  fi
  count="$(( $count - 1 ))"
done
exit 0