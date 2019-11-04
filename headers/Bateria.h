//
// Created by Alex Reis on 02/11/2019.
//

#ifndef CARRACE_BATERIA_H
#define CARRACE_BATERIA_H

class Bateria{
    int cap_max;
    int cap_init;
public:
    Bateria(int cap_max, int cap_init);
    ~Bateria();
    void carregaBateria(int quantidade = 0);
    void descarregaBateria(int quantidade = 0);
private:
    void setCapMax(int cap_max);
    void setCapInit(int cap_init);
};


#endif //CARRACE_Bateria_H

