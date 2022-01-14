#include <stdio.h>
#define MAX 100

/*Estrutura a qual define como será a pilha. Nesse caso ela recebe a quantidade máxima de dados e qual é o topo da pilha*/
struct PILHA
{
    /*Os dados da estrutura se referem a um vetor.*/
    int dados[MAX];
    int topo;
};

typedef struct PILHA pilha;

/*Função que adiciona itens à pilha.*/
void push(pilha *P, int num)
{
    /*Caso o topo seja menor que o índice máximo.*/
    if (P->topo < MAX - 1)
    {
        P->topo++;
        P->dados[P->topo] = num;
    }
}

/*Função para remover itens da pilha.*/
int pop(pilha *P)
{
    int num;

    if (P->topo >= 0)
    {
        num = P->dados[P->topo];
        P->topo--;
    }

    return num;
}

void main()
{
    pilha P;
    /*Topo marcado como -1 pois ainda não existe nada no vetor.*/
    P.topo = -1;

    printf("Digite o próximo elemento: \n");
    int elemento;
    scanf("%i", &elemento);

    while (elemento != 0)
    {
        push(&P, elemento);

        printf("Digite o próximo elemento: \n");
        scanf("%i", &elemento);
    }

    for (int i = 0; i <= P.topo; i++)
    {
        printf("%i ", P.dados[i]);
    }
}