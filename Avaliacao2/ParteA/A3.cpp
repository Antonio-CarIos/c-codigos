#include "A3.h"

// Construtor: inicializa a raiz como nula
Arvore::Arvore() {
    raiz = NULL;
}

// Fun��o recursiva para inserir um novo n� na �rvore
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
    // Inser��o de acordo com a ordem alfab�tica do nome
    if (nome < atual->nome)
        atual->esq = inserirNo(atual->esq, nome, sexo, idade, peso);
    else if (nome > atual->nome)
        atual->dir = inserirNo(atual->dir, nome, sexo, idade, peso);

    return atual;
}

// Chamada p�blica para inserir um n�
void Arvore::inserir(string nome, char sexo, int idade, float peso) {
    raiz = inserirNo(raiz, nome, sexo, idade, peso);
}

// Percorre a �rvore em ordem (ordenado por nome)
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

// Chamada p�blica para listar todos os n�s
void Arvore::listar() {
    if (raiz == NULL)
        cout << "�rvore vazia!\n";
    else
        listarInOrder(raiz);
}

// Fun��o recursiva auxiliar que separa homens e mulheres
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
