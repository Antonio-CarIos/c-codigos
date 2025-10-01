#include "lista_dupla_completa.h"
#include "lista_encadeada.h"
#include "lista_recursiva.h"
#include "pares_recursivos.h"
#include "pilha.h"
#include <iostream>

using namespace std;

int main() {
  int sistema;

  do {
    system("cls");
    cout << "========================================================" << endl;
    cout << "              SISTEMA DE ESTRUTURAS DE DADOS" << endl;
    cout << "========================================================" << endl;
    cout << "  [1] SOMA DE PARES RECURSIVA (A.2)" << endl;
    cout << "  [2] LISTA ENCADEADA RECURSIVA (A.4)" << endl;
    cout << "  [3] LISTA ENCADEADA SIMPLES (B.1)" << endl;
    cout << "  [4] PILHA ENCADEADA (B.2)" << endl;
    cout << "  [5] LISTA DUPLAMENTE ENCADEADA (C.1)" << endl;
    cout << "  [0] SAIR" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "  ESCOLHA O SISTEMA: ";
    cin >> sistema;

    switch (sistema) {
    case 1: {
      ParesRecursivos pr;
      int opc;
      do {
        opc = pr.menu();
        switch (opc) {
        case 1: {
          int n;
          cout << "Digite um numero inteiro: ";
          cin >> n;
          int soma = pr.somaParesRecursiva(n);
          cout << "Soma dos pares de 0 ate " << n << " = " << soma << endl;
          system("pause");
          break;
        }
        }
      } while (opc != 2);
      break;
    }

    case 2: {
      ListaRecursiva lr;
      int opc, valor;
      do {
        opc = lr.menu();
        switch (opc) {
        case 1:
          cout << "Digite o valor a ser inserido: ";
          cin >> valor;
          lr.InserirInicio(valor);
          system("pause");
          break;
        case 2:
          lr.ImprimirRecursivo();
          system("pause");
          break;
        case 3:
          cout << "Digite o valor a ser buscado: ";
          cin >> valor;
          if (lr.BuscarRecursivo(valor))
            cout << "Elemento " << valor << " encontrado!" << endl;
          else
            cout << "Elemento " << valor << " nao encontrado!" << endl;
          system("pause");
          break;
        case 4:
          cout << "Digite o valor a ser excluido: ";
          cin >> valor;
          lr.ExcluirRecursivo(valor);
          system("pause");
          break;
        }
      } while (opc != 5);
      break;
    }

    case 3: {
      ListaEncadeada le;
      int opc, valor;
      do {
        opc = le.menu();
        switch (opc) {
        case 1:
          le.CriarListaVazia();
          cout << "Lista vazia criada!" << endl;
          system("pause");
          break;
        case 2:
          cout << "Digite o valor a ser inserido: ";
          cin >> valor;
          le.InserirElemento(valor);
          system("pause");
          break;
        case 3:
          le.PercorrerLista();
          system("pause");
          break;
        case 4:
          cout << "Numero de elementos na lista: " << le.NumeroElementos()
               << endl;
          system("pause");
          break;
        }
      } while (opc != 5);
      break;
    }

    case 4: {
      PilhaEncadeada pe;
      int opc, valor;
      do {
        opc = pe.menu();
        switch (opc) {
        case 1:
          cout << "Digite o valor a ser inserido: ";
          cin >> valor;
          pe.InserirElemento(valor);
          system("pause");
          break;
        case 2:
          pe.ExcluirElemento();
          system("pause");
          break;
        case 3:
          pe.ListarConteudo();
          system("pause");
          break;
        case 4:
          cout << "Digite o valor a ser verificado: ";
          cin >> valor;
          if (pe.VerificarElemento(valor))
            cout << "Elemento " << valor << " esta na pilha!" << endl;
          else
            cout << "Elemento " << valor << " nao esta na pilha!" << endl;
          system("pause");
          break;
        }
      } while (opc != 5);
      break;
    }

    case 5: {
      ListaDuplaCompleta ldc;
      int opc, valor, posicao;
      do {
        opc = ldc.menu();
        switch (opc) {
        case 1:
          cout << "Digite o valor a ser inserido: ";
          cin >> valor;
          cout << "Digite a posicao (0 a " << ldc.menu() << "): ";
          cin >> posicao;
          ldc.IncluirElemento(valor, posicao);
          system("pause");
          break;
        case 2:
          ldc.ImpressaoConteudo();
          system("pause");
          break;
        case 3:
          cout << "Digite o valor a ser buscado: ";
          cin >> valor;
          if (ldc.BuscarElemento(valor))
            cout << "Elemento " << valor << " encontrado!" << endl;
          else
            cout << "Elemento " << valor << " nao encontrado!" << endl;
          system("pause");
          break;
        case 4:
          cout << "Digite a posicao a ser excluida: ";
          cin >> posicao;
          ldc.ExcluirElemento(posicao);
          system("pause");
          break;
        case 5:
          // Tamanho seria implementado como método adicional
          cout << "Tamanho da lista: implementar metodo" << endl;
          system("pause");
          break;
        }
      } while (opc != 6);
      break;
    }
    }
  } while (sistema != 0);

  cout << "Programa finalizado!" << endl;
  return 0;
}
