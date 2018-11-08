gcc -c mrdo.c -o mrdo.o
ar rcs libmrdo.a mrdo.o
gcc -c dobib.c -o dobib.o
gcc -o dobib.exe dobib.o -L. -lmrdo
dobib.exe