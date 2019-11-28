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

using namespace std;


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

Piloto * DirecaoGeralViacao::apagaPiloto(string nome){
    if(procuraPiloto(nome) !=  nullptr){
        for(size_t i=0; i < pilotos.size(); i++){
            if(pilotos[i]->getNome() == nome) pilotos.erase(pilotos.begin() + i);
        }
        delete procuraPiloto(nome);
    }
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

Carro * DirecaoGeralViacao::procuraCarro(char id){
        for (vector<Carro *>::const_iterator it = carros.cbegin();
            it != carros.cend();
            it++)
        if ((*it)->getID() == id)
            return *it;
    return nullptr;
}
Carro * DirecaoGeralViacao::novoCarro(int capInit, int capMax, string marca, string modelo, int velMax, int estado, char id){
    id = rewriteID(id);
    if (procuraCarro(id) != nullptr) novoCarro(capInit, capMax, marca, modelo, velMax, estado, id);
    
    if (procuraCarro(id) == nullptr) {
        Carro * c = new Carro(marca, modelo,capMax, capInit,velMax,estado, id);
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
    int startpos = 9;
    while (!dados.eof()) {
        getline(dados, s);
        istringstream iss(s);
        iss >> capInit >> capMax >> marca >> modelo >> std::ws;  
        
        Consola::gotoxy(10, startpos);
        cout << marca << " " << modelo;
        
        if(!marca.empty() && !modelo.empty()) 
            novoCarro(capInit, capMax, marca, modelo, 1, 1, ' ');

        startpos++;
    }
    dados.close();
 
}

char DirecaoGeralViacao::rewriteID(char id){
    char randomletter = 'a' + (rand() % 26);
    return randomletter;
}

string DirecaoGeralViacao::rewriteNome(string nome){
    char randomletter = 'A' + (rand() % 26);
    return nome += randomletter;
}

Autodromo * DirecaoGeralViacao::procuraAutodromo(string nome){
    for (vector<Autodromo *>::const_iterator it = autodromos.cbegin();
        it != autodromos.cend();
        it++)
    if ((*it)->getNome() == nome)
        return *it;
    return nullptr;
}

Autodromo * DirecaoGeralViacao::novoAutodromo(string nome, int capacidade, int tamanho){
    if(procuraAutodromo(nome) != nullptr) nome = rewriteNome(nome);
    
    if (procuraAutodromo(nome) == nullptr) {
        Autodromo * a = new Autodromo(nome, capacidade, tamanho);
        autodromos.push_back(a);
        return a;
    }
    return nullptr;
}

void DirecaoGeralViacao::carregaA(string file){
    ifstream dados(file);
    int capacidade;
    int tamanho;
    string nome;
    string s;
    
   
    if (!dados.is_open()) {
        return;
    }

    bool ok;
    int startpos = 9;
    while (!dados.eof()) {
        getline(dados, s);
        istringstream iss(s);
        iss >> capacidade >> tamanho >> nome >> std::ws;  
        
        Consola::gotoxy(10, startpos);
        cout << nome << " " << capacidade << " carros" << "\n";
        
        if(!nome.empty() && tamanho != 0 && capacidade != 0) 
            novoAutodromo(nome, capacidade, tamanho);
        
        startpos++;

    }
    dados.close();

}
