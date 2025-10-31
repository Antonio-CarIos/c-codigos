#include "C.h"
#include <iomanip>
#include <fstream> 
#include <cstdlib> 

const int INF = 9999;

// =====================================================
// CONSTRUTOR
// Inicializa a matriz de adjac�ncia com valores "INF"
// e 0 na diagonal principal (dist�ncia de um v�rtice para ele mesmo)
// =====================================================
Graph::Graph(int vertices) {
    numVertices = vertices;
    matrizAdj = vector< vector<int> >(vertices, vector<int>(vertices, INF));

    for (int i = 0; i < vertices; i++)
        matrizAdj[i][i] = 0;
}

// =====================================================
// DESTRUTOR
// Mostra uma mensagem apenas para fins did�ticos
// =====================================================
Graph::~Graph() {
    cout << "\n[INFO] Grafo destru�do!\n";
}

// =====================================================
// INSERIR ARESTA
// Adiciona uma aresta entre dois v�rtices com determinado peso
// =====================================================
void Graph::inserirAresta(int origem, int destino, int peso) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        matrizAdj[origem][destino] = peso;
        matrizAdj[destino][origem] = peso; // grafo n�o direcionado
        cout << "Aresta inserida entre " << origem << " e " << destino
             << " com peso " << peso << "!\n";
    } else {
        cout << "�ndices inv�lidos!\n";
    }
}

// =====================================================
// REMOVER ARESTA
// Substitui o peso por INF, indicando que n�o h� conex�o
// =====================================================
void Graph::removerAresta(int origem, int destino) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        matrizAdj[origem][destino] = INF;
        matrizAdj[destino][origem] = INF;
        cout << "Aresta removida entre " << origem << " e " << destino << "!\n";
    } else {
        cout << "�ndices inv�lidos!\n";
    }
}

// =====================================================
// MOSTRAR MATRIZ DE ADJAC�NCIA
// Exibe a matriz de pesos (INF = sem liga��o)
// =====================================================
void Graph::mostrarMatriz() {
    cout << "\nMatriz de Adjac�ncia (pesos):\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrizAdj[i][j] == INF)
                cout << setw(5) << "INF"; // formata largura da c�lula
            else
                cout << setw(5) << matrizAdj[i][j];
        }
        cout << endl;
    }
}

// =====================================================
// CONTAR ARESTAS
// Conta o n�mero total de conex�es (sem repeti��es)
// =====================================================
int Graph::contarArestas() {
    int cont = 0;
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (matrizAdj[i][j] != INF && matrizAdj[i][j] != 0)
                cont++;
        }
    }
    return cont;
}

// =====================================================
// MOSTRAR GRAU DOS V�RTICES
// O grau � o n�mero de arestas conectadas a um v�rtice
// =====================================================
void Graph::mostrarGrauDosVertices() {
    cout << "\nGrau dos v�rtices:\n";
    for (int i = 0; i < numVertices; i++) {
        int grau = 0;
        for (int j = 0; j < numVertices; j++) {
            if (matrizAdj[i][j] != INF && matrizAdj[i][j] != 0)
                grau++;
        }
        cout << "V�rtice " << i << " -> Grau: " << grau << endl;
    }
}

// =====================================================
// LIMPAR TELA
// Usado ap�s cada opera��o para deixar o menu limpo
// =====================================================
void Graph::limparTela() {
    system("cls");
}

// =====================================================
// ALGORITMO DE FLOYD�WARSHALL
// Calcula os menores caminhos entre todos os pares de v�rtices
// =====================================================
void Graph::floydWarshall() {
    // Cria uma c�pia da matriz de adjac�ncia para n�o modificar a original
    vector< vector<int> > dist = matrizAdj;

    // Triple loop do algoritmo de Floyd�Warshall
    for (int k = 0; k < numVertices; k++) {       // v�rtice intermedi�rio
        for (int i = 0; i < numVertices; i++) {   // v�rtice de origem
            for (int j = 0; j < numVertices; j++) { // v�rtice de destino
                // Se o caminho via k for menor, atualiza a dist�ncia
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Exibe o resultado final
    cout << "\nMatriz de Caminhos M�nimos (Floyd�Warshall):\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }
}

// =====================================================
// LER GRAFO DE ARQUIVO .TXT
// L� uma matriz de dist�ncias e armazena em matrizAdj
// =====================================================
void Graph::lerGrafoDeArquivo(string nomeArquivo) {
    ifstream arquivo(nomeArquivo.c_str());

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    cout << "\nLendo grafo do arquivo: " << nomeArquivo << endl;

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            int valor;
            arquivo >> valor;

            if (arquivo.fail()) {
                cout << "Erro ao ler valor no arquivo!" << endl;
                arquivo.close();
                return;
            }

            // Se valor for -1, significa que n�o h� liga��o
            if (valor == -1)
                matrizAdj[i][j] = INF;
            else
                matrizAdj[i][j] = valor;
        }
    }

    arquivo.close();
    cout << "Arquivo lido com sucesso!" << endl;
}

// =====================================================
// MENU INTERATIVO
// =====================================================
void Graph::menuGrafo() {
    int opcao, origem, destino, peso;
    string nomeArquivo;

    do {
        cout << "\n===== MENU DO GRAFO =====\n";
        cout << "1. Inserir aresta\n";
        cout << "2. Remover aresta\n";
        cout << "3. Mostrar matriz de adjac�ncia\n";
        cout << "4. Mostrar grau dos v�rtices\n";
        cout << "5. Contar arestas\n";
        cout << "6. Executar Floyd�Warshall (caminhos m�nimos)\n";
        cout << "7. Ler grafo de arquivo (.txt)\n"; // NOVA OP��O
        cout << "0. Sair\n";
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite v�rtice origem: ";
                cin >> origem;
                cout << "Digite v�rtice destino: ";
                cin >> destino;
                cout << "Digite o peso da aresta: ";
                cin >> peso;
                inserirAresta(origem, destino, peso);
                system("pause");
                limparTela();
                break;

            case 2:
                cout << "Digite v�rtice origem: ";
                cin >> origem;
                cout << "Digite v�rtice destino: ";
                cin >> destino;
                removerAresta(origem, destino);
                system("pause");
                limparTela();
                break;

            case 3:
                mostrarMatriz();
                system("pause");
                limparTela();
                break;

            case 4:
                mostrarGrauDosVertices();
                system("pause");
                limparTela();
                break;

            case 5:
                cout << "Total de arestas: " << contarArestas() << endl;
                system("pause");
                limparTela();
                break;

            case 6:
                floydWarshall();
                system("pause");
                limparTela();
                break;

            case 7:
                cout << "Digite o nome do arquivo (ex: grafo.txt): ";
                cin >> nomeArquivo;
                lerGrafoDeArquivo(nomeArquivo);
                system("pause");
                limparTela();
                break;

            case 0:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Op��o inv�lida!\n";
                system("pause");
                limparTela();
        }

    } while (opcao != 0);
}

