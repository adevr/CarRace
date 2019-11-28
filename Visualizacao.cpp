/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visualizacao.cpp
 * Author: Alex Reis
 * 
 * Created on 21 de novembro de 2019, 21:43
 */

#include <iostream>
#include "Visualizacao.h"
#include "Consola.h"


using namespace std;

Visualizacao::Visualizacao(DirecaoGeralViacao *dgv){
    Visualizacao::dgv = dgv;
}

istringstream Visualizacao::issReadCommand(){
    string line;
    getline(cin, line);
    istringstream iss(line);
    return iss;
}

void Visualizacao::exitCommand(){
    Consola::gotoxy(10, 16);
    cout << "Comando executado com sucesso";
    Consola::gotoxy(10, 18);
    cout << "Pressione (Esc) para voltar para o menu";
}

void Visualizacao::modoComandoUm(){
    string nome;
    string s1;
    string s2;
    string s3;
    string s4;
    string s5;
    string s6;
    string s7;
    char s8;
    char s9;
    
    
    Consola::clrscr();
    
    Consola::gotoxy(10, 5);
    cout << "##### RACE SIMULATOR #####";
    Consola::gotoxy(10, 6);
    cout << "######### MODO 1 #########";
    
    Consola::gotoxy(10, 18);
    cout << "Comando > ";
    
    while(1){
        istringstream comando = issReadCommand();
        comando >> nome; 
        if (nome.compare("carregaP")==0){
             comando >> s1;
             Visualizacao::dgv->carregaP(s1);
             exitCommand();
             Consola::getch();
             break;
        }else if(nome.compare("carregaC")==0){
            comando >> s1;
            Visualizacao::dgv->carregaC(s1);
            exitCommand();
            Consola::getch();
            break;
        }else if(nome.compare("carregaA")==0){
            comando >> s1;
            Visualizacao::dgv->carregaA(s1);
            exitCommand();
            Consola::getch();
            break;
        }else if(nome.compare("cria")==0){
            comando >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8;
            if(s1.compare("c")==0) Visualizacao::dgv->novoCarro(stoi(s2), stoi(s3), s4, s5, stoi(s6), stoi(s7), s8);
            if(s1.compare("p")==0) Visualizacao::dgv->novoPiloto(s3.append(" ").append(s4));
            if(s1.compare("a")==0) Visualizacao::dgv->novoAutodromo(s2, stoi(s3), stoi(s4));
        }else if(nome.compare("apaga")==0){
            comando >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8;
            //if(s1.compare("c")==0) delete Visualizacao::dgv->procuraCarro(s2);
            if(s1.compare("p")==0) Visualizacao::dgv->apagaPiloto(s2.append(" ").append(s3));
            if(s1.compare("a")==0) delete Visualizacao::dgv->procuraAutodromo(s2);
        }
        
        vector<Carro *> carros = Visualizacao::dgv->getCarros();
         for (vector<Carro *>::const_iterator it = carros.cbegin();
            it != carros.cend();
            it++)
             cout << (*it)->getMarca() << " " << (*it)->getModelo() << " " << (*it)->getID() << "\n";
        /*
        else if(comando.find("cria")!=std::string::npos){}
        else if(comando.find("apaga")!=std::string::npos){}
        else if(comando.find("entranocarro")!=std::string::npos){}
        else if(comando.find("saidocarro")!=std::string::npos){}
        else if(comando.find("lista")!=std::string::npos){}
        else cout << "Outro comando qualquer";*/
    }
    
}

void Visualizacao::modoUm()
{    
    Consola::clrscr();
    
    Consola::gotoxy(10, 5);
    cout << "##### RACE SIMULATOR #####";
    Consola::gotoxy(10, 6);
    cout << "######### MODO 1 #########";
    Consola::gotoxy(10,9);
    cout << "(1) Executar Comando";
    Consola::gotoxy(10, 10);
    cout << "(Esc) Voltar";
    
        
    while (1) {
        char tecla = Consola::getch(); 
        
        switch((int)tecla){
            case 49:
                modoComandoUm();
                break;
            case 27:
                openConsole();
                break;
            case 120:
                cout << "EXIT";
        }
        if (tecla == ' ')
            break;
    }
    /*
    Piloto *p = Visualizacao::dgv->getPilotos()[0];
    cout << p->getNome();*/
    
}

void Visualizacao::modoDois()
{
    
}


void Visualizacao::openConsole()
{
    Consola::clrscr();
    Consola::setScreenSize(20, 50);
    Consola::setBackgroundColor(Consola::BRANCO_CLARO);
    //Consola::setTextColor(Consola::AZUL);
    Consola::gotoxy(10, 5);
    cout << "##### RACE SIMULATOR #####";
    Consola::gotoxy(10, 6);
    cout << "##### Menu Principal #####";
    Consola::gotoxy(10, 8);
    cout << "(1) Modo 1";
    Consola::gotoxy(10, 9);
    cout << "(2) Modo 2";
    
   /* 1 = 49
    2 = 50
    x = 120 */
    
    while (1) {
        char tecla = Consola::getch(); 
        
        switch((int)tecla){
            case 49:
                modoUm();
                break;
            case 50:
                modoDois();
                break;
            case 120:
                cout << "EXIT";
        }
        if (tecla == ' ')
            break;
    }
}





