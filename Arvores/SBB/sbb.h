#ifndef SBB_H
#define SBB_H

typedef enum{
    Vertical, Horizontal
}Inclinacao;

typedef struct NO *Apontador;

typedef struct NO{
    int chave;
    Apontador esquerda, direita;
    Inclinacao BitEsq, BitDir;
}NO;

void inicializa(Apontador *no);

void Insere(int valor, Apontador *Ap);

void IInsere(int valor, Apontador *Ap, Inclinacao *IAp, short *Fim);

void EE(Apontador *Ap);

void ED(Apontador *Ap);

void DD(Apontador *Ap);   

void DE(Apontador *Ap);

void pesquisa(int valor, Apontador *no);

int altura(Apontador no);

void imprime(Apontador no);

#endif
