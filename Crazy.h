#pragma once

#include "Piloto.h"

class Crazy : public Piloto
{

public:
	Crazy(string nome);
	virtual ~Crazy(); // destrutor
	int executaComportamento(int tempo) override;
};

