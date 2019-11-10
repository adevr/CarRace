//
// Created by Alex Reis on 02/11/2019.
//

#ifndef RACESIMULATOR_SINALEMERGENCIA_H
#define RACESIMULATOR_SINALEMERGENCIA_H

class SinalEmergencia{
    bool estado;
public:
    SinalEmergencia();
    ~SinalEmergencia();
    bool getEstado();
private:
    void setEstado(bool estado);
};


#endif //RACESIMULATOR_SINALEMERGENCIA_H

