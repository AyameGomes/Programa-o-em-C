#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int info;
    struct NO *prox;
};
typedef struct NO lista;

int menu()
{
    int escolha;

    printf("Menu: \n");
    printf("1: inserir elemento na lista 1. \n");
    printf("2: inserir elemento na lista 2. \n");
    printf("3 mostrar a lista 1 e a lista 2. \n");
    printf("4: mostrar a intersecção da lista 1 com a lista 2. \n");
    printf("5: mostrar a união da lista 1 com a lista 2. \n");
    printf("6: fim do programa. \n");

    scanf("%d", &escolha);
    return escolha;
}

int buscaElemento(lista *L, int elemento)
{
    lista *aux, *preL;

    aux = L->prox;

    while ((aux != NULL) && (elemento > aux->info))
    {
        aux = aux->prox;
    }

    if ((aux != NULL) && (elemento == aux->info))
    {
        return 1;
    }
    return 0;
}

lista *insereElemento(lista *L, int elemento)
{
    lista *el;

    if (!buscaElemento(L, elemento))
    {
        el = (lista *)malloc(sizeof(lista));
        el->info = elemento;
        el->prox = L->prox;
        L->prox = el;
    }

    return L;
}

lista *removeElemento(lista *L, int elemento)
{
    lista *pre, *lixo;

    if (buscaElemento(L, elemento))
    {
        lixo = pre->prox;
        pre->prox = lixo->prox;
        free(lixo);
    }

    return L;
}

void imprimeLista(lista *L)
{
    if (L != NULL)
    {
        printf("%d |", L->info);
        imprimeLista(L->prox);
    }
}

void uniao(lista *L1, lista *L2, lista *Luniao)
{
    lista *aux;
    aux = L1;

    while ((aux->prox != NULL))
    {
        aux = aux->prox;
        if (buscaElemento(L2, aux->info))
        {
            insereElemento(Luniao, aux->info);
        }
    }
}

void intersec(lista *L1, lista *L2, lista *Lintersec)
{
    lista *aux1 = L1;
    lista *aux2 = L2;

    while (aux1->prox != NULL)
    {
        aux1 = aux1->prox;
        insereElemento(Lintersec, aux1->info);
    }

    while (aux2->prox != NULL)
    {
        aux2 = aux2->prox;
        insereElemento(Lintersec, aux2->info);
    }
}

void main()
{
    lista *L1;
    L1 = (lista *)malloc(sizeof(lista));
    L1->prox = NULL;

    lista *L2;
    L2 = (lista *)malloc(sizeof(lista));
    L2->prox = NULL;

    lista *Lintersec;
    Lintersec = (lista *)malloc(sizeof(lista));
    Lintersec->prox = NULL;

    lista *Luniao;
    Luniao = (lista *)malloc(sizeof(lista));
    Luniao->prox = NULL;

    int escolha;
    do
    {
        escolha = menu();

        if (escolha == 1)
        {
            int elemento;
            printf("Digite o elemento a ser inserido: \n");
            scanf("%d", &elemento);
            insereElemento(L1, elemento);
        }

        if (escolha == 2)
        {
            int elemento;
            printf("Digite o elemento a ser inserido: \n");
            scanf("%d", &elemento);
            insereElemento(L2, elemento);
        }

        if (escolha == 3)
        {
            printf("Lista 1: \n");
            imprimeLista(L1->prox);
            printf("\n");

            printf("Lista 2: \n");
            imprimeLista(L2->prox);
            printf("\n");
        }

        if (escolha == 4)
        {
            intersec(L1, L2, Lintersec);
            printf("Intersecção das duas listas: \n");
            imprimeLista(Lintersec->prox);
            printf("\n");
        }

        if (escolha == 5)
        {
            intersec(L1, L2, Luniao);
            printf("União das duas listas: \n");
            imprimeLista(Luniao->prox);
            printf("\n");
        }

    } while (escolha != 6);
}