/* 					Matriz Esparça
	Uma matriz esparça é aquela que possui a maioria das suas células com valores
	igual a zero ou nulas. Ela é comum em planilhas de cálculo e em certos métodos numéricos.
	É importante considerar uma estrutura de dados que manipule adequadamente uma matriz
	esparça ao mesmo tempo que garante o uso otimizado da memória     
	
	INSERÇÃO: 1- Verifica se há cabeçalho para a coluna, cria se necessário
		  2- Verifica se há cabeçalho para a linha, cria se necessário
		  3- Aloca o novo nó
		  4- Insere o novo nó na posição correta na coluna
		  5- Insere o novo nó na posição correta na linha                                */


#include <stdlib.h>
#include <stdio.h>

#include "matrizesp.c"

//Funçao principal
int main(int argc, char *argv[]) {
	
	tipo_celula *mtz;
	mtz = alocaNo (0, 0, 0);

	
	insereMtz(&mtz, 4, 9, 100);
	insereMtz(&mtz, 2, 2, 200);
	insereMtz(&mtz, 2, 11, 400);
	insereMtz(&mtz, 1, 2, 300);
	
	imprimeMtz();
	
	return 1;
	
}