#ifndef LISTA_RECURSIVA_H
#define LISTA_RECURSIVA_H

typedef struct NoRecursivo {
  int info;
  NoRecursivo *prox;
} NOR;

class ListaRecursiva {
private:
  NOR *inicio;
  int tamanho;

public:
  ListaRecursiva();
  ~ListaRecursiva();
  int ListaVazia();
  void InserirInicio(int k);
  void ImprimirRecursivo();
  void ImprimirRecursivoHelper(NOR *atual);
  bool BuscarRecursivo(int k);
  bool BuscarRecursivoHelper(NOR *atual, int k);
  void ExcluirRecursivo(int k);
  NOR *ExcluirRecursivoHelper(NOR *atual, int k);
  int menu();
};

#endif
