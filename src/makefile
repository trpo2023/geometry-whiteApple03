all : ./bin/project.exe

./bin/project.exe : ./obj/main.o  ./obj/get_figure.o ./obj/polygon_with_circle.o
	mkdir -p ./bin
	g++ ./obj/main.o ./obj/polygon_with_circle.o  ./obj/get_figure.o -o ./bin/project.exe

./obj/main.o : ./source/main.cpp
	mkdir -p ./obj
	g++ -Wall -Werror -c ./source/main.cpp -o ./obj/main.o

./obj/polygon_with_circle.o : ./figures/polygon_with_circle/polygon_with_circle.cpp
	g++ -Wall -Werror -c ./figures/polygon_with_circle/polygon_with_circle.cpp -o ./obj/polygon_with_circle.o
./obj/get_figure.o : ./assistants/get_figure.cpp	
	g++ -Wall -Werror -c ./assistants/get_figure.cpp -o ./obj/get_figure.o

clean : 
	rm ./bin/project.exe ./obj/main.o ./obj/get_figure.o ./bin/debug ./obj/polygon_with_circle.o
run :
	./bin/project.exe

debug : ./bin/debug

./bin/debug : ./source/main.cpp ./assistants/get_figure.cpp
	g++ -g ./source/main.cpp ./assistants/get_figure.cpp -o ./bin/debug


