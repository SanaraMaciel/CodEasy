#ifndef InterpretadorH
#define InterpretadorH
#include <iostream>
using namespace std;
#include <string>
#include "AnalisadorLexico.h"
#include "AnalisadorSintatico.h"
#include "GeradorDeResposta.h"
//---------------------------------------------------------------

class Interpretador
{
private:
	AnalisadorLexico al;
	AnalisadorSintatico as;
	GeradorDeResposta gdr;
	int      CodigoDoErro,
		     PosicaoTexto,
		     PosicaoRepeticao,
		     PosicaoAnterior,
	         QuantidadeRepeticoes;
	string   Texto,
		     Expressao,
		     Resposta,
	         Condicao;
	Ponteiro Tabela,
		     Variaveis;

	Ponteiro retirarPalavras(Ponteiro);
public:
	Interpretador();
	~Interpretador();
	void     setTexto(string);
	string   getResposta(void);
	string   getExpressao(void);
	int      getPosicaoTexto(void);
	void     atualizarVariavel(int);
	int      separarExpressao(void);
	int      analisarExpressao(void);
	void     excluirListaDeVariaveis(void);
	int      retirarComentarios(void);
};
//---------------------------------------------------------------
#endif
