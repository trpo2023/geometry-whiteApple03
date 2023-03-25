TARGET_DIR = ./bin/
OBJ_DIR = ./obj/
TARGET = ${TARGET_DIR}project.exe
GEOMETRY_PATH = ./src/libGeometry/
GEOMETRY_OBJ = ./obj/libGeometry/

DEBUG = ./src/bin/debug
params = ""

source_dirs = src src/assistants src/figures/Circle src/figures/Polygon  src/figures/Triangle


search_wildcards := $(addsuffix /*.cpp,$(source_dirs))
SRC = $(wildcard $(search_wildcards))

all : $(TARGET)


$(TARGET): $(addprefix ${OBJ_DIR},$(notdir $(patsubst %.cpp,%.o,$(wildcard $(search_wildcards))))) ${GEOMETRY_PATH}libGeometry.a
	mkdir -p ${TARGET_DIR}
	g++  $^ -L${GEOMETRY_PATH} -lGeometry -o $@ 

VPATH := $(source_dirs)
	
${OBJ_DIR}%.o: %.cpp
	mkdir -p ${OBJ_DIR}
	g++ -c -MMD -Wall -Werror $(addprefix -I,$(source_dirs)) $< -o $@
${GEOMETRY_PATH}libGeometry.a: ${GEOMETRY_OBJ}intersection.o ${GEOMETRY_OBJ}ParantFigure.o
	ar rcs $@ $^
${GEOMETRY_OBJ}intersection.o: ${GEOMETRY_PATH}intersection.cpp 
	mkdir -p ${GEOMETRY_OBJ}
	g++ -c -MMD -Wall -Werror -o $@ $<
${GEOMETRY_OBJ}ParantFigure.o: ${GEOMETRY_PATH}ParantFigure/Figure.cpp 
	g++ -c -MMD -Wall -Werror -o $@ $<

print:
	echo ${search_wildcards}

clean : 
	rm $(TARGET) ${OBJ_DIR}*.[do] ${OBJ_DIR} $(DEBUG)
run :
	$(TARGET) ${params}

debug : $(DEBUG)

$(DEBUG) : $(SRC)
	g++ -g $^ -o $@

.PHONY : debug run clean
include $(wildcard *.d intersection.d)


