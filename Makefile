all: hello more more2

hello: hello.c
	gcc hello.c -O0 -o hello

more: more.c
	gcc more.c -O0 -o more

more2: more2.c
	gcc more2.c -O0 -o more2