all: 
	 gcc -oFast reversi.c -o reversi

debugger:
	gcc debugger.c -lSDL2 -lm -o debug

