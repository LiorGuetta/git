CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinc
TARGET = sudoku
SRC = src/main.c src/sudoku.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
