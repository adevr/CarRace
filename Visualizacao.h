/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visualizacao.h
 * Author: Alex Reis
 *
 * Created on 21 de novembro de 2019, 21:43
 */

#ifndef VISUALIZACAO_H
#define VISUALIZACAO_H
#include <iostream>
#include <sstream>
#include <vector>
#include <typeinfo>
#include "Comando.h"


class Visualizacao {
    Comando *comando;
    int tempo;
public:
    Visualizacao(Comando *comando);
    
    void moldura();
    void mainMenu();

    void modoUm();
    void selectorModoUm();
    void interpreterUm();

    void modoDois();
    void interpreterDois();

    void exitCommand(int type);
    void listCommands();
    void exitConfirmation();

    istringstream issReadCommand();
    int getTempo();
    void setTempo(int tempo);
    void passatempo(int n);
    void invalidCommand();
private:
};

#endif /* VISUALIZACAO_H */

