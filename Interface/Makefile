PROG = Inter.o parse.o
TARGET = Inter
CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`


all : ${TARGET}

${TARGET}: ${PROG}
	${CC} ${CFLAGS} -export-dynamic -o ${TARGET} ${PROG} ${LIBS}


clean:
	rm ${PROG} ${TARGET}
