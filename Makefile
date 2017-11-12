CC = g++
LD = g++
CFLAGS = -c -g -std=c++11 -pedantic-errors -Wall
LFLAGS = -g

OBJS = main_test.o Pencil.o Paper.o
PROG = kataexe

default: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LFLAGS) $(OBJS) -o $(PROG)

main_test.o: main_test.cpp Pencil.h Paper.h
	$(CC) $(CFLAGS) main_test.cpp

Pencil.o: Pencil.cpp Pencil.h Paper.h Utility.h
	$(CC) $(CFLAGS) Pencil.cpp

Paper.o: Paper.cpp Paper.h Pencil.h Utility.h
	$(CC) $(CFLAGS) Paper.cpp


clean:
	rm -f *.o
real_clean:
	rm -f $(PROG)
	rm -f *.o
