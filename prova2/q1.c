#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO lista;

lista *insereFinal(lista *L, int elem)
{
    lista *el;
    lista *aux;
    aux = L;
    int achou = 0;

    while (aux != NULL)
    {
        if (elem == aux->info)
            achou = 1;
        aux = aux->prox;
    }
    if (!achou)
    {
        el = (lista *)malloc(sizeof(lista));
        el->info = elem;
        el->prox = L;
        L = el;
    }
    else
    {
        printf("Elemento %d ja existe\n", elem);
    }
    return L;
}

void imprimeListas(lista *L)
{
    lista *aux;
    aux = L;

    while (aux != NULL)
    {
        printf("-> %d ", aux->info);
        aux = aux->prox;
    }
}

lista *intercala(lista *L1, lista *L2)
{
    lista *aux1, *aux2;

    aux1 = L1;
    aux2 = L1->prox;

    while (aux1 != NULL)
    {
        aux1->prox = L2;
        aux1 = L2;

        L2 = L2->prox;
        aux1->prox = aux2;

        if (aux2 != NULL)
            aux2 = aux2->prox;

        aux1 = aux1->prox;
    }
    return L1;
}

int main(void)
{
    lista *L1, *L2;
    int num, MAX;

    L1 = NULL, L2 = NULL;
    printf("Digite quantos numeros voce quer inserir em cada lista:");
    scanf("%d", &MAX);

    for (int i = 0; i < MAX; i++)
    {
        printf("Digite um numero:");
        scanf("%d", &num);

        L1 = insereFinal(L1, num);
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("Digite um numero:");
        scanf("%d", &num);

        L2 = insereFinal(L2, num);
    }

    printf("\n\nLista 1 ");
    imprimeListas(L1);

    printf("\n\nLista 2 ");
    imprimeListas(L2);

    L1 = intercala(L1, L2);
    printf("\n\n(L1 e L2): ");

    imprimeListas(L1);

    return 0;
}