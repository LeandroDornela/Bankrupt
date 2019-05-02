/**
  * Autor: Leandro Dornela Ribeiro
  * Data: 13/08/2017
  */

#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Tabuleiro.h"
#include "Propriedade.h"

class Propriedade;
class Jogador
{
    public:
        Jogador(int personalidade, int saldo); // Construtor.
        int GetSaldo(); // Retorna o saldo.
        int GetVitorias(); // Retorna o total de vitorias.
        std::string GetPersonalidade(); // Retorna a personalidade como string.
        void RecebeAluguel(int val); // Incrementa o valor do saldo.
        void Venceu(); // Incrementa o contador de vitorias.
        int Move(); // Determina a nova posicao do jogador.
        void Decisao(Propriedade *propriedade); // Toma uma decisao de acordo com a posicao onde parou.
        bool ForaDoJogo(); // Verifica se o jogador pode continuar o jogo.
        void Reset(int saldo); // Reseta as variaveis para um novo teste.
        ~Jogador(); // Destrutor.

    private:
        int personalidade; // Identificador da personalidade do jogador.
        int saldo; // Saldo do jogador.
        int posicaoAtual; // Posicao do jogador no tabuleiro.
        int vitorias; // Contador de vitorias.

        int JogaDado(); // Retorna um numero aleatorio de 1 a 6;
        void PagaAluguel(Propriedade *propriedade); // Paga o aluguel de uma propriedade.
        void Impulsivo(Propriedade *propriedade); // Acoes para o jogador impulsivo.
        void Exigente(Propriedade *propriedade); // Acoes para o jogador exigente.
        void Cauteloso(Propriedade *propriedade); // Acoes para o jogador cauteloso.
        void Aleatorio(Propriedade *propriedade); // Acoes para o jogadot aleatorio.
};

#endif
