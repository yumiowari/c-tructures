/*
    Implementação das funções de pilha

    Por Rafael Renó Corrêa, 2024
*/

#include <stdio.h>
#include <stdlib.h>
 
#include "pilha.h"

struct no{
    int info; // informação

    struct no *prox; // próximo nó
};

struct pilha{
    int qtd; // quantidade de nós na pilha
    
    struct no *topo; // topo da pilha
};

int makePile(Pilha *pilha){
    pilha = (Pilha*) malloc(sizeof(Pilha));
    if(!pilha)return 1;

    pilha->qtd = 0;
    pilha->topo = NULL;

    return 0;
}

int pushToPile(Pilha *pilha, int info){
    if(pilha){
        No *newNode = (No*) malloc(sizeof(No));
        if(!newNode)return 2;

        newNode->info = info;

        if(pilha->qtd > 0){
            newNode->prox = pilha->topo;

            pilha->topo = newNode;
        }else{ // é o primeiro nó
            newNode->prox = NULL;

            pilha->topo = newNode;
        }

        pilha->qtd++;

        return 0;
    }else return 1;
}

int popFromPile(Pilha *pilha, int *info){
    if(pilha){
        if(pilha->qtd > 0){
            No *aux;
            aux = pilha->topo;

            *info = aux->info;

            pilha->topo = aux->prox;
            free(aux);

            pilha->qtd--;

            return 0;
        }else return 2;
    }else return 1;
}

int fillPile(Pilha *pilha, char *path){
    int info;

    if(pilha){
        FILE *f = fopen(path, "r");
        if(!f)return 2;

        while(feof(f)){ // "A non-zero value is returned in the case that the end-of-file indicator associated with the stream is set. Otherwise, zero is returned."
            fscanf(f, "%d\n", &info);

            if(!pushToPile(pilha, info))return 3;
        }

        return 0;
    }else return 1;
}

int savePile(Pilha *pilha, char *path){
    int *info;
    int i = 0;

    if(pilha){
        if(pilha->qtd > 0){
            FILE *f = fopen(path, "w");
            if(!f)return 3;

            while(i < pilha->qtd){
                popFromPile(pilha, info);

                fprintf(f, "%d\n", *info);

                i++;
            }

            return 0;
        }else return 2;
    }else return 1;
}

int checkPileHeight(Pilha *pilha){
    if(pilha){
        return pilha->qtd;
    }else return -1;
}