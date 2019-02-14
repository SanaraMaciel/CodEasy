#ifndef BibliotecaDeFuncoesH
#define BibliotecaDeFuncoesH
#include <iostream>
using namespace std;
#include <string>
typedef struct NoTabela * Ponteiro;
typedef struct NoPilha *Pilha;
//---------------------------------------------------------------
struct  NoPilha
{
	Pilha Link;
	string Palavra;
};

struct NoTabela
{
	Ponteiro LinkEsquerdo,
			 LinkDireito;
	string   Palavra,
		     Tipo;
	int      Valor;
};

class BibliotecaDeFuncoes
{
private:

public:
	BibliotecaDeFuncoes();
	~BibliotecaDeFuncoes();
protected:
	string   PalavraChave[5];
	Ponteiro encadearPalavra(Ponteiro,string, string, int);
	Ponteiro desencadearTodasPalavras(Ponteiro Lista);
	Pilha empilharPalavras(Pilha, string);
	Pilha desempilharPalavras(Pilha, string*);
	Ponteiro desencadearNumeros(Ponteiro, Ponteiro);
};
//---------------------------------------------------------------
#endif
