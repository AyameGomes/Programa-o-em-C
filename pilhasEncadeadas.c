#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO pilha;

pilha *insere(pilha *topo, int elemento)
{
    pilha *el;
    el = (pilha *)malloc(sizeof(pilha));

    el->info = elemento;
    el->prox = topo;

    topo = el;

    return topo;
}

pilha *remover(pilha *topo)
{
    pilha *lixo;

    if (topo != NULL)
    {
        lixo = topo;
        topo = topo->prox;
        free(lixo);
    }

    return topo;
}

void imprimir(pilha *topo)
{
    pilha *aux = topo;

    printf("| %d |", aux->info);
    while (aux->prox != NULL)
    {
        aux = aux->prox;
        printf(" %d |", aux->info);
    }
}

void main()
{
    pilha *topo;
    topo = NULL;

    int numero;
    printf("Digite um número: \n");
    scanf("%d", &numero);

    while (numero >= 0)
    {
        topo = insere(topo, numero);
        printf("Digite um número: \n");
        scanf("%d", &numero);
    }

    if (topo != NULL)
    {
        imprimir(topo);
    }
    else
    {
        printf("Lista vazia! \n");
    }
}