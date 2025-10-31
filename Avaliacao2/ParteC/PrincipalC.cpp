#include "C.h"

int main() {
    int vertices;

    // Solicita ao usu�rio o n�mero de v�rtices do grafo
    cout << "Digite o numero de vertices do grafo: ";
    cin >> vertices;

    // Cria um objeto da classe Graph com a quantidade informada
    Graph g(vertices);

    // Inicia o menu interativo para manipula��o do grafo
    g.menuGrafo();

    return 0;
}
