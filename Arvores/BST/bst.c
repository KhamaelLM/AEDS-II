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
    
    
}

void preOrdem(Apontador no){
    if (no == NULL)
        return;
    printf("\n- %d",no->chave);
    preOrdem(no->esquerda);
    preOrdem(no->direita);
}

void ordem(Apontador no){
    if (no == NULL)
        return;
    ordem(no->esquerda);
    printf("\n- %d",no->chave);
    ordem(no->direita);
}

void posOrdem(Apontador no){
    if (no == NULL)
        return;
    posOrdem(no->esquerda);
    posOrdem(no->direita);
    printf("\n- %d",no->chave);
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

void antecessor(Apontador valor, Apontador *no){
    if ((*no)->direita != NULL){
        antecessor(valor, &(*no)->direita);
        return;
    }
    valor->chave = (*no)->chave;
    valor = *no;
    *no = (*no)->esquerda;
    free(valor);
}

void retira(int valor, Apontador *no){
    Apontador aux;
    if(*no == NULL){
        printf("\nErro: esse valor não está na árvore\n");
        return;
    }
    if(valor < (*no)->chave){
        retira(valor, &(*no)->esquerda);
        return;
    }
    if(valor > (*no)->chave){
        retira(valor, &(*no)->direita);
        return;
    }
    if((*no)->direita == NULL){
        aux = *no;
        *no = (*no)->esquerda;
        free(aux);
        return;
    }
    if((*no)->esquerda != NULL){
        antecessor(*no, &(*no)->esquerda);
        return;
    }
    aux = *no;
    *no = (*no)->direita;
    free(aux);
}

int altura(Apontador no){
    if(no == NULL)
        return -1;
    else{
        int alturaEsq = altura(no->esquerda);
        int alturaDir = altura(no->direita);
        if(alturaEsq < alturaDir)
            return alturaDir + 1;
        else 
            return alturaEsq + 1;
    }
}
