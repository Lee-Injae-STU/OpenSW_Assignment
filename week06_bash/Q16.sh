#! /bin/bash

file_wordcnt(){
  if [ ! -e $FILE ]; then
    echo "$1 파일이 존재하지 않습니다."
    return 1
  fi
}

read -p "Enter a file name: " FILE
file_wordcnt $FILE
echo "file_wordcnt 함수의 종료상태: $?"