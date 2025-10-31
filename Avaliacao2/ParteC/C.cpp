#include "C.h"
#include <iomanip>
#include <fstream> 
#include <cstdlib> 

const int INF = 9999;

// =====================================================
// CONSTRUTOR
// Inicializa a matriz de adjacência com valores "INF"
// e 0 na diagonal principal (distância de um vértice para ele mesmo)
// =====================================================
Graph::Graph(int vertices) {
    numVertices = vertices;
    matrizAdj = vector< vector<int> >(vertices, vector<int>(vertices, INF));

    for (int i = 0; i < vertices; i++)
        matrizAdj[i][i] = 0;
}

// =====================================================
// DESTRUTOR
// Mostra uma mensagem apenas para fins didáticos
// =====================================================
Graph::~Graph() {
    cout << "\n[INFO] Grafo destruído!\n";
}

// =====================================================
// INSERIR ARESTA
// Adiciona uma aresta entre dois vértices com determinado peso
// =====================================================
void Graph::inserirAresta(int origem, int destino, int peso) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        matrizAdj[origem][destino] = peso;
        matrizAdj[destino][origem] = peso; // grafo não direcionado
        cout << "Aresta inserida entre " << origem << " e " << destino
             << " com peso " << peso << "!\n";
    } else {
        cout << "Índices inválidos!\n";
    }
}

// =====================================================
// REMOVER ARESTA
// Substitui o peso por INF, indicando que não há conexão
// =====================================================
void Graph::removerAresta(int origem, int destino) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        matrizAdj[origem][destino] = INF;
        matrizAdj[destino][origem] = INF;
        cout << "Aresta removida entre " << origem << " e " << destino << "!\n";
    } else {
        cout << "Índices inválidos!\n";
    }
}

// =====================================================
// MOSTRAR MATRIZ DE ADJACÊNCIA
// Exibe a matriz de pesos (INF = sem ligação)
// =====================================================
void Graph::mostrarMatriz() {
    cout << "\nMatriz de Adjacência (pesos):\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrizAdj[i][j] == INF)
                cout << setw(5) << "INF"; // formata largura da célula
            else
                cout << setw(5) << matrizAdj[i][j];
        }
        cout << endl;
    }
}

// =====================================================
// CONTAR ARESTAS
// Conta o número total de conexões (sem repetições)
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
// MOSTRAR GRAU DOS VÉRTICES
// O grau é o número de arestas conectadas a um vértice
// =====================================================
void Graph::mostrarGrauDosVertices() {
    cout << "\nGrau dos vértices:\n";
    for (int i = 0; i < numVertices; i++) {
        int grau = 0;
        for (int j = 0; j < numVertices; j++) {
            if (matrizAdj[i][j] != INF && matrizAdj[i][j] != 0)
                grau++;
        }
        cout << "Vértice " << i << " -> Grau: " << grau << endl;
    }
}

// =====================================================
// LIMPAR TELA
// Usado após cada operação para deixar o menu limpo
// =====================================================
void Graph::limparTela() {
    system("cls");
}

// =====================================================
// ALGORITMO DE FLOYD–WARSHALL
// Calcula os menores caminhos entre todos os pares de vértices
// =====================================================
void Graph::floydWarshall() {
    // Cria uma cópia da matriz de adjacência para não modificar a original
    vector< vector<int> > dist = matrizAdj;

    // Triple loop do algoritmo de Floyd–Warshall
    for (int k = 0; k < numVertices; k++) {       // vértice intermediário
        for (int i = 0; i < numVertices; i++) {   // vértice de origem
            for (int j = 0; j < numVertices; j++) { // vértice de destino
                // Se o caminho via k for menor, atualiza a distância
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Exibe o resultado final
    cout << "\nMatriz de Caminhos Mínimos (Floyd–Warshall):\n";
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
// Lê uma matriz de distâncias e armazena em matrizAdj
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

            // Se valor for -1, significa que não há ligação
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
        cout << "3. Mostrar matriz de adjacência\n";
        cout << "4. Mostrar grau dos vértices\n";
        cout << "5. Contar arestas\n";
        cout << "6. Executar Floyd–Warshall (caminhos mínimos)\n";
        cout << "7. Ler grafo de arquivo (.txt)\n"; // NOVA OPÇÃO
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite vértice origem: ";
                cin >> origem;
                cout << "Digite vértice destino: ";
                cin >> destino;
                cout << "Digite o peso da aresta: ";
                cin >> peso;
                inserirAresta(origem, destino, peso);
                system("pause");
                limparTela();
                break;

            case 2:
                cout << "Digite vértice origem: ";
                cin >> origem;
                cout << "Digite vértice destino: ";
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
                cout << "Opção inválida!\n";
                system("pause");
                limparTela();
        }

    } while (opcao != 0);
}

