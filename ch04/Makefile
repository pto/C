CFLAGS=-ansi -pedantic

all: find atof calc

find: getline.o strindex.o

calc: getline.o

clean:
	rm -f *.o
	# use cleanall to remove executables

cleanall: clean
	rm -f find atof calc
