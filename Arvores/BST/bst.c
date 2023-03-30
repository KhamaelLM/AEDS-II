#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa(Apontador *no){
    *no = NULL;
}

void insere (Apontador *no, int valor){

    if(*no==NULL){
         *no = (Apontador)malloc(sizeof(NO));
        (*no)->chave = valor;
        (*no)->esquerda = NULL;
        (*no)->direita = NULL;
        printf("\nValor inserido: %d\n", valor);
        return;
    }
    if (valor < ((*no)->chave)){
        insere(&(*no)->esquerda, valor);
        return;
    }
    if(valor > ((*no)->chave)){
        insere(&(*no)->direita, valor);
        return;
    }
    else
        printf("\nESSE VALOR JÁ ESTÁ NA ÁRVORE\n");
}

void imprime(Apontador no){
    if (no == NULL)
        return;
    imprime(no->esquerda);
    printf("\n- %d",no->chave);
    imprime(no->direita);
    
}

void pesquisa(Apontador *no, int valor){
    if(*no==NULL){
        printf("\nValor não encontrado na árvore!\n");
        return;
    }
    if (valor < (*no)->chave){
        pesquisa(&(*no)->esquerda, valor);
        return;
    }
    if (valor > (*no)->chave){
        pesquisa(&(*no)->direita, valor);
    }
    else{
        printf("\nValor encontrado: %d \n",(*no)->chave);
    }
}