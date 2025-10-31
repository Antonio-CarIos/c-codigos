#include "A1.h"
#include <windows.h>

// -------------------------------------------------------------
// Fun��o para limpar o console
// -------------------------------------------------------------
void limparTela() {
    system("cls");
}

// -------------------------------------------------------------
// Fun��o para inserir um valor na �rvore bin�ria de busca
// -------------------------------------------------------------
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        // Cria um novo n� se a raiz for nula
        No* novo = new No;
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    // Insere � esquerda se o valor for menor
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    // Insere � direita se o valor for maior
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    // Retorna a raiz atualizada
    return raiz;
}

// -------------------------------------------------------------
// Fun��o auxiliar para encontrar o menor valor (usada na remo��o)
// -------------------------------------------------------------
No* encontrarMenor(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

// -------------------------------------------------------------
// Fun��o para remover um valor da �rvore bin�ria de busca
// -------------------------------------------------------------
No* remover(No* raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    // Busca o valor na sub�rvore correspondente
    if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else {
        // Caso 1: n� sem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            delete raiz;
            return NULL;
        }
        // Caso 2: n� com apenas um filho
        else if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            delete raiz;
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            delete raiz;
            return temp;
        }
        // Caso 3: n� com dois filhos
        No* temp = encontrarMenor(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

// -------------------------------------------------------------
// Fun��o para listar os valores em ordem crescente (in-order)
// -------------------------------------------------------------
void listar(No* raiz) {
    if (raiz != NULL) {
        listar(raiz->esquerda);
        cout << raiz->valor << " ";
        listar(raiz->direita);
    }
}

// -------------------------------------------------------------
// Fun��o recursiva que encontra o maior valor na �rvore (Quest�o 2)
// -------------------------------------------------------------
No* encontrarMaior(No* raiz) {
    if (raiz == NULL)
        return NULL;
    else if (raiz->direita == NULL)
        return raiz; // �ltimo n� � direita � o maior
    else
        return encontrarMaior(raiz->direita);
}
