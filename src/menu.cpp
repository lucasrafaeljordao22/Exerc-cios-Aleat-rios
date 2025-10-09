#include <iostream>
#include <string>
#include <algorithm> // para shuffle
#include <ctime>     // para time
#include <random>
#include <vector>
#include <climits>
using namespace std;

// Motor de random global
// Gerador de números aleatórios (std::mt19937)
// inicializado com std::random_device para boa aleatoriedade.
static std::mt19937 rng(std::random_device{}());

/*
 * Jogo: Inverter Letras
 * ---------------------
 * Descrição:
 *   Seleciona uma palavra aleatória de uma lista, embaralha suas letras
 *   e pede que o utilizador tente adivinhar a palavra original.
 *
 * Entradas:
 *   - entrada padrão (std::cin): tentativas do utilizador (strings)
 *
 * Saídas:
 *   - mensagens no console informando a palavra embaralhada, se
 *     a tentativa está correta/errada e dicas periódicas.
 *
 * Comportamento adicional:
 *   - a cada 3 tentativas erradas o jogo revela uma letra não descoberta
 *     (mostrada em uma máscara com '_' para as letras ocultas).
 *
 * Erros/validações:
 *   - assume-se que o utilizador digite uma palavra (string); entradas vazias
 *     são tratadas como tentativas inválidas mas não encerram o jogo.
 */
void playInverterLetras() {
    vector<string> palavras = {
		"computador", "vermelho", "verde", "branco", "roxo", "azul", 
		"ciano", "preto", "teclado", "rato", "zebra", "gato", "macaco", 
		"cachorro", "elefante", "girafa","banana", "laranja", "maca",
		"uva", "pera", "abacaxi", "melancia", "pessego", "tomate",
		"alface", "arroz", "feijao", "carne", "manteiga", "maionese",
		"esparguete", "salsicha", "massa",
		"cidade", "pais", "mundo", "terra", 
		"galaxia", "universo", "estrela", "planeta", "cometa",
		"sol", "lua", "nuvens", "ceu", "deus", "diabo",  
		"arvore", "relva", "floresta", "rio", "mar", "oceano", 
		"montanha", "colina", "valle", "deserto", "ilha", 
		"futebol", "basquete", "tenis", "volei", "cricket", 
		"xadrez", "dama", "poker", "blackjack",
		"programacao", "casa", "carro", "livro", "caneta", "papel",
		"telefone", "janela", "porta", "cadeira", "mesa", "cama",
		"relogio", "calendario", "computador", "internet", "software"

	};

    // escolhe uma palavra aleatória
    uniform_int_distribution<size_t> dist(0, palavras.size() - 1);
    string palavraOriginal = palavras[dist(rng)];
    string palavraEmbaralhada = palavraOriginal;

    // embaralha a palavra
    shuffle(palavraEmbaralhada.begin(), palavraEmbaralhada.end(), rng);

    string tentativa;
    int tentativas = 0;
    // Dicas: '_' para letras não reveladas
    string hintMask(palavraOriginal.size(), '_');

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
            // a cada 3 tentativas erradas, revele uma letra como dica
            if (tentativas % 3 == 0) {
                // encontra índices ainda não revelados
                vector<size_t> unrevealed;
                for (size_t i = 0; i < hintMask.size(); ++i) {
                    if (hintMask[i] == '_') unrevealed.push_back(i);
                }

                if (!unrevealed.empty()) {
                    uniform_int_distribution<size_t> pick(0, unrevealed.size() - 1);
                    size_t chosen = unrevealed[pick(rng)];
                    hintMask[chosen] = palavraOriginal[chosen];
                    cout << "Dica: " << hintMask << "\n";
                } else {
                    cout << "Dica: Todas as letras já foram reveladas.\n";
                }
            }
        }
    } while (true);
}

/*
 * Jogo: Adivinha o Número
 * -----------------------
 * Descrição:
 *   O computador escolhe um número inteiro secreto entre 1 e 100.
 *   O utilizador faz palpites até acertar o número.
 *
 * Entradas:
 *   - entrada padrão (std::cin): palpites do utilizador (números inteiros)
 *
 * Saídas:
 *   - indica se o palpite é "Muito baixo", "Muito alto" ou correto.
 *   - conta e exibe o número de tentativas quando o utilizador acerta.
 *
 * Validações:
 *   - entradas não numéricas são detectadas, o fluxo é limpo e o utilizador
 *     é solicitado a tentar novamente.
 */
