OBJS =  main.o
CFLAG = -Wall -g
CC = gcc
INCLUDE =
LIBS =

hello:${OBJ}
   ${CC} ${CFLAGS} ${INCLUDES} -o bin/$@ obj/${OBJS} obj/${LIBS}

.cpp.o:
   ${CC} ${CFLAGS} ${INCLUDES} -c bin/$<

clean:
   -rm -f *.o core *.core
