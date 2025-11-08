#! /bin/bash

factorial(){
  a=$(seq $NUM)
  result=1
  for i in $a; do
    result=$(( $result * $i ))
  done
  echo $result
}

read -p "Enter a number: " NUM
factorial $NUM