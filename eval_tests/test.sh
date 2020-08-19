#!/bin/sh

for entry in "eval_tests/$1"/*
do
  num=$(cut -d'_' -f3 <<<$entry)
  echo "\033[1;33m"$num TEST"\033[0m"
  cat $entry
  echo
  if [ "$1" = "error" ]
  then
    ./fillit $entry | cat -e
  else
    time ./fillit $entry | cat -e
  fi
  echo
done

if [ "$1" = "error" ]
then
  echo "\033[1;33m"LAST TEST, invalid file"\033[0m"
  ./fillit wasdadsddasdsafgewfas | cat -e
fi
