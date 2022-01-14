#include <stdio.h>

struct NO
{
    int id;
    char nome[40];

    /*guarda endereços de structs no's*/
    struct NO *prox;
};
typedef struct NO lista;

void main()
{
    /*guarda o endereço inicial da lista, do primeiro no*/
    lista *L, *aux;
    /*L é o endereço do primeiro no, quando L igual a null, a lista está vazia e simplesmente inicializada*/
    L = NULL;

    /*aloca memória do tamanho de struct lista*/
    aux = (lista *)malloc(sizeof(lista));
}
