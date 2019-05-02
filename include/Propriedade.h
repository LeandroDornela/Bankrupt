/**
  * Autor: Leandro Dornela Ribeiro
  * Data: 13/08/2017
  */

#ifndef PROPRIEDADE_H
#define PROPRIEDADE_H

#include "Jogador.h"

class Jogador;
class Propriedade
{
    public:
        Propriedade(int vv, int va); // Construtor.
        int GetValorDeVenda(); // Retorna o custo devenda.
        int GetValorDeAluguel(); // Retorna o valor de aluguel.
        Jogador *GetDono(); // Retorna o ponteiro para o dono.
        void SetDono(Jogador *dono); // Determina um novo dono.
        ~Propriedade(); // Destrutor.

    private:
        int valorDeVenda; // Valor para comprar a propriedade.
        int valorDeAluguel; // Valor de aluguel da propriedade.
        Jogador *dono; // Ponteiro para o dono da propriedade.
};

#endif
