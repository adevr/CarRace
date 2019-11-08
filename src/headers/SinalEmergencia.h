//
// Created by Alex Reis on 02/11/2019.
//

#ifndef CARRACE_SINALEMERGENCIA_H
#define CARRACE_SINALEMERGENCIA_H

class SinalEmergencia{
    bool estado;
public:
    SinalEmergencia();
    ~SinalEmergencia();
    bool getEstado();
private:
    void setEstado(bool estado);
};


#endif //CARRACE_SINALEMERGENCIA_H

