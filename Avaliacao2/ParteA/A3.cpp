#include "A3.h"

// Construtor: inicializa a raiz como nula
Arvore::Arvore() {
    raiz = NULL;
}

// Função recursiva para inserir um novo nó na árvore
No* Arvore::inserirNo(No* atual, string nome, char sexo, int idade, float peso) {
    if (atual == NULL) {
        No* novo = new No;
        novo->nome = nome;
        novo->sexo = sexo;
        novo->idade = idade;
        novo->peso = peso;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    // Inserção de acordo com a ordem alfabética do nome
    if (nome < atual->nome)
        atual->esq = inserirNo(atual->esq, nome, sexo, idade, peso);
    else if (nome > atual->nome)
        atual->dir = inserirNo(atual->dir, nome, sexo, idade, peso);

    return atual;
}

// Chamada pública para inserir um nó
void Arvore::inserir(string nome, char sexo, int idade, float peso) {
    raiz = inserirNo(raiz, nome, sexo, idade, peso);
}

// Percorre a árvore em ordem (ordenado por nome)
void Arvore::listarInOrder(No* atual) {
    if (atual != NULL) {
        listarInOrder(atual->esq);
        cout << "Nome: " << atual->nome
             << " | Sexo: " << atual->sexo
             << " | Idade: " << atual->idade
             << " | Peso: " << atual->peso << endl;
        listarInOrder(atual->dir);
    }
}

// Chamada pública para listar todos os nós
void Arvore::listar() {
    if (raiz == NULL)
        cout << "Árvore vazia!\n";
    else
        listarInOrder(raiz);
}

// Função recursiva auxiliar que separa homens e mulheres
void Arvore::gerarListasAux(No* atual, list<No*>& homens, list<No*>& mulheres) {
    if (atual != NULL) {
        gerarListasAux(atual->esq, homens, mulheres);
        if (atual->sexo == 'M' || atual->sexo == 'm')
            homens.push_back(atual);
        else if (atual->sexo == 'F' || atual->sexo == 'f')
            mulheres.push_back(atual);
        gerarListasAux(atual->dir, homens, mulheres);
    }
}

// Gera as listas ordenadas por nome
void Arvore::gerarListas(list<No*>& homens, list<No*>& mulheres) {
    homens.clear();
    mulheres.clear();
    gerarListasAux(raiz, homens, mulheres);
}
