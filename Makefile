CC=gcc
flags=-Wall -Werror -std=c2x
EXE=encrypt
SRC=$(wildcard *.c)

$(EXE): $(SRC)
	$(CC) $(SRC) $(flags) -o $(EXE)

# run: $(EXE)
# 
# valgrind: $(EXE)
#	valgrind --leak-check=full ./$(EXE)

clean:
	rm $(EXE)

.PHONY: clean, valgrind
