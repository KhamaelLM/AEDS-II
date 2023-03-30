#include "bst.c"

int main(){

    NO *arvore;
    inicializa(&arvore);

    int valor, resposta = 0;

    while(1){
        printf("\n------ ÁRVORE BST------\n1 - Inserir valor\n2 - Pesquisar valor\n3 - Imprimir árvore\n4 - Remover valor\n0 - Sair\n");
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
            imprime(arvore);
        }else if(resposta == 4){
            printf("\nEm breve!\n");
        }
        else
            printf("Opção inválida\n");
    }

    return 0;
}