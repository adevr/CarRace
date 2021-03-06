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

Comando::Comando(DirecaoGeralViacao* dgv, EntidadeReguladoraAutodromos* era, Log log, Campeonato* campeonato) {
    Comando::dgv = dgv;
    Comando::era = era;
    Comando::log = log;
    Comando::campeonato = campeonato;
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
    log.addLog("Carregamento de Autodromos em massa.");
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
        if (!nome.empty())  Comando::dgv->novoPiloto(nome, tipo);
        startpos++;
    }
    dados.close();
    log.addLog("Carregamento de Pilotos em massa.");
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
    log.addLog("Carregamento de Carros em massa.");
}


void Comando::cria(istringstream &info)
{
    string s1, s2, s3, s4, s5, s6, s7;
    char s8;  

    info >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8;
    if (s1.compare("c") == 0) dgv->novoCarro(stoi(s2), stoi(s3), s4, s5, stoi(s6), stoi(s7), s8);
    if (s1.compare("p") == 0) dgv->novoPiloto(s3.append(" ").append(s4), s2);
    if (s1.compare("a") == 0) era->novoAutodromo(s2, stoi(s3), stoi(s4));

    log.addLog("Novo elemento criado.");
}

void Comando::apaga(istringstream &info)
{
    string s1, s2, s3;
    char c;
    if (s1.compare("c") == 0){
        info >> c; 
        dgv->apagaCarro(c);
    }
    if (s1.compare("p") == 0){
        info >> s1 >> s2 >> s3;
        dgv->apagaPiloto(s2.append(" ").append(s3));
    }
    if (s1.compare("a") == 0){ 
        info >> s1 >> s2 >> s3;
        era->apagaAutodromo(s2);
    }

    log.addLog("Elemento existente apagado.");
}

void Comando::pilotoEntraNoCarro(istringstream &info)
{
    string nome, apelido; char carro;
    info >> carro >> nome >> apelido;

    Piloto* p = dgv->procuraPiloto(nome.append(" ").append(apelido));
    Carro* c = dgv->procuraCarro(carro);
    if (c != nullptr && p != nullptr) {
        if (!(c->getDano() >= 70))
            p->entraCarro(c);
        else cout << "O carro esta danificado.";

        log.addLog(nome.append(" ").append(apelido).append(" entra no carro."));
    }
    else cout << "Nao foi encontrado nenhum piloto/carro com essas especificacoes";
}

void Comando::pilotoSaiDoCarro(istringstream &info) 
{
    string nome, apelido;

    info >> nome >> apelido;
    dgv->procuraPiloto(nome.append(" ").append(apelido))->saiCarro();
    log.addLog(nome.append(" ").append(apelido).append(" sai do carro."));
}

void Comando::lista()
{
    vector<Piloto*> pilotos = dgv->getPilotos();
    vector<Carro*> carros = dgv->getCarros();
    vector<Autodromo*> autodromos = era->getAutodromos();

    int startpos = 6;
    Consola::gotoxy(45, 5);
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
    log.addLog("Listagem de elementos.");
}

void Comando::ajuda() {
    Consola::gotoxy(45, 2);
    cout << "      Listagem de Comandos      ";
    Consola::gotoxy(25, 4);
    cout << "----------------------------------------------------------------------------";
    Consola::gotoxy(25, 5);
    cout << "|    Comando    |     Argumentos     |              Descricao              |";
    Consola::gotoxy(25, 6);
    cout << "----------------------------------------------------------------------------";
    Consola::gotoxy(25, 7);
    cout << "|   carregaP    |      filename      |  Carrega os Pilotos no programa     |";
    Consola::gotoxy(25, 8);
    cout << "|   carregaC    |      filename      |  Carrega os Carros no programa      |";
    Consola::gotoxy(25, 9);
    cout << "|   carregaA    |      filename      |  Carrega os Autodromos no programa  |";
    Consola::gotoxy(25, 10);
    cout << "|   cria        |     type, dados    |  Cria um objeto do tipo definido    |";
    Consola::gotoxy(25, 11);
    cout << "|   apaga       |     type, ident    |  Apaga o objeto do tipo definido    |";
    Consola::gotoxy(25, 12);
    cout << "| entranocarro  |    carro, piloto   |  O piloto entra no carro definido   |";
    Consola::gotoxy(25, 13);
    cout << "|  saidocarro   |        carro       |  O piloto dentro do carro sai       |";
    Consola::gotoxy(25, 14);
    cout << "|   lista       |        -----       |  Lista Pilotos, carros e autodromos |";
    Consola::gotoxy(25, 15);
    cout << "|   savedgv     |        -----       |  Guarda dgv em memoria              |";
    Consola::gotoxy(25, 16);
    cout << "|   loaddgv     |        -----       |  Substitui dgv em memoria           |";
    Consola::gotoxy(25, 17);
    cout << "|   deldgv      |        -----       |  Apaga dgv em memoria               |";
    Consola::gotoxy(25, 18);
    cout << "----------------------------------------------------------------------------";
    log.addLog("Listagem Ajuda");
}

void Comando::carregaBat(istringstream& info)
{
    char carro; 
    int mAh;
    
    info >> carro >> mAh;

    Carro* c = dgv->procuraCarro(carro);
    Bateria* b = c->getBateria();
    Velocidade* v = c->getVelocidade();
    
    if (v->getVelAtual() == 0)
        b->carregaBateria(mAh);
    else {
        Consola::gotoxy(1, 1);
        cout << "Enquanto o carro estiver em movimento";
        Consola::gotoxy(1, 2);
        cout << "Nao e possivel carregar a sua bateria";
    }
    log.addLog("Carrega bateria do carro");
}

