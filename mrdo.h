#ifndef MRDO_H
#define MRDO_H

void gotoxy (int x, int y);

void ShowConsoleCursor(int showFlag);

void SetColor(int ForgC);

char menuInicial();

int contaFrutas(char url[]);

void carregarFase(char url[], int *xFrutas, int *yFrutas, char **mapa, int *xyNinho);

typedef struct{
	
	int x, y;
	int ultima;
	char status;
	
}mrDo;

typedef struct{
	
	int x, y, status;
		
	
}Tiro;

typedef struct{
	
	int x, y, status;
	int ultima;	
	
}fantasma;


char movimentoMrDo (mrDo Do, int contFrutas, int *xFrutas, int *yFrutas, char **mapa, int *xyNinho);

//free(xFrutas);
//free(yFrutas);

#endif
