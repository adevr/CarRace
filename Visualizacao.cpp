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



using namespace std;
using namespace drawer;

Visualizacao::Visualizacao(Comando *comando) {
    Visualizacao::comando = comando;
}

istringstream Visualizacao::issReadCommand() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    return iss;
}

void Visualizacao::exitCommand(int type) {
    Consola::gotoxy(10, 20);
    cout << "Comando executado com sucesso";
    Consola::gotoxy(10, 22);
    cout << "(Esc) Voltar   (N) Novo";
    while (1) {
        char tecla = Consola::getch();

        switch ((int) tecla) {
            case 110:
                if(type == 1) interpreterUm();
                else if(type == 2) modoDois();
                break;
            case 27:
                if (type == 1) modoUm();
                else if (type == 2) mainMenu();
                break;
        }
        if (tecla == ' ')
            break;
    }

}


void Visualizacao::modoUm() {
    desenhaMenu();

    Consola::gotoxy(45, 3);
    cout << "            Modo 1            ";
    Consola::gotoxy(45, 9);
    cout << "##############################";
    Consola::gotoxy(45, 10);
    cout << "#    (1) Executar Comando    #";
    Consola::gotoxy(45, 11);
    cout << "##############################";
    Consola::gotoxy(45, 14);
    cout << "##############################";
    Consola::gotoxy(45, 15);
    cout << "#    (ESC) Voltar            #";
    Consola::gotoxy(45, 16);
    cout << "##############################";

    selectorModoUm();

}

void Visualizacao::selectorModoUm()
{
    while (1) {
        char tecla = Consola::getch();

        switch ((int)tecla) {
        case 49:
            interpreterUm();
            break;
        case 27:
            mainMenu();
            break;
        case 120:
            cout << "EXIT";
        }
        if (tecla == ' ')
            break;
    }
}

void Visualizacao::interpreterUm()
{
    string nome;
    string s1;
    string s2;
    string s3;

    desenhaMenu();

    Consola::gotoxy(45, 3);
    cout << "            Modo 1            ";
    Consola::gotoxy(45, 26);
    cout << "Comando > ";

    while (1) {
        istringstream com = issReadCommand();
        com >> nome;
        if (nome.compare("carregaP") == 0) {
            com >> s1;
            comando->carregaP(s1);
            exitCommand(1);
            Consola::getch();
            break;
        }
        else if (nome.compare("carregaC") == 0) {
            com >> s1;
            comando->carregaC(s1);
            exitCommand(1);
            Consola::getch();
            break;
        }
        else if (nome.compare("carregaA") == 0) {
            com >> s1;
            comando->carregaA(s1);
            exitCommand(1);
            Consola::getch();
            break;
        }
        else if (nome.compare("cria") == 0) {
            comando->cria(com);
            exitCommand(1);
            Consola::getch();
            break;
        }
        else if (nome.compare("apaga") == 0) {
            comando->apaga(com);
            exitCommand(1);
            Consola::getch();
            break;
        }
        else if (nome.compare("entranocarro") == 0) {
            comando->pilotoEntraNoCarro(com);
            exitCommand(1);
            Consola::getch();
            break;
        }
        else if (nome.compare("saidocarro") == 0) {
            // colocar o carro que está no piloto a null pointer
            comando->pilotoSaiDoCarro(com);
            exitCommand(1);
            Consola::getch();
            break;
        }
        else if (nome.compare("lista") == 0) {
            comando->lista();
            exitCommand(1);
            Consola::getch();
            break;
            //  get as string method nos carros, autodromos e pilotos
        }
        else {
            invalidCommand();
            Consola::getch();
            break;
        }
    }
}


void Visualizacao::modoDois() {
    desenhaMenu();
    Consola::gotoxy(45, 7);
    cout << "            Modo 2          ";
    Consola::gotoxy(45, 9);
    cout << "##############################";
    Consola::gotoxy(45, 26);
    cout << "Comando > ";

    interpreterDois();
}

