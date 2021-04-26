CC = gcc

SRC = ${wildcard ./src/*.c}
EXEC = ./build/keystance

all: ${SRC}
	${CC} ${SRC} `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -o ${EXEC}

clean:
	rm *.o
	rm ./build/keystance