void Comando::carregaTudo()
{
    Velocidade *velocidade;
    Bateria *bateria;
    vector<Carro*> carros = dgv->getCarros();

    for (size_t i = 0; i < carros.size(); i++){
        velocidade = carros[i]->getVelocidade();
        bateria = carros[i]->getBateria();
        if (velocidade->getVelAtual() == 0)
            bateria->carregaBateria(100);
        else cout << "O " << carros[i]->getMarca() << " " << carros[i]->getModelo() << " tem de estar parado para ser carregado";
    }
    
    Consola::gotoxy(35, 16);
    cout << "Todos os carros parados teem com as baterias no maximo";
    log.addLog("Carrega bateria de todos os carros");
}

void Comando::listaCarros()
{
    Bateria* bat;
    Velocidade* v;
    vector<Carro*> carros = dgv->getCarros();

    int startpos = 14;
    Consola::gotoxy(45, 5);
    for (size_t i = 0; i < carros.size(); i++) {
        bat = carros[i]->getBateria();
        v = carros[i]->getVelocidade();

        Consola::gotoxy(15, startpos);
        cout << "Marca: " << carros[i]->getMarca() << " | Modelo: " << carros[i]->getModelo()
            << " | ID: " << carros[i]->getID() << " | Capacidade Atual: " << bat->getCapAtual()
            << " | Velocidade Atual: " << v->getVelAtual();
        startpos++;
    }
    log.addLog("Lista Carros");
}

void Comando::destroi(istringstream& info)
{
    char id;
    info >> id;

    vector<Piloto*> pilotos = dgv->getPilotos();

    for (size_t i = 0; i < pilotos.size(); i++) {
        Carro* c = pilotos[i]->getCarro();
        if (c != nullptr){
            if (c->getID() == id) pilotos[i]->saiCarro();
        }
    }
    
    dgv->apagaCarro(id);
    log.addLog("Destroi carro.");
}

void Comando::acidente(istringstream& info) 
{
    char id;
    vector<Piloto*> pilotos;
    info >> id;

    pilotos = dgv->getPilotos();
    Carro* c = dgv->procuraCarro(id);
    for (size_t i = 0; i < pilotos.size(); i++){
        if (pilotos[i]->getCarro() == c){
            SinalEmergencia* s = c->getSinal();
            Velocidade* v = c->getVelocidade();
            s->setEstado(true);
            v->travar(100);
            c->setDano(100);
            pilotos[i]->morre();
        }
    }
    log.addLog("Acidente de viacao");
}

void Comando::stop(istringstream& info)
{
    string nome, apelido;

    info >> nome >> apelido;
    Piloto* piloto = dgv->procuraPiloto(nome.append(" ").append(apelido));
    
    piloto->para();
    log.addLog(nome.append(" ").append(apelido).append(" para."));
}

void Comando::mostraLogs()
{
    static vector<string> logs = log.getLogs();

    int startpos = 15;
    for (size_t i = 0; i < logs.size(); i++) {
        Consola::gotoxy(45, startpos + i);
        cout << logs[i];
    }
}

bool Comando::corrida()
{
    log.addLog("Corrida iniciada.");
    return campeonato->iniciarProximaCorrida();

}

void Comando::adicionaParticipante(istringstream& info)
{
    string nome, apelido;

    info >> nome >> apelido;

    Piloto* participante = dgv->procuraPiloto(nome.append(" ").append(apelido));
    if (participante != nullptr) {
        campeonato->definirParticipante(participante);
        log.addLog("Adicionar Participante.");
    }
    else cout << "Nao foi encontrado nenhum piloto com esse nome";

}

void Comando::iniciarCampeonato(istringstream& info)
{
    string a1, a2, a3, a4;
    vector <Autodromo*> autodromos;
    info >> a1 >> a2 >> a3 >> a4;

    if (era->procuraAutodromo(a1) != nullptr) autodromos.push_back(era->procuraAutodromo(a1));
    if (era->procuraAutodromo(a2) != nullptr) autodromos.push_back(era->procuraAutodromo(a2));
    if (era->procuraAutodromo(a3) != nullptr) autodromos.push_back(era->procuraAutodromo(a3));
    if (era->procuraAutodromo(a4) != nullptr) autodromos.push_back(era->procuraAutodromo(a4));

    campeonato->setAutodromos(autodromos);
    log.addLog("Iniciar Campeonato.");
}

bool Comando::passatempo(int tempo)
{
    log.addLog("Avanca tempo durante a corrida.");
    return campeonato->avancaTempo(tempo);
}


void Comando::saveDgv(int id){
    for (size_t i = 0; i < backupDGV.size(); i++){
        if (backupDGV[i]->getID() != id){
            DirecaoGeralViacao *newDGV  = new DirecaoGeralViacao(id);
            newDGV->setCarros(dgv->getCarros());
            newDGV->setPilotos(dgv->getPilotos());

            backupDGV.push_back(newDGV);
        }
    }
}

void Comando::deleteDgv(int id)
{
    if (backupDGV.size() > 1)
    {
        for (size_t i = 0; i < backupDGV.size(); i++){
            if (backupDGV[i]->getID() == id){
                if (backupDGV[i] != dgv){
                    delete backupDGV[i];
                    backupDGV.erase(backupDGV.begin() + i);
                }
            }
        }
    }
}

void Comando::loadDgv(int id) 
{
    for (size_t i = 0; i < backupDGV.size(); i++){
        if (backupDGV[i]->getID() == id){
            dgv->setPilotos(backupDGV[i]->getPilotos());
            dgv->setCarros(backupDGV[i]->getCarros());
        }
    }
}



