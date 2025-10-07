#include <iostream>
#include <cstdlib>

// Par ou Impar - jogador escolhe um numero e par/impar contra o computador
void playParImpar() {
    std::cout << "\n-- Par ou Impar --\n";
    std::cout << "Escolha um numero inteiro: ";
    int n;
    if (!(std::cin >> n)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Entrada invalida. Voltando ao menu.\n";
        return;
    }
    int comp = std::rand() % 10 + 1; // 1..10
    std::cout << "Computador jogou: " << comp << " (total = " << n+comp << ")\n";
    bool totalPar = ((n + comp) % 2 == 0);

    std::cout << "Escolha: 1) Par  2) Impar\n";
    int escolha;
    if (!(std::cin >> escolha)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Entrada invalida. Voltando ao menu.\n";
        return;
    }

    bool jogadorGanha = (escolha == 1 && totalPar) || (escolha == 2 && !totalPar);
    if (jogadorGanha) std::cout << "Voce venceu!\n";
    else std::cout << "Computador venceu!\n";
}
