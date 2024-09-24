all: main

main: main.o temp_functions.o
	gcc -o report  main.o temp_functions.o

main.o: main.c temp_functions.h
	gcc -c -o  main.o  main.c

temp_functions.o: temp_functions.c temp_functions.h
	gcc -c -o temp_functions.o temp_functions.c

clean:
	Srm -rf *.o main
	del *.o
	del prog.exe