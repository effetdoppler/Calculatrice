PROG = Inter.o ../lib/parser2.o
TARGET = Inter
CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

all : ${TARGET}

${TARGET}: ${PROG}
	${CC} ${CFLAGS} -rdynamic -o ${TARGET} ${PROG} ${LIBS}

../lib/parser2.o : ../lib/parser2.c ../lib/parser2.h
Inter.o : Inter.c ../lib/parser2.h

clean:
	rm ${PROG} ${TARGET}
