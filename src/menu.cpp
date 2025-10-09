#include <iostream>
#include <cstdlib>
#include <ctime>

// Declaracoes das funcoes (em header)
#include "../include/function.h"

int main() {
	std::srand(std::time(nullptr));

	while (true) {
		std::cout << "\n=== Menu de Jogos ===\n";
		std::cout << "1) Adivinhar o numero\n";
		std::cout << "2) Pedra, Papel, Tesoura\n";
		std::cout << "3) Par ou Impar\n";
		std::cout << "4) Sair\n";
		std::cout << "Escolha uma opcao: ";

		int opc;
		if (!(std::cin >> opc)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Entrada invalida. Tente novamente.\n";
			continue;
		}

		switch (opc) {
			case 1: playAdivinha(); break;
			case 2: playRPS(); break;
			case 3: playParImpar(); break;
			case 4: std::cout << "Saindo...\n"; return 0;
			default: std::cout << "Opcao invalida.\n"; break;
		}
	}
	return 0;
}

