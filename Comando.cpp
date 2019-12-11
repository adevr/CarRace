/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   Autodromo.cpp
  * Author: Alex Reis
  *
  * Created on 09 de novembro de 2019, 15:30
  */
#include "Comando.h"



Comando::Comando(DirecaoGeralViacao* dgv, EntidadeReguladoraAutodromos* era) {
    Comando::dgv = dgv;
    Comando::era = era;
}

void Comando::carregaA(string filename)
{
    ifstream dados(filename);
    int capacidade;
    int tamanho;
    string nome;
    string s;


    if (!dados.is_open()) {
        return;
    }

    int startpos = 15;
    while (!dados.eof()) {
        getline(dados, s);
        istringstream iss(s);
        iss >> capacidade >> tamanho >> nome >> std::ws;

        Consola::gotoxy(45, startpos);
        cout << nome << " " << capacidade << " carros" << "\n";

        if (!nome.empty() && tamanho != 0 && capacidade != 0)
           era->novoAutodromo(nome, capacidade, tamanho);

        startpos++;

    }
    dados.close();
}

void Comando::carregaP(string filename)
{
    ifstream dados(filename);
    string primeiroNome;
    string apelido;
    string tipo;
    string s;


    if (!dados.is_open()) {
        return;
    }

    int startpos = 15;
    while (!dados.eof()) {
        getline(dados, s);
        istringstream iss(s);
        iss >> tipo >> primeiroNome >> apelido >> std::ws;
        Consola::gotoxy(45, startpos);
        string nome = primeiroNome.append(" ").append(apelido);
        getline(iss, nome);

        cout << tipo << " " << nome;
        if (!nome.empty())  Comando::dgv->novoPiloto(nome);
        startpos++;
    }
    dados.close();
}

void Comando::carregaC(string filename)
{
    ifstream dados(filename);
    int capInit;
    int capMax;
    string marca;
    string modelo;
    string s;


    if (!dados.is_open()) {
        return;
    }

    int startpos = 15;
    while (!dados.eof()) {
        getline(dados, s);
        istringstream iss(s);
        iss >> capInit >> capMax >> marca >> modelo >> std::ws;

        Consola::gotoxy(45, startpos);
        cout << marca << " " << modelo;

        if (!marca.empty() && !modelo.empty())
            dgv->novoCarro(capInit, capMax, marca, modelo, 1, 1, ' ');

        startpos++;
    }
    dados.close();

}

void Comando::cria(istringstream &info)
{
    string s1, s2, s3, s4, s5, s6, s7;
    char s8;  

    info >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8;
    if (s1.compare("c") == 0) dgv->novoCarro(stoi(s2), stoi(s3), s4, s5, stoi(s6), stoi(s7), s8);
    if (s1.compare("p") == 0) dgv->novoPiloto(s3.append(" ").append(s4));
    if (s1.compare("a") == 0) era->novoAutodromo(s2, stoi(s3), stoi(s4));
}

void Comando::apaga(istringstream &info)
{
    string s1, s2, s3;
    
    info >> s1 >> s2 >> s3;
    if (s1.compare("c") == 0) dgv->apagaCarro(s2[1]);
    if (s1.compare("p") == 0) dgv->apagaPiloto(s2.append(" ").append(s3));
    if (s1.compare("a") == 0) era->apagaAutodromo(s2);
}

void Comando::pilotoEntraNoCarro(istringstream &info)
{
    string piloto; char carro;

    info >> piloto >> carro;
    Piloto* p = dgv->procuraPiloto(piloto);
    Carro* c = dgv->procuraCarro(carro);
    p->entraCarro(c);
}

void Comando::pilotoSaiDoCarro(istringstream &info) 
{
    string piloto;

    info >> piloto;
    dgv->procuraPiloto(piloto)->saiCarro();
}

void Comando::lista()
{
    vector<Piloto*> pilotos = dgv->getPilotos();
    vector<Carro*> carros = dgv->getCarros();
    vector<Autodromo*> autodromos = era->getAutodromos();

    int startpos = 12;
    Consola::gotoxy(45, 11);
    cout << "Pilotos";
    for (size_t i = 0; i < pilotos.size(); i++) {
        Consola::gotoxy(45, startpos);
        cout << pilotos[i]->getAsString();
        startpos++;
    }

    startpos = startpos + 1;
    Consola::gotoxy(45, startpos);
    cout << "Carros";
    for (size_t i = 0; i < carros.size(); i++) {
        Consola::gotoxy(45, startpos + 1);
        cout << carros[i]->getAsString();
        startpos++;
    }

    startpos = startpos + 2;
    Consola::gotoxy(45, startpos);
    cout << "Autodromos";
    for (size_t i = 0; i < autodromos.size(); i++) {
        Consola::gotoxy(45, startpos + 1);
        cout << autodromos[i]->getAsString();
        startpos++;
    }
}

void Comando::ajuda() {
    Consola::gotoxy(45, 7);
    cout << "      Listagem de Comandos      ";
    Consola::gotoxy(25, 9);
    cout << "----------------------------------------------------------------------------";
    Consola::gotoxy(25, 10);
    cout << "|    Comando    |     Argumentos     |              Descricao              |";
    Consola::gotoxy(25, 11);
    cout << "----------------------------------------------------------------------------";
    Consola::gotoxy(25, 12);
    cout << "|   carregaP    |      filename      |  Carrega os Pilotos no programa     |";
    Consola::gotoxy(25, 13);
    cout << "|   carregaC    |      filename      |  Carrega os Carros no programa      |";
    Consola::gotoxy(25, 14);
    cout << "|   carregaA    |      filename      |  Carrega os Autodromos no programa  |";
    Consola::gotoxy(25, 15);
    cout << "|   cria        |     type, dados    |  Cria um objeto do tipo definido    |";
    Consola::gotoxy(25, 16);
    cout << "|   apaga       |     type, ident    |  Apaga o objeto do tipo definido    |";
    Consola::gotoxy(25, 17);
    cout << "| entranocarro  |    carro, piloto   |  O piloto entra no carro definido   |";
    Consola::gotoxy(25, 18);
    cout << "|  saidocarro   |        carro       |  O piloto dentro do carro sai       |";
    Consola::gotoxy(25, 18);
    cout << "|   lista       |        -----       |  Lista Pilotos, carros e autodromos |";
    Consola::gotoxy(25, 19);
    cout << "----------------------------------------------------------------------------";

}