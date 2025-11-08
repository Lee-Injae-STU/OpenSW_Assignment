#! /bin/bash

file_wordcnt(){
  files=$(ls *.txt)
  for FILE in $files; do
    cnt=$(cat $FILE | wc -w)
    echo "$FILE 파일의 단어는 $cnt 개 입니다."
  done
  
}

file_wordcnt