#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;

    /*guarda endereços de structs no's*/
    struct NO *prox;
};
typedef struct NO lista;

/*L guarda o endereço inicial da lista, elemento é o que será procurado, *pre retorna o endereço do nó anterior ao procurado*/
/*a função retorna um caso encontrou e 0 caso não*/
int buscaElem(lista *L, int elemento, lista **pre)
{
    lista *aux, *preL;

    aux = L;
    preL = NULL;

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

lista *insere(lista *L, int elemento)
{
    lista *pre, *el;

    /*caso o elemento não existe*/
    if (!buscaElem(L, elemento, &pre))
    {
        el = (lista *)malloc(sizeof(lista));
        el->info = elemento;

        /*caso a lista esteja vaia ou esse deva ser o primeiro elemento*/
        if (L == NULL || pre == NULL)
        {
            el->prox = L;
            L = el;
        }
        /*caso deva inserir no meio da lista*/
        else
        {
            el->prox = pre->prox;
            pre->prox = el;
        }
    }

    return L;
}

lista *remover(lista *L, int elemento)
{
    lista *pre, *lixo;

    if (buscaElem(L, elemento, &pre))
    {
        if (L->info == elemento)
        {
            lixo = L;
            L = L->prox;
        }
        else
        {
            lixo = pre->prox;
            pre->prox = lixo->prox;
        }
        free(lixo);
    }
    return L;
}

void imprime(lista *L)
{
    lista *aux;

    aux = L;
    while (aux != NULL)
    {
        printf(" %d |", aux->info);
        aux = aux->prox;
    }
}

void main()
{
    lista *L;
    L = NULL;
    int num;

    printf("Digite um número: \n");
    scanf("%d", &num);

    while (num != 0)
    {
        L = insere(L, num);
        printf("Digite um número: \n");
        scanf("%d", &num);
    }

    printf("\n Lista: \n");
    imprime(L);
}