all : project.exe

project.exe : main.o
	g++ main.o -o project.exe


clean : 
	rm project.exe main.o
run :
	./project.exe

main.o : main.cpp
	g++ -Wall -Werror -c main.cpp -o main.o

