#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sLSE{ //precisa trocar pra LDE
    int carta, naipe;
    struct sLSE *dir;
    struct sLSE *esq; 
}LSE;

void initLSE(LSE **ptrLSE){ //inicializa a lista com null. tem que inicializar esq e dir. nao?
   // *ptrLSE = alocarLSE();
    *ptrLSE = NULL;
}

LSE* alocarLSE(){
    return (LSE*) malloc(sizeof(LSE));
}

int listaVaziaLSE(LSE *ptrLSE){  // verifica se a lista esta vazia
    if(ptrLSE == NULL){ 
        printf("Lista Vazia!\n"); 
        return 1;
    }else{
        return 0;
    }
}

void inserirInicioLSE(LSE **ptrLista, int carta, int naipe){
    LSE *aux;

    aux = alocarLSE(); //alocamos o no aux criado
    
    if(aux != NULL){ // se o no foi alocado corretamente
        aux->carta = carta; //insere o conteudo desejado no no criado - carta
        aux->naipe = naipe; // insere o conteudo desejado no no criado - naipe
        aux->dir = (*ptrLista); // aponta o no pro inicio da lista, colocando o mesmo na 1 posição
        *ptrLista = aux; // atualiza o endereço de onde a lista estava aprontando para o novo inicio criado
    }else{
        printf("Erro ao alocar o LSE.\n"); // erro pq nao deu certo a alocação
        exit(1);
    }
}

void removeInicioLDE(LSE **ptrL){ 
    LSE *aux;
    aux = *ptrL; // ponteiro auxiliar recebe o ponteiro com endereço da lista
    if(!listaVaziaLSE(*ptrL)){ //se a lista nao estiver vazia
        *ptrL = aux->dir; //ponteiro da lista aponta pro segundo elemento da lista - no a direita
        (*ptrL)->esq = NULL; // "desconecta" a lista do primeiro no, que queremos remover
        free(aux); //libera o no
    }else{
        exit(1);
    }
}

void removeCelulaLDE(LSE **ptrL, LSE *no){ //faltou uma repetição aqui não? pra achar o no
    if((*ptrL) == NULL) return; //lista vazia
    
    if(no == *ptrL) // se so tem um no
        removeInicioLDE(&no); //remove ele
    else{
        (no->esq)->dir = no->dir; // aponta o antecessor do no que queremos remover pro no a direita do que queremos remover
        if(no->dir != NULL) // se não for o final da lista
            (no->dir)->esq = no->esq; // no a direita do que vamos remover aponta pro no a esquerda do no que sera removido
        
        free(no);// remove o no
    }
}

int imprimeListaLSE(LSE *ptrLista){
    LSE *aux;
    aux = ptrLista; //ponteiro auxiliar para percorrer a lista

    if(listaVaziaLSE(aux)){ // lista vazia
        return 1;
    }else{
        while(aux != NULL){ // enquanto não for o fim da lista
            printf("%d%d, ", aux->carta,aux->naipe); //imprime a carta e o nipe
            aux = aux->dir; // anda pro proximo no
        }
    }
    return 0;
}