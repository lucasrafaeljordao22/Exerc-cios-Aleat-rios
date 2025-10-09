#include <iostream>
#include <string>
#include <algorithm> // para shuffle
#include <ctime>     // para time
#include <vector>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // inicializa random

    vector<string> palavras = {"computador", "programacao", "casa", "carro", "gato", "livro"};
    
    // escolhe uma palavra aleatória
    string palavraOriginal = palavras[rand() % palavras.size()];
    string palavraEmbaralhada = palavraOriginal;

    // embaralha a palavra
    random_shuffle(palavraEmbaralhada.begin(), palavraEmbaralhada.end());

    string tentativa;
    int tentativas = 0;

    cout << "=== Jogo Inverte Letras ===\n";
    cout << "Tente adivinhar a palavra!\n";
    cout << "Palavra embaralhada: " << palavraEmbaralhada << endl;

    do {
        cout << "Sua tentativa: ";
        cin >> tentativa;
        tentativas++;

        if (tentativa == palavraOriginal) {
            cout << "Parabéns! Você acertou em " << tentativas << " tentativas.\n";
            break;
        } else {
            cout << "Errado! Tente novamente.\n";
        }
    } while (true);

    return 0;
}