void Visualizacao::interpreterDois()
{
    string nome;
    string s1;
    string s2;
    string s3;

    while (1) {
        istringstream com = issReadCommand();
        com >> nome;
        if (nome.compare("campeonato") == 0) {
            comando->iniciarCampeonato(com);
            exitCommand(2);
            Consola::getch();
            break;
        }
        else if (nome.compare("listacarros") == 0) {
            comando->listaCarros();
            exitCommand(2);
            Consola::getch();
            break;
        }
        else if (nome.compare("carregatudo") == 0) {
            comando->carregaTudo();
            exitCommand(2);
            Consola::getch();
            break;
        }
        else if (nome.compare("carregabat") == 0) {
            comando->carregaBat(com);
            exitCommand(2);
            Consola::getch();
            break;
        }
        else if (nome.compare("destroi") == 0) {
            comando->destroi(com);
            exitCommand(2);
            Consola::getch();
            break;
        }
        else if (nome.compare("acidente") == 0) {
            comando->acidente(com);
            exitCommand(2);
            Consola::getch();
            break;
        }
        else if (nome.compare("stop") == 0) {
            comando->stop(com);
            exitCommand(2);
            Consola::getch();
            break;
        }
        else if (nome.compare("log") == 0) {
            comando->mostraLogs();
            exitCommand(2);
            Consola::getch();
            break;
        }
        else if (nome.compare("corrida") == 0) {
            desenhaInterfaceCorrida();
            comando->corrida();
            interpreterCorrida();
            //exitCommand(2);
            //Consola::getch();
            //break;
        }
        else if (nome.compare("adicionaParticipante") == 0) {
            comando->adicionaParticipante(com);
            exitCommand(2);
            Consola::getch();
            break;
        }
        else {
            invalidCommand();
            Consola::getch();
            break;
        }
    }
}


void Visualizacao::mainMenu() {
    desenhaMenu();
    desenhaMainMenuOptions();

    while (1) {
        char tecla = Consola::getch();

        switch ((int) tecla) {
            case 49:
                modoUm();
                break;
            case 50:
                modoDois();
                break;
            case 51:
                listCommands(); 
                break;
            case 120:
                exitConfirmation();
        }
        if (tecla == ' ')
            break;
    }

}


void Visualizacao::listCommands() {
    desenhaMenu();
    desenhaListagemAjuda();
    while (1) {
        char tecla = Consola::getch();

        switch ((int) tecla) {
            case 49:
                interpreterUm();
                break;
            case 27:
                mainMenu();
                break;
        }
        if (tecla == ' ')
            break;
    }
}

void Visualizacao::exitConfirmation() {
    desenhaMenu();
    Consola::gotoxy(45, 4);
    cout << "      RACE SIMULATOR      ";
    Consola::gotoxy(45, 7);
    cout << "      Menu Principal      ";
    Consola::gotoxy(35, 14);
    cout << "######################################################";
    Consola::gotoxy(35, 16);
    cout << "    Tem a certeza que pretende sair do simulador?     ";
    Consola::gotoxy(35, 18);
    cout << "    (S) Sim                               (N) Nao     ";
    Consola::gotoxy(35, 20);
    cout << "######################################################";

    while (1) {
        char tecla = Consola::getch();

        switch ((int) tecla) {
            case 115:
                exit(0);
                break;
            case 110:
                mainMenu();
                break;
        }
        if (tecla == ' ')
            break;
    }
}


void Visualizacao::invalidCommand() {
    Consola::gotoxy(45, 20);
    cout << "Comando inválido";
    Consola::gotoxy(45, 22);
    cout << "(Esc) Voltar   (N) Novo";
    while (1) {
        char tecla = Consola::getch();

        switch ((int) tecla) {
            case 110:
                interpreterUm();
                break;
            case 27:
                modoUm();
                break;
        }
        if (tecla == ' ')
            break;
    }

}

void Visualizacao::interpreterCorrida()
{
    string nome, s1, s2, s3;
    int tempo;

    while (1) {
        istringstream com = issReadCommand();
        com >> nome;

        if(nome.compare("acidente")==0)
            comando->acidente(com);
        else if(nome.compare("destroi")==0)
            comando->destroi(com);
        else if(nome.compare("stop")==0)
            comando->stop(com);
        else if(nome.compare("carregatudo")==0)
            comando->carregaTudo();
        else if(nome.compare("carregabat")==0)
            comando->carregaBat(com);
        else if(nome.compare("passatempo")==0){
            com >> tempo;
            desenhaInterfaceCorrida();
            if(comando->passatempo(tempo))
                break;
        }
    }
    while(1){
    char tecla = Consola::getch();
    switch ((int) tecla) {
        case 27:
            mainMenu();
            break;
    }
    if (tecla == ' ')
        break;
}
}
