#include <stdio.h>
#define MAX 100

struct LISTA
{
    int dados[MAX];
    int total;
};
typedef struct LISTA lista;

int buscarBin(lista *L, int elemento, int *pos)
{
    int inicio, fim, meio, achou = 0;
    inicio = 0;
    fim = L->total - 1;

    while (inicio <= fim && !achou)
    {
        meio = (inicio + fim) / 2;

        if (elemento > L->dados[meio])
        {
            inicio = meio + 1;
            (*pos) = inicio;
        }
        else
        {
            if (elemento < L->dados[meio])
            {
                fim = meio - 1;
                (*pos) = meio;
            }
            else
            {
                if (elemento == L->dados[meio])
                {
                    achou = 1;
                    (*pos) = meio;
                }
            }
        }
    }

    return achou;
}

int buscar(lista *L, int elemento, int *pos)
{
    int i = 0;

    while (i < L->total && elemento > L->dados[i])
    {

        i++;
    }

    (*pos) = i;

    if (L->total == i)
    {
        return 0;
    }
    else
    {
        if (elemento == L->dados[i])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void imprimir(lista *L)
{
    for (int i = 0; i < L->total; i++)
    {
        printf("%d ", L->dados[i]);
    }

    printf("\n");
}

void inserir(lista *L, int elemento)
{
    int pos, i, existe;

    existe = buscar(L, elemento, &pos);

    if (!existe)
    {
        for (i = L->total; i > pos; i--)
        {
            L->dados[i] = L->dados[i - 1];
        }

        L->dados[i] = elemento;
        L->total++;
    }
}

void remover(lista *L, int elemento)
{
    int pos, i, existe;

    existe = buscar(L, elemento, &pos);

    if (existe)
    {
        for (i = pos; i < L->total - 1; i++)
        {
            L->dados[i] = L->dados[i + 1];
        }

        L->total--;
    }
}

void main()
{
    lista L;
    L.total = 0;

    int numero;
    for (int i = 0; i < 5; i++)
    {

        scanf("%d", &numero);
        inserir(&L, numero);
    }

    imprimir(&L);

    scanf("%d", &numero);
    remover(&L, numero);

    imprimir(&L);
}