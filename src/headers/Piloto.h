//
// Created by Alex Reis on 02/11/2019.
//

#ifndef RACESIMULATOR_PILOTO_H
#define RACESIMULATOR_PILOTO_H

#include <string>
using namespace std;

class Piloto {
    string nome;
public:
    Piloto(string nome);
    ~Piloto();
private:
    void setNome(string nome);
};


#endif //RACESIMULATOR_CARRO_H
