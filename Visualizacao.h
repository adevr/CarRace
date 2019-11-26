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

#include <vector>
#include "DirecaoGeralViacao.h"


class Visualizacao {
    DirecaoGeralViacao *dgv;
public:
    Visualizacao(DirecaoGeralViacao *dgv);
    
    void openConsole();
    void modoUm();
    void modoDois();
    void modoComandoUm();
    void exitCommand();
    
};

#endif /* VISUALIZACAO_H */

