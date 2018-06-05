CFLAGS=-ansi -pedantic

all: find calc atoi

find: getline.o strindex.o

calc: getline.o atof.o

atoi: atof.o

clean:
	rm -f *.o
	# use cleanall to remove executables

cleanall: clean
	rm -f find calc atoi
