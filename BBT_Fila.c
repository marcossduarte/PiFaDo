#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sNoFila{ // cria a estrutura do no da fila para ser usado no baralho.... qual?
    int carta,naipe;
    struct sNoFila *dir;
}NoFila;

typedef struct sFila{
    NoFila *inicio;
    NoFila *final;
}Fila;

NoFila* alocaNoFila(){ // aloca um no na memoria
    return (NoFila*) malloc(sizeof(NoFila));
}

void initFila(Fila *ptrF){ // inicializa a filha com null
    //ptrF = (Fila*) malloc(sizeof(Fila));
    ptrF->inicio = NULL; 
    ptrF->final = NULL;
}

int vazioFila(Fila *ptrF){ // verifica se a fila essta vazia comparando o conteudo da mesma
    if(ptrF->inicio == NULL) return 1;
    if(ptrF->final == NULL) return 1;
    return 0;
}

void insereFila(Fila *ptrF, int carta, int naipe){
    if(ptrF == NULL) return;
    NoFila *novo; //cria um novo no na fila
    novo = alocaNoFila(); //aloca o no na memoria
    novo->dir = NULL; // inicializa ele com null ??

    novo->carta = carta; //passa os conteudos pro no criado
    novo->naipe = naipe;

    if(ptrF->inicio == NULL){ //se a fila estiver vazia, adiciona no inicio da fila
    
        ptrF->inicio = novo; 
        ptrF->final = novo;
        return;
    }
    ptrF->final->dir = novo; // se não estiver, aponta o conteúdo do ultimo elemento pro novo criado
    ptrF->final = novo; // atualiza o final com o conteudo do novo no
}

void removeFila(Fila *ptrF){//remove no inicio da lista
    if(ptrF == NULL){ 
        printf("Lista nao alocada!\n");
        return;
    } 
    if(ptrF->inicio == NULL){
        printf("Lista vazia!\n");
    }

    NoFila *novo;
    novo = alocaNoFila();
    novo = ptrF->inicio; //aux recebe o no que esta no inicio
    ptrF->inicio = ptrF->inicio->dir; // o inicio da lista recebe o 2 elemento da lista;

    if(ptrF->inicio == NULL){ //se nao tiver nada na lista
        ptrF->final = NULL; //o fim da lista recebe null
    }    
    free(novo);// libera o no
}

void inicioFila(Fila *ptrF){ //imprimir a fila?
    if(ptrF == NULL) return;
    if(vazioFila(ptrF)) return;
    
    printf("%d%d\n", ptrF->inicio->carta, ptrF->inicio->naipe); //imprime a fila com as cartas e seus naipes
}

void listaFilaClassico(Fila *ptrF){ //imprime a fila removendo
    if(ptrF == NULL) return;
    if(vazioFila(ptrF)) return;
    while(!vazioFila(ptrF)){ //enquanto nao estiver vazio
        printf("%d%d\n", ptrF->inicio->carta, ptrF->inicio->naipe); //printa o conteudo
        removeFila(ptrF); // remove o que foi printado
    }
}
