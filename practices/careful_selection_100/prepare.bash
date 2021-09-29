#!/bin/bash

for i in {1..100}; do
  echo "${i}:${i}.cpp" >> Makefile
  echo -e "\tg++ -g -std=c++17 -Wall ${i}.cpp -o ${i}.out" >> Makefile
done
