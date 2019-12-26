#include "Campeonato.h"


Campeonato::Campeonato()
{

}

bool Campeonato::verificaOcurrenciaCorrida(Autodromo *autodromo)
{
	Pista* pista = autodromo->getPista();
	Corrida* corrida = pista->getCorrida();
	return corrida->__comecou();
}


void Campeonato::iniciarProximaCorrida(vector<Autodromo*> autodromos) 
{
	for (size_t i = 0; i < autodromos.size(); i++) {
		if (!verificaOcurrenciaCorrida(autodromos[i])) {
			Pista* pista = autodromos[i]->getPista();
			Corrida* corrida = pista->getCorrida();
			corrida->iniciar();
		}
	}
}