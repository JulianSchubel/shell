C=gcc
CFLAGS=-Wall -Wextra --pedantic
OBJECTS=main.o parse_cmd.o display_cmd.o

shell : ${OBJECTS}
	${C} ${CFLAGS} -o $@ ${OBJECTS}

main.o : main.c
	${C} ${CFLAGS} -c $<

parse_cmd.o :
	${C} ${CFLAGS} -c ./utils/parse_cmd.c

display_cmd.o :
	${C} ${CFLAGS} -c ./utils/display_cmd.c

clean : 
	rm -rf ./main.o ./parse_cmd.o ./display_cmd.o
