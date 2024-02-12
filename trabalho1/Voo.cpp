#include "Voo.h"
#include "Pessoa.h"
#include <string.h>

namespace poo
{
    //Construtor
    Voo::Voo(Companhia& companhia, string origem, string destino, DataHorario& data) : companhia(companhia), origem(origem), destino(destino), data(data) {
        //Setando todos os atributos "nome" e "cpf" de cada objeto da classe Pessoa para "Vazio"
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 25; j++) {
                poltrona[j][i] = NULL;
            }
        }
        //Inicializando a quantidade de vagas do voo
        numVagas = 150;
    }
    
    //Destrutor
    Voo::~Voo() { 
    }
    
    //Implementação dos métodos
    string Voo::proximoLivre() {
        string cadeiraLivre;
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 6; j++) {
                //Verofoca se a poltrona está vazia e, caso esteja, retorna seu valor
                if (poltrona[i][j] == NULL) {
                    cadeiraLivre = to_string(i + 1);
                    cadeiraLivre.append(1, ((char) ('A' + j)));
                    cadeiraLivre.insert(0, 3 - cadeiraLivre.size(), '0');
                    return cadeiraLivre;
                }
            }
        }
        //Retorna "cheio" caso não haja poltronas livres
        return "cheio";
    }
    
    bool Voo::verifica(string cadeira) {
        //Variável booleana que diz que uma poltrona está ocupada (retorna verdadeiro)
        bool ocupada = true;
        //Transforma string em linha e coluna da matriz *Pessoa
        int linha = stoi(cadeira.substr(0,2)) - 1;
        int coluna = cadeira[2] - 'A';
        //Caso essa poltrona esteja vazia, retorna falso
        if (poltrona[linha][coluna] ==  NULL) {
            ocupada = false;
        }
        return ocupada;
    }

    bool Voo::ocupa(string cadeira, Pessoa& passageiro) {
        //Variável booleana que diz que uma poltrona pode ser ocupada (retorna verdadeiro se for ocupada)
        bool ehOcupada = true;
        //Verifica se está vazia
        if (!(verifica(cadeira))) {
            //Transforma string em linha e coluna da matriz *Pessoa
            int linha = stoi(cadeira.substr(0,2)) - 1;
            int coluna = cadeira[2] - 'A';
            poltrona[linha][coluna] = &passageiro;
            //Decrementa 1 da quantidade de vagas disponíveis no voo
            numVagas--;
        }
        else {
            //Retorna falso se a cadeira já estiver ocupada
            ehOcupada = false;
        }
        return ehOcupada;
    }
    
    bool Voo::desocupa(string cadeira) {
        //Variável booleana que diz que uma poltrona pode ser desocupada (retorna verdadeiro se for desocupada)
        bool ehDesocupada = true;
        //Verifica se a cadeira pode ser desocupada, ou seja, se está ocupada
        if (verifica(cadeira)) {
            //Transforma string em linha e coluna da matriz *Pessoa
            int linha = stoi(cadeira.substr(0,2)) - 1;
            int coluna = cadeira[2] - 'A';
            //Poltrona é desocupada
            poltrona[linha][coluna] = NULL;
            //Incrementa 1 da quantidade de vagas disponíveis no voo
            numVagas++;
        }
        else {
            //Retorna falso caso a cadeira esteja vazia, ou seja, não tem como desocupar
            ehDesocupada = false;
        }
        return ehDesocupada;
    }
    
    int Voo::vagas() {
        return numVagas;
    }
    
    void Voo::imprime() {
        cout << "-------Informacoes do voo-------" << endl;
        companhia.imprime();
        cout << "Origem: " << origem << endl;
        cout << "Destino: " << destino << endl;
        data.imprime(true);
        cout << endl;
        string numero;
        
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 6; j++) {
                //Transforma linha e coluna da matriz *Pessoa em string
                    numero = to_string(i + 1);
                    numero.append(1, ((char) ('A' + j)));
                    numero.insert(0, 3 - numero.size(), '0');
                    cout << "Poltrona: " << numero << endl;
                //Verifica se há passageiros nas poltronas e imprime seus dados
                if (poltrona[i][j] != NULL) {
                    poltrona[i][j]->imprime(); 
                    cout << endl;
                }
                else {
                    cout << "Vazia" << endl;
                    cout << endl;
                }
            }
        }
    }
}