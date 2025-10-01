#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct NoEncadeado {
  int info;
  NoEncadeado *prox;
} NOE;

class ListaEncadeada {
private:
  NOE *inicio;
  int tamanho;

public:
  ListaEncadeada();
  ~ListaEncadeada();
  void CriarListaVazia();
  void InserirElemento(int k);
  void PercorrerLista();
  int NumeroElementos();
  int menu();
};

#endif
