all: fork.c
	gcc fork.c
run:
	./a.out
clean:
	rm *.out
