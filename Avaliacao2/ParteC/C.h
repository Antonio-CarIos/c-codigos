#ifndef C_H
#define C_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ====================================================================
//  Classe Graph - Representa um grafo n�o direcionado e ponderado
//  utilizando uma matriz de adjac�ncia (pesos).
// ====================================================================
class Graph {
private:
    int numVertices;                         // Quantidade de v�rtices no grafo
    vector< vector<int> > matrizAdj;          // Matriz de adjac�ncia (com pesos)

public:
    Graph(int vertices);                      // Construtor
    ~Graph();                                 // Destrutor

    // M�todos b�sicos de manipula��o do grafo
    void inserirAresta(int origem, int destino, int peso = 1); // Adiciona aresta com peso
    void removerAresta(int origem, int destino);                // Remove aresta
    void mostrarMatriz();                                       // Exibe matriz de adjac�ncia
    int contarArestas();                                        // Conta n�mero de arestas
    void mostrarGrauDosVertices();                              // Exibe o grau de cada v�rtice
    void limparTela();                                          // Limpa o console (Windows)
    void floydWarshall();                                       // Algoritmo de caminho m�nimo
	void lerGrafoDeArquivo(string nomeArquivo);
    void menuGrafo();                                           // Menu interativo para o usu�rio
};

#endif

