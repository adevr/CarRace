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


bool Campeonato::iniciarProximaCorrida() 
{	
	if (autodromos.size() == Campeonato::estados.size()){
		Consola::gotoxy(45, 7);
		cout << "Campeonato Finalizado";
		createClassificacao();
		classificacaoCampeonato();
		return true;
	}else{
		for (size_t i = 0; i < autodromos.size(); i++) {
			if (!verificaOcurrenciaCorrida(autodromos[i])) {
				Pista* pista = autodromos[i]->getPista();
				Corrida* corrida = pista->getCorrida();
				
				if (pista->getParticipantes().size() >= 2){
					corrida->iniciar();
				}else{
					cout << "Nao existem participantes suficientes presentes na pista.";
				}			
				break;
			}
		}
		return false;
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
	if (piloto->getCarro() != nullptr)
		pilotos.push_back(piloto);
}

vector <Autodromo*> Campeonato::getAutodromos() { return Campeonato::autodromos;  }

void Campeonato::setAutodromos(vector <Autodromo*> autodromos)
{
	Campeonato::autodromos = autodromos;
}

bool Campeonato::avancaTempo(int tempo)
{
	for (size_t i = 0; i < autodromos.size(); i++) {
		if (!verificaOcurrenciaCorrida(autodromos[i])) {
			Pista* pista = autodromos[i]->getPista();
			Corrida* corrida = pista->getCorrida();
			bool estado = corrida->correr(tempo, pista->getComprimento());
			if (estado == true){
				Campeonato::estados.push_back(estado);
				return true;
			}
			break;
		}
	}
	return false;
}

void Campeonato::createClassificacao()
{
	for (size_t i = 0; i < pilotos.size(); i++){
		classCampeonato.push_back(pilotos[i]->getNome());
	}
}

vector <string> Campeonato::getClassCampeonato(){
	return Campeonato::classCampeonato;
}

  vector <Piloto*> Campeonato::getPilotos()
  {
	  return Campeonato::pilotos;
  }

  void Campeonato::classificacaoCampeonato()
  {
	  vector<string> classC = getClassCampeonato();
	  vector<Piloto*> part = getPilotos();
	  vector<int> ponts;

	  for (size_t i = 0; i < part.size(); i++) {
		  ponts.push_back(part[i]->getPontuacao());
	  }

	  sort(ponts.begin(), ponts.end(), greater<int>());

	  for (size_t i = 0; i < ponts.size(); i++) {
		  if (part[i]->getPontuacao() == ponts[i]) {
			  Consola::gotoxy(10, 10 + i);
			  cout << "1. " << part[i]->getNome() << " - " << part[i]->getCarro()->getAsString() << " - Pontuacao: " << ponts[i];
		  }
	  }
  }