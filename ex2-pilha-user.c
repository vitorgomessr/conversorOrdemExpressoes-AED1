#include <stdio.h>
#include <math.h>
#include "ex2-estatica-TAD.h"
#include "ex2-dinamica-TAD.h"

int main()
{
    int valida;
    char lei[MAX];
    int aux;

    for(aux=0; aux<MAX; aux++)
    {
        lei[aux]='\0';
    }

    do
    {
        printf("DIGITE A EXPRESSÃO NA FORMA INFIXA: ");
        scanf("%s", lei);

        valida = valida_escopo(lei);

        if(valida==1)
        {
            printf("EXPRESSÃO VALIDADA E SALVA\n\n");
        }
        else if(valida==0)
        {
            printf("EXPRESSÃO INVÁLIDA, mais escopos abertos do que fechados\n");
            printf("TENTE NOVAMENTE!\n\n");
        }
        else if(valida==-1)
        {
            printf("EXPRESSÃO INVÁLIDA, fechamento dos escopos incoerentes\n");
            printf("TENTE NOVAMENTE!\n\n");
        }
        else if(valida==-2)
        {
            printf("EXPRESSÃO INVÁLIDA, chave dentro de colchete ou parentese\n");
            printf("TENTE NOVAMENTE!\n\n");
        }
        else if(valida==-3)
        {
            printf("EXPRESSÃO INVÁLIDA, colchete dentro de parentese\n");
            printf("TENTE NOVAMENTE!\n\n");
        }
        else if(valida==-4)
        {
            printf("EXPRESSÃO INVÁLIDA, caracter inválido digitado\n");
            printf("TENTE NOVAMENTE!\n\n");
        }
        else if(valida==-5)
        {
            printf("EXPRESSÃO INVÁLIDA, mais escopos fechados do que abertos\n");
            printf("TENTE NOVAMENTE!\n\n");
        }

    }while(valida<=0);

    char lei_convertida[MAX];
    for(aux=0; aux<MAX; aux++)
    {
        lei_convertida[aux]='\0';
    }

    if(converte(lei, lei_convertida)==1)
    {
        printf("EXPRESSÃO PÓS-FIXADA: %s\n\n", lei_convertida);
    }
    else
    {
        printf("ERRO NA CONVERSÃO\n");
        return -1;
    }

    struct numeros coleta[6];

    int guard[6];
    for(aux=0; aux<6; aux++)
    {
        guard[aux]=0;
    }

    for(aux=0; lei_convertida[aux]!='\0'; aux++)
    {
        if(lei_convertida[aux]=='A' && guard[0]==0)
        {
            coleta[0].letra = 'A';
            printf("DIGITE O VALOR DE A: ");
            scanf("%f", &coleta[0].dados);
            guard[0]++;
        }
        if(lei_convertida[aux]=='B' && guard[1]==0)
        {
            coleta[1].letra = 'B';
            printf("DIGITE O VALOR DE B: ");
            scanf("%f", &coleta[1].dados);
            guard[1]++;
        }
        if(lei_convertida[aux]=='C' && guard[2]==0)
        {
            coleta[2].letra = 'C';
            printf("DIGITE O VALOR DE C: ");
            scanf("%f", &coleta[2].dados);
            guard[2]++;
        }
        if(lei_convertida[aux]=='D' && guard[3]==0)
        {
            coleta[3].letra = 'D';
            printf("DIGITE O VALOR DE D: ");
            scanf("%f", &coleta[3].dados);
            guard[3]++;
        }
        if(lei_convertida[aux]=='E' && guard[4]==0)
        {
            coleta[4].letra = 'E';
            printf("DIGITE O VALOR DE E: ");
            scanf("%f", &coleta[4].dados);
            guard[4]++;
        }
        if(lei_convertida[aux]=='F' && guard[5]==0)
        {
            coleta[5].letra = 'F';
            printf("DIGITE O VALOR DE F: ");
            scanf("%f", &coleta[5].dados);
            guard[5]++;
        }
    }

    float resultado;
    int avaliado;

    avaliado = avalia(lei_convertida, coleta, &resultado);
    if(avaliado == 1)
    {
        printf("\nRESULTADO DA OPERAÇÃO: %.2f\n", resultado);
        printf("\nPROGRAMA FINALIZADO. VOLTE SEMPRE!\n");
    }
    else if(avaliado == 0)
    {
        printf("\nFALHA NA OPERAÇÃO\n");
    }
    else if(avaliado == -1)
    {
        printf("\nOPERADORES INSUFICIENTES\n");
    }
    else
    {
        printf("\nOPERANDOS INSUFICIENTES\n");
    }

    return 0;
}

