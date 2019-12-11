/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alex Reis
 *
 * Created on 21 de novembro de 2019, 19:54
 */

#include <cstdlib>
#include "Visualizacao.h"
#include "DirecaoGeralViacao.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    DirecaoGeralViacao *dgv = new DirecaoGeralViacao(1);
    EntidadeReguladoraAutodromos *era = new EntidadeReguladoraAutodromos(1);

    Comando *comando = new Comando(dgv, era);

    Visualizacao ui(comando);
    
    ui.openConsole();
    return 0;
}

