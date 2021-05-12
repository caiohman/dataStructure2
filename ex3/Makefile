exec = exec_name
lib = read
lib2 = indice
main = main
dir = src

all: $(lib2).o $(lib).o $(main).o
	gcc -o $(exec) $(main).o $(lib).o $(lib2).o

$(main).o: $(dir)/$(main).c
	gcc -c $(dir)/$(main).c -Wall -g

$(lib).o: $(dir)/$(lib).c $(dir)/$(lib).h
	gcc -c $(dir)/$(lib).c -Wall -g

$(lib2).o: $(dir)/$(lib2).c $(dir)/$(lib2).h
	gcc -c $(dir)/$(lib2).c -Wall -g


.PHONY: clean test

run:
	./$(exec)

clean:
	rm -rf *.o

test:
	./$(exec) < teste.in |tee teste.out

diff: teste.out Testes/1.out
	diff teste.out Testes/1.out > resultado.txt

valgrind: $(exec)
	valgrind --leak-check=yes ./$(exec) < teste.in > teste.out	
