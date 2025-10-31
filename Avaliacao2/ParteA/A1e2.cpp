#include "A1.h"
#include <windows.h>

// -------------------------------------------------------------
// Função para limpar o console
// -------------------------------------------------------------
void limparTela() {
    system("cls");
}

// -------------------------------------------------------------
// Função para inserir um valor na árvore binária de busca
// -------------------------------------------------------------
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        // Cria um novo nó se a raiz for nula
        No* novo = new No;
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    // Insere à esquerda se o valor for menor
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    // Insere à direita se o valor for maior
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    // Retorna a raiz atualizada
    return raiz;
}

// -------------------------------------------------------------
// Função auxiliar para encontrar o menor valor (usada na remoção)
// -------------------------------------------------------------
No* encontrarMenor(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

// -------------------------------------------------------------
// Função para remover um valor da árvore binária de busca
// -------------------------------------------------------------
No* remover(No* raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    // Busca o valor na subárvore correspondente
    if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else {
        // Caso 1: nó sem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            delete raiz;
            return NULL;
        }
        // Caso 2: nó com apenas um filho
        else if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            delete raiz;
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            delete raiz;
            return temp;
        }
        // Caso 3: nó com dois filhos
        No* temp = encontrarMenor(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

// -------------------------------------------------------------
// Função para listar os valores em ordem crescente (in-order)
// -------------------------------------------------------------
void listar(No* raiz) {
    if (raiz != NULL) {
        listar(raiz->esquerda);
        cout << raiz->valor << " ";
        listar(raiz->direita);
    }
}

// -------------------------------------------------------------
// Função recursiva que encontra o maior valor na árvore (Questão 2)
// -------------------------------------------------------------
No* encontrarMaior(No* raiz) {
    if (raiz == NULL)
        return NULL;
    else if (raiz->direita == NULL)
        return raiz; // último nó à direita é o maior
    else
        return encontrarMaior(raiz->direita);
}
