#ifndef AnalisadorLexicoH
#define AnalisadorLexicoH
#include <iostream>
using namespace std;
#include <string>
#include <time.h>
#include "BibliotecaDeFuncoes.h"
//---------------------------------------------------------------

class AnalisadorLexico : public BibliotecaDeFuncoes
{
private:
	Pilha Topo;
public:
	AnalisadorLexico();
	~AnalisadorLexico();
	
	int analisarEscrita(string,Ponteiro,Ponteiro);
	int analisarPalavras(Ponteiro,Ponteiro);
};
//---------------------------------------------------------------
#endif
