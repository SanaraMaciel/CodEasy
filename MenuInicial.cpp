#include "MenuInicial.h"

int CodEasy::MenuInicial::getStatus(void)
{
	return Status;
}

string CodEasy::MenuInicial::getNomePagina(void)
{
	return SubJanela->getNome();
}

string CodEasy::MenuInicial::getDestino(void)
{
	return SubJanela->getfolderName();
}
