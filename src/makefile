all : ./bin/project.exe

./bin/project.exe : ./obj/main.o ./obj/get_figure_name.o ./obj/get_figure_obj.o
	mkdir -p ./bin
	g++ ./obj/main.o ./obj/get_figure_name.o ./obj/get_figure_obj.o -o ./bin/project.exe

./obj/main.o : ./source/main.cpp
	mkdir -p ./obj
	g++ -Wall -Werror -c ./source/main.cpp -o ./obj/main.o

./obj/get_figure_name.o : ./assistants/get_figure_name.cpp	
	g++ -Wall -Werror -c ./assistants/get_figure_name.cpp	-o ./obj/get_figure_name.o

./obj/get_figure_obj.o : ./assistants/get_figure_obj.cpp	
	g++ -Wall -Werror -c ./assistants/get_figure_obj.cpp -o ./obj/get_figure_obj.o

clean : 
	rm ./bin/project.exe ./obj/main.o
run :
	./bin/project.exe
