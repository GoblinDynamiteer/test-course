CC = gcc
UNTIY_HOME = ../../unity
UNITY_SRC = $(UNTIY_HOME)/src

EXECUTABLE = refactor_calc
SRC_EXT = c
OBJ_EXT = o
EXE_EXT = exe
MAIN_C = main.c
TEST_C = test.c

COMMAND_DELETE = -rm -f
CC_FLAGS = -Wall -I $(UNITY_SRC)

# Find source files
SRC_MAIN = $(filter-out $(TEST_C), $(wildcard *.$(SRC_EXT)))
SRC_TEST = $(filter-out $(MAIN_C), $(wildcard *.$(SRC_EXT)))
SRC_TEST += $(wildcard $(UNITY_SRC)/*.$(SRC_EXT))

#Replace .c with .o
OBJ_MAIN = $(SRC_MAIN:.$(SRC_EXT)=.$(OBJ_EXT))
OBJ_TEST = $(SRC_TEST:.$(SRC_EXT)=.$(OBJ_EXT))

.PHONY: clean_exec

#Remove executable -> build -> run
all: main run

main: $(OBJ_MAIN)
	@echo "Building main"
	@$(CC) $(OBJ_MAIN) -o $(EXECUTABLE) $(CC_FLAGS)

test: $(OBJ_TEST)
	@echo "Building test"
	@$(CC) $(OBJ_TEST) -o test_$(EXECUTABLE) $(CC_FLAGS)

#Compile source files to object files
%.$(OBJ_EXT): %.$(SRC_EXT)
	@echo "Compiling $< -> $@"
	@$(CC) $< -c -o $@ $(CC_FLAGS)

#Remove object files and executable
clean: clean_exec
	@echo "Cleaning files"
	@$(COMMAND_DELETE) $(OBJ_MAIN)
	@$(COMMAND_DELETE) $(OBJ_TEST)

#Remove executable
clean_exec:
	@echo "Cleaning target"
	@$(COMMAND_DELETE) *.$(EXE_EXT)

#Run executable
run: $(EXECUTABLE)
	@.\$(EXECUTABLE)
