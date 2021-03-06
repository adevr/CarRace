/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   EntidadeReguladoraAutodromos.h
  * Author: Alex Reis
  *
  * Created on 09 de dezembro de 2019, 11:30
  */

#ifndef COMANDO_H
#define COMANDO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ostream>
#include <sstream>
#include "Consola.h"
#include "DirecaoGeralViacao.h"
#include "EntidadeReguladoraAutodromos.h"
#include "Log.h"
#include "Campeonato.h"


using namespace std;


class Comando 
{
    vector<DirecaoGeralViacao *> backupDGV;
    DirecaoGeralViacao* dgv;
    EntidadeReguladoraAutodromos* era;
    Log log;
    Campeonato* campeonato;
public:
    Comando(DirecaoGeralViacao* dgv, EntidadeReguladoraAutodromos* era, Log log, Campeonato* campeonato);

    void carregaA(string filename);
    void carregaP(string filename);
    void carregaC(string filename);
    
    void cria(istringstream &info);
    void apaga(istringstream &info);

    void pilotoEntraNoCarro(istringstream &info);
    void pilotoSaiDoCarro(istringstream &info);

    void lista();
    void ajuda();

    void carregaBat(istringstream& info);
    void carregaTudo();
    
    void listaCarros();
    void destroi(istringstream &info);

    void acidente(istringstream& info);
    void stop(istringstream& info);

    void mostraLogs();
    bool corrida();
    void adicionaParticipante(istringstream& info);
    void iniciarCampeonato(istringstream& info);

    bool passatempo(int tempo);


    DirecaoGeralViacao* getDGV();
    EntidadeReguladoraAutodromos* getERA();

    void saveDgv(int id);
    void deleteDgv(int id);
    void loadDgv(int id);
};

#endif /* COMANDO_H */