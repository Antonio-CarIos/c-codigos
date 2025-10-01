#include "pilha.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

PilhaEncadeada::PilhaEncadeada() {
  pilha.Topo = NULL;
  pilha.tamanho = 0;
  cout << "\nPilha Encadeada Inicializada!" << endl;
}

PilhaEncadeada::~PilhaEncadeada() {
  while (pilha.Topo != NULL) {
    ExcluirElemento();
  }
  cout << "\nPilha Encadeada Destruida!" << endl;
}

void PilhaEncadeada::InserirElemento(int k) {
  No *novo = new No;
  novo->infor = k;
  novo->prox = pilha.Topo;
  pilha.Topo = novo;
  pilha.tamanho++;
  cout << "Elemento " << k << " inserido no topo da pilha!" << endl;
}

void PilhaEncadeada::ExcluirElemento() {
  if (pilha.Topo == NULL) {
    cout << "PILHA VAZIA! Nada para excluir." << endl;
    return;
  }

  No *temp = pilha.Topo;
  int valor = temp->infor;
  pilha.Topo = pilha.Topo->prox;
  delete temp;
  pilha.tamanho--;
  cout << "Elemento " << valor << " removido do topo da pilha!" << endl;
}

void PilhaEncadeada::ListarConteudo() {
  if (pilha.Topo == NULL) {
    cout << "PILHA VAZIA!" << endl;
    return;
  }

  No *atual = pilha.Topo;
  int cont = 1;
  cout << "Conteudo da pilha (do topo para a base):" << endl;
  while (atual != NULL) {
    cout << "Posicao[" << cont << "] = " << atual->infor << endl;
    atual = atual->prox;
    cont++;
  }
}

bool PilhaEncadeada::VerificarElemento(int k) {
  No *atual = pilha.Topo;
  while (atual != NULL) {
    if (atual->infor == k) {
      return true;
    }
    atual = atual->prox;
  }
  return false;
}

int PilhaEncadeada::menu() {
  int Opc;
  system("cls");
  cout << "========================================================" << endl;
  cout << "                    PILHA ENCADEADA" << endl;
  cout << "========================================================" << endl;
  cout << "  [1] INSERIR ELEMENTO (PUSH)" << endl;
  cout << "  [2] EXCLUIR ELEMENTO (POP)" << endl;
  cout << "  [3] LISTAR CONTEUDO" << endl;
  cout << "  [4] VERIFICAR ELEMENTO" << endl;
  cout << "  [5] SAIR" << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << "  OPCAO ESCOLHIDA: ";
  cin >> Opc;
  return Opc;
}
