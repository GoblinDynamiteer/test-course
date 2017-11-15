TARGET = dumbTest
LIBS =
UNITYPATH = c:/kod/unity/src/
CC = gcc
SRC_EXT = c
OBJ_EXT = o
CFLAGS = -g -Wall
SRC = $(wildcard *.$(SRC_EXT)) $(wildcard $(UNITYPATH)*.$(SRC_EXT))
OBJ = $(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

#Remove executable -> build -> run
all: cleantarget link run

link: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

#Remove object files and executable
clean:
	-rm -f *.$(OBJ_EXT)
	-rm -f $(UNITYPATH)*.$(OBJ_EXT)
	-rm -f $(TARGET).*

#Remove executable
cleantarget:
		-rm -f $(TARGET).exe

#Run executable
run: $(TARGET)
	.\$(TARGET)
