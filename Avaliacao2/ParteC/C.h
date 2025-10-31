#ifndef C_H
#define C_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ====================================================================
//  Classe Graph - Representa um grafo não direcionado e ponderado
//  utilizando uma matriz de adjacência (pesos).
// ====================================================================
class Graph {
private:
    int numVertices;                         // Quantidade de vértices no grafo
    vector< vector<int> > matrizAdj;          // Matriz de adjacência (com pesos)

public:
    Graph(int vertices);                      // Construtor
    ~Graph();                                 // Destrutor

    // Métodos básicos de manipulação do grafo
    void inserirAresta(int origem, int destino, int peso = 1); // Adiciona aresta com peso
    void removerAresta(int origem, int destino);                // Remove aresta
    void mostrarMatriz();                                       // Exibe matriz de adjacência
    int contarArestas();                                        // Conta número de arestas
    void mostrarGrauDosVertices();                              // Exibe o grau de cada vértice
    void limparTela();                                          // Limpa o console (Windows)
    void floydWarshall();                                       // Algoritmo de caminho mínimo
	void lerGrafoDeArquivo(string nomeArquivo);
    void menuGrafo();                                           // Menu interativo para o usuário
};

#endif

