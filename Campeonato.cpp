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


void Campeonato::iniciarProximaCorrida() 
{
	
	for (size_t i = 0; i < autodromos.size(); i++) {
		if (!verificaOcurrenciaCorrida(autodromos[i])) {
			Pista* pista = autodromos[i]->getPista();
			Corrida* corrida = pista->getCorrida();
			corrida->iniciar();
			break;
		}
	}
}

void Campeonato::definirParticipante(Piloto* piloto)
{
	for (size_t i = 0; i < autodromos.size(); i++) {
		Pista* pista = autodromos[i]->getPista();
		if (piloto->getCarro() != nullptr){
			pista->setParticipante(piloto);
		}
		else cout << "O piloto esta apeado";
	}
}

vector <Autodromo*> Campeonato::getAutodromos() { return Campeonato::autodromos;  }

void Campeonato::setAutodromos(vector <Autodromo*> autodromos)
{
	Campeonato::autodromos = autodromos;
}

void Campeonato::avancaTempo(int tempo)
{
	if (autodromos.size() == Campeonato::estados.size())
		cout << "Campeonato Finalizado";
	else {
		for (size_t i = 0; i < autodromos.size(); i++) {
			if (!verificaOcurrenciaCorrida(autodromos[i])) {
				Pista* pista = autodromos[i]->getPista();
				Corrida* corrida = pista->getCorrida();
				bool estado = corrida->correr(tempo, pista->getComprimento());
				if (estado == true)
					Campeonato::estados.push_back(estado);
			}
		}
	}
}