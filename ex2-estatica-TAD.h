typedef struct pilha * Pilha;

#define MAX 21

Pilha cria_pilha();
int pilha_vazia(Pilha P);
int pilha_cheia(Pilha P);
int push(Pilha P, char elem);
int pop(Pilha P, char *elem);
int le_topo(Pilha P, char *elem);
int valida_escopo(char conta[]);
int converte(char conta_pre[], char conta_pos[]);
