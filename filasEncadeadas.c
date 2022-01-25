#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO fila;

void inserir(fila **inicio, fila **final, int elemento)
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

fila *remover(fila *inicio)
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

void imprimir(fila *inicio)
{
    fila *aux = inicio;

    printf("| %d |", aux->info);
    while (aux->prox != NULL)
    {
        aux = aux->prox;
        printf(" %d |", aux->info);
    }
}

void main()
{
    fila *inicio, *final;
    inicio = NULL;
    final = NULL;

    int numero;
    printf("Digite um número: \n");
    scanf("%d", &numero);

    while (numero >= 0)
    {
        inserir(&inicio, &final, numero);
        printf("Digite um número: \n");
        scanf("%d", &numero);
    }

    imprimir(inicio);
}