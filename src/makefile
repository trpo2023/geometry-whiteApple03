all : ./bin/project.exe

./bin/project.exe : ./obj/main.o  ./obj/get_figure.o  ./obj/Figure.o ./obj/Circle.o ./obj/Polygon.o
	mkdir -p ./bin
	g++ ./obj/main.o ./obj/Figure.o ./obj/get_figure.o ./obj/Circle.o ./obj/Polygon.o -o ./bin/project.exe

./obj/main.o : ./source/main.cpp
	mkdir -p ./obj
	g++ -Wall -Werror -c ./source/main.cpp -o ./obj/main.o

./obj/get_figure.o : ./assistants/get_figure.cpp	
	g++ -Wall -Werror -c ./assistants/get_figure.cpp -o ./obj/get_figure.o
./obj/Figure.o : ./ParantFigure/Figure.cpp
	g++ -Wall -Werror -c ./ParantFigure/Figure.cpp -o ./obj/Figure.o
./obj/Circle.o : ./figures/Circle/Circle.cpp
	g++ -Wall -Werror -c ./figures/Circle/Circle.cpp -o ./obj/Circle.o
./obj/Polygon.o : ./figures/Polygon/Polygon.cpp	
	g++ -Wall -Werror -c ./figures/Polygon/Polygon.cpp -o ./obj/Polygon.o
clean : 
	rm ./bin/project.exe ./obj/main.o ./obj/get_figure.o ./bin/debug ./obj/Figure.o ./obj/Polygon.o ./obj/Circle.o 
run :
	./bin/project.exe

debug : ./bin/debug

./bin/debug : ./source/main.cpp ./assistants/get_figure.cpp
	g++ -g ./source/main.cpp ./assistants/get_figure.cpp -o ./bin/debug


