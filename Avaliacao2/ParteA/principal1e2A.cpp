#include "A1.h"
#include <cstdlib>

int main() {
    No* raiz = NULL;
    int opcao, valor;

    do {
        cout << "=============================\n";
        cout << "   ARVORE BINARIA DE BUSCA  \n";
        cout << "=============================\n";
        cout << "1. Inserir valores iniciais\n";
        cout << "2. Remover valores (9, 5 e 20)\n";
        cout << "3. Listar arvore (em ordem)\n";
        cout << "4. Encontrar maior valor\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            raiz = inserir(raiz, 20);
            raiz = inserir(raiz, 5);
            raiz = inserir(raiz, 12);
            raiz = inserir(raiz, 36);
            raiz = inserir(raiz, 27);
            raiz = inserir(raiz, 45);
            raiz = inserir(raiz, 9);
            raiz = inserir(raiz, 2);
            raiz = inserir(raiz, 6);
            raiz = inserir(raiz, 17);
            raiz = inserir(raiz, 40);
            cout << "Valores inseridos com sucesso!\n";
            system("pause");
            limparTela();
            break;

        case 2:
            raiz = remover(raiz, 9);
            raiz = remover(raiz, 5);
            raiz = remover(raiz, 20);
            cout << "Valores 9, 5 e 20 removidos com sucesso!\n";
            system("pause");
            limparTela();
            break;

        case 3:
            cout << "Valores em ordem: ";
            listar(raiz);
            cout << endl;
            system("pause");
            limparTela();
            break;

        case 4: {
            No* maior = encontrarMaior(raiz);
            if (maior != NULL)
                cout << "O maior valor da arvore eh: " << maior->valor << endl;
            else
                cout << "A arvore esta vazia.\n";
            system("pause");
            limparTela();
            break;
        }

        case 0:
            cout << "Encerrando o programa...\n";
            break;

        default:
            cout << "Opcao invalida!\n";
            system("pause");
            limparTela();
            break;
        }
    } while (opcao != 0);

    return 0;
}
