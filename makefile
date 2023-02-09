all : project

project : main.o
	gcc main.o -o project


clean : 
	rm project main.o
run :
	./project

main.o : main.c
	gcc -Wall -Werror -c main.c -o main.o

