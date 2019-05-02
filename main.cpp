/**
  * Autor: Leandro Dornela Ribeiro
  * Data: 13/08/2017
  */

#include "Tabuleiro.h"


int main()
{
    srand(time(0)); // Seed para o gerador de numeros aleatorios.

    const int maxTurnos = 1000; // Maximo de turnos.
    const int maxJogadores = 4; // Maximo de jogadores.
    const int saldoInicial = 300; // Saldo inicial dos jogadores.
    const int maxTestes = 300; // Maximo de partidas.
    int jogadoresAtivos = maxJogadores; // Numero de jogadores ativos na partida.
    int timeOut = 0; // Partidas terminadas por time out.
    int totalTurnos = 0; // Contador de turnos.
    Tabuleiro tabuleiro; // Tabuleiro do jogo.
    Jogador *jogadores[maxJogadores]; // Array com os jogadores.


    // Criacao dos jogadores.
    for(int i = 0; i < maxJogadores; i++)
    {
        jogadores[i] = new Jogador(i, saldoInicial);
    }


    // Faz o numero estabelecido de partidas.
    for(int t = 0; t < maxTestes; t++)
    {
        // Randomiza os jogadores.
        Jogador *aux[maxJogadores];
        for(int i = 0; i < maxJogadores; i++)
        {
            aux[i] = jogadores[i];
            jogadores[i] = NULL;
        }
        for(int i = 0; i < maxJogadores; i++)
        {
            int np = rand() %4;

            if(jogadores[np] == NULL)
            {
                jogadores[np] = aux[i];
            }
            else
            {
                while(jogadores[np] != NULL)
                {
                    np++;
                    if(np > maxJogadores) np = 0;
                }

                jogadores[np] = aux[i];
            }
        }


        // Realiza as jogadas.
        for(int i = 0; i < maxTurnos; i++)
        {
            // Da a vitoria ao jogador com saldo positivo quando somente ele esta ativo.
            if(jogadoresAtivos == 1)
            {
                for(int j = 0; j < maxJogadores; j++)
                {
                    if(jogadores[j]->GetSaldo() >= 0)
                    {
                        jogadores[j]->Venceu();
                    }
                }
                break;
            }

            totalTurnos++;

            // Se haver mais de 1 jogador faz as jogadas dos jogadores ativos.
            for(int j = 0; j < maxJogadores; j++)
            {
                // Verifica se o jogador ainda esta no jogo.
                if(jogadores[j]->GetSaldo() >= 0)
                {
                    int idPropriedade = jogadores[j]->Move();
                    jogadores[j]->Decisao(tabuleiro.GetPropriedade(idPropriedade));

                    // Verifica se o jogador esta fora de jogo, se sim, reduz o numero de jogadores ativos
                    // e remove ele como dono das propriedades.
                    if(jogadores[j]->ForaDoJogo())
                    {
                        jogadoresAtivos--;
                        tabuleiro.ValidaPropriedades();
                    }
                }
            }

            // Se foi o ultimo turno etao havera time out.
            if(i == maxTurnos - 1)
            {
                timeOut++;
            }
        }


        // Se ha mais de 1 jogador ativo deve ser feito o desempate. Caso os outros tenham
        // o mesmo saldo do primeiro, ele ganha pela ordem de jogo.
        if(jogadoresAtivos > 1)
        {
            Jogador *maior = jogadores[0];

            for(int i = 1; i < maxJogadores; i++)
            {
                if(jogadores[i]->GetSaldo() > maior->GetSaldo())
                {
                    maior = jogadores[i];
                }
            }

            maior->Venceu();
        }


        // Reseta os jogadores e o tabuleiro para a proxima partida.
        for(int j = 0; j < maxJogadores; j++)
        {
            jogadores[j]->Reset(saldoInicial);
        }
        tabuleiro.Reset();
        jogadoresAtivos = 4;
    }


    // Saida.
    std::cout << "====================RESULTADOS====================\n";
    std::cout << "- Partidas finalizadas por time out: " << timeOut << "\n";
    std::cout << "- Media de turnos por partida: " << totalTurnos/float(maxTestes) << "\n";
    std::cout << "- Porcentagem de vitorias por comportamento:\n";

    for(int i = 0; i < maxJogadores; i++)
    {
        std::cout << "      " << jogadores[i]->GetPersonalidade() << ": " << jogadores[i]->GetVitorias()/float(maxTestes)*100 << "%\n";
    }

    Jogador *maior = jogadores[0];
    for(int i = 1; i < maxJogadores; i++)
    {
        if(jogadores[i]->GetVitorias() > maior->GetVitorias())
        {
            maior = jogadores[i];
        }
    }
    std::cout << "- Comportamento que mais venceu: " << maior->GetPersonalidade() << "\n";
    std::cout << "==================================================\n";
}
