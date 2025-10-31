import java.util.Scanner;

class NoABB {
    int valor;
    int contador; 
    NoABB esquerda;
    NoABB direita;
    
    public NoABB(int valor) {
        this.valor = valor;
        this.contador = 1; 
        this.esquerda = null;
        this.direita = null;
    }
}


public class ArvoreBinariaBusca {
    private NoABB raiz;
    private Scanner scanner;
     
    public ArvoreBinariaBusca() {
        this.raiz = null;
        this.scanner = new Scanner(System.in);
        System.out.println("Árvore Binária de Busca Inicializada!");
    }
    
    public void inserir(int valor) {
        raiz = inserirRecursivo(raiz, valor);
    }
    
    private NoABB inserirRecursivo(NoABB no, int valor) {
        if (no == null) {
            System.out.println("Valor " + valor + " inserido como novo nó!");
            return new NoABB(valor);
        }
        
        if (valor < no.valor) {
            no.esquerda = inserirRecursivo(no.esquerda, valor);
        } else if (valor > no.valor) {
            no.direita = inserirRecursivo(no.direita, valor);
        } else {
            no.contador++;
            System.out.println("Valor " + valor + " repetido! Contador: " + no.contador);
        }
        return no;
    }
    
    public void remover(int valor) {
        raiz = removerRecursivo(raiz, valor);
    }
    
    private NoABB removerRecursivo(NoABB no, int valor) {
        if (no == null) {
            System.out.println("Valor " + valor + " não encontrado!");
            return null;
        }
        
        if (valor < no.valor) {
            no.esquerda = removerRecursivo(no.esquerda, valor);
        } else if (valor > no.valor) {
            no.direita = removerRecursivo(no.direita, valor);
        } else {
            if (no.contador > 1) {
                no.contador--;
                System.out.println("Contador decrementado. Ocorrências restantes: " + no.contador);
            } else {
                System.out.println("Nó com valor " + valor + " removido completamente!");
                
                if (no.esquerda == null && no.direita == null) {
                    return null; 
                } else if (no.esquerda == null) {
                    return no.direita; 
                } else if (no.direita == null) {
                    return no.esquerda; 
                } else {
                    NoABB sucessor = encontrarMenorValor(no.direita);
                    no.valor = sucessor.valor;
                    no.contador = sucessor.contador;
                    no.direita = removerRecursivo(no.direita, sucessor.valor);
                }
            }
        }
        return no;
    }
    
    private NoABB encontrarMenorValor(NoABB no) {
        while (no.esquerda != null) {
            no = no.esquerda;
        }
        return no;
    }
    
    public boolean ehCheia() {
        return ehCheiaRecursivo(raiz);
    }
    
    private boolean ehCheiaRecursivo(NoABB no) {
        if (no == null) {
            return true;
        }
        
        if (no.esquerda == null && no.direita == null) {
            return true;
        }
        
        if (no.esquerda != null && no.direita != null) {
            return ehCheiaRecursivo(no.esquerda) && ehCheiaRecursivo(no.direita);
        }
        
        return false;
    }
    
    public void emOrdem() {
        System.out.print("Em Ordem: ");
        emOrdemRecursivo(raiz);
        System.out.println();
    }
    
    private void emOrdemRecursivo(NoABB no) {
        if (no != null) {
            emOrdemRecursivo(no.esquerda);
            System.out.print(no.valor + "(" + no.contador + ") ");
            emOrdemRecursivo(no.direita);
        }
    }
    
    public void preOrdem() {
        System.out.print("Pré-Ordem: ");
        preOrdemRecursivo(raiz);
        System.out.println();
    }
    
    private void preOrdemRecursivo(NoABB no) {
        if (no != null) {
            System.out.print(no.valor + "(" + no.contador + ") ");
            preOrdemRecursivo(no.esquerda);
            preOrdemRecursivo(no.direita);
        }
    }
    
    public void posOrdem() {
        System.out.print("Pós-Ordem: ");
        posOrdemRecursivo(raiz);
        System.out.println();
    }
    
    private void posOrdemRecursivo(NoABB no) {
        if (no != null) {
            posOrdemRecursivo(no.esquerda);
            posOrdemRecursivo(no.direita);
            System.out.print(no.valor + "(" + no.contador + ") ");
        }
    }
    
    public boolean buscar(int valor) {
        return buscarRecursivo(raiz, valor);
    }
    
    private boolean buscarRecursivo(NoABB no, int valor) {
        if (no == null) {
            return false;
        }
        
        if (valor == no.valor) {
            System.out.println("Valor " + valor + " encontrado! Ocorrências: " + no.contador);
            return true;
        } else if (valor < no.valor) {
            return buscarRecursivo(no.esquerda, valor);
        } else {
            return buscarRecursivo(no.direita, valor);
        }
    }
    
    public void menu() {
        int opcao;
        
        do {
            System.out.println("\n========================================================");
            System.out.println("           ÁRVORE BINÁRIA DE BUSCA - MENU");
            System.out.println("========================================================");
            System.out.println("  [1] INSERIR elemento");
            System.out.println("  [2] REMOVER elemento");
            System.out.println("  [3] BUSCAR elemento");
            System.out.println("  [4] VERIFICAR se árvore é CHEIA");
            System.out.println("  [5] IMPRIMIR em ORDEM");
            System.out.println("  [6] IMPRIMIR PRÉ-ORDEM");
            System.out.println("  [7] IMPRIMIR PÓS-ORDEM");
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
                    if (ehCheia()) {
                        System.out.println("A árvore É CHEIA!");
                    } else {
                        System.out.println("A árvore NÃO É CHEIA!");
                    }
                    break;
                    
                case 5:
                    emOrdem();
                    break;
                    
                case 6:
                    preOrdem();
                    break;
                    
                case 7:
                    posOrdem();
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
