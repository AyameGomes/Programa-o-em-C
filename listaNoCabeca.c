#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO lista;

int buscaElemento(lista *L, int elemento, lista **pre)
{
    lista *aux, *preL;

    aux = L->prox;
    preL = L;

    while ((aux != NULL) && (elemento > aux->info))
    {
        preL = aux;
        aux = aux->prox;
    }

    (*pre) = preL;
    if ((aux != NULL) && (elemento == aux->info))
    {
        return 1;
    }
    return 0;
}

lista *insereElemento(lista *L, int elemento)
{
    lista *pre, *el;

    if (!buscaElemento(L, elemento, &pre))
    {
        el = (lista *)malloc(sizeof(lista));
        el->info = elemento;
        el->prox = pre->prox;
        pre->prox = el;
    }

    return L;
}

lista *removeElemento(lista *L, int elemento)
{
    lista *pre, *lixo;

    if (buscaElemento(L, elemento, &pre))
    {
        lixo = pre->prox;
        pre->prox = lixo->prox;
        free(lixo);
    }

    return L;
}

void main()
{
    lista *L;
    L = (lista *)malloc(sizeof(lista));
    L->prox = NULL;
}