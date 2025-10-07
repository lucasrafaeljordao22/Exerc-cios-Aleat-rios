#include <iostream>
#include <cstdlib>

// Funcao reutilizavel para o jogo de adivinhar o numero.
void playAdivinha() {
    int numeroSecreto = std::rand() % 100 + 1; // Numero entre 1 e 100
    int palpite = 0;
    int tentativas = 0;

    std::cout << "Bem-vindo ao jogo de adivinhar o numero!\n";
    std::cout << "Tente adivinhar o numero entre 1 e 100.\n";

    do {
        std::cout << "Digite seu palpite: ";
        if (!(std::cin >> palpite)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida. Por favor, digite um numero.\n";
            continue;
        }
        tentativas++;
+
        if (palpite < numeroSecreto) {
            std::cout << "Muito baixo! Tente novamente.\n";
        } else if (palpite > numeroSecreto) {
            std::cout << "Muito alto! Tente novamente.\n";
        } else {
            std::cout << "Parabens! Voce acertou em " << tentativas << " tentativas.\n";
        }
    } while (palpite != numeroSecreto);
}

