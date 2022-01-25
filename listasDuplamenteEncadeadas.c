#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox, *ant;
};
typedef struct NO lista;

int buscaElemento(lista *L, int elemento, lista **pre)
{
    lista *auxiliar, *preL;
    auxiliar = L->prox;
    preL = L;

    while ((auxiliar != L) && (elemento > auxiliar->info))
    {
        preL = auxiliar;
        auxiliar = auxiliar->prox;
    }

    (*pre) = preL;

    if ((auxiliar != L) && (elemento == auxiliar->info))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void *insereElemento(lista *L, int elemento)
{
    lista *pre, *el;

    if (!buscaElemento(L, elemento, &pre))
    {
        el = (lista *)malloc(sizeof(lista));
        el->info = elemento;
        el->prox = pre->prox;
        el->ant = pre;

        pre->prox->ant = el;
        pre->prox = el;
    }
}

void *removeElemento(lista *L, int elemento)
{
    lista *pre, *lixo;

    if (buscaElemento(L, elemento, &pre))
    {
        lixo = pre->prox;
        lixo->ant->prox = lixo->prox;
        lixo->prox->ant = lixo->ant;
        free(lixo);
    }
}

void main()
{
    lista *L;
    L = (lista *)malloc(sizeof(lista));
    L->prox = L;
    L->ant = L;
}