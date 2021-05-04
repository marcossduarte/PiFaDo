#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
A função irá inicializar o baralho em ordem crescente,
logo após o baralho será embaralhado.
*/
void inicializaBaralho(LSE **ptrBaralho){
    char str[3];
    char naipe[1];

    for(int i = 0; i < 4; i++){
        switch (i){
            case 0:
                strcpy(naipe,"O");
                break;
            
            case 1:{
                strcpy(naipe , "P");
                break;
            }
            case 2:{
                strcpy(naipe , "E");
                break;
            }
            case 3:{
                strcpy(naipe , "C");
                break;
            }
        }
        for (int j = 0; j < 13; j++){
            int num = j+1;
            if(num == 1 || num > 10){
                switch (num){
                    case 1:{
                        strcpy(str, "A");
                        strncat(str, naipe,1);
                        break;
                    }
                    case 11:{
                        strcpy(str, "J");
                        strncat(str, naipe,1);                        
                        break;
                    }
                    case 12:{
                        strcpy(str, "Q");
                        strncat(str, naipe,1);
                        break;
                    }
                    case 13:{
                        strcpy(str, "K");
                        strncat(str, naipe,1);
                    }
                }
            }else{
                strncat(itoa(num, str, 10), naipe,1);
            }
            inserirInicioLSE(ptrBaralho, str);
        }
    }
}

/*
Função feita para construir o baralho embaralhado, pegando
o padrÃ£o, buscando um numero entre 1 e 54 e alocando essa carta
no deque de cartas embaralhadas.
*/
void embaralhaLDE (LSE **ptrL, Fila *ptrF){
    LSE *aux;
    aux = (*ptrL);
    int cont = 54;
    int numRand;
    srand( (unsigned)time(NULL) );
    
    /*
    Função criada para gerar 54 numeros aleatórios para embaralhar o baralho     
    */
    for (int i = 0; i < 54; i++){
        numRand = rand()%cont;
        printf("%d %d ", i,numRand);
        for(int j = 0; j < numRand; j++){
            aux = aux->dir;
        }
        printf("%s\n", aux->carta);
        
        //insereFila(ptrF->inicio, aux->carta);
        removeCelulaLDE(ptrL, &aux);
        
        if(*ptrL != NULL)
            aux = *ptrL;
        cont --;
    }
}