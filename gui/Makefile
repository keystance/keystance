CC = g++
SRC = ${wildcard ./src/*.cpp}
EXEC = ./build/kst

all: ./src/main.cpp
	${CC} ${SRC} -w -lSDL2 -o ${EXEC}

clean:
	rm *.o
	rm ./build/kst