int converte(char conta_pre[], char conta_pos[])
{
    Pilha A;
    A = cria_pilha();
    int aux = 0;
    int aux_pos = 0;
    char topo;

    while(conta_pre[aux]!='\0')
    {
        if(conta_pre[aux]=='A'||conta_pre[aux]=='B'||conta_pre[aux]=='C'||
            conta_pre[aux]=='D'||conta_pre[aux]=='E'||conta_pre[aux]=='F')
        {
            conta_pos[aux_pos] = conta_pre[aux];
            aux_pos++;
        }
        else if(conta_pre[aux]=='+'||conta_pre[aux]=='-'||conta_pre[aux]=='*'||
            conta_pre[aux]=='/'||conta_pre[aux]=='^')
        {
            if(conta_pre[aux]=='+')
            {
                le_topo(A, &topo);
                if(topo=='*'||topo=='/'||topo=='^'||topo=='-')
                {
                    pop(A, &topo);
                    conta_pos[aux_pos] = topo;
                    aux_pos++;
                    push(A, conta_pre[aux]);
                }
                else
                {
                    push(A, conta_pre[aux]);
                }
            }
            else if(conta_pre[aux]=='-')
            {
                le_topo(A, &topo);
                if(topo=='*'||topo=='/'||topo=='^'||topo=='+')
                {
                    pop(A, &topo);
                    conta_pos[aux_pos] = topo;
                    aux_pos++;
                    push(A, conta_pre[aux]);
                }
                else
                {
                    push(A, conta_pre[aux]);
                }
            }
            else if(conta_pre[aux]=='*')
            {
                if(pilha_vazia(A) == 1)
                {
                    push(A, conta_pre[aux]);
                }
                else
                {
                    le_topo(A, &topo);
                    if(topo=='/'||topo=='*'||topo=='^')
                    {
                        pop(A, &topo);
                        conta_pos[aux_pos] = topo;
                        aux_pos++;
                        push(A, conta_pre[aux]);
                    }
                    else
                    {
                        push(A, conta_pre[aux]);
                    }
                }
            }
            else if(conta_pre[aux]=='/')
            {
                if(pilha_vazia(A) == 1)
                {
                    push(A, conta_pre[aux]);
                }
                else
                {
                    le_topo(A, &topo);
                    if(topo=='/'||topo=='*'||topo=='^')
                    {
                        pop(A, &topo);
                        conta_pos[aux_pos] = topo;
                        aux_pos++;
                        push(A, conta_pre[aux]);
                    }
                    else
                    {
                        push(A, conta_pre[aux]);
                    }
                }
            }
            else if(conta_pre[aux]=='^')
            {
                le_topo(A, &topo);
                if(topo=='^')
                {
                    pop(A, &topo);
                    conta_pos[aux_pos] = topo;
                    aux_pos++;
                    push(A, conta_pre[aux]);
                }
                else
                {
                    push(A, conta_pre[aux]);
                }
            }
        }
        else if(conta_pre[aux]=='('||conta_pre[aux]==')')
        {
            if(conta_pre[aux]=='(')
            {
                push(A, conta_pre[aux]);
            }
            else
            {
                le_topo(A, &topo);
                while(topo!='(')
                {
                    pop(A, &topo);
                    conta_pos[aux_pos] = topo;
                    aux_pos++;
                    le_topo(A, &topo);
                }
                pop(A, &topo);
            }
        }
        else if(conta_pre[aux]=='['||conta_pre[aux]==']')
        {
            if(conta_pre[aux]=='[')
            {
                push(A, conta_pre[aux]);
            }
            else
            {
                le_topo(A, &topo);
                while(topo!='[')
                {
                    pop(A, &topo);
                    conta_pos[aux_pos] = topo;
                    aux_pos++;
                    le_topo(A, &topo);
                }
                pop(A, &topo);
            }
        }
        else if(conta_pre[aux]=='{'||conta_pre[aux]=='}')
        {
            if(conta_pre[aux]=='{')
            {
                push(A, conta_pre[aux]);
            }
            else
            {
                le_topo(A, &topo);
                while(topo!='{')
                {
                    pop(A, &topo);
                    conta_pos[aux_pos] = topo;
                    aux_pos++;
                    le_topo(A, &topo);
                }
                pop(A, &topo);
            }
        }
        else if(conta_pre[aux]!='\0')
        {
            break;
        }
        else
        {
            return 0;
        }
        aux++;
    }

    while(pilha_vazia(A)!=1)
    {
        le_topo(A, &topo);
        if(topo!='(')
        {
            pop(A, &topo);
            conta_pos[aux_pos] = topo;
            aux_pos++;
        }
        else
        {
            pop(A, &topo);
        }
    }

    return 1;
}

