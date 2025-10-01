#include "lista_recursiva.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

ListaRecursiva::ListaRecursiva() {
  inicio = NULL;
  tamanho = 0;
  cout << "\nLista com Operacoes Recursivas Inicializada!" << endl;
}

ListaRecursiva::~ListaRecursiva() {
  NOR *atual = inicio;
  while (atual != NULL) {
    NOR *temp = atual;
    atual = atual->prox;
    delete temp;
  }
  cout << "\nLista com Operacoes Recursivas Destruida!" << endl;
}

int ListaRecursiva::ListaVazia() { return (inicio == NULL); }

void ListaRecursiva::InserirInicio(int k) {
  NOR *novo = new NOR;
  novo->info = k;
  novo->prox = inicio;
  inicio = novo;
  tamanho++;
}

void ListaRecursiva::ImprimirRecursivo() {
  if (ListaVazia()) {
    cout << "LISTA VAZIA!" << endl;
    return;
  }
  cout << "Conteudo da lista: ";
  ImprimirRecursivoHelper(inicio);
  cout << endl;
}

void ListaRecursiva::ImprimirRecursivoHelper(NOR *atual) {
  if (atual == NULL)
    return;
  cout << atual->info << " ";
  ImprimirRecursivoHelper(atual->prox);
}

bool ListaRecursiva::BuscarRecursivo(int k) {
  return BuscarRecursivoHelper(inicio, k);
}

bool ListaRecursiva::BuscarRecursivoHelper(NOR *atual, int k) {
  if (atual == NULL)
    return false;
  if (atual->info == k)
    return true;
  return BuscarRecursivoHelper(atual->prox, k);
}

void ListaRecursiva::ExcluirRecursivo(int k) {
  inicio = ExcluirRecursivoHelper(inicio, k);
}

NOR *ListaRecursiva::ExcluirRecursivoHelper(NOR *atual, int k) {
  if (atual == NULL)
    return NULL;

  if (atual->info == k) {
    NOR *temp = atual->prox;
    delete atual;
    tamanho--;
    cout << "Elemento " << k << " excluido com sucesso!" << endl;
    return temp;
  }

  atual->prox = ExcluirRecursivoHelper(atual->prox, k);
  return atual;
}

int ListaRecursiva::menu() {
  int Opc;
  system("cls");
  cout << "========================================================" << endl;
  cout << "        LISTA ENCADEADA COM OPERACOES RECURSIVAS" << endl;
  cout << "========================================================" << endl;
  cout << "  [1] INSERIR ELEMENTO NO INICIO" << endl;
  cout << "  [2] IMPRIMIR LISTA (RECURSIVO)" << endl;
  cout << "  [3] BUSCAR ELEMENTO (RECURSIVO)" << endl;
  cout << "  [4] EXCLUIR ELEMENTO (RECURSIVO)" << endl;
  cout << "  [5] SAIR" << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << "  OPCAO ESCOLHIDA: ";
  cin >> Opc;
  return Opc;
}
