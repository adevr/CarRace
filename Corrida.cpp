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

bool Corrida::finalizaCorrida(vector<Piloto*> participantes){
    if (participantes.size() == Corrida::classificacaoCorrida.size()) {
        desenhaClassificacaoCorrida(Corrida::classificacaoCorrida);
        toggleCorrida(true);
        Corrida::classificacaoCorrida.clear();
        return true;
    }else return false;
}

Corrida::Corrida(vector < Piloto*>participantes) 
{
    Corrida::participantes = participantes;
    Corrida::toggleCorrida(false);
}

Corrida::~Corrida(){}

bool Corrida::correr(int tempo, int tamanhoPista) 
{
    int init, end, carPos;
    init = 20;
    end = 115;
    carPos = 5;

    for (size_t i = 0; i < participantes.size(); i++) {
        int distanciaInit = participantes[i]->getDistanciaPercorrida();
        // rever executacomportamento
        int distancia = participantes[i]->executaComportamento(tempo);
        Carro * carro = participantes[i]->getCarro();
        Bateria* bateria =  carro->getBateria();
        Velocidade* velocidade = carro->getVelocidade();

        if (distancia >= tamanhoPista){
            participantes[i]->setDistanciaPercorrida(tamanhoPista);
            if (!(find(classificacaoCorrida.begin(), classificacaoCorrida.end(), participantes[i]->getNome()) != classificacaoCorrida.end())){
                Corrida::classificacaoCorrida.push_back(participantes[i]->getNome());
                if((i+1) == 1) participantes[i]->setPontuacao(participantes[i]->getPontuacao()+10);
                if((i+1) == 2) participantes[i]->setPontuacao(participantes[i]->getPontuacao()+5);
                if((i+1) == 3) participantes[i]->setPontuacao(participantes[i]->getPontuacao()+2); 
            }
        }else if (distanciaInit == distancia){
            velocidade->travar(1);
            Consola::gotoxy(init, carPos);
            cout << carro->getID();
        }else {
            velocidade->acelerar(1);
            bateria->descarregaBateria(1);
            Consola::gotoxy(init + distancia, carPos);
            cout << carro->getID();
        }
        carPos += 5;
        Consola::gotoxy(25, 26);
    }

    return finalizaCorrida(participantes);
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
        if (participantes[i]->getCarro() != nullptr){
            Consola::gotoxy(init, carPos);
            cout << participantes[i]->getCarro()->getID();
            
        }   
        carPos += 5;     
    }
    Consola::gotoxy(25, 26);  
}

