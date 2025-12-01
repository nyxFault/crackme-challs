all:
	gcc -o crackme_argv crackme_argv.c
	gcc -o crackme_stdin crackme_stdin.c

clean:
	rm -f crackme_argv crackme_stdin