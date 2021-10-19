#!/bin/sh
name=$1
string=`grep $name ./README.md -n`
if test -z $string;then
  echo -e "\033[31m${name}\033[0m does not exist"
else
  OLD_IFS="$IFS"
  IFS=":"
  arr=($string)
  IFS="$OLD_IFS"
  line=${arr[0]}
  sed -i "${line}d" ./README.md
  echo -e "\033[32m${name}\033[0m pop success"
fi

