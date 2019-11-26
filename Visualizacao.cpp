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

void Visualizacao::exitCommand(){
    Consola::gotoxy(10, 16);
    cout << "Comando executado com sucesso";
    Consola::gotoxy(10, 18);
    cout << "Pressione (Esc) para voltar para o menu";
}

void Visualizacao::modoComandoUm(){
    string comando;
    
    Consola::clrscr();
    
    Consola::gotoxy(10, 5);
    cout << "##### RACE SIMULATOR #####";
    Consola::gotoxy(10, 6);
    cout << "######### MODO 1 #########";
    
    Consola::gotoxy(10, 18);
    cout << "Comando > ";
    /*
     * IMPLEMENTAR COM ISSTRING
     */
    while(1){
        getline(cin, comando);   
        if (comando.find("carregaP")!=std::string::npos){
             Visualizacao::dgv->carregaP("Pilotos.txt");
             exitCommand();
             Consola::getch();
             break;
        }else if(comando.find("carregaC")!=std::string::npos){
            Visualizacao::dgv->carregaC("Carros.txt");
            break;
        }
        else if(comando.find("carregaA")!=std::string::npos){
            //Visualizacao::dgv->carregaA("Autodromos.txt");
        }
        else if(comando.find("cria")!=std::string::npos){}
        else if(comando.find("apaga")!=std::string::npos){}
        else if(comando.find("entranocarro")!=std::string::npos){}
        else if(comando.find("saidocarro")!=std::string::npos){}
        else if(comando.find("lista")!=std::string::npos){}
        else cout << "Outro comando qualquer";
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
    Consola::setTextColor(Consola::VERDE_CLARO);
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





