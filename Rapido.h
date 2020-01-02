#pragma once

#include "Piloto.h"

class Rapido : public Piloto
{
public:
	Rapido(string nome);
	virtual ~Rapido(); // destrutor
	int executaComportamento(int tempo) override;
};

