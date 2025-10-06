#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr)); // Inicializa o gerador de números aleatórios
    int numeroSecreto = std::rand() % 100 + 1; // Número entre 1 e 100
    int palpite;
    int tentativas = 0;

    std::cout << "Bem-vindo ao jogo de adivinhar o número!\n";
    std::cout << "Tente adivinhar o número entre 1 e 100.\n";

    do {
        std::cout << "Digite seu palpite: ";
        std::cin >> palpite;
        tentativas++;

        if (palpite < numeroSecreto) {
            std::cout << "Muito baixo! Tente novamente.\n";
        } else if (palpite > numeroSecreto) {
            std::cout << "Muito alto! Tente novamente.\n";
        } else {
            std::cout << "Parabéns! Você acertou em " << tentativas << " tentativas.\n";
        }
    } while (palpite != numeroSecreto);

    return 0;
}