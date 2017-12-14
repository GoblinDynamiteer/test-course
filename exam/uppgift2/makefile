#For Exam
#Test, verifiering och certifiering
#Mjukvaruutvecklare inbyggda system
#2017-12-14

#By Johan Kampe


CC = gcc
ECHO = @echo
UNTIY_HOME = ./unity
UNITY_SRC = $(UNTIY_HOME)/src

SRC_EXT = c
OBJ_EXT = o
EXE_EXT = exe
APP_NAME = template

MAIN = main
TEST = test

MAIN_SRC = main.$(SRC_EXT)
TEST_SRC = test.$(SRC_EXT)

COMMAND_DELETE = -rm -f
CC_FLAGS = -Wall -I$(UNITY_SRC)

# Find source files
SRC_MAIN = $(filter-out $(TEST_SRC), $(wildcard *.$(SRC_EXT)))

SRC_TEST = $(wildcard $(UNITY_SRC)/*.$(SRC_EXT))
SRC_TEST += $(filter-out $(MAIN_SRC), $(wildcard *.$(SRC_EXT)))

# Replace .c with .o
OBJ_MAIN = $(SRC_MAIN:.$(SRC_EXT)=.$(OBJ_EXT))
OBJ_TEST = $(SRC_TEST:.$(SRC_EXT)=.$(OBJ_EXT))

.PHONY: clean_exec

ifndef VERBOSE
.SILENT:
endif

# Remove executable -> build -> run
all: main run

main: $(OBJ_MAIN)
	$(ECHO) "Building main"
	$(CC) $(OBJ_MAIN) -o $(APP_NAME) $(CC_FLAGS)

test: $(OBJ_TEST)
	echo "Building test"
	$(CC) $(OBJ_TEST) -o test_$(APP_NAME) $(CC_FLAGS)

# Compile source files to object files
%.$(OBJ_EXT): %.$(SRC_EXT)
	$(ECHO) "Compiling $< -> $@"
	$(CC) $< -c -o $@ $(CC_FLAGS)

# Remove object files and executable
clean: clean_exec
	$(ECHO) "Cleaning files"
	$(COMMAND_DELETE) $(OBJ_MAIN)
	$(COMMAND_DELETE) $(OBJ_TEST)

# Remove executable
clean_exec:
	$(ECHO) "Cleaning target"
	$(COMMAND_DELETE) *.$(EXE_EXT)

# Run executable
run: $(APP_NAME)
	.\$(APP_NAME)

help:
	@echo "Rule:        | Description"
	@echo "-----------------------------------------"
	@echo "make         | Build main"
	@echo "make test    | Build tests"
	@echo "make clean   | Clean object files and exe"
	@echo "-----------------------------------------"
	@echo "Add -VERBOSE=1 for verbose mode"
