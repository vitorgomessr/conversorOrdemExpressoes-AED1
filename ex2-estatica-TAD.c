#include <stdio.h>
#include <stdlib.h>
#include "ex2-estatica-TAD.h"

struct pilha
{
    int topo;
    char vet[MAX];
};


Pilha cria_pilha()
{
    Pilha P;
    P = (Pilha)malloc(sizeof(struct pilha));

    if (P != NULL)
    {
        P->topo = 0;
    }
    return P;
}


int pilha_vazia(Pilha P)
{
    if(P->topo == 0)
    {
        return 1;
    }

    return 0;
}

int pilha_cheia(Pilha P)
{
    if(P->topo == MAX-1)
    {
        return 1;
    }
    return 0;
}

int push(Pilha P, char elem)
{
    if(P == NULL || pilha_cheia(P)==1)
    {
        return 0;
    }
    else
    {
        P->vet[P->topo] = elem;
        P->topo++;

        return 1;
    }
}

int pop(Pilha P, char *elem)
{
    if(P==NULL || pilha_vazia(P)==1)
    {
        return 0;
    }

    P->topo--;
    *elem = P->vet[P->topo];

    return 1;
}

int le_topo(Pilha P, char *elem)
{
    if(P == NULL || pilha_vazia(P) == 1)
    {
        return 0;
    }
    else
    {
        *elem = P->vet[P->topo-1];
        return 1;
    }
}
