#include "Rapido.h"

Rapido::Rapido(string nome) : Piloto(nome){}

Rapido::~Rapido(){}

int Rapido::executaComportamento(int tempo)
{
	int distancia = getDistanciaPercorrida();
	setTempo(tempo);
	if (getTempo() >= 1) {
		distancia =	passatempo(tempo);
	}
	return distancia;
}

