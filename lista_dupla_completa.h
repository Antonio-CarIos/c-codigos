#ifndef LISTA_DUPLA_COMPLETA_H
#define LISTA_DUPLA_COMPLETA_H

typedef struct NoDuplo {
  int info;
  NoDuplo *prox;
  NoDuplo *ant;
} NOD;

class ListaDuplaCompleta {
private:
  NOD *inicio;
  NOD *fim;
  int tamanho;

public:
  ListaDuplaCompleta();
  ~ListaDuplaCompleta();
  int ListaVazia();
  void IncluirElemento(int k, int posicao);
  void ImpressaoConteudo();
  bool BuscarElemento(int k);
  void ExcluirElemento(int posicao);
  int menu();
};

#endif
