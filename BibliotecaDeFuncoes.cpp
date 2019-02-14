#include "BibliotecaDeFuncoes.h"


BibliotecaDeFuncoes::BibliotecaDeFuncoes()
{
	PalavraChave[0] = "inteiro";
	PalavraChave[1] = "escrever";
	PalavraChave[2] = "ler";
	PalavraChave[3] = "se";
	PalavraChave[4] = "enquanto";
}


BibliotecaDeFuncoes::~BibliotecaDeFuncoes()
{
}


Ponteiro BibliotecaDeFuncoes::encadearPalavra(Ponteiro Lista, string UmaPalavra, string UmTipo, int UmValor)
{
	Ponteiro NovaPalavra = new NoTabela();

	NovaPalavra->Palavra = UmaPalavra;
	NovaPalavra->Tipo    = UmTipo;
	NovaPalavra->Valor   = UmValor;

	NovaPalavra->LinkDireito = Lista->LinkDireito;
	NovaPalavra->LinkEsquerdo = Lista;
	Lista->LinkDireito->LinkEsquerdo = NovaPalavra;
	Lista->LinkDireito = NovaPalavra;

	return Lista;
}

Ponteiro BibliotecaDeFuncoes::desencadearTodasPalavras(Ponteiro Lista)
{
	Ponteiro Auxiliar = Lista->LinkDireito;
	while (Auxiliar != Lista)
	{
		Auxiliar->LinkEsquerdo->LinkDireito = Auxiliar->LinkDireito;
		Auxiliar->LinkDireito->LinkEsquerdo = Auxiliar->LinkEsquerdo;
		delete(Auxiliar);
		Auxiliar = Lista->LinkDireito;
	}
	Lista = Auxiliar;

	return Lista;
}

Pilha BibliotecaDeFuncoes::empilharPalavras(Pilha UmTopo, string UmaPalavra)
{
	Pilha Novo = new NoPilha();

	Novo->Palavra = UmaPalavra;
	Novo->Link = UmTopo;
	UmTopo = Novo;

	return UmTopo;
}

Pilha BibliotecaDeFuncoes::desempilharPalavras(Pilha UmTopo, string * UmaPalavra)
{
	Pilha Auxiliar = UmTopo;

	if (UmTopo != NULL)
	{
		*UmaPalavra = UmTopo->Palavra;
		UmTopo = UmTopo->Link;
		delete(Auxiliar);
	}

	return UmTopo;
}

Ponteiro BibliotecaDeFuncoes::desencadearNumeros(Ponteiro Lista, Ponteiro Excluir)
{
	Excluir->LinkEsquerdo->LinkDireito = Excluir->LinkDireito;
	Excluir->LinkDireito->LinkEsquerdo = Excluir->LinkEsquerdo;
	delete(Excluir);

	return Lista;
}