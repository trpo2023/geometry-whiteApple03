TARGET_DIR = ./bin/
OBJ_DIR = ./obj/
TARGET = ${TARGET_DIR}project.exe
GEOMETRY_PATH = ./src/libGeometry/
GEOMETRY_OBJ = ./obj/libGeometry/

params = ""

source_dirs =  src src/assistants src/figures/Circle src/figures/Polygon  src/figures/Triangle 
includes = src/libGeometry src/libGeometry/ParantFigure 
source_dirs_test =  ./test ./src/assistants/ ./src/figures/Circle/ ./src/figures/Polygon/  ./src/figures/Triangle/ 

search_wildcards := $(addsuffix /*.cpp,$(source_dirs))

all : ${GEOMETRY_OBJ}libGeometry.a $(TARGET)


$(TARGET): $(addprefix ${OBJ_DIR},$(notdir $(patsubst %.cpp,%.o,$(wildcard $(search_wildcards)))))
	mkdir -p ${TARGET_DIR}
	g++  $^ -L${GEOMETRY_OBJ} -lGeometry -o $@ 

VPATH := $(source_dirs_test) $(source_dirs)

	
${OBJ_DIR}%.o: %.cpp
	mkdir -p ${OBJ_DIR}
	g++ -c -MMD -Wall -Werror   $(addprefix -I,$(source_dirs)) $< -o $@

${GEOMETRY_OBJ}libGeometry.a: ${GEOMETRY_OBJ}intersection.o ${GEOMETRY_OBJ}ParantFigure.o
	ar rcs $@ $^
${GEOMETRY_OBJ}intersection.o: ${GEOMETRY_PATH}intersection.cpp 
	mkdir -p ${GEOMETRY_OBJ}
	g++ -c -MMD -Wall -Werror $(addprefix -I,$(includes)) -o $@ $<
${GEOMETRY_OBJ}ParantFigure.o: ${GEOMETRY_PATH}ParantFigure/Figure.cpp 
	g++ -c -MMD -Wall -Werror $(addprefix -I,$(includes)) -o $@ $<


clean : 
	rm $(TARGET) ${OBJ_DIR}*.[do] ${OBJ_DIR} 
run :
	$(TARGET) ${params}


.PHONY :  run clean

OBJ_DIR_TEST = ./obj/test/
TARGET_TEST = ${TARGET_DIR}project-test.exe


search_wildcards_test := $(addsuffix /*.cpp,$(source_dirs_test))

test : ${GEOMETRY_OBJ}libGeometry.a $(TARGET_TEST)



$(TARGET_TEST): $(addprefix ${OBJ_DIR_TEST},$(notdir $(patsubst %.cpp,%.o,$(wildcard $(search_wildcards_test))))) 
	mkdir -p ${TARGET_DIR}
	g++  $^ -L${GEOMETRY_OBJ} -lGeometry -o $@ 

	
${OBJ_DIR_TEST}%.o: %.cpp
	mkdir -p ${OBJ_DIR_TEST}
	g++ -c -MMD -Isrc -Ithirdparty $(addprefix -I,$(source_dirs_test)) $< -o $@

run_test : 
	$(TARGET_TEST) 

include $(wildcard *.d )


