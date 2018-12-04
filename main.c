#include <stdlib.h>
#include <stdio.h>
#include "mrdo.h"

#define LINHA 23
#define COLUNA 60

void main(){

 char url[] = "fase1.txt"; 
	
 int contFrutas = contaFrutas(url); // retorna o numero de frutas na fase
 int *xFrutas, *yFrutas, i, j; // declara os vetores das posicoes das frutas
 
 xFrutas = (int*) malloc(sizeof(int)*contFrutas);
 yFrutas = (int*) malloc(sizeof(int)*contFrutas);
 
 char **mapa = (char**)malloc(LINHA* sizeof(char*)); //Aloca um Vetor de Ponteiros
 
 for (i = 0; i < LINHA; i++){ //Percorre as linhas do Vetor de Ponteiros
 		mapa[i] = (char*) malloc(COLUNA * sizeof(char)); //Aloca um Vetor de caracteres para cada posição do Vetor de Ponteiros.
		for (j = 0; j < COLUNA; j++) mapa[i][j] = '0';//inicializa o vetor com '0'
 }   
 
 // _________________________________________________________________________________________________________
//home	*** MENU INICIAL ***
	
	char opcao = '0', x = 0;
	
	while (opcao == '0'){ // Forca o inicio para a tela de menu inicial
		
		opcao = menuInicial();// escolha opcao de 1 a 4 no menu 
		
			while (opcao == '1'){ // Opcao 1 - "Novo Jogo" - Inicia o jogo
	
				system("cls");
				carregarFase(url, xFrutas, yFrutas, mapa);// Le arquivo da fase e desenha ela na tela;
				/*for (i = 0; i < LINHA; i++){
					for (j = 0; j < COLUNA; j++)
						printf ("%c", mapa[i][j]);
					printf ("\n");					
				}
				getch(); teste carregamento de mapa - funcionando!*/
				/*for (i = 0; i < contFrutas; i++){
					
					printf ("%d", xFrutas[i]);
					printf ("%d", yFrutas[i]);
					printf ("\n");
				}
				getch(); - Teste se funcao esta retornando as cordenadas das frutas - funcionando!*/
//_______________________________________________________________________________________
//Movimento do Mr. Do (dentro da fase)
				int cx=30, cy=22; 
				mrDo Do;
				Do.x = 30;
				Do.y = 22;
				Do.ultima = 72;//CIMA
				opcao = movimentoMrDo(Do, contFrutas, xFrutas, yFrutas, mapa);
	        	   		
			}//Fim de opcao == 1 - Novo Jogo
			
	
	}//Fim Opcao 0 - Menu principal

free(xFrutas);
free(yFrutas);
for (i = 0; i < LINHA ; i++) free(mapa[i]);
free (mapa);

}//Fim da Main
