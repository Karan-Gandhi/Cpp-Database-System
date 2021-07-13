CC := g++
CFLAGS := -Wall
OBJS := obj/main.o obj/Schema.o obj/Database.o obj/Node.o

all: clean compile run

compile: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o bin/main

obj/main.o: src/main.cpp
	${CC} ${CFLAGS} -c src/main.cpp -o obj/main.o

obj/Schema.o: src/Schema.cpp
	${CC} ${CFLAGS} -c src/Schema.cpp -o obj/Schema.o

obj/Database.o: src/Database.cpp
	${CC} ${CFLAGS} -c src/Database.cpp -o obj/Database.o

obj/Node.o: src/Node.cpp
	${CC} ${CFLAGS} -c src/Node.cpp -o obj/Node.o

run:
	bin/main

clean:
	del bin obj
