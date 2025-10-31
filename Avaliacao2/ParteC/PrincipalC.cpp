#include "C.h"

int main() {
    int vertices;

    // Solicita ao usuário o número de vértices do grafo
    cout << "Digite o numero de vertices do grafo: ";
    cin >> vertices;

    // Cria um objeto da classe Graph com a quantidade informada
    Graph g(vertices);

    // Inicia o menu interativo para manipulação do grafo
    g.menuGrafo();

    return 0;
}
