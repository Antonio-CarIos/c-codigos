#include "A3.h"
#include <windows.h>

// Função auxiliar para exibir as listas
void exibirLista(list<No*>& lista, string titulo) {
    cout << "\n--- " << titulo << " ---\n";
    if (lista.empty()) {
        cout << "Nenhum registro encontrado.\n";
        return;
    }

    for (list<No*>::iterator it = lista.begin(); it != lista.end(); ++it) {
    No* pessoa = *it;
    cout << "Nome: " << pessoa->nome
         << " | Sexo: " << pessoa->sexo
         << " | Idade: " << pessoa->idade
         << " | Peso: " << pessoa->peso << endl;
	}

}

int main() {
    Arvore arvore;
    list<No*> homens;
    list<No*> mulheres;

    int opcao;
    string nome;
    char sexo;
    int idade;
    float peso;

    do {
        cout << "===== MENU =====\n";
        cout << "1. Inserir pessoa\n";
        cout << "2. Listar toda a arvore\n";
        cout << "3. Gerar listas (homens e mulheres)\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o sexo (M/F): ";
                cin >> sexo;
                cout << "Digite a idade: ";
                cin >> idade;
                cout << "Digite o peso: ";
                cin >> peso;

                arvore.inserir(nome, sexo, idade, peso);

                cout << "\nPessoa inserida com sucesso!\n";
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                cout << "=== Listagem completa ===\n";
                arvore.listar();
                cout << endl;
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                arvore.gerarListas(homens, mulheres);
                exibirLista(homens, "Homens");
                exibirLista(mulheres, "Mulheres");
                cout << endl;
                system("pause");
                system("cls");
                break;

            case 0:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opção inválida!\n";
                system("pause");
                system("cls");
        }
    } while (opcao != 0);

    return 0;
}
