#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <TIME.H>
#include "mrdo.h"

#define ESQUERDA 75
#define DIREITA 77
#define CIMA 72
#define BAIXO 80


void gotoxy (int x, int y)
{
        COORD coord = {0, 0};
        coord.X = x; coord.Y = y; // Coordenadas X e Y
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ShowConsoleCursor(int showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void SetColor(int ForgC)
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }

/*             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15*/ 

char menuInicial(){
	
		char opcao; 
		int x;
	
		//Menu Principal
		system ("cls");
		fflush(stdin);
		SetColor(14); // seleciona a cor de texto amarela - Funcao SetColor
	
		for (x = 14; x < 106; x++){ // Desenha a primeira Barra do menu (mais grossa, caracter 220)
			gotoxy(x,8);		
			printf ("%c", 220);		
		}
		
		gotoxy(55, 9);
		printf ("Mr Do!");
	
		for (x = 14; x < 106; x++){// Desenha a segunda Barra do menu (mais fina, caracter 196)
			gotoxy(x,11);		
			printf ("%c", 196);		
		}
	
		printf ("\n\t\t\t 1 - Novo Jogo");
		printf ("\n\t\t\t 2 - Continuar");
		printf ("\n\t\t\t 3 - High Scores");
		printf ("\n\t\t\t 4 - Sair");
	
	
		for (x = 14; x < 106; x++){// Desenha a terceira Barra do menu (mais fina, caracter 196)
			gotoxy(x,17);		
			printf ("%c", 95);		
		}
		
		gotoxy(15,18);
		printf ("Entre com a Opcao desejada:"); // Desenha a quarta Barra do menu (mais grossa, caracter 220)
	
		for (x = 14; x < 106; x++){
			gotoxy(x,19);		
			printf ("%c", 223);		
		}
		
		opcao = getch();
		
		if ((opcao != '0') && (opcao != '1') && (opcao !='2') && (opcao !='3') && (opcao !='4')) {
			printf ("\n\t\tOpcao Invalida!");
			opcao = '0';
		}// Fim do Menu Inicial
		
		return opcao;
		
}

int contaFrutas(char url[]){

	char v[23][60],ch = '0';
	int contFrutas = 0;
	int i = 0, j = 0;
	
					
	FILE *arq;
	
	arq = fopen(url, "r");
	
	if (arq == NULL) printf ("Erro, nao foi possivel abrir o arquivo\n");
	
	else {
						
		while (ch != EOF) {
					
			ch = fgetc(arq);
			v[i][j] = ch;
			
			if (v[i][j] == 'f')	contFrutas++;
			
			if (ch == '\n') {
				i++;
				j=0;
			}
						
			j++;
		}
	}
				
	fclose(arq);
	return contFrutas;
}	
	


void carregarFase(char url[], int *xFrutas, int *yFrutas, char **mapa){
	
//________________________________________________________________________________________________________
//
//********** Ler Mapa da fase a partir do Arquivo TXT ********* Inicio do Jogo (opcao == 1)
//_______________________________________________________________________________________________	
	char ch = '0';
	int num = 0;
	int i = 0, j = 0, cont = 0;
	

	FILE *arq;
	
	arq = fopen(url, "r");
	
	if (arq == NULL) printf ("Erro, nao foi possivel abrir o arquivo\n");
	
	else {
						
		while (ch != EOF) {
			
			ch = fgetc(arq);
			
			mapa[i][j] = ch;
			
			j++;
			
			if (ch == '\n') {
				i++;
				j=0;
			}
		}
	}
				
	fclose(arq);
	SetColor(2);			
	for (i = 0; i < 23; i++){	
		for (j = 0; j < 60; j++){
			
			if (mapa[i][j] == 'N'){ 
			SetColor (8);
			printf ("%c", 206); //se caracter do arquivo texto da fase for 'N' desenha ninho
			}	
			if (mapa[i][j] == 'p'){
				SetColor(2);
				printf ("%c", 176);//se caracter do arquivo texto da fase for 'p' desenha parede
			} 
			if (mapa[i][j] == 'v') printf ("%c", 32); //se caracter do arquivo texto da fase for 'v' desenha caminho
			if (mapa[i][j] == 'f'){
				SetColor(4);
				printf ("%c", 229); //se caracter do arquivo texto da fase for 'f' desenha fruta
				SetColor(8);
				xFrutas[cont] = j;
				yFrutas[cont] = i;
				/*printf ("%d", xFrutas[cont]); 
				printf ("%d", yFrutas[cont]); - Teste imprimindo as coordenadas das frutas - Funcionando*/ 
				cont++;
					
			} 
							
		} 
	
	printf ("\n");	
	
	}
	
	/*gotoxy(50, 12);
	printf("%d", contFrutas); codigo teste para verificar a quantidade de frutas - funcionando!*/
}

int limiteMapa(int x, int y){
	
	gotoxy (80, 8);
	printf ("            ", x, y);
	gotoxy (80, 8);
	printf ("X: %d Y: %d", x, y);
	
	if(x < 60 && x > -1)
	{
		if(y < 23 && y > -1)
		{
			return 1;
		}
		else
		{
			return 0;	
		}
	}	
	else
	{
		return 0;	
	}
}

char movimentoMrDo (mrDo Do, int contFrutas, int *xFrutas, int *yFrutas, char **mapa) {
	
	int keypress;
	int d = 2, i, xaux = 0, yaux = 0, direcaoTiro, a; 
	char tecla, opcao, status = '1';//1 - vivo, 0 - morto;
	int totalFrutas[contFrutas], score = 0, contador = 0;
	Tiro tiro;				
		
	for (i = 0; i < contFrutas; i++) totalFrutas[i] = 0; //inicia o vetor de frutas comidas em zero.
	
	ShowConsoleCursor(0);
	
	gotoxy(Do.x, Do.y);
	SetColor(14);
	printf ("%c", 232); // desenha o Mr. Do
	
	while(status == '1'){  
		
		gotoxy (80, 6);
		printf ("SCORE : %d", score);
		ShowConsoleCursor(0);
			
		if(kbhit()) keypress = getch();
		else keypress = 0;
		
		switch(keypress){
			
			case 224:
				
				//apaga o mrDo na posicao anterior
				gotoxy(Do.x, Do.y);
				printf (" ");// apaga o Mr. Do
				mapa[Do.y][Do.x] = 'v';
				
				//descobre qual seta foi clicada
				keypress = getch();
				
				if(keypress == 75 && limiteMapa(Do.x-1, Do.y) == 1){
					Do.x--;//esquerda
					Do.ultima = ESQUERDA;
				}
				if(keypress == 77 && limiteMapa(Do.x+1, Do.y) == 1){
					Do.x++;//direita
					Do.ultima = DIREITA;
				}
				if(keypress == 80 && limiteMapa(Do.x, Do.y+1) == 1){
					Do.y++;//baixo
					Do.ultima = BAIXO;
				}
				if(keypress == 72 && limiteMapa(Do.x, Do.y-1) == 1){
					Do.y--;//cima	
					Do.ultima = CIMA;
				}				
				gotoxy(Do.x,Do.y);
				printf("%c",232);
				
							
				for (i = 0; i < contFrutas; i++){
			
					/*printf ("%d", xFrutas[i]);
					printf ("%d", yFrutas[i]); - Teste imprimindo coordenadas das frutas - funcionando!*/ 
			
					if((Do.y == yFrutas[i])) yaux = 1; //Se a coordenada y do Mr. Do for igual a da fruta[i]
					else yaux = 0;
			
					if ((Do.x == xFrutas[i])) xaux = 1;//Se a coordenada x do Mr. Do for igual a da fruta[i]
					else xaux = 0;
			
					if ((yaux == 1 ) && (xaux == 1))totalFrutas[i] = 1;//Ambas coordenadas iguais - Come Fruta.
					
				}
				
				break;
				
			case 32:
				
				//1 - Esquerda, 2 - Direita, 3 - Cima, 4 - Baixo
				tiro.status = 1;
				tiro.x = Do.x;
				tiro.y = Do.y;
				a = 0;//variavel para nao apagar o Mr. Do no primeiro tiro.
				
				if (Do.ultima == ESQUERDA) direcaoTiro = 1;
				if (Do.ultima == DIREITA) direcaoTiro = 2;
				if (Do.ultima == CIMA) direcaoTiro = 3;
				if (Do.ultima == BAIXO) direcaoTiro = 4;
				break;
				
			default: break;			
		}
			
			if (tiro.status == 1){
				
				if ( a > 0){
				gotoxy(tiro.x,tiro.y);
				printf (" ");
				}
				
				a++;
				
				if((direcaoTiro == 1)&& limiteMapa(tiro.x-1, tiro.y) == 1){
					
					if (mapa[tiro.y][tiro.x-1] == 'p')
						tiro.status = 0;
					else {
						
						tiro.x--;//esquerda
						gotoxy(tiro.x, tiro.y);
						printf ("%c", 250);// imprime tiro
					}
				}
				
				if((direcaoTiro == 2) && limiteMapa(tiro.x+1, tiro.y) == 1){
					
					if (mapa[tiro.y][tiro.x+1] == 'p')
						tiro.status = 0;
					else {
						
						tiro.x++;//direita
						gotoxy (tiro.x, tiro.y);
						printf ("%c", 250);// imprime tiro
					} 
				}
				
				if((direcaoTiro == 4) && limiteMapa(tiro.x, tiro.y+1) == 1){
					if (mapa[tiro.y+1][tiro.x] == 'p')
						tiro.status = 0; 
						else {
						
						tiro.y++;//baixo
						gotoxy(tiro.x, tiro.y);
						printf ("%c", 250);// imprime tiro
					}
					
				}
				if((direcaoTiro == 3) && limiteMapa(tiro.x, tiro.y-1) == 1){
					if (mapa[tiro.y-1][tiro.x] == 'p')
						tiro.status = 0;
					else {
						
						tiro.y--;//cima	
						gotoxy(tiro.x, tiro.y);
						printf ("%c", 250);// imprime tiro						
						
					} 
					
				}
				
			}
			
			usleep(80000);
			
			contador = 0;
			for (i = 0 ; i < contFrutas; i++)		
    			if ((totalFrutas[i]) == 1){
    				contador++;
    				score = contador*50;//Cinquenta pontos cada fruta comida
				}  
    			
		if (contador == contFrutas) status = '0';//Comeu todas as frutas e passa para a proxima fase 
	}
             	        		   	
//______________________________________________________________________________________________________________________
//Tela após passar de fase, caso o jogador coma todas as frutas
	/*int j;
	system ("cls");
	for (i = 0; i < 23; i++){
		for (j = 0; j < 60; j++) printf ("%c", mapa[i][j]);
		printf ("\n");
	} teste imprimindo estado da fase - funcionando*/ 
	system ("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\t************* FASE COMPLETADA! PARABENS! **********");
    printf ("\n\n\n\n\n\n\n Pressione qualquer tecla para voltar ao menu principal ");
	opcao = '0'; 
	getch();
    system ("cls");
    return opcao;
	
}

