gcc -c mrdo.c -o mrdo.o
ar rcs libmrdo.a mrdo.o
gcc -c main.c -o main.o
gcc -o main.exe main.o -L. -lmrdo
