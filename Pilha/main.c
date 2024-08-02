/*
    Interface para utilização da pilha

    Por Rafael Renó Corrêa, 2024
*/

#include <stdio.h>

#include "pilha.h"

int testPile(Pilha *pilha);
// rotina para testar as funções da pilha
//
// códigos de retorno:
// 0 - sucesso;
// 1 - falha.

int main(void){
    Pilha *pilha = NULL;

    if(testPile(pilha)){
        printf("O teste da pilha sucedeu.\n");

        // interface

        return 0;
    }else{
        fprintf(stderr, "O teste da pilha falhou.\n");

        return 1;
    }
}

int testPile(Pilha *pilha){
    int *info;

    FILE *f = fopen("cache/log.txt", "w");

    // criação da pilha
    if(!makePile(pilha))return 1;

    fprintf(f, "%s", "Criação da pilha: OK\n");
    //

    // empilhar
    if(!pushToPile(pilha, 1))return 1;
    fprintf(f, "%s", "Push: 1\n");

    fprintf(f, "%s", "Empilhar: OK\n");
    //

    // retornar tamanho
    if(*info = checkPileHeight(pilha) > 0){
        fprintf(f, "%s", "Height: ");
        fprintf(f, "%d\n", *info);

        fprintf(f, "%s", "Retornar tamanho: OK\n");
    }
    //

    // desempilhar
    if(!popFromPile(pilha, info))return 1;
    fprintf(f, "%s", "Pop: ");
    fprintf(f, "%d\n", *info);

    fprintf(f, "%s", "Desempilhar: OK\n");
    //

    // empilhar (2)
    if(!pushToPile(pilha, 1))return 1;
    fprintf(f, "%s", "Push: 1\n");

    if(!pushToPile(pilha, 2))return 1;
    fprintf(f, "%s", "Push: 2\n");

    fprintf(f, "%s", "Empilhar (2): OK\n");
    //

    // salvar pilha
    if(!savePile(pilha, "cache/pile.txt"))return 1;

    fprintf(f, "%s", "Persistência da pilha: OK\n");
    //

    // recuperar pilha
    if(!fillPile(pilha, "cache/pile.txt"))return 1;

    fprintf(f, "%s", "Recuperação da pilha: OK\n");
    //

    // desempilhar (2)
    if(!popFromPile(pilha, info))return 1;
    fprintf(f, "%s", "Pop: ");
    fprintf(f, "%d\n", *info);

    if(!popFromPile(pilha, info))return 1;
    fprintf(f, "%s", "Pop: ");
    fprintf(f, "%d\n", *info);

    fprintf(f, "%s", "Desempilhar (2): OK\n");
    //

    fclose(f);

    return 0;
}