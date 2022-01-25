#include <stdio.h>
#include <stdlib.h>

struct NO
{
    int num;
    int tempo;
    struct NO *prox;
};
typedef struct NO fila;

void inserirElem(fila **inicio, fila **final, int n, int tempoExec)
{
    fila *el;

    el = (fila *)malloc(sizeof(fila));
    el->num = n;
    el->tempo = tempoExec;
    el->prox = NULL;

    if ((*inicio) == NULL)
        (*inicio) = el;
    else
        (*final)->prox = el;
    (*final) = el;
}

fila *removerElem(fila *inicio)
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

void executaProcessos(fila *inicio, fila *final)
{
    while (inicio != NULL)
    {
        if ((inicio->tempo) > 20)
        {
            printf("\nEXECUTANDO O PROCESSO #P%d - 20ut\n", inicio->num);
            inicio->tempo = (inicio->tempo) - 20;
            inserirElem(&inicio, &final, inicio->num, inicio->tempo);
        }
        else
        {
            printf("\nEXECUTANDO O PROCESSO #P%d - %dut\n", inicio->num, inicio->tempo);
        }
        inicio = removerElem(inicio);
    }
    printf("\n---OS PROCESSOS FORAM CONCLUIDOS--");
}

int main(void)
{
    int numProc, tempoProc, qtd;
    fila *inicio, *final;
    inicio = NULL;
    final = NULL;

    printf("\nDigite quantos processos deverao ser executados:");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("\nDigite o numero do processo:");
        scanf("%d", &numProc);
        printf("\nDigite seu tempo de execucao:");
        scanf("%d", &tempoProc);

        inserirElem(&inicio, &final, numProc, tempoProc);
    }

    executaProcessos(inicio, final);

    return 0;
}