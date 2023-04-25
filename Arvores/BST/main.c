#include "bst.c"

int main(){

    NO *arvore;
    inicializa(&arvore);

    int valor, resposta = 0;

    while(1){
        printf("\n------ ÁRVORE BST------\n1 - Inserir valor\n2 - Pesquisar valor\n3 - Imprimir árvore\n4 - Remover valor\n5 - Altura\n0 - Sair\n");
        scanf("%d", &resposta);
        if(resposta == 0)
            break;
        else if(resposta == 1){
            printf("Digite o valor:\n");
            scanf("%d", &valor);
            insere(&arvore, valor);
        }else if(resposta == 2){
            printf("Digite o valor a ser procurado: \n");
            scanf("%d", &valor);
            pesquisa(&arvore, valor);
        }else if(resposta == 3){
            printf("\n1 - Pre Ordem\n2 - Ordem\n3 - Pos Ordem\n");
            scanf("%d", &resposta);
            switch(resposta){
                case 1:
                    preOrdem(arvore);
                    break;
                case 2:
                    ordem(arvore);
                    break;
                case 3:
                    posOrdem(arvore);
                    break;
            }
        }else if(resposta == 4){
            printf("\nDigite o valor para ser removido:\n");
            scanf("%d", &valor);
            retira(valor, &arvore);
            printf("\n");
        }else if(resposta == 5){
            printf("A altura da árvore é: %d\n", altura(arvore));
        }
        else
            printf("Opção inválida\n");
    }

    return 0;
}