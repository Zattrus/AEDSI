all: conjunto.c main.c
	@gcc conjunto.c main.c -c program

conjunto.c: conjunto.c
	@gcc conjunto.c -c

main.c: main.c
	@gcc main.c -c

run:
	@./program.exe

go: 
	@make all
	@make run

clean:
	@del *.c *.exe
	@cls