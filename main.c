#include <stdlib.h>
#include "mrdo.h"


void main(){

 char url[] = "fase1.txt"; 
	
 int contFrutas = contaFrutas(url); // retorna o numero de frutas na fase
 int *xFrutas, *yFrutas, i; // declara os vetores das posicoes das frutas
 
 xFrutas = (int*) malloc(sizeof(int)*contFrutas);
 yFrutas = (int*) malloc(sizeof(int)*contFrutas);
 
 // _________________________________________________________________________________________________________
//home	*** MENU INICIAL ***
	
	char opcao = '0', x = 0;
	
	while (opcao == '0'){ // Forca o inicio para a tela de menu inicial
		
		opcao = menuInicial();// escolha opcao de 1 a 4 no menu 
		
			while (opcao == '1'){ // Opcao 1 - "Novo Jogo" - Inicia o jogo
	
				system("cls");
				carregarFase(url, xFrutas, yFrutas);// Le arquivo da fase e desenha ela na tela;
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
				Do.ultimaDirecao = 2;
				opcao = movimentoMrDo(Do, contFrutas, xFrutas, yFrutas);
	        	   		
			}//Fim de opcao == 1 - Novo Jogo
			
	
	}//Fim Opcao 0 - Menu principal

free(xFrutas);
free(yFrutas);

}//Fim da Main
