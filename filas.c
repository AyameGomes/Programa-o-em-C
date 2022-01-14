#include <stdio.h>
#define MAX 100

/*Início indica o índice do primeiro elemento, final indica o próximo índica vazio após o último elemento.*/
struct FILA
{
    int dados[MAX];
    int inicio, final, total;
};

typedef struct FILA fila;

void inserir(fila *F, int num)
{
    if (F->total < MAX)
    {
        F->dados[F->final] = num;
        F->final++;
        F->final = F->final % MAX;
        F->total++;
    }
}

int remove(fila *F)
{
    int num;

    if (F->total > 0)
    {
        num = F->dados[F->inicio];
        F->inicio++;
        F->inicio = F->inicio % MAX;
        F->total--;
    }

    return num;
}

void main()
{
    fila F;
    F.inicio = 0;
    F.final = 0;
    F.total = 0;
}