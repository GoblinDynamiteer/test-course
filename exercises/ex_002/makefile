TARGET = helloworld
LIBS =
CC = gcc
SRC_EXT = c
OBJ_EXT = o
CFLAGS = -g -Wall
SRC = $(wildcard *.$(SRC_EXT))
OBJ = $(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

#Remove executable -> build -> run
all: cleantarget link run

compile:
	$(CC) hello.c main.c world.c -o $(TARGET)

link: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

#Remove object files and executable
clean:
	-rm -f *.$(OBJ_EXT)
	-rm -f $(SUBDIR)/*.$(OBJ_EXT)
	-rm -f $(TARGET).*

#Remove executable
cleantarget:
		-rm -f $(TARGET).*

#Run executable
run: $(TARGET)
	.\$(TARGET)
