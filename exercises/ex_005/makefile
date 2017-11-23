CC = gcc
UNTIY_SRC_PATH = ../../unity/src
COMPILER_FLAGS = -g -Wall
EXECUTABLE = refactor_calc
EXECUTABLE_TEST = test_refactor_calc
SRC_EXT = c
OBJ_EXT = o
MAIN_C = main.c
TEST_C = test.c

#Get all *.c-files in folder EXCEPT main.c and test.c
SRC = $(filter-out $(MAIN_C) $(TEST_C), $(wildcard *.$(SRC_EXT)))

#Replace .c with .o
OBJ = $(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

.PHONY: cleantarget

#Remove executable -> build -> run
all: compile_main run

compile_main: $(OBJ) main.o
	$(CC) $(OBJ) main.o -o $(EXECUTABLE) $(COMPILER_FLAGS)

test: $(OBJ) $(UNTIY_SRC_PATH)/unity.o test.o
	$(CC) $(OBJ) test.o $(UNTIY_SRC_PATH)/unity.o -o $(EXECUTABLE_TEST) $(COMPILER_FLAGS)
#Remove object files and executable
clean:
	-rm -f *.$(OBJ_EXT)
	-rm -f $(EXECUTABLE).exe

#Remove executable
cleantarget:
	-rm -f $(EXECUTABLE).exe

#Run executable
run: $(EXECUTABLE)
	.\$(EXECUTABLE)
