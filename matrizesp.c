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

#ifndef matrizesp.c
#define matrizesp.c

//Protótipos da função
tipo_celula* alocaNo(int valor, int coluna, int linha);
void insereMtz(tipo_celula **mtz, int coluna, int linha, int valor);
int buscaMtz(tipo_celula **mtz, int coluna, int linha);
void imprimeMtz(tipo_celula *mtz);
void verifica_coluna(tipo_celula **mtz, int coluna);
void verifica_linha(tipo_celula **mtz, int linha);
void insereColuna(tipo_celula **mtz, tipo_celula *novoNo);
void insereLinha(tipo_celula **mtz, tipo_celula *novoNo);

//Estrutura 
struct matriz{
	int valor; 
	int coluna;
	int linha;
	struct matriz *prox;
	struct matriz *abaixo;
	
}; typedef struct matriz tipo_celula; 

//Funçao para inserção de uma nova célula na matriz
void insereMtz(tipo_celula **mtz, int coluna, int linha, int valor){
	
	//Verifica se há cabeçalho para a coluna e cria se necessário
	verifica_coluna(mtz, coluna);
	
	//Verifica se há cabeçalho para a linha e cria se necessário
	verifica_linha(mtz, linha);
	
	//Aloca o novo nó
	tipo_celula *novoNo;
	novoNo = alocaNo(valor, coluna, linha);
	
	//Insere o novo nó na posição correta na coluna
	insereColuna(mtz, novoNo);
	
	//Insere o novo nó na posição correta na linha
	insereLinha(mtz, novoNo);
}

//FUnção que verifica a coluna da mtz
void verifica_coluna(tipo_celula **mtz, int coluna){
	tipo_celula *aux;
	aux = (*mtz)->prox;
	
	//Percorre o cabeçalho
	while((aux !=NULL) && (aux->coluna != coluna))
		aux = aux->prox;
		
	//verifica se o cabeçalho especificado no parametro nao foi encontrado, entao cria e insere
	if( aux == Null ){
		tipo_celula *novoCabecalho;
		novoCabecalho = alocaNo(0, coluna, 0); //Aloca(valor, coluna, linha)
		
		//verifica se é o primeiro cabeçalho a ser inserido
		if((*mtz)->prox == NULL){
			(*mtz)->prox = novoCabecalho;
		}else{
		
			//Insere novo cabeçalho
			aux = (*mtz)->prox;
			tipo_celula *auxAtras;
			//Trata caso espeial, do novo cabeçalho ser menor que todos
			if(coluna < aux->coluna){
				novoCabecalho->prox = aux;
				(*mtz)->prox = novoCabecalho;
			}else{
		
				while( (aux->prox != NULL) && (aux->coluna < coluna) ){
					auxAtras = aux;
					aux = aux->prox;
				}
				novoCabecalho->prox = aux;
				auxAtras->prox = novoCabecalho;
			}
			
		}
	//Se cabeçalho existe, então não faz nada
	}
}	
	
//Funçao que verifica a linha da mtz	
void verifica_linha(tipo_celula **mtz, int linha){
	tipo_celula *aux;
	aux = (*mtz)->abaixo;
	
	//Percorre cabeçalho
	while((aux != NULL) && (aux->linha != linha)){
		aux = aux->abaixo;
	}
	
	//verifica se o cabeçalho especificado no parametro nao foi encontrado, entao cria e insere
	if(aux==null){
		tipo_celula *novoCabecalho;
		novoCabecalho = alocaNo(0, 0, linha); //Aloca(valor, coluna, linha)
	//verifica se é o primeiro cabeçalho a ser inserido
		if((*mtz)->abaixo == NULL){
			(&mtz)->abaixo = novoCabecalho;
		}else{
			
			//Insere novo cabeçalho
			aux = (*mtz)-> abaixo;
			tipo_celula *auxAtras;
			//Trata caso espeial, do novo cabeçalho ser menor que todos
			if(linha < aux->linha){
				novoCabecalho->abaixo = aux;
				(*mtz)->abaixo = novoCabecalho;
			}else{
		
				while( (aux->abaixo != NULL) && (aux->linha < linha) ){
					auxAtras = aux;
					aux = aux->prox;
				}
			novoCabecalho->prox = aux;
			auxAtras->prox = novoCabecalho;
			}
		}
	//Se cabeçalho existe, então não faz nada	
	}	
	
}

//Função que insere celula na coluna
void insereColuna(tipo_celula **mtz, tipo_celula *novoNo){
	tipo_celula *aux, *auxAnt;
	
	aux = (*mtz)->prox;
	//Encontra a coluna onde a nova celula deve ser inserida
	while (aux->coluna != novoNo->coluna)
		aux = aux->prox;
	
	//verifica se há celula nessa coluna
	if(aux->abaixo == NULL){
		aux->abaixo = novoNo;
	}else{//Encontra a posição correta em relaçao a linha, onde a nova celula deve ser inserida
		auxAnt = aux;
		aux = aux->abaixo; //Atualiza aux para apontar para a primeira celula com valor
		while( (aux != NULL) && (aux->linha < novoNo->linha) ){
			auxAnt = aux;
			aux = aux->abaixo;
		}	
		novoNo->abaixo = aux;
		auxAnt->abaixo = novoNo;
	}	
}

//FUnção que insere
void insereLinha(tipo_celula **mtz, tipo_celula *novoNo){
	tipo_celula *aux, *auxAnt;
	
	aux = (*mtz)->abaixo;
	//Encontra a coluna onde a nova celula deve ser inserida
	while (aux->linha != novoNo->linha)
		aux = aux->abaixo;
	
	//verifica se há celula nessa coluna
	if(aux->prox == NULL){
		aux->prox = novoNo;
	}else{ //Encontra a posição correta em relaçao a coluna, onde a nova celula deve ser inserida
		auxAnt = aux;
		aux = aux->prox; //Atualiza aux para apontar para a primeira celula com valor
		while( (aux != NULL) && (aux->coluna < novoNo->coluna) ){
			auxAnt = aux;
			aux = aux->abaixo;
		}	
		novoNo->prox = aux;
		auxAnt->prox = novoNo;
	}	
	
}


//Funçao que busca o valor armazenado na matriz com base nos parametros linha e coluna
int buscaMtz(tipo_celula **mtz, int coluna, int linha){
	
	//Percorre o cabeçalho da coluna buscando o parametro
	
	//A partir do cabeçalho encontrado, percorre a linha buscando o parametro
	
	//Verifica se a celula correta foi encontrada, se sim retorna valor, se não, retorna como n encontrado
	
}

//Função que imprime a matriz
void imprimeMtz(tipo_celula *mtz){
	
	/* Percorre linha por linha, cada linha percorre todas as celulas de suas colunas, imprimindo
	o indice da linha/coluna e o valor armazenado */
	tipo_celula *auxLinha, *auxColuna;
	auxLinha = mtz->abaixo;
	while (auxLinha != NULL ){
		auxCOluna = auxLinha->prox;
		while (auxColuna != NULL){
			printf("[%d,%d] = %d", auxColuna->coluna, auxLinha->linha, auxLinha->valor)
		}
		printf("\n");
	}
	
}

//Função que aloca o novo nó
tipo_celula* alocaNo(int valor, int coluna, int linha){
    tipo_celula *novoNo;
    //Aloca na memória
    novoNo = (tipo_celula*) malloc(sizeof(tipo_celula));
  
        novoNo->valor = valor;
        novoNo->prox = NULL;
	novoNo->abaixo = NULL;
	novoNo->coluna = coluna;
	novoNo->linha = linha;
        
    return novoNo;
    
}


#endif