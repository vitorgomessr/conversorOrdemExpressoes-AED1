typedef struct no * Pilhad;

struct numeros
    {
        char letra;
        float dados;
    };

Pilhad cria_pilhad();
int pilha_vaziad(Pilhad P);
int pushd(Pilhad *P, float elem);
int popd(Pilhad *P, float *elem);
int le_topod(Pilhad P, float elem);
int avalia(char lei[], struct numeros coleta[], float *res);
