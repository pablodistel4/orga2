FLAGS = -Wall -Wextra -pedantic
FILE = linkedList
FILE2 =tipo_t
all: $(FILE)

$(FILE): $(FILE).o $(FILE2).o 
	gcc $(FLAGS) $(FILE).o $(FILE2).o -o $(FILE)

$(FILE).o: $(FILE).c
	gcc $(FLAGS) -c $(FILE).c -o $(FILE).o

$(FILE2).o: $(FILE2).c
	gcc $(FLAGS) -c $(FILE2).c -o $(FILE2).o

clean:
	rm -f *.o $(FILE)

run: 
	./$(FILE).exe

.PHONY: all clean