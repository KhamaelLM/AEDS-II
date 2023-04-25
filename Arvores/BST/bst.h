#ifndef BST_H
#define BST_H

typedef struct NO * Apontador;

typedef struct NO{
    int chave;
    Apontador esquerda, direita;
}NO;

void inicializa(Apontador *no);

void insere (Apontador *no, int valor);

void imprime(Apontador no);

void preOrdem(Apontador no);

void ordem(Apontador no);

void posOrdem(Apontador no);

void pesquisa(Apontador *no, int valor);

void antecessor(Apontador valor, Apontador *no);

void retira(int valor, Apontador *no);

int altura(Apontador no);

#endif