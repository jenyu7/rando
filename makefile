all: run.c
	gcc -o rand run.c

run: all
	./rand

clean:
	rm -f *~
	rm -f rando
