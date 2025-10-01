#include "lista_encadeada.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

ListaEncadeada::ListaEncadeada() {
  CriarListaVazia();
  cout << "\nLista Encadeada Inicializada!" << endl;
}

ListaEncadeada::~ListaEncadeada() {
  NOE *atual = inicio;
  while (atual != NULL) {
    NOE *temp = atual;
    atual = atual->prox;
    delete temp;
  }
  cout << "\nLista Encadeada Destruida!" << endl;
}

void ListaEncadeada::CriarListaVazia() {
  inicio = NULL;
  tamanho = 0;
}

void ListaEncadeada::InserirElemento(int k) {
  NOE *novo = new NOE;
  novo->info = k;
  novo->prox = inicio;
  inicio = novo;
  tamanho++;
  cout << "Elemento " << k << " inserido com sucesso!" << endl;
}

void ListaEncadeada::PercorrerLista() {
  if (inicio == NULL) {
    cout << "LISTA VAZIA!" << endl;
    return;
  }

  NOE *atual = inicio;
  int cont = 1;
  cout << "Conteudo da lista:" << endl;
  while (atual != NULL) {
    cout << "Elemento[" << cont << "] = " << atual->info << endl;
    atual = atual->prox;
    cont++;
  }
}

int ListaEncadeada::NumeroElementos() { return tamanho; }

int ListaEncadeada::menu() {
  int Opc;
  system("cls");
  cout << "========================================================" << endl;
  cout << "               LISTA ENCADEADA SIMPLES" << endl;
  cout << "========================================================" << endl;
  cout << "  [1] CRIAR LISTA VAZIA" << endl;
  cout << "  [2] INSERIR ELEMENTO" << endl;
  cout << "  [3] PERCORRER LISTA" << endl;
  cout << "  [4] NUMERO DE ELEMENTOS" << endl;
  cout << "  [5] SAIR" << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << "  OPCAO ESCOLHIDA: ";
  cin >> Opc;
  return Opc;
}
