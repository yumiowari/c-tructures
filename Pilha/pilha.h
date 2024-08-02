/*
    Assinatura das funções de pilha

    Por Rafael Renó Corrêa, 2024
*/

#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;
typedef struct no No;

int makePile(Pilha *pilha);
// função para alocar a memória do ponteiro para o topo da pilha
//
// códigos de retorno:
// 0 - all right;
// 1 - memória RAM insuficiente.

int pushToPile(Pilha *topo, int info);
// função para empilhar um nó na pilha
//
// códigos de retorno:
// 0 - all right;
// 1 - falha na declaração da pilha;
// 2 - memória RAM insuficiente.

int popFromPile(Pilha *pilha, int *info);
// função para desempilhar um nó da pilha
//
// códigos de retorno:
// 0 - all right;
// 1 - falha na declaração da pilha;
// 2 - pilha vazia.

int fillPile(Pilha *pilha, char *path);
// função para preencher a pilha a partir do arquivo
//
// códigos de retorno:
// 0 - all right;
// 1 - falha na declaração da pilha;
// 2 - caminho inválido;
// 3 - memória RAM insuficiente.

int savePile(Pilha *pilha, char *path);
// função para persistir a pilha em arquivo
//
// códigos de retorno:
// 0 - all right;
// 1 - falha na declaração da pilha;
// 2 - pilha vazia;
// 3 - caminho inválido.

int checkPileHeight(Pilha *pilha);
// função para checar o tamanho da pilha
//
// códigos de retorno:
// > 0: tamanho da pilha;
// -1: falha na declaração da pilha.

#endif // PILHA_H