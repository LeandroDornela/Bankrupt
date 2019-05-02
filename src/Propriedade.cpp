/**
  * Autor: Leandro Dornela Ribeiro
  * Data: 13/08/2017
  */

#include "Propriedade.h"


// Construtor.
Propriedade::Propriedade(int vv, int va)
{
    valorDeVenda = vv;
    valorDeAluguel = va;
    dono = NULL;
}


// Retorna o custo devenda.
int Propriedade::GetValorDeVenda()
{
    return valorDeVenda;
}


// Retorna o valor de aluguel.
int Propriedade::GetValorDeAluguel()
{
    return valorDeAluguel;
}


// Retorna o ponteiro para o dono.
Jogador *Propriedade::GetDono()
{
    return dono;
}


// Determina um novo dono.
void Propriedade::SetDono(Jogador *d)
{
    dono = d;
}


// Destrutor.
Propriedade::~Propriedade()
{

}
