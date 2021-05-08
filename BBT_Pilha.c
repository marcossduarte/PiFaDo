#include <stdio.h>
#include <stdlib.h>

typedef struct sPilha{ // cria a estrutura de dados pilha para (a pilha ta sendo usada em que parte do baralho?)
    int carta, naipe;
    struct sPilha *dir;
}pilha;

pilha* alocaNoPilha(){ // faz a alocação da pilha na memoria
    return (pilha*) malloc(sizeof(pilha));
}

void initPilha(pilha *ptrP){  //inicializa a pilha
    ptrP->dir = NULL;
    if ( ptrP == NULL ){
        printf("Erro na alocacao do no\n");
        exit(0);
    }
}

int vaziaPilha(pilha *ptrP){ //verifica se a pilha esta vazia
    if ( ptrP->dir == NULL ) return 1;
    return 0;
}

void inserePilha(pilha **ptrP, int carta, int naipe){ 
    pilha *novo;
    novo = alocaNoPilha(); //cria um novo no para alocar
    if ( novo == NULL ) return; // verifica se foi alocado corretamente
    printf("passou!\n");
    novo->carta = carta; // passa o valor pro no criado
    novo->naipe = naipe; // passa o no recebido na função pro no criado
    novo->dir = *ptrP; // o que faz aqui mesmo? Atualiza pro dir estar na mesma posição do no add? no "topp" da lista
    
    *ptrP = novo;
}

void removePilha(pilha **ptrP){ //recebe o endereço de onde remover
    if(vaziaPilha(*ptrP)) { // verifica se ta vazia
        printf("Lista Vazia!\n");
        return;
    }
    
    pilha *aux; //cria um auxiliar pra receber o conteudo que vamos remover
    aux = *ptrP; // aux recebe o endereco de onde esta o no a remover
    
    *ptrP = aux->dir; // atualiza a posição do ultimo elemento (???)
    
    free(aux); //libera o no
}

void listaPilhaClassico(pilha *ptrP){ //imprimir o conteudo da pilha
    if(vaziaPilha(ptrP)){ //verifica se esta vazia
        printf("Lista vazia!\n");
        return;
    }
    
    pilha *aux; //ponteiro auxiliar para percorrer a pilha

    while(ptrP != NULL){ // segue o laço enquanto a lista não estiver vazia. Removendo da pilha
        printf("%d%d\n", ptrP->carta, ptrP->naipe);  // printa a carta e o naipe
        aux = ptrP; // aux recebe o conteúdo que acabou de ser exibido
        ptrP = ptrP->dir; // atualiza a posição do no que esta no "topo" (???)
        removePilha(&aux); // remove o no que acabou de ser exibido
    }
}

void listaPilhaNaoClassico(pilha *ptrP){ // Exibe a pilha sem remover os dados da mesma
    if(vaziaPilha(ptrP)){ // verifica se esta vazia
        printf("Lista vazia!\n"); 
        return;
    }
    
    pilha *aux; // cria um ponteiro auxiliar para percorrer a pilha
    aux = ptrP; // ponteiro recebe a pilha que vamos percorrer

    while(!vaziaPilha(aux)){ // enquanto for diferente de vazio
        printf("%d%d\n", aux->carta, aux->naipe); // printa a carta
        aux = aux->dir; // anda pro proximo da pilha para exibir
    }
}