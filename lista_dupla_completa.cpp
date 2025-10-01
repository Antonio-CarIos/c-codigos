#include "lista_dupla_completa.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

ListaDuplaCompleta::ListaDuplaCompleta() {
  inicio = fim = NULL;
  tamanho = 0;
  cout << "\nLista Duplamente Encadeada Completa Inicializada!" << endl;
}

ListaDuplaCompleta::~ListaDuplaCompleta() {
  NOD *atual = inicio;
  while (atual != NULL) {
    NOD *temp = atual;
    atual = atual->prox;
    delete temp;
  }
  cout << "\nLista Duplamente Encadeada Completa Destruida!" << endl;
}

int ListaDuplaCompleta::ListaVazia() { return (inicio == NULL); }

void ListaDuplaCompleta::IncluirElemento(int k, int posicao) {
  if (posicao < 0 || posicao > tamanho) {
    cout << "Posicao invalida! Use posicoes entre 0 e " << tamanho << endl;
    return;
  }

  NOD *novo = new NOD;
  novo->info = k;

  if (ListaVazia()) {
    // Primeiro elemento
    novo->prox = NULL;
    novo->ant = NULL;
    inicio = fim = novo;
  } else if (posicao == 0) {
    // Inserir no inicio
    novo->prox = inicio;
    novo->ant = NULL;
    inicio->ant = novo;
    inicio = novo;
  } else if (posicao == tamanho) {
    // Inserir no fim
    novo->prox = NULL;
    novo->ant = fim;
    fim->prox = novo;
    fim = novo;
  } else {
    // Inserir no meio
    NOD *atual = inicio;
    for (int i = 0; i < posicao - 1; i++) {
      atual = atual->prox;
    }
    novo->prox = atual->prox;
    novo->ant = atual;
    atual->prox->ant = novo;
    atual->prox = novo;
  }

  tamanho++;
  cout << "Elemento " << k << " inserido na posicao " << posicao
       << " com sucesso!" << endl;
}

void ListaDuplaCompleta::ImpressaoConteudo() {
  if (ListaVazia()) {
    cout << "LISTA VAZIA!" << endl;
    return;
  }

  NOD *atual = inicio;
  int cont = 1;
  cout << "Conteudo da lista (do inicio ao fim):" << endl;
  while (atual != NULL) {
    cout << "Posicao[" << cont << "] = " << atual->info << endl;
    atual = atual->prox;
    cont++;
  }
}

bool ListaDuplaCompleta::BuscarElemento(int k) {
  NOD *atual = inicio;
  while (atual != NULL) {
    if (atual->info == k) {
      return true;
    }
    atual = atual->prox;
  }
  return false;
}

void ListaDuplaCompleta::ExcluirElemento(int posicao) {
  if (ListaVazia()) {
    cout << "LISTA VAZIA! Nada para excluir." << endl;
    return;
  }

  if (posicao < 0 || posicao >= tamanho) {
    cout << "Posicao invalida! Use posicoes entre 0 e " << tamanho - 1 << endl;
    return;
  }

  NOD *del;

  if (posicao == 0) {
    // Excluir do inicio
    del = inicio;
    inicio = inicio->prox;
    if (inicio != NULL) {
      inicio->ant = NULL;
    } else {
      fim = NULL; // Lista ficou vazia
    }
  } else if (posicao == tamanho - 1) {
    // Excluir do fim
    del = fim;
    fim = fim->ant;
    fim->prox = NULL;
  } else {
    // Excluir do meio
    del = inicio;
    for (int i = 0; i < posicao; i++) {
      del = del->prox;
    }
    del->ant->prox = del->prox;
    del->prox->ant = del->ant;
  }

  int valor = del->info;
  delete del;
  tamanho--;
  cout << "Elemento na posicao " << posicao << " (valor: " << valor
       << ") excluido com sucesso!" << endl;
}

int ListaDuplaCompleta::menu() {
  int Opc;
  system("cls");
  cout << "========================================================" << endl;
  cout << "          LISTA DUPLAMENTE ENCADEADA COMPLETA" << endl;
  cout << "========================================================" << endl;
  cout << "  [1] INCLUIR ELEMENTO EM QUALQUER POSICAO" << endl;
  cout << "  [2] IMPRESSAO DO CONTEUDO" << endl;
  cout << "  [3] BUSCAR ELEMENTO" << endl;
  cout << "  [4] EXCLUIR ELEMENTO DE QUALQUER POSICAO" << endl;
  cout << "  [5] VER TAMANHO DA LISTA" << endl;
  cout << "  [6] SAIR" << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << "  OPCAO ESCOLHIDA: ";
  cin >> Opc;
  return Opc;
}
