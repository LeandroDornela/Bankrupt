/**
  * Autor: Leandro Dornela Ribeiro
  * Data: 13/08/2017
  */

#ifndef TABULEIRO_H
#define TABULEIRO_H
#define TAMANHO 20

#include <iostream>
#include <fstream>
#include "Propriedade.h"

class Propriedade;
class Tabuleiro
{
    public:
        Tabuleiro(); // Construtor.
        Propriedade *GetPropriedade(int id); // Retorna uma propriedade dado seu id.
        void ValidaPropriedades(); // Verifica se os donos das propriedades possuem saldo.
        void Reset(); // Reseta para um novo teste.
        ~Tabuleiro(); // Destrutor.

    private:
        Propriedade *propriedades[TAMANHO]; // Array com as propriedades.

        void LerEntrada(); // Le o arquivo com as informacoes das propriedades.
};

#endif
