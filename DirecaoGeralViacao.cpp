/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DirecaoGeralViacao.cpp
 * Author: Alex Reis
 * 
 * Created on 23 de novembro de 2019, 11:30
 */

#include <fstream>
#include <ostream>
#include <sstream>

#include <iostream>
#include <vector>

#include "DirecaoGeralViacao.h"
#include "Consola.h"


DirecaoGeralViacao::DirecaoGeralViacao(int id) {
    DirecaoGeralViacao::dgvID = id;
}

Piloto * DirecaoGeralViacao::procuraPiloto(string nome){
    for (vector<Piloto *>::const_iterator it = pilotos.cbegin();
            it != pilotos.cend();
            it++)
        if ((*it)->getNome() == nome)
            return *it;
    return nullptr;
}
Piloto * DirecaoGeralViacao::novoPiloto(string nome){
    if (procuraPiloto(nome) == nullptr) {
        Piloto * p = new Piloto(nome);
        pilotos.push_back(p);
        return p;
    }  
    return nullptr;
}
void DirecaoGeralViacao::carregaP(string file){
    ifstream dados(file);
    string primeiroNome;
    string apelido;
    string tipo;
    string s;
    
   
    if (!dados.is_open()) {
        return;
    }

    bool ok;
    int startpos = 9;
    while (!dados.eof()) {
        getline(dados, s);
        istringstream iss(s);
        iss >> tipo >> primeiroNome >> apelido >>std::ws; 
        Consola::gotoxy(10, startpos);
        string nome = primeiroNome.append(" ").append(apelido);
        getline(iss, nome);
        
        cout << tipo << " " << nome ;
        if(!nome.empty()) novoPiloto(nome);
        startpos++;
    }
    dados.close();
 
}

Carro * DirecaoGeralViacao::procuraCarro(string marca){
        for (vector<Carro *>::const_iterator it = carros.cbegin();
            it != carros.cend();
            it++)
        if ((*it)->getMarca() == marca)
            return *it;
    return nullptr;
}
Carro * DirecaoGeralViacao::novoCarro(int capInit, int capMax, string marca, string modelo, int velMax, int estado){
    if (procuraCarro(marca) == nullptr) {
        Carro * c = new Carro(marca, modelo,capMax, capInit,velMax,estado);
        carros.push_back(c);
        return c;
    }
    return nullptr;
}
void DirecaoGeralViacao::carregaC(string file){
    ifstream dados(file);
    int capInit;
    int capMax;
    string marca;
    string modelo;
    string s;
    
   
    if (!dados.is_open()) {
        return;
    }

    bool ok;
    while (!dados.eof()) {
        getline(dados, s);
        istringstream iss(s);
        iss >> capInit >> capMax >> marca >> modelo >> std::ws;  
        
        //getline(iss, nome);
        
        if(!marca.empty() && !modelo.empty()) 
            novoCarro(capInit, capMax, marca, modelo, 1, 1);

    }
    dados.close();
 
}

Autodromo * DirecaoGeralViacao::procuraAutodromo(string id){}
Autodromo * DirecaoGeralViacao::novoAutodromo(){}
void DirecaoGeralViacao::carregaA(string file){}
