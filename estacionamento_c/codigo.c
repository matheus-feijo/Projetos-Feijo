#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char placa[10];
    char marca[20];
} TItem;

typedef struct celula {
	struct celula *pProx;
	TItem item;
} TCelula;

typedef struct {
	TCelula *pTopo;
	int tamanho;
} TPilha;

void iniciarPilha(TPilha *pPilha);
int isVazia(TPilha *pPilha);
void push(TPilha *pPilha, TItem x);
void pop(TPilha *pPilha,TItem *px);
void imprimir(TPilha *pPilha);
int verificaQnt(TPilha *pPilha);

void iniciarPilha(TPilha *pPilha){
    pPilha->pTopo = NULL;
    pPilha->tamanho = 0;
}

int isVazia(TPilha *pPilha){
    return pPilha->pTopo == NULL;
}

void push(TPilha *pPilha, TItem x){
    TCelula *novo = (TCelula *) malloc(sizeof(TCelula));
    novo->item = x;

    novo->pProx = pPilha->pTopo;
    pPilha->pTopo = novo;
    pPilha->tamanho++;

}

void pop(TPilha *pPilha, TItem *px){
    TCelula *pAux;

    pAux = pPilha->pTopo;

    pPilha->pTopo = pPilha->pTopo->pProx;
    *px = pAux->item;
    free(pAux);
    pPilha->tamanho--;
}

void peek(TPilha *pPilha){

}

void imprimir(TPilha *pPilha){
    TCelula *pAux;

    pAux= pPilha->pTopo;

    while(pAux != NULL){
        printf("Item: %d\n",pAux->item);
        pAux = pAux->pProx;
    }
}

int verificaQnt(TPilha *pPilha){
    return pPilha->tamanho;
}

int main(){
    TPilha pilha;
    char comand[3];
    TItem car, cRemovido;

    iniciarPilha(&pilha);
    isVazia(&pilha);

    while(strcmp(comand," ")){
        printf("\tESTACIONAMENTO\n");
        printf("Entrada de veiculos: digite 'E'\n");
        printf("Saida de veiculos: digite 'S'\n");
        printf(">");
        scanf("%c",comand);

      if(strcmp(comand,"E")==0){
                if(verificaQnt(&pilha) <10){
                    printf("VAGA LIBERADA:\n");
                    printf("Placa do carro: ");
                    scanf("%s",car.placa);
                    printf("Marca do carro: ");
                    scanf("%s",car.marca);
                    push(&pilha,car);
                    printf("Carro estacionado.\n");
                }else{
                    printf("VAGA NAO LIBERADA.\n");
                    printf("Quantidade de veiculos excedida.\n");
                }
        }else if(strcmp(comand,"S")==0){
            if(isVazia(&pilha)){
                printf("Estacionamento esta vazio.\n");
            }else{
                pop(&pilha,&cRemovido);
                printf("Carro: %s\t Placa: %s \nSaiu do estacionamento\n",cRemovido.marca,cRemovido.placa);
            }
        }
    }

    return 0;
}