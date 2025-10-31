import java.util.Scanner;

class NoAVL {
    int valor;
    int altura;
    NoAVL esquerda;
    NoAVL direita;
    
    public NoAVL(int valor) {
        this.valor = valor;
        this.altura = 1; 
        this.esquerda = null;
        this.direita = null;
    }
}

public class ArvoreAVL {
    private NoAVL raiz;
    private Scanner scanner;
    
    public ArvoreAVL() {
        this.raiz = null;
        this.scanner = new Scanner(System.in);
        System.out.println("Árvore AVL Inicializada!");
    }
    
    private int altura(NoAVL no) {
        return (no == null) ? 0 : no.altura;
    }
    
    private int fatorBalanceamento(NoAVL no) {
        return (no == null) ? 0 : altura(no.esquerda) - altura(no.direita);
    }
    
    private void atualizarAltura(NoAVL no) {
        if (no != null) {
            no.altura = 1 + Math.max(altura(no.esquerda), altura(no.direita));
        }
    }
    
    private NoAVL rotacaoDireita(NoAVL y) {
        NoAVL x = y.esquerda;
        NoAVL T2 = x.direita;
        
        x.direita = y;
        y.esquerda = T2;
        
        atualizarAltura(y);
        atualizarAltura(x);
        
        return x;
    }
    
    private NoAVL rotacaoEsquerda(NoAVL x) {
        NoAVL y = x.direita;
        NoAVL T2 = y.esquerda;
        
        y.esquerda = x;
        x.direita = T2;
        
        atualizarAltura(x);
        atualizarAltura(y);
        
        return y;
    }
    
    public void inserir(int valor) {
        raiz = inserirRecursivo(raiz, valor);
        System.out.println("Valor " + valor + " inserido na AVL!");
    }
    
    private NoAVL inserirRecursivo(NoAVL no, int valor) {
        if (no == null) {
            return new NoAVL(valor);
        }
        
        if (valor < no.valor) {
            no.esquerda = inserirRecursivo(no.esquerda, valor);
        } else if (valor > no.valor) {
            no.direita = inserirRecursivo(no.direita, valor);
        } else {
            System.out.println("Valor " + valor + " duplicado! Não permitido na AVL.");
            return no;
        }
        
        atualizarAltura(no);
        
        int balanceamento = fatorBalanceamento(no);
        
        if (balanceamento > 1 && valor < no.esquerda.valor) {
            System.out.println("Aplicando rotação Direita (LL)");
            return rotacaoDireita(no);
        }
        
        if (balanceamento < -1 && valor > no.direita.valor) {
            System.out.println("Aplicando rotação Esquerda (RR)");
            return rotacaoEsquerda(no);
        }
        
        if (balanceamento > 1 && valor > no.esquerda.valor) {
            System.out.println("Aplicando rotação Esquerda-Direita (LR)");
            no.esquerda = rotacaoEsquerda(no.esquerda);
            return rotacaoDireita(no);
        }
        
        if (balanceamento < -1 && valor < no.direita.valor) {
            System.out.println("Aplicando rotação Direita-Esquerda (RL)");
            no.direita = rotacaoDireita(no.direita);
            return rotacaoEsquerda(no);
        }
        
        return no;
    }
    
    public void remover(int valor) {
        raiz = removerRecursivo(raiz, valor);
    }
    
    private NoAVL removerRecursivo(NoAVL no, int valor) {
        if (no == null) {
            System.out.println("Valor " + valor + " não encontrado!");
            return null;
        }
        
        if (valor < no.valor) {
            no.esquerda = removerRecursivo(no.esquerda, valor);
        } else if (valor > no.valor) {
            no.direita = removerRecursivo(no.direita, valor);
        } else {
            System.out.println("Valor " + valor + " removido da AVL!");
            
            if (no.esquerda == null || no.direita == null) {
                NoAVL temp = (no.esquerda != null) ? no.esquerda : no.direita;
                
                if (temp == null) {
                    no = null; 
                } else {
                    no = temp; 
                }
            } else {
                NoAVL temp = encontrarMenorValor(no.direita);
                no.valor = temp.valor;
                no.direita = removerRecursivo(no.direita, temp.valor);
            }
        }
        
        if (no == null) {
            return null;
        }
        
        atualizarAltura(no);
        
        int balanceamento = fatorBalanceamento(no);
        
        if (balanceamento > 1 && fatorBalanceamento(no.esquerda) >= 0) {
            System.out.println("Aplicando rotação Direita (LL) após remoção");
            return rotacaoDireita(no);
        }
        
        if (balanceamento > 1 && fatorBalanceamento(no.esquerda) < 0) {
            System.out.println("Aplicando rotação Esquerda-Direita (LR) após remoção");
            no.esquerda = rotacaoEsquerda(no.esquerda);
            return rotacaoDireita(no);
        }
        
        if (balanceamento < -1 && fatorBalanceamento(no.direita) <= 0) {
            System.out.println("Aplicando rotação Esquerda (RR) após remoção");
            return rotacaoEsquerda(no);
        }
        
        if (balanceamento < -1 && fatorBalanceamento(no.direita) > 0) {
            System.out.println("Aplicando rotação Direita-Esquerda (RL) após remoção");
            no.direita = rotacaoDireita(no.direita);
            return rotacaoEsquerda(no);
        }
        
        return no;
    }
    
