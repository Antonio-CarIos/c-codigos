# 🏫 Laboratório de Estrutura de Dados e Técnicas de Programação

## 📚 Primeira Avaliação - Implementação de Estruturas de Dados

Este repositório contém os scripts desenvolvidos para a **primeira avaliação** da disciplina **Laboratório de Estrutura de Dados e Técnicas de Programação**, sob a orientação do professor **Francisco Chagas de Lima Júnior**.

### 👨‍🏫 Professor
- **Francisco Chagas de Lima Júnior**

### 👨‍🎓👩‍🎓 Alunos Desenvolvedores
- **Antonio Carlos Monteiro Silva**
- **Gabryelle Ingride Pinto França**

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem**: C++
- **Paradigma**: Programação Estruturada e Orientação a Objetos
- **Compilador**: Compatível com GCC/G++ e Falcon
- **Sistema Operacional**: Windows/Linux

---

## 🚀 Como Compilar e Executar

### 📟 **Compilação com FALCON:**
Os scripts foram desenvolvidos em ambiente Falcon e Neovim, uns criados pelo Windows e Linux, os que são projetos Falcon estão localizados na pasta com o formato `fpj`, e podem ser executados diretamente no compilador Falcon. Os que foram feitos no Neovim estão direto como scripts `.cpp` e `.h`, também sendo possível utilizar o compilador Falcon. Entretando, para aqueles que não usam o Falcon, é possível executar via comando bash.

### 🐚 **Compilação Manual:**
```bash
# Método 1: Compilar tudo de uma vez
g++ -o programa main.cpp *.cpp

# Método 2: Compilar arquivo por arquivo
g++ -c main.cpp
g++ -c pares_recursivos.cpp  
g++ -c lista_recursiva.cpp
g++ -c lista_encadeada.cpp
g++ -c pilha.cpp
g++ -c lista_dupla_completa.cpp
g++ -o programa main.o pares_recursivos.o lista_recursiva.o lista_encadeada.o pilha.o lista_dupla_completa.o
./programa
