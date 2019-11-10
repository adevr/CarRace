//
// Created by Alex Reis on 08/11/2019.
//

#ifndef RACESIMULATOR_VELOCIDADE_H
#define RACESIMULATOR_VELOCIDADE_H

class Velocidade{
    int vel_max;
    int vel_atual;
public:
    Velocidade(int vel_max);
    ~Velocidade();
    int getVelMax();
    int getVelAtual();
    int acelerar(int velocidade);
    int travar(int velocidade);
private:
    void setVelMax(int vel_max);
    void setVelAtual(int vel_atual);
};


#endif //RACESIMULATOR_VELOCIDADE_H