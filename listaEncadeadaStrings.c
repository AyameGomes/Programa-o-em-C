#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NO
{
    char info[10];
    struct NO *prox;
};
typedef struct NO lista;

int menu()
{
    int op;

    printf("Escolha uma operação: \n");
    printf("1: Insere \n");
    printf("2: Remove \n");
    printf("3: Mostra \n");
    printf("4: Conta Elementos \n");
    printf("1: Fim \n");
    scanf("%d", &op);
    return op;
}

int buscaElemento(lista *L, char *fruta, lista **pre)
{
    lista *aux, *preL;

    aux = L->prox;
    preL = L;

    while ((aux != NULL) && (strcmp(fruta, aux->info) > 0))
    {
        preL = aux;
        aux = aux->prox;
    }

    (*pre) = preL;
    if ((aux != NULL) && (strcmp(fruta, aux->info) == 0))
    {
        return 1;
    }
    return 0;
}

lista *insereElemento(lista *L, char *fruta)
{
    lista *pre, *el;

    if (!buscaElemento(L, fruta, &pre))
    {
        el = (lista *)malloc(sizeof(lista));
        strcpy(el->info, fruta);
        el->prox = pre->prox;
        pre->prox = el;
    }
    else
    {
        printf("Elemento já existe! \n");
    }

    return L;
}

void removeElem(lista *L, char *fruta)
{
    lista *pre, *lixo;

    if (buscaElemento(L, fruta, &pre))
    {
        lixo = pre->prox;
        pre->prox = lixo->prox;
        free(lixo);
    }
    else
    {
        printf("Elemento não existe! \n");
    }
}

int contaElementos(lista *L)
{
    if (L != NULL)
    {
        return (contaElementos(L->prox) + 1);
    }
    else
    {
        return 0;
    }
}

void imprimeLista(lista *L)
{
    if (L != NULL)
    {
        printf("%s \n", L->info);
        imprimeLista(L->prox);
    }
}

void main()
{
    lista *L;
    char fruta[10];
    L = (lista *)malloc(sizeof(lista));
    L->prox = NULL;

    int op;
    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("Digite o elemento: \n");
            scanf("%s", fruta);
            insereElemento(L, fruta);
            break;

        case 2:
            printf("Digite o elemento: \n");
            scanf("%s", fruta);
            removeElem(L, fruta);
            break;

        case 3:
            imprimeLista(L->prox);
            break;

        case 4:
            printf("A lista possui %d elementos. \n", contaElementos(L->prox));
            break;

        case 5:
            break;

        default:
            printf("Opção inválida! \n");
        }
    } while (op != 5);
}