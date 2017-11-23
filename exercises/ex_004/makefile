TARGET = refactor
LIBS =
CC = gcc
SRC_EXT = c
OBJ_EXT = o
CFLAGS = -g -Wall
MAINS = main.c
SRC = $(filter-out $(MAINS), $(wildcard *.$(SRC_EXT)))
OBJ = $(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

.PHONY: cleantarget

#Remove executable -> build -> run
all: cleantarget link run

link: $(OBJ) main.o
	$(CC) $(OBJ) main.o -o $(TARGET) $(LIBS)

#Remove object files and executable
clean:
	-rm -f *.$(OBJ_EXT)
	-rm -f $(SUBDIR)/*.$(OBJ_EXT)
	-rm -f $(TARGET).*

#Remove executable
cleantarget:
		-rm -f $(TARGET).exe

#Run executable
run: $(TARGET)
	.\$(TARGET)
