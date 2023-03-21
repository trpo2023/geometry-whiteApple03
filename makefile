TARGET = ./src/bin/project.exe
DEBUG = ./src/bin/debug
params = ""

source_dirs = src src/assistants src/figures/Circle src/figures/Polygon src/ParantFigure


search_wildcards := $(addsuffix /*.cpp,$(source_dirs))
SRC = $(wildcard $(search_wildcards))

all : $(TARGET)


$(TARGET): $(addprefix ./src/obj/,$(notdir $(patsubst %.cpp,%.o,$(wildcard $(search_wildcards)))))
	g++ $^ -o $@ 

VPATH := $(source_dirs)
	
./src/obj/%.o: %.cpp

	g++ -c -MMD -Wall -Werror $(addprefix -I,$(source_dirs)) $< -o $@

print:
	echo ${search_wildcards}

clean : 
	rm $(TARGET) ./src/obj/*.[do] $(DEBUG)
run :
	$(TARGET) ${params}

debug : $(DEBUG)

$(DEBUG) : $(SRC)
	g++ -g $^ -o $@

.PHONY : debug run clean
include $(wildcard ./src/obj/*.d)


