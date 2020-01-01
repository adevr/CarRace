#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Consola.h"

using namespace std;

namespace drawer 
{
	void desenhaMenu();
	void desenhaMainMenuOptions();
	void desenhaListagemAjuda();
	void desenhaInterfaceCorrida();
	void desenhaClassificacaoCorrida(vector<string> classificacao);
};