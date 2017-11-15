TARGET = dumbTest
LIBS =
UNITYPATH = C:/Kod/unity/src/
CC = gcc
SRC_EXT = c
OBJ_EXT = o
CFLAGS = -g -Wall
#SOURCES = $(wildcard *.cpp) $(wildcard */*.cpp)
SRC = $(wildcard *.$(SRC_EXT)) $(wildcard $(UNITYPATH)*.$(SRC_EXT))
OBJ = $(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

#Remove executable -> build -> run
all: cleantarget link run

compile:
	$(CC) $(SRC) -I $(UNITYPATH) -o $(TARGET)

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
