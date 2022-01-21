all: interface.c worker.c
	gcc -o interface interface.c
	gcc -o worker worker.c

clean:
	-rm interface
	-rm worker
	-rm p1
	-rm p2
