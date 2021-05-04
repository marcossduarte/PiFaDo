#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoFila{
    char carta[2];
    struct sNoFila *dir;
}NoFila;

typedef struct sFila{
    NoFila *inicio;
    NoFila *final;
}Fila;

NoFila* alocaNoFila(){
    return (NoFila*) malloc(sizeof(NoFila));
}

void initFila(Fila *ptrF){
    ptrF->inicio = NULL;
    ptrF->final = NULL;
}

int vazioFila(Fila *ptrF){
    if(ptrF->inicio == NULL) return 1;
    if(ptrF->final == NULL) return 1;
    return 0;
}

void insereFila(Fila *ptrF, char *elem){
    if(ptrF == NULL) return;
    NoFila *novo;
    novo = alocaNoFila();
    novo->dir = NULL;

    strcpy(novo->carta, elem);

    if(ptrF->inicio == NULL){
    
        ptrF->inicio = novo;
        ptrF->final = novo;
        return;
    }
    ptrF->final->dir = novo;
    ptrF->final = novo;
}

void removeFila(Fila *ptrF){
    if(ptrF == NULL){
        printf("Lista nao alocada!\n");
        return;
    } 
    if(ptrF->inicio == NULL){
        printf("Lista vazia!\n");
    }

    NoFila *novo;
    novo = alocaNoFila();
    novo = ptrF->inicio;
    ptrF->inicio = ptrF->inicio->dir;

    if(ptrF->inicio == NULL){
        ptrF->final = NULL;
    }    
    free(novo);
}

void listaFilaClassico(Fila *ptrF){
    if(ptrF == NULL) return;
    if(vazioFila(ptrF)) return;

    printf("%s\n", ptrF->inicio->carta);
}
