#!/bin/sh

if [ $# -eq 0 ]; then
	gcc -o main.o main.c && ./main.o < input.txt
else
	gcc -o main.o main.c && ./main.o < demo.txt
fi
