CC = gcc
SRC = ${wildcard ./src/*.c}
EXEC = ./kst

all: ./src/main.c
	${CC} ${SRC} -o ${EXEC}
