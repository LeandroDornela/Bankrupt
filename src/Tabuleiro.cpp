/**
  * Autor: Leandro Dornela Ribeiro
  * Data: 13/08/2017
  */

#include "Tabuleiro.h"


// Construtor.
Tabuleiro::Tabuleiro()
{
    LerEntrada();
}


// Retorna uma propriedade dado seu id.
Propriedade *Tabuleiro::GetPropriedade(int id)
{
    return propriedades[id];
}


// Verifica se os donos das propriedades possuem saldo.
void Tabuleiro::ValidaPropriedades()
{
    for(int i = 0; i < TAMANHO; i++)
    {
        if((propriedades[i]->GetDono() != NULL) && (propriedades[i]->GetDono()->GetSaldo() < 0))
        {
            propriedades[i]->SetDono(NULL);
        }
    }
}


// Reseta oque for necessario para um novo teste.
void Tabuleiro::Reset()
{
    for(int i = 0; i < TAMANHO; i++)
    {
        propriedades[i]->SetDono(NULL);
    }
}


// Destrutor.
Tabuleiro::~Tabuleiro()
{
    // remover as propriedades
}


// Le o arquivo com as informacoes das propriedades.
void Tabuleiro::LerEntrada()
{
    int valorDeVenda;
    int valorDeAluguel;

    std::ifstream arqEntrada;
    arqEntrada.open("gameConfig.txt");

    if(!arqEntrada.is_open())
    {
        std::cout << "Não foi possível abrir o arquivo!\n";
        arqEntrada.clear( );
    }
    else
    {
        for(int i = 0; i < TAMANHO; i++)
        {
            arqEntrada >> valorDeVenda >> valorDeAluguel;
            propriedades[i] = new Propriedade(valorDeVenda, valorDeAluguel);
        }
        arqEntrada.close();
    }
}
