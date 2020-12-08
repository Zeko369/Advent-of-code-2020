#!/bin/sh

if [ $# -eq 0 ]; then
  g++ -o main.o main.cpp && ./main.o < input.txt
else
  g++ -o main.o main.cpp && ./main.o < demo.txt
fi