    private NoAVL encontrarMenorValor(NoAVL no) {
        while (no.esquerda != null) {
            no = no.esquerda;
        }
        return no;
    }
    
    public boolean buscar(int valor) {
        return buscarRecursivo(raiz, valor);
    }
    
    private boolean buscarRecursivo(NoAVL no, int valor) {
        if (no == null) {
            return false;
        }
        
        if (valor == no.valor) {
            System.out.println("Valor " + valor + " encontrado na AVL! Altura: " + no.altura);
            return true;
        } else if (valor < no.valor) {
            return buscarRecursivo(no.esquerda, valor);
        } else {
            return buscarRecursivo(no.direita, valor);
        }
    }
    
    public void emOrdem() {
        System.out.print("Em Ordem: ");
        emOrdemRecursivo(raiz);
        System.out.println();
    }
    
    private void emOrdemRecursivo(NoAVL no) {
        if (no != null) {
            emOrdemRecursivo(no.esquerda);
            System.out.print(no.valor + "(" + no.altura + ") ");
            emOrdemRecursivo(no.direita);
        }
    }
    
    public void preOrdem() {
        System.out.print("Pré-Ordem: ");
        preOrdemRecursivo(raiz);
        System.out.println();
    }
    
    private void preOrdemRecursivo(NoAVL no) {
        if (no != null) {
            System.out.print(no.valor + "(" + no.altura + ") ");
            preOrdemRecursivo(no.esquerda);
            preOrdemRecursivo(no.direita);
        }
    }
    
    public void posOrdem() {
        System.out.print("Pós-Ordem: ");
        posOrdemRecursivo(raiz);
        System.out.println();
    }
    
    private void posOrdemRecursivo(NoAVL no) {
        if (no != null) {
            posOrdemRecursivo(no.esquerda);
            posOrdemRecursivo(no.direita);
            System.out.print(no.valor + "(" + no.altura + ") ");
        }
    }
    
    public void mostrarArvore() {
        System.out.println("Estrutura da Árvore AVL:");
        mostrarArvoreRecursivo(raiz, 0);
    }
    
    private void mostrarArvoreRecursivo(NoAVL no, int nivel) {
        if (no != null) {
            mostrarArvoreRecursivo(no.direita, nivel + 1);
            
            for (int i = 0; i < nivel; i++) {
                System.out.print("    ");
            }
            
            System.out.println(no.valor + " (h:" + no.altura + ")");
            
            mostrarArvoreRecursivo(no.esquerda, nivel + 1);
        }
    }
    
    public void menu() {
        int opcao;
        
        do {
            System.out.println("\n========================================================");
            System.out.println("                  ÁRVORE AVL - MENU");
            System.out.println("========================================================");
            System.out.println("  [1] INSERIR elemento");
            System.out.println("  [2] REMOVER elemento");
            System.out.println("  [3] BUSCAR elemento");
            System.out.println("  [4] IMPRIMIR em ORDEM");
            System.out.println("  [5] IMPRIMIR PRÉ-ORDEM");
            System.out.println("  [6] IMPRIMIR PÓS-ORDEM");
            System.out.println("  [7] MOSTRAR estrutura da árvore");
            System.out.println("  [8] VOLTAR ao menu principal");
            System.out.println("--------------------------------------------------------");
            System.out.print("  Opção escolhida: ");
            
            opcao = scanner.nextInt();
            
            switch (opcao) {
                case 1:
                    System.out.print("Digite o valor a ser inserido: ");
                    int valorInserir = scanner.nextInt();
                    inserir(valorInserir);
                    break;
                    
                case 2:
                    System.out.print("Digite o valor a ser removido: ");
                    int valorRemover = scanner.nextInt();
                    remover(valorRemover);
                    break;
                    
                case 3:
                    System.out.print("Digite o valor a ser buscado: ");
                    int valorBuscar = scanner.nextInt();
                    if (!buscar(valorBuscar)) {
                        System.out.println("Valor " + valorBuscar + " não encontrado!");
                    }
                    break;
                    
                case 4:
                    emOrdem();
                    break;
                    
                case 5:
                    preOrdem();
                    break;
                    
                case 6:
                    posOrdem();
                    break;
                    
                case 7:
                    mostrarArvore();
                    break;
                    
                case 8:
                    System.out.println("Retornando ao menu principal...");
                    break;
                    
                default:
                    System.out.println("Opção inválida! Tente novamente.");
            }
            
            if (opcao != 8) {
                System.out.println("\nPressione ENTER para continuar...");
                scanner.nextLine(); 
                scanner.nextLine(); 
            }
            
        } while (opcao != 8);
    }
}
