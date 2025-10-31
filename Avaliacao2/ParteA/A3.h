#ifndef A3_H
#define A3_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

// Estrutura do n� da �rvore
struct No {
    string nome;
    char sexo;   // 'M' ou 'F'
    int idade;
    float peso;
    No* esq;
    No* dir; 
};

// Classe que representa a �rvore bin�ria de busca
class Arvore {
private:
    No* raiz; // ponteiro para o n� raiz

    // Fun��es auxiliares privadas (usadas internamente)
    No* inserirNo(No* atual, string nome, char sexo, int idade, float peso);
    void listarInOrder(No* atual);
    void gerarListasAux(No* atual, list<No*>& homens, list<No*>& mulheres);

public:
    Arvore();
    void inserir(string nome, char sexo, int idade, float peso);
    void listar();
    void gerarListas(list<No*>& homens, list<No*>& mulheres);
};

#endif
