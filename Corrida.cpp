/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Corrida.cpp
 * Author: Alex Reis
 * 
 * Created on 24 de novembro de 2019, 20:48
 */

#include "Corrida.h"


void Corrida::toggleCorrida(bool estado){ 
    /*
     * falta verificar se existem pelo menos
     * 2 carros na pista
     * criar funçao no carro? ou corrida?
     */
    Corrida::estado = estado; 
}
bool Corrida::__comecou(){ return Corrida::estado; }


Corrida::Corrida(vector < Piloto*>participantes) 
{
    Corrida::participantes = participantes;
    Corrida::toggleCorrida(false);
}

Corrida::~Corrida(){}

void Corrida::correr() 
{
    
}

void Corrida::setParticipante(Piloto *piloto){
    if (piloto != nullptr)
        participantes.push_back(piloto);
    else cout << "Piloto Invalido";
}

void Corrida::iniciar()
{
    int init, end, carPos;
    init = 20;
    end = 115;
    carPos = 5;
        
    for (size_t i = 0; i < participantes.size(); i++) {
        Consola::gotoxy(init, carPos);
        cout << "D";
        carPos += 5;
    }


    //correr();
    /*REVER AUTODROMO E PISTA
     * detetar passatempo
     * o primeiro carro a atingir a distancia total 
     * que a pista tem é adicionado ao vetor classificacao
     * quando todos os carros acabarem 
     * a corrida acabou e muda o seu estado
     */
       
}

