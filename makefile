TARGET_DIR = ./src/bin/
OBJ_DIR = ./src/obj/
TARGET = ${TARGET_DIR}project.exe
GEOMETRY_PATH = ./src/libGeometry/
GEOMETRY_OBJ = ./src/obj/libGeometry/

DEBUG = ./src/bin/debug
params = ""

source_dirs = src src/assistants src/figures/Circle src/figures/Polygon src/ParantFigure src/figures/Triangle


search_wildcards := $(addsuffix /*.cpp,$(source_dirs))
SRC = $(wildcard $(search_wildcards))

all : $(TARGET)


$(TARGET): $(addprefix ./src/obj/,$(notdir $(patsubst %.cpp,%.o,$(wildcard $(search_wildcards))))) ${GEOMETRY_PATH}libGeometry.a
	mkdir -p ${TARGET_DIR}
	g++  $^ -L./src/libGeometry -lGeometry -o $@ 

VPATH := $(source_dirs)
	
./src/obj/%.o: %.cpp
	mkdir -p ${OBJ_DIR}
	g++ -c -MMD -Wall -Werror $(addprefix -I,$(source_dirs)) $< -o $@
${GEOMETRY_PATH}libGeometry.a: ${GEOMETRY_OBJ}intersection.o
	ar rcs $@ $^
${GEOMETRY_OBJ}intersection.o: ${GEOMETRY_PATH}intersection.cpp
	g++ -c -MMD -Wall -Werror -o $@ $<

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
include $(wildcard *.d intersection.d)


