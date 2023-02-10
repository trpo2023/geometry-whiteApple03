all : ./bin/project.exe

./bin/project.exe : ./obj/main.o
	mkdir -p ./bin
	g++ ./obj/main.o -o ./bin/project.exe

./obj/main.o : ./source/main.cpp
	mkdir -p ./obj
	g++ -Wall -Werror -c ./source/main.cpp -o ./obj/main.o

clean : 
	rm ./bin/project.exe ./obj/main.o
run :
	./project.exe
