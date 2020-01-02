#include "Crazy.h"

Crazy::Crazy(string nome) : Piloto(nome) {}
Crazy::~Crazy() {}

int Crazy::executaComportamento(int tempo) 
{
	int distancia = getDistanciaPercorrida();
	setTempo(tempo);
	if (getTempo() >= 3) {
		distancia = passatempo(tempo);
	}

	return distancia;
}