int valida_escopo(char conta[])
{
    Pilha A;
    A = cria_pilha();
    char topo1;

    int aux = 0;
    while(conta[aux]!='\0')
    {
        if(conta[aux]=='(' || conta[aux]=='[' || conta[aux]=='{')
        {
            if(pilha_vazia(A)==1)
            {
                push(A, conta[aux]);
            }

            else
            {
                le_topo(A, &topo1);

                if((conta[aux]=='{') && (topo1=='[' || topo1=='('))
                {
                    return -2;          // chave dentro de parenteses ou colchete
                }
                else if(conta[aux]=='[' && topo1=='(')
                {
                    return -3;          // colchete dentro de parenteses
                }
                else
                {
                    push(A, conta[aux]);
                }
            }
        }

        else if(conta[aux]==')' || conta[aux]==']' || conta[aux]=='}')
        {
            le_topo(A, &topo1);
            if(pilha_vazia(A)==1)
            {
                return -5;              // mais escopos fechados do que o necessario
            }
            if(conta[aux]==')' && topo1=='(')
            {
                pop(A, &topo1);
            }
            else if(conta[aux]==']' && topo1=='[')
            {
                pop(A, &topo1);
            }
            else if(conta[aux]=='}' && topo1=='{')
            {
                pop(A, &topo1);
            }
            else
            {
                return -1;               // falha escopo fecha sem abrir
            }
        }
        else if(conta[aux]!='+'&&conta[aux]!='-'&&conta[aux]!='/'&&
                    conta[aux]!='*'&&conta[aux]!='^'&&conta[aux]!='A'&&
                    conta[aux]!='B'&&conta[aux]!='C'&&conta[aux]!='D'&&
                    conta[aux]!='E'&&conta[aux]!='F')
        {
            return -4;                  // caracter inválido
        }
        aux++;
    }

    if(pilha_vazia(A)==1)
    {
        return 1;                       // sucesso
    }
    else
    {
        return 0;                      // mais escopos abertos do que fechados
    }
}

int avalia(char lei[], struct numeros coleta[], float *res)
{
    int aux;
    int verifica[2];
    verifica[0] = 0;
    verifica[1] = 0;

    for(aux=0; lei[aux]!='\0'; aux++)
    {
        if(lei[aux]>=65 && lei[aux]<=70)
        {
            verifica[0]++;
        }
        else
        {
            verifica[1]++;
        }
    }

    if(verifica[0]-verifica[1]>1)
    {
        return -1;           // faltam operadores
    }
    if(verifica[0]-verifica[1]<1)
    {
        return -2;          // faltam operandos
    }

    Pilhad A;
    A = cria_pilhad();

    float conta1;
    float conta2;

    for(aux=0; lei[aux]!='\0'; aux++)
    {
        if(lei[aux]>=65 && lei[aux]<=70)
        {
            if(lei[aux]=='A')
            {
                pushd(&A, coleta[0].dados);
            }
            else if(lei[aux]=='B')
            {
                pushd(&A, coleta[1].dados);
            }
            else if(lei[aux]=='C')
            {
                pushd(&A, coleta[2].dados);
            }
            else if(lei[aux]=='D')
            {
                pushd(&A, coleta[3].dados);
            }
            else if(lei[aux]=='E')
            {
                pushd(&A, coleta[4].dados);
            }
            else
            {
                pushd(&A, coleta[5].dados);
            }
        }
        else
        {
            popd(&A, &conta1);
            popd(&A, &conta2);

            if(lei[aux]=='*')
            {
                conta1 = conta1*conta2;
                pushd(&A, conta1);
            }
            else if(lei[aux]=='/')
            {
                conta1 = conta2/conta1;
                pushd(&A, conta1);
            }
            else if(lei[aux]=='+')
            {
                conta1 = conta2+conta1;
                pushd(&A, conta1);
            }
            else if(lei[aux]=='-')
            {
                conta1 = conta2-conta1;
                pushd(&A, conta1);
            }
            else
            {
                conta1 = pow(conta2, conta1);
                pushd(&A, conta1);
            }
        }
    }
    popd(&A, &*res);

    if(pilha_vaziad(A)==1)
    {
        return 1;           // sucesso
    }
    else
    {
        return 0;           // falha
    }
}
