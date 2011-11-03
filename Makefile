CC = g++
OBJFILES := $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(OBJFILES)
	$(CC) -o outofsight -lSDL $(OBJFILES)

