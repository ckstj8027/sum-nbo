
all: sum-nbo


sum-nbo: main.o add.o
	gcc -o sum-nbo main.o add.o



main.o: main.c add.h 
	gcc -c -o main.o main.c

add.o: add.c add.h  
	gcc -c -o add.o add.c


clean:
	rm -f sum-nbo main.o add.o