
PROGRAM = easy_numbers
SRCDIR = ../..

CPPFLAGS =
CFLAGS = -O0 -ggdb -W -Wall -Werror

LDFLAGS =
LIBS =
HEADERS = easy_numbers.h easy_notation.h
OBJECTS = easy_numbers.o write.o functions.o trigonometry.o \
	  vectors_2.o vectors_3.o matrices.o demo.o

SRC = ${HEADERS} ${OBJECTS:%.o=%.c}

${PROGRAM}: ${OBJECTS}
	${CC} ${LDFLAGS} ${OBJECTS} ${LIBS} -o ${PROGRAM}

${OBJECTS}: ${HEADERS}

${SRC}: %: ${SRCDIR}/%
	if [ -f $@ ]; then chmod u+w $@; fi
	cp $< $@
	chmod a-w $@

CLEANFILES += ${PROGRAM} ${OBJECTS} ${SRC}

clean:
	rm -f ${CLEANFILES}

.PHONY: clean
