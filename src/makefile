all : ./bin/project.exe

./bin/project.exe : ./obj/main.o
	g++ ./obj/main.o -o ./bin/project.exe


clean : 
	rm ./bin/project.exe ./obj/main.o
run :
	./project.exe

./obj/main.o : ./source/main.cpp
	g++ -Wall -Werror -c ./source/main.cpp -o ./obj/main.o

