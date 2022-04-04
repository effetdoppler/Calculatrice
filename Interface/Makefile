PROG = Inter.o ../lib/parser2.o
TARGET = Inter
CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0` -lm

all : ${TARGET}

${TARGET}: ${PROG}
	${CC} ${CFLAGS} -rdynamic -o ${TARGET} ${PROG} ${LIBS}

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm ${PROG} ${TARGET}
