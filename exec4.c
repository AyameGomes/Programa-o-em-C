#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO fila;
typedef struct NO pilha;

pilha *inserePilha(pilha *topo, int elemento)
{
    pilha *el;
    el = (pilha *)malloc(sizeof(pilha));

    el->info = elemento;
    el->prox = topo;

    topo = el;

    return topo;
}

pilha *removerPilha(pilha *topo)
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

void imprimirPilha(pilha *topo)
{
    pilha *aux = topo;

    printf("| %d |", aux->info);
    while (aux->prox != NULL)
    {
        aux = aux->prox;
        printf(" %d |", aux->info);
    }
}

void inserirFila(fila **inicio, fila **final, int elemento)
{
    fila *el;

    el = (fila *)malloc(sizeof(fila));
    el->info = elemento;
    el->prox = NULL;

    if ((*inicio) == NULL)
    {
        (*inicio) = el;
    }
    else
    {
        (*final)->prox = el;
    }

    (*final) = el;
}

fila *removerFila(fila *inicio)
{
    fila *lixo;

    if (inicio != NULL)
    {
        lixo = inicio;
        inicio = inicio->prox;
        free(lixo);
    }

    return inicio;
}

void main()
{
    fila *inicio, *final;
    inicio = NULL;
    final = NULL;

    pilha *topo;
    topo = NULL;

    int numero;
    printf("Digite um número: \n");
    scanf("%d", &numero);

    while (numero >= 0)
    {
        inserirFila(&inicio, &final, numero);
        printf("Digite um número: \n");
        scanf("%d", &numero);
    }

    if (inicio->info % 2 == 0)
    {
        topo = inserePilha(topo, inicio->info);
    }
    while (inicio->prox != NULL)
    {
        inicio = removerFila(inicio);
        if (inicio->info % 2 == 0)
        {
            topo = inserePilha(topo, inicio->info);
        }
    }

    imprimirPilha(topo);
}