void playAdivinhaNumero() {
    uniform_int_distribution<int> dist(1, 100);
    int secreto = dist(rng);
    int tentativa;
    int tentativas = 0;

    cout << "=== Adivinha o Número ===\n";
    cout << "Estou a pensar em um número entre 1 e 100. Tente adivinhar!\n";

    do {
        cout << "Seu palpite: ";
        if (!(cin >> tentativa)) {
            cin.clear();
            string trash;
            getline(cin, trash);
            cout << "Entrada inválida. Digite um número.\n";
            continue;
        }
        tentativas++;

        if (tentativa == secreto) {
            cout << "Parabéns! Você acertou em " << tentativas << " tentativas.\n";
            break;
        } else if (tentativa < secreto) {
            cout << "Muito baixo. Tente um número maior.\n";
        } else {
            cout << "Muito alto. Tente um número menor.\n";
        }
    } while (true);
}

void playQuenteFrio();

/*
 * Função: main (Menu Principal)
 * -----------------------------
 * Descrição:
 *   Mostra um menu simples no console e permite ao utilizador escolher entre
 *   os jogos implementados. Lê a opção do utilizador e chama a função do jogo
 *   correspondente. O menu permanece ativo até o utilizador selecionar "Sair".
 *
 * Opções disponíveis:
 *   1 - Inverter letras
 *   2 - Adivinha o numero
 *   3 - Quente ou Frio
 *   4 - Sair
 *
 * Observações:
 *   - Entradas inválidas (texto quando se espera número) são tratadas e
 *     o utilizador é convidado a tentar novamente.
 */

int main() {
    int opcao = 0;

    do {
        cout << "\n=== Menu Principal ===\n";
        cout << "1. Inverter letras\n";
        cout << "2. Adivinha o numero\n";
        cout << "3. Quente ou Frio\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            string trash;
            getline(cin, trash);
            cout << "Entrada inválida. Digite 1, 2, 3 ou 4.\n";
            continue;
        }

        switch (opcao) {
            case 1:
                playInverterLetras();
                break;
            case 2:
                playAdivinhaNumero();
                break;
            case 3:
                playQuenteFrio();
                break;
            case 4:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 4);

    return 0;
}

/*
 * Jogo: Quente ou Frio
 * --------------------
 * O computador escolhe um número secreto entre 1 e 100.
 * O utilizador dá palpites. A cada palpite o programa responde
 * com uma indicação qualitativa da proximidade:
 *   - "Muito quente"  : diferença <= 2
 *   - "Quente"        : diferença entre 3 e 5
 *   - "Morno"         : diferença entre 6 e 10
 *   - "Frio"          : diferença > 10
 *
 * Além disso, o jogo informa se o palpite atual é o mais próximo
 * até agora. O jogo termina quando o utilizador acerta o número.
 */
void playQuenteFrio() {
    uniform_int_distribution<int> dist(1, 100);
    int secreto = dist(rng);
    int tentativa;
    int tentativas = 0;
    int melhorDistancia = INT_MAX; // menor diferença observada até agora

    cout << "=== Quente ou Frio ===\n";
    cout << "Estou pensando em um número entre 1 e 100. Tente adivinhar!\n";

    do {
        cout << "Seu palpite: ";
        if (!(cin >> tentativa)) {
            cin.clear();
            string trash;
            getline(cin, trash);
            cout << "Entrada inválida. Digite um número entre 1 e 100.\n";
            continue;
        }

        if (tentativa < 1 || tentativa > 100) {
            cout << "Por favor, digite um número entre 1 e 100.\n";
            continue;
        }

        tentativas++;
        int diff = abs(tentativa - secreto);

        // marca se este palpite é o melhor até agora
        bool novoMelhor = diff < melhorDistancia;
        if (novoMelhor) melhorDistancia = diff;

        if (diff == 0) {
            cout << "Parabéns! Você encontrou o número secreto em " << tentativas << " tentativas.\n";
            break;
        }

        // resposta qualitativa
        if (diff <= 2) cout << "Muito quente";
        else if (diff <= 5) cout << "Quente";
        else if (diff <= 10) cout << "Morno";
        else cout << "Frio";

        // informa se é o palpite mais próximo até agora
        if (novoMelhor) cout << " — Este é seu melhor palpite até agora.";

        cout << "\n";
    } while (true);
}