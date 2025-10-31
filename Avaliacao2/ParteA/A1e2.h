#ifndef A1_H
#define A1_H

#include <iostream>
using namespace std;

// Estrutura b�sica do n� da �rvore bin�ria
struct No {
    int valor;
    No* esquerda;
    No* direita;
};

// Fun��es principais da �rvore
No* inserir(No* raiz, int valor);     // Insere um novo valor na �rvore
No* remover(No* raiz, int valor);     // Remove um valor da �rvore
void listar(No* raiz);                // Lista os valores em ordem crescente
No* encontrarMaior(No* raiz);         // Fun��o recursiva que encontra o maior valor
void limparTela();                    // Limpa o console (para Windows)

#endif
