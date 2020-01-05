#include "drawer.h"

void drawer::desenhaMenu()
{
    Consola::setBackgroundColor(Consola::PRETO);
    Consola::clrscr();
    Consola::setScreenSize(100, 100);
    Consola::setTextColor(Consola::AMARELO);
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

void drawer::desenhaInterfaceCorrida()
{
    Consola::setBackgroundColor(Consola::PRETO);
    Consola::clrscr();
    Consola::setScreenSize(100, 100);
    Consola::setTextColor(Consola::AMARELO);
    for (int i = 1; i <= 115; i++) {
        Consola::gotoxy(i, 1);
        cout << "#";
        Consola::gotoxy(i, 28);
        cout << "#";
    }

    for (int i = 1; i <= 115; i++) {
        Consola::gotoxy(i, 23);
        cout << "#";
    }

    for (int i = 1; i <= 23; i++) {
        Consola::gotoxy(85, i);
        cout << "#";
    }

    for (int i = 1; i <= 28; i++) {
        Consola::gotoxy(1, i);
        cout << "#";
        Consola::gotoxy(115, i);
        cout << "#";
    }

    Consola::gotoxy(15, 26);
    cout << "Comando > ";
    Consola::gotoxy(25, 26);

}

void drawer::desenhaMainMenuOptions()
{
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
}

void drawer::desenhaListagemAjuda()
{
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

}

void drawer::desenhaClassificacaoCorrida(vector<string> classificacao) 
{
    desenhaInterfaceCorrida();

    for (size_t i = 0; i < classificacao.size(); i++) {
        int position = i+1;
        Consola::gotoxy(45, 10 + i);
        cout << position << " - " << classificacao[i];
    }
}