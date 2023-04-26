#include "sbb.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

void inicializa(Apontador *no){
    *no = NULL;
}

void Insere(int valor, Apontador *Ap){
    short Fim;
    Inclinacao IAp;
    IInsere(valor, Ap, &IAp, &Fim);
}

void IInsere(int valor, Apontador *Ap, Inclinacao *IAp, short *Fim){

    if(*Ap == NULL){
        *Ap = (Apontador)malloc(sizeof(NO));
        *IAp = Horizontal;
        (*Ap)->chave = valor;
        (*Ap)->BitEsq = Vertical;
        (*Ap)->BitDir = Vertical;
        (*Ap)->esquerda = NULL;
        (*Ap)->direita = NULL;
        *Fim = FALSE;
        return;
    }
    if(valor < (*Ap)->chave){

        IInsere(valor, &(*Ap)->esquerda,&(*Ap)->BitEsq, Fim);

        if(*Fim)
            return;
        if((*Ap)->BitEsq != Horizontal){
            *Fim = TRUE;
            return;
        }
        if ((*Ap)->esquerda->BitEsq == Horizontal){
            EE(Ap);
            *IAp = Horizontal;
            return;
        }
        if ((*Ap)->esquerda->BitDir == Horizontal){
            ED(Ap);
            *IAp = Horizontal;
        }
        return; 
    }
    if(valor <= (*Ap)->chave){
        printf("\nErro: Chave já está na árvore\n");
        *Fim = TRUE;
        return;
    }
    IInsere(valor, &(*Ap)->direita,&(*Ap)->BitDir, Fim);
    if(*Fim)
        return;
    if((*Ap)->BitDir != Horizontal){
        *Fim = TRUE;
        return;
    }
    if ((*Ap)->direita->BitDir == Horizontal){
        DD(Ap);
        *IAp = Horizontal;
        return;
    }
    if ((*Ap)->direita->BitEsq == Horizontal){
        DE(Ap);
        *IAp = Horizontal;
    }
}

void EE(Apontador *Ap){
    Apontador Ap1;
    Ap1 = (*Ap)->esquerda;
    (*Ap)->esquerda = Ap1->direita;
    Ap1->direita = *Ap;
    Ap1->BitEsq = Vertical;
    (*Ap)->BitEsq = Vertical;
    *Ap = Ap1;
}

void ED(Apontador *Ap){
    Apontador Ap1, Ap2;
    Ap1 = (*Ap)->esquerda;
    Ap2 = Ap1->direita; 
    Ap1->BitDir = Vertical;
    (*Ap)->BitEsq = Vertical; 
    Ap1->direita = Ap2->esquerda; 
    Ap2->esquerda = Ap1;
    (*Ap)->esquerda = Ap2->direita; 
    Ap2->direita = *Ap; 
    *Ap = Ap2;
}

void DD(Apontador *Ap){
    Apontador Ap1;
    Ap1 = (*Ap)->direita;
    (*Ap)->direita = Ap1->esquerda;
    Ap1->esquerda = *Ap;
    Ap1->BitDir = Vertical;
    (*Ap)->BitDir = Vertical;
    *Ap = Ap1;
}

void DE(Apontador *Ap){
    Apontador Ap1, Ap2;
    Ap1 = (*Ap)->direita; 
    Ap2 = Ap1->esquerda; 
    Ap1->BitEsq = Vertical;
    (*Ap)->BitDir = Vertical; 
    Ap1->esquerda = Ap2->direita; 
    Ap2->direita = Ap1;
    (*Ap)->direita = Ap2->esquerda; 
    Ap2->esquerda = *Ap; 
    *Ap = Ap2;
}

void pesquisa(int valor, Apontador *no){
    if ((*no)==NULL){
        printf("\nErro: Esse valor não está na árvore\n");
        return;
    }
    if(valor < (*no)->chave){
        pesquisa(valor, &(*no)->esquerda);
        return;
    }
    if(valor > (*no)->chave)
        pesquisa(valor, &(*no)->direita);
    else
        printf("\nValor encontrado!\n");
}

int alturaH(Apontador no){
    if(no == NULL)
        return -1;
    else{
        int alturaEsq = alturaH(no->esquerda);
        int alturaDir = alturaH(no->direita);
        if(alturaEsq < alturaDir)
            return alturaDir + 1;
        else 
            return alturaEsq + 1;
    }
}

int alturaV(Apontador no){
    if(no == NULL)
        return -1;
    else{
        int alturaEsq = alturaV(no->esquerda);
        int alturaDir = alturaV(no->direita);
        if(no->BitDir == Vertical)
            return alturaDir + 1;
        if(no->BitEsq == Vertical)
            return alturaEsq + 1;
        if (alturaDir == alturaEsq)
            return alturaDir;
    }
}

void imprime(Apontador no){
    if(no == NULL)
      return;
    imprime(no->esquerda);
    printf("\n- %d",no->chave);
    imprime(no->direita);
}