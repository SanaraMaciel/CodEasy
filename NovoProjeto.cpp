#include "NovoProjeto.h"


string CodEasy::NovoProjeto::getNome(void)
{
	string UmNome;
	MarshalString(Nome, UmNome);

	return UmNome;
}


string CodEasy::NovoProjeto::getfolderName(void)
{
	string UmfolderName;
	MarshalString(folderName, UmfolderName);

	return UmfolderName;
}

int CodEasy::NovoProjeto::getStatusNovoProjeto(void)
{
	return StatusNovoProjeto;
}

void CodEasy::NovoProjeto::setStatusNovoProjeto(int UmStatus)
{
	StatusNovoProjeto = UmStatus;
}
