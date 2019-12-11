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
    Consola::gotoxy(45, 20);
    cout << "Comando executado com sucesso";
    Consola::gotoxy(45, 22);
    cout << "(Esc) Voltar   (N) Novo";
    while (1) {
        char tecla = Consola::getch();

        switch ((int) tecla) {
            case 110:
                if(type == 1) modoComandoUm();
                else if(type == 2) modoDois();
                break;
            case 27:
                modoUm();
                break;
        }
        if (tecla == ' ')
            break;
    }

}

void Visualizacao::modoComandoUm() {
    string nome;
    string s1;
    string s2;
    string s3;

    moldura();
    Consola::gotoxy(45, 7);
    cout << "            Modo 1            ";
    Consola::gotoxy(45, 9);
    cout << "##############################";
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
        } else if (nome.compare("carregaC") == 0) {
            com >> s1;
            comando->carregaC(s1);
            exitCommand(1);
            Consola::getch();
            break;
        } else if (nome.compare("carregaA") == 0) {
            com >> s1;
            comando->carregaA(s1);
            exitCommand(1);
            Consola::getch();
            break;
        } else if (nome.compare("cria") == 0) {
            comando->cria(com);
            exitCommand(1);
            Consola::getch();
            break;
        } else if (nome.compare("apaga") == 0) {
            comando->apaga(com);
            exitCommand(1);
            Consola::getch();
            break;
        } else if (nome.compare("entranocarro") == 0) {
            comando->pilotoEntraNoCarro(com);
            exitCommand(1);
            Consola::getch();
            break;
        } else if (nome.compare("saidocarro") == 0) {
            // colocar o carro que está no piloto a null pointer
            comando->pilotoSaiDoCarro(com);
            exitCommand(1);
            Consola::getch();
            break;
        } else if (nome.compare("lista") == 0) {
            comando->lista();
            exitCommand(1);
            Consola::getch();
            break;
            //  get as string method nos carros, autodromos e pilotos
        } else {
            invalidCommand();
            Consola::getch();
            break;
        }
    }
}

void Visualizacao::modoUm() {
    moldura();
    Consola::gotoxy(45, 7);
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


    while (1) {
        char tecla = Consola::getch();

        switch ((int) tecla) {
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
}

void Visualizacao::modoDois() {
    string nome;
    string s1;
    string s2;
    string s3;

    moldura();
    Consola::gotoxy(45, 7);
    cout << "            Modo 2          ";
    Consola::gotoxy(45, 9);
    cout << "##############################";
    Consola::gotoxy(45, 26);
    cout << "Comando > ";

    while (1) {
        istringstream comando = issReadCommand();
        comando >> nome;
        if (nome.compare("campeonato") == 0) {
            comando >> s1 >> s2 >> s3;
            Consola::gotoxy(45, 15);
            cout << "Comando em desenvolvimento.. nao disponivel.";
            Consola::gotoxy(45, 16);
            cout << "(ESC) Voltar";
            while (1) {
                char tecla = Consola::getch();

                switch ((int) tecla) {
                    case 110:
                        modoDois();
                        break;
                    case 27:
                        openConsole();
                        break;
                }
                if (tecla == ' ')
                    break;
            }
        }else if (nome.compare("passatempo") == 0) {
            comando >> s1;
            //passatempo(stoi(s1));
            exitCommand(2);
            Consola::getch();
            break;
        } else {
            invalidCommand();
            Consola::getch();
            break;
        }
    }
}

void Visualizacao::openConsole() {
    moldura();
    Consola::gotoxy(45, 4);
    cout << "      RACE SIMULATOR      ";
    Consola::gotoxy(45, 7);
    cout << "      Menu Principal      ";
    Consola::gotoxy(45, 9);
    cout << "##########################";
    Consola::gotoxy(45, 10);
    cout << "#      (1) Modo 1        #";
    Consola::gotoxy(45, 11);
    cout << "##########################";
    Consola::gotoxy(45, 14);
    cout << "##########################";
    Consola::gotoxy(45, 15);
    cout << "#      (2) Modo 2        #";
    Consola::gotoxy(45, 16);
    cout << "##########################";
    Consola::gotoxy(45, 19);
    cout << "##########################";
    Consola::gotoxy(45, 20);
    cout << "#      (3) Ajuda         #";
    Consola::gotoxy(45, 21);
    cout << "##########################";
    Consola::gotoxy(45, 24);
    cout << "##########################";
    Consola::gotoxy(45, 25);
    cout << "#      (x) Sair          #";
    Consola::gotoxy(45, 26);
    cout << "##########################";
    /* 1 = 49
     2 = 50
     x = 120 */

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

void Visualizacao::moldura() {
    Consola::setBackgroundColor(Consola::BRANCO_CLARO);
    Consola::clrscr();
    Consola::setScreenSize(100, 100);
    Consola::setTextColor(Consola::AZUL);
    for (int i = 1; i <= 115; i++) {
        Consola::gotoxy(i, 1);
        cout << "#";
        Consola::gotoxy(i, 28);
        cout << "#";
    }
    for (int i = 1; i <= 28; i++) {
        Consola::gotoxy(1, i);
        cout << "#";
        Consola::gotoxy(115, i);
        cout << "#";
    }
}

void Visualizacao::listCommands() {
    moldura();
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

    Consola::gotoxy(45, 24);
    cout << "##############################";
    Consola::gotoxy(45, 25);
    cout << "#    (ESC) Voltar            #";
    Consola::gotoxy(45, 26);
    cout << "##############################";

    while (1) {
        char tecla = Consola::getch();

        switch ((int) tecla) {
            case 49:
                modoComandoUm();
                break;
            case 27:
                openConsole();
                break;
        }
        if (tecla == ' ')
            break;
    }
}

void Visualizacao::exitConfirmation() {
    moldura();
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
                openConsole();
                break;
        }
        if (tecla == ' ')
            break;
    }
}

int Visualizacao::getTempo() {
    return Visualizacao::tempo;
}

void Visualizacao::setTempo(int tempo) {
    Visualizacao::tempo = tempo;
}

void Visualizacao::passatempo(int n) {
    setTempo(getTempo() + n);
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
                modoComandoUm();
                break;
            case 27:
                modoUm();
                break;
        }
        if (tecla == ' ')
            break;
    }

}