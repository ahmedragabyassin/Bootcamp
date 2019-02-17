CC = gcc
HEADERS = func1.h func2.h
CFLAGS= Wl,-Map,sum.map main.o func1.o func2.o

sum.exe : main.o func1.o func2.o
	$(CC) -o sum.exe main.o func1.o func2.o
	objdump -x main.o func1.o func2.o
	$(CC) $(CFLAGS)
main.o : main.c func1.h func2.h
	$(CC) -c main.c
func1.o : func1.h func1.c
	$(CC) -c func1.c
func2.o : func2.h func2.c
	$(CC) -c func2.c
clean: 
	rm -f *.o 
	rm -f *.exe
	rm -f *.map
	echo Clean Done
