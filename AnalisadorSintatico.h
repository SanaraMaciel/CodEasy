#ifndef AnalisadorSintaticoH
#define AnalisadorSintaticoH
#include <iostream>
using namespace std;
#include <string>
#include "BibliotecaDeFuncoes.h"
//---------------------------------------------------------------

class AnalisadorSintatico : public BibliotecaDeFuncoes
{
private:
	int procurarPalavraChave(Ponteiro, Ponteiro);
	int procurarVariavel(Ponteiro, Ponteiro);
	int analisarOperacao(Ponteiro, Ponteiro);
	int analisarFuncao(int, Ponteiro, Ponteiro);
public:
	AnalisadorSintatico();
	~AnalisadorSintatico();
	int analisarUmaExpressao(Ponteiro,Ponteiro);
	
};
//---------------------------------------------------------------
#endif