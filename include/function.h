// function.h - protótipos e stubs das funções de jogo
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

// Comentário geral:
// Este header fornece versões "stub" (simples) das funções de jogo.
// Elas permitem que o menu seja compilado e executado mesmo quando as
// implementações completas ainda não existam. Quando quiser substituir
// por implementações reais, crie os arquivos .cpp correspondentes e
// remova ou atualize estes stubs.

/*
 * Jogo: Adivinha (stub)
 * ---------------------
 * Propósito: placeholder para a função do jogo de adivinhar. Mostra uma
 * mensagem informando que a implementação ainda não foi provida.
 */
inline void playAdivinha() {
    std::cout << "[Adivinha] Nao implementado.\n";
}

/*
 * Jogo: Pedra-Papel-Tesoura (stub)
 * --------------------------------
 * Propósito: placeholder para o jogo RPS. Substitua por implementacao
 * real quando desejar incluir este jogo no menu.
 */
inline void playRPS() {
    std::cout << "[RPS] Nao implementado.\n";
}

/*
 * Jogo: Par ou Impar (stub)
 * -------------------------
 * Propósito: placeholder que informa que o jogo nao esta implementado.
 */
inline void playParImpar() {
    std::cout << "[ParImpar] Nao implementado.\n";
}

#endif // FUNCTION_H
