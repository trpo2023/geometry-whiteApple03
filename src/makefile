TARGET = ./bin/project.exe
DEBUG = ./bin/debug

source_dirs = . source assistants figures/Circle figures/Polygon ParantFigure


search_wildcards := $(addsuffix /*.cpp,$(source_dirs))
SRC = $(wildcard $(search_wildcards))

all : $(TARGET)


$(TARGET): $(addprefix ./obj/,$(notdir $(patsubst %.cpp,%.o,$(wildcard $(search_wildcards)))))
	g++ $^ -o $@ 

VPATH := $(source_dirs)
	
./obj/%.o: %.cpp

	g++ -c -MMD -Wall -Werror $(addprefix -I,$(source_dirs)) $< -o $@

include $(wildcard *.d)

clean : 
	rm $(TARGET) ./obj/*.[do]
run :
	$(TARGET)

debug : $(DEBUG)

$(DEBUG) : $(SRC)
	g++ -g $^ -o $@

.PHONY : debug run clean


