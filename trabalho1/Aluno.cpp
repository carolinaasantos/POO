#include "Aluno.h"
#include <iomanip>

namespace poo
{
    //Construtor
    Aluno::Aluno(string cpf, string nome, int ra, double p1, double p2, double t1, double t2, double t3) : Pessoa(cpf, nome), ra(ra), p1(p1), p2(p2), t1(t1), t2(t2), t3(t3) {
    }
    
    //Destrutor
    Aluno::~Aluno() {
    }
    
    //Implementação dos métodos
    int Aluno::getRA() const {
        return ra;
    }
    
    void Aluno::imprime() const {
        Pessoa::imprime();
        cout << "RA: " << ra << endl;
        cout << "Media: " << media() << endl;
    }
    
    double Aluno::media() const {
        //Calculando a media das provas, dos trabalhos e a media final
        double mediaFinal, mp, mt;
        mt = (t1 + t2*2 + t3*3) / 6;
        mp = (p1 + p2) / 2;
        mediaFinal = (mp * 8 + mt * 2) / 10;
        return mediaFinal;
    }
    
    bool Aluno::aprovado() const {
        //Verificando se a media eh maior ou igual a 6
        if (media() >= 6.0)
            return true;
        else
            return false;
    }
    
    bool Aluno::pac() const {
        //Verificando se a media está entre 5 e 6
        double valorMedia;
        valorMedia = media();
        if (valorMedia >= 5 && valorMedia < 6)
            return true;
        else
            return false;
    }
    
    double Aluno::notaPAC() const {
        //Verificando a nota minima que o aluno precisa tirar
        if (pac()) {
            double notaMin;
            notaMin = 12 - media();
            return notaMin;
        }
        else 
            return 0;
    }
}