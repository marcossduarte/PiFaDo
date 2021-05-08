#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoDeque{// qual restrição desse deque?
    int carta, naipe;
    struct sNoDeque *dir;
    struct sNoDeque *esq;
}NoDeque;

typedef struct sDEQUE{
    int qnt;
    NoDeque *inicio;
    NoDeque *final;
}DEQUE;

NoDeque* alocaNoDeque(){
    return ((NoDeque*) malloc(sizeof(NoDeque)));
}

void initDeque(DEQUE *ptrD){ //inicializa o inicio e fim do deque com NULL
    ptrD = (DEQUE*) malloc(sizeof(DEQUE));
    ptrD->inicio = NULL;
    printf("123\n");
    ptrD->final = NULL;
    ptrD->qnt = 0;
}

int vazioDeque(DEQUE *ptrD){ //verfica se esta vazio, de acordo com o conteudo do no
    if (ptrD->inicio == NULL) return 1;
    
    return 0;
}

void insereInicioDeque(DEQUE *ptrD, int carta, int naipe){
    if(ptrD == NULL){ //verifica se o deque foi alocado corretamente
        printf("Deque nao inicializado!\n");
        return;
    }     
    
    NoDeque *novo;
    novo = alocaNoDeque();
    if(novo == NULL) { //verifica se o no foi alocado corretamente
        printf("Não foi alocado.\n");
        return;
    }
    //os conteudos que serão inseridos são passados pros nos
    novo->carta = carta; 
    novo->naipe = naipe;
    novo->dir = ptrD->inicio;//direita do novo no recebe o inicio atual do deque
    novo->esq = NULL; // inicializa o esquerda do novo no com NULL

    if(vazioDeque(ptrD)) { //se o deque estiver vazio
        ptrD->final = novo; //insere no final o novo no 
    }else {
        (ptrD->inicio)->esq = novo; // se nao, adiciona ao lado esquerdo do inicio, se tornando o novo inicio 
    }

    ptrD->inicio = novo; //ponteiro de inicio recebe o novo no criado, atualizando a referencia de inicio do deque
    ptrD->qnt += 1; //atualiza o numero de nos
}

void insereFinalDeque(DEQUE *ptrD, int carta, int naipe){
    NoDeque* novo;
    novo = alocaNoDeque();
    if(novo == NULL) return;

    //inicializa os nos com os conteudos recebidos na função 
    novo->carta = carta;
    novo->naipe = naipe;
    novo->dir = NULL; //inicializa a direita do novo no como null, por ser o final

    if(vazioDeque(ptrD) == 1){ //se estiver vazio
        ptrD->inicio = novo; //inicio e fim recebem o novo no criado
        ptrD->final = novo;
    }else{// se nao estiver vazio
        (ptrD->final)->dir = novo; //a direita do ultimo elemento recebe para o novo, que se torna o atual fim
        novo->esq = ptrD->final; //a esquerda do novo recebe o endereco do final 
        ptrD->final = novo; // final aponta pro novo no criado
    }
    ptrD->qnt += 1; //atualiza o numero de no's
}

void removeFinalDeque(DEQUE *ptrD){
    if(ptrD == NULL) return;
    if(vazioDeque(ptrD)) return;

    NoDeque *aux = ptrD->final; //no auxiliar recebe o endereço do final
    if(aux == ptrD->inicio){// se final for igual inicio, inicializa os dois com null, pode estar vazio o deque
        ptrD->inicio = NULL;
        ptrD->final = NULL;
    }else{ //se nao estiver vazio
        (aux->esq)->dir = NULL; // inicializa o no a direita do ultimo no com null, tirando a referencia do atual ultimo no
        ptrD->final = aux->dir; // atualiza a referencia de final passando agora para o no que era o penultimo no, que agr e ultimo 
    }
    free(aux); // remove o no
    ptrD->qnt -= 1; //atualiza a quantidade de nos
}

void removeInicioDeque(DEQUE *ptrD){
    NoDeque *aux;
    if(vazioDeque(ptrD)) return;

    aux = (ptrD->inicio)->dir; // aux recebe a referencia para o segundo elemento do deque
    free(ptrD->inicio); // remove o elemento do inicio
    ptrD->inicio = aux; //atualiza a referencia de inicio, que agr e o antigo segundo elemento

    if(ptrD->inicio != NULL) //deque nao vazio
        (ptrD->inicio)->esq = NULL; // inicializa o esq do inicio com null
    else// deque vazio
        ptrD->final = NULL; //final recebe null
    
    ptrD->qnt -= 1; //atualiza o numero de no's
}

void listaDequeNaoClassico(DEQUE *ptrD){//imprimir o deque sem remover
    if(vazioDeque(ptrD)) return;
    
    NoDeque *aux;
    aux = ptrD->inicio; //ponteiro inicial pega referencia para o inicio do deque
    
    while(aux != NULL){ // enquanto nao chegar no fim do deque
        printf("%d%d\t", aux->carta, aux->naipe); // imprime a carta e seu naipe
        aux = aux->dir;// anda pro proximo no
    }
    printf("\n");
}

void listaDequeClassico(DEQUE *ptrD){ //imprimir o deque removendo os no's

    if(vazioDeque(ptrD)) return;

    while(ptrD->inicio != NULL){ //enquanto nao chegar no fim do deque
        printf("%d%d\t", ptrD->inicio->carta, ptrD->inicio->naipe); //imprime a carta e seu naipe 
        removeInicioDeque(ptrD); //remove o no que foi impresso
    }

    printf("\n");
    return;
}