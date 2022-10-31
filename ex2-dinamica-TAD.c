#include<string.h>
#include<stdlib.h>

#include"ex2-dinamica-TAD.h"

struct no
{
    float info;
    struct no *prox;
};


Pilhad cria_pilhad()
{
    return NULL;
}

int pilha_vaziad(Pilhad P)
{
    if(P == NULL)
    {
        return 1;
    }

    return 0;
}


int pushd(Pilhad *P, float elem)
{
    Pilhad N = (Pilhad)malloc(sizeof(struct no));

    if(N == NULL)
    {
        return 0;
    }

    N->info = elem;
    N->prox = *P;
    *P = N;

    return 1;
}

int popd(Pilhad *P, float *elem)
{
    if(pilha_vaziad(*P)== 1)
    {
        return 0;
    }
    Pilhad aux = *P;

    *elem = aux->info;

    *P = aux->prox;
    free(aux);
    return 1;
}

int le_topod(Pilhad P, float elem)
{
    if(pilha_vaziad(P)==1)
    {
        return 0;
    }

    elem = P->info;
    return 1;
}
