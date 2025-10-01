#ifndef PILHA_H
#define PILHA_H

typedef struct Reg {
  int infor;
  Reg *prox;
} No;

typedef struct TipoPilha {
  No *Topo;
  int tamanho;
} Pilha;

class PilhaEncadeada {
private:
  Pilha pilha;

public:
  PilhaEncadeada();
  ~PilhaEncadeada();
  void InserirElemento(int k);
  void ExcluirElemento();
  void ListarConteudo();
  bool VerificarElemento(int k);
  int menu();
};

#endif
