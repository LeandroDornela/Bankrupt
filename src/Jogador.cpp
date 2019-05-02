/**
  * Autor: Leandro Dornela Ribeiro
  * Data: 13/08/2017
  */

#include "Jogador.h"


// Construtor.
Jogador::Jogador(int p, int s)
{
    personalidade = p;
    saldo = s;
    posicaoAtual = 0;
    vitorias = 0;
}


// Retorna o saldo.
int Jogador::GetSaldo()
{
    return saldo;
}


// Retorna o total de vitorias.
int Jogador::GetVitorias()
{
    return vitorias;
}


// Retorna a personalidade como string.
std::string Jogador::GetPersonalidade()
{
    switch(personalidade)
    {
        case 0:
            return "Impulsivo";
        case 1:
            return "Exigente";
        case 2:
            return "Cauteloso";
        case 3:
            return "Aleatorio";
    }
    return NULL;
}


// Incrementa o valor do saldo.
void Jogador::RecebeAluguel(int val)
{
    saldo += val;
}


// Incrementa o contador de vitorias.
void Jogador::Venceu()
{
    vitorias++;
}


// Determina a nova posicao do jogador.
int Jogador::Move()
{
    int resultadoDado = JogaDado();
    int novaPosicao = posicaoAtual + resultadoDado;

    // Completou uma volta.
    if(novaPosicao >= TAMANHO)
    {
        novaPosicao = novaPosicao - TAMANHO;
        saldo += 100;
    }
    posicaoAtual = novaPosicao;

    return posicaoAtual;
}


// Toma uma decisao de acordo com a posicao onde parou.
void Jogador::Decisao(Propriedade *propriedade)
{
    // Se a propriedade nao tem um dono.
    if(propriedade->GetDono() == NULL)
    {
        switch (personalidade)
        {
            case 0:
                Impulsivo(propriedade);
            break;
            case 1:
                Exigente(propriedade);
            break;
            case 2:
                Cauteloso(propriedade);
            break;
            case 3:
                Aleatorio(propriedade);
            break;
        }
    }
    else if(propriedade->GetDono() != this)
    {
        PagaAluguel(propriedade);
    }
}


// Verifica se o jogador pode continuar o jogo.
bool Jogador::ForaDoJogo()
{
    if(saldo < 0)
    {
        return true;
    }
    return false;
}


// Reseta as variaveis para um novo teste.
void Jogador::Reset(int s)
{
    saldo = s;
    posicaoAtual = 0;
}


// Destrutor.
Jogador::~Jogador()
{

}


// Retorna um numero aleatorio de 1 a 6;
int Jogador::JogaDado()
{
    return rand() % 6 + 1;
}


// Paga o aluguel de uma propriedade.
void Jogador::PagaAluguel(Propriedade *propriedade)
{
    // Reduz o saldo do jogador.
    saldo -= propriedade->GetValorDeAluguel();

    // Incrementa o saldo do dono da propriedade.
    propriedade->GetDono()->RecebeAluguel(propriedade->GetValorDeAluguel());
}


// Compra qualquer propriedade sobre a qual ele parar.
void Jogador::Impulsivo(Propriedade *propriedade)
{
    int dif = saldo - propriedade->GetValorDeVenda();

    if(dif > 0)
    {
        saldo = dif;
        propriedade->SetDono(this);
    }
}


// Compra qualquer propriedade, desde que o aluguel dela seja maior do que 50.
void Jogador::Exigente(Propriedade *propriedade)
{
    int dif = saldo - propriedade->GetValorDeVenda();

    if(dif > 0 && propriedade->GetValorDeAluguel() > 50)
    {
        saldo = dif;
        propriedade->SetDono(this);
    }
}


// Compra qualquer propriedade desde que ele tenha uma reserva de 80 sobrando depois de realizada a compra.
void Jogador::Cauteloso(Propriedade *propriedade)
{
    int dif = saldo - propriedade->GetValorDeVenda();

    if(dif >= 80)
    {
        saldo = dif;
        propriedade->SetDono(this);
    }
}


// Compra a propriedade que ele parar em cima com probabilidade de 50%.
void Jogador::Aleatorio(Propriedade *propriedade)
{
    int dif = saldo - propriedade->GetValorDeVenda();
    int compra = rand() %2;

    if(dif > 0 && compra)
    {
        saldo = dif;
        propriedade->SetDono(this);
    }
}
