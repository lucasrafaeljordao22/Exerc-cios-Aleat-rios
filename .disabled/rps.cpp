#include <iostream>
#include <cstdlib>

// Pedra, Papel, Tesoura - jogador vs computador
void playRPS() {
    std::cout << "\n-- Pedra, Papel ou Tesoura --\n";
    std::cout << "Escolha: 1) Pedra  2) Papel  3) Tesoura\n";

    int escolha;
    if (!(std::cin >> escolha)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Entrada invalida. Voltando ao menu.\n";
        return;
    }

    int comp = std::rand() % 3 + 1; // 1..3

    auto name = [](int v){ return v==1?"Pedra":(v==2?"Papel":"Tesoura"); };
    std::cout << "Voce: " << name(escolha) << "  vs  Computador: " << name(comp) << "\n";

    if (escolha == comp) {
        std::cout << "Empate!\n";
    } else if ((escolha==1 && comp==3) || (escolha==2 && comp==1) || (escolha==3 && comp==2)) {
        std::cout << "Voce ganhou!\n";
    } else {
        std::cout << "Computador ganhou!\n";
    }
}
