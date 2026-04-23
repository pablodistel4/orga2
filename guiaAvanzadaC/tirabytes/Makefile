FLAGS = -Wall -Wextra -pedantic
FILE = tirabytes
all: $(FILE)

$(FILE): $(FILE).o
	gcc $(FLAGS) $(FILE).o -o $(FILE)

$(FILE).o: $(FILE).c
	gcc $(FLAGS) -c $(FILE).c -o $(FILE).o

clean:
	rm *.o $(FILE)

run: 
	./$(FILE).exe

.PHONY: all clean