#include "helper.h"


char helper::rewriteID(char id)
{
	return 'a' + (rand() % 26);
}

string helper::rewriteNome(string nome)
{
	char randomletter = 'A' + (rand() % 26);
	return nome += randomletter;
}