#ifndef GeradorDeRespostaH
#define GeradorDeRespostaH
#include <iostream>
using namespace std;
#include <string>
#include <math.h>
#include <sstream>
#include "BibliotecaDeFuncoes.h"
//---------------------------------------------------------------

class GeradorDeResposta : public BibliotecaDeFuncoes
{
private:
	string TipoExpressao;
	int      calcularOperacao(Ponteiro, Ponteiro);
public:
	GeradorDeResposta();
	~GeradorDeResposta();
	void     setTipoExpressao(string);
	string   executarFuncao(Ponteiro, Ponteiro);
	Ponteiro esvaziarLista(Ponteiro);
	
};
//---------------------------------------------------------------
#endif
