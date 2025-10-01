#include "pares_recursivos.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

ParesRecursivos::ParesRecursivos() {
  cout << "\nSistema de Soma de Pares Recursivo Inicializado!" << endl;
}

ParesRecursivos::~ParesRecursivos() {
  cout << "\nSistema de Soma de Pares Recursivo Finalizado!" << endl;
}

int ParesRecursivos::somaParesRecursiva(int n) {
  if (n < 0)
    return 0;
  if (n % 2 != 0)
    return somaParesRecursiva(n - 1);
  return n + somaParesRecursiva(n - 2);
}

int ParesRecursivos::menu() {
  int Opc;
  system("cls");
  cout << "========================================================" << endl;
  cout << "            SOMA DE NUMEROS PARES RECURSIVA" << endl;
  cout << "========================================================" << endl;
  cout << "  [1] CALCULAR SOMA DE PARES ATE N" << endl;
  cout << "  [2] SAIR" << endl;
  cout << "--------------------------------------------------------" << endl;
  cout << "  OPCAO ESCOLHIDA: ";
  cin >> Opc;
  return Opc;
}
