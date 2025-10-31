#ifndef A1_H
#define A1_H

#include <iostream>
using namespace std;

// Estrutura básica do nó da árvore binária
struct No {
    int valor;
    No* esquerda;
    No* direita;
};

// Funções principais da árvore
No* inserir(No* raiz, int valor);     // Insere um novo valor na árvore
No* remover(No* raiz, int valor);     // Remove um valor da árvore
void listar(No* raiz);                // Lista os valores em ordem crescente
No* encontrarMaior(No* raiz);         // Função recursiva que encontra o maior valor
void limparTela();                    // Limpa o console (para Windows)

#endif
