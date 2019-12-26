#include "Campeonato.h"


Campeonato::Campeonato()
{

}

bool Campeonato::verificaOcurrenciaCorrida(Autodromo *autodromo)
{
	Corrida* race = autodromo->getCorrida();
	return race->__comecou();
}


void Campeonato::iniciarPróximaCorrida(vector<Autodromo*> autodromos) 
{
	for (size_t i = 0; i < autodromos.size(); i++) {
		if (!verificaOcurrenciaCorrida(autodromos[i])) {
			Corrida * c = autodromos[i]->getCorrida();
			c->iniciar();
		}
	}
}