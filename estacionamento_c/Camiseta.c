#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char cor_tamanho[30];
} TItem;

typedef struct celula {
    struct celula *pProx;
    TItem item;
} TCelula;

typedef struct {
    TCelula *pPrimeiro, *pUltimo;
} TLista;

void iniciarLista(TLista *pLista);
int isVazia (TLista *pLista);

void iniciarLista (TLista *pLista) {
	pLista->pPrimeiro = NULL;
	pLista->pUltimo = NULL;
}

int isVazia (TLista *pLista) {
	return pLista->pPrimeiro == NULL;
}

void inserir(TLista *pLista, TItem x){
    TCelula *novo = (TCelula *) malloc(sizeof(TCelula));
    novo->item = x;
    novo->pProx = NULL;

    novo->pProx = pLista->pPrimeiro;
    pLista->pPrimeiro = novo;

}

void strTamanho(TCelula *x){
    int tam = strlen(x->item.cor_tamanho);
    int i;
    for(i=0;i<tam;i++){
        if(x->item.cor_tamanho[i-1] == ' '){
            printf("Tamanho: %c\n",x->item.cor_tamanho[i]);
        }
    }

}

void imprimir(TLista *pLista, int n){
    TCelula *pAux;
    int i,j;

    pAux = pLista->pPrimeiro;
    for(i = 0;i<n;i++){
        for(j=0;j<n;j++){
            if(strcmp(pAux->item.cor_tamanho,"Branco")==0){
                printf("%s %s\n",pAux->item.cor_tamanho,pAux->item.nome);
                strTamanho(&pAux->item.cor_tamanho);
            }
            pAux = pAux->pProx;
        }
    }
}

int main(){
    int n,i;
    TItem camisa;
    TLista lista;

    do{
        scanf("%d",&n);
    }while(n<1 || n>60);

    for(i=0;i<n;i++){
        scanf("\n%[^\n]s",camisa.nome);
        scanf("\n%[^\n]s",camisa.cor_tamanho);
        printf("\n");
        inserir(&lista,camisa);
    }
    imprimir(&lista,n);

}