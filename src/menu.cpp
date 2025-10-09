#include <iostream>
#include <cstdlib>   // para rand() e srand()
#include <ctime>     // para time()
#include <cmath>     // para abs()
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // inicializa o gerador de números aleatórios
    int numeroSecreto = rand() % 100 + 1; // número aleatório entre 1 e 100
    int tentativa;
    int tentativas = 0;

    cout << "=== Jogo Quente ou Frio ===\n";
    cout << "Tente adivinhar o número entre 1 e 100!\n";

    do {
        cout << "Digite sua tentativa: ";
        cin >> tentativa;
        tentativas++;

        int diferenca = abs(numeroSecreto - tentativa);

        if (tentativa == numeroSecreto) {
            cout << "Parabéns! Você acertou em " << tentativas << " tentativas.\n";
            break;
        } else if (diferenca <= 5) {
            cout << "Quente!\n";
        } else if (diferenca <= 15) {
            cout << "Morno.\n";
        } else {
            cout << "Frio.\n";
        }
    } while (true);

    return 0;
}
// Jogo "Quente ou Frio" em C++