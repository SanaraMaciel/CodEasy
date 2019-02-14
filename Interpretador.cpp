#include "Interpretador.h"


Interpretador::Interpretador()
{
	CodigoDoErro = -1;
	Texto = "";
	PosicaoTexto = 0;
	PosicaoAnterior = 0;
	PosicaoRepeticao = 0;
	QuantidadeRepeticoes = 0;
	Expressao = "";
	Resposta = "";
	Condicao = "";

	Tabela = new NoTabela();
	Tabela->LinkDireito = Tabela;
	Tabela->LinkEsquerdo = Tabela;

	Variaveis = new NoTabela();
	Variaveis->LinkDireito = Variaveis;
	Variaveis->LinkEsquerdo = Variaveis;
}


Interpretador::~Interpretador()
{
	delete(Tabela);
	delete(Variaveis);
}

void Interpretador::setTexto(string UmTexto)
{
	Texto = UmTexto;
}

string Interpretador::getResposta(void)
{
	return Resposta;
}

string Interpretador::getExpressao(void)
{
	return Expressao;
}

int Interpretador::getPosicaoTexto(void)
{
	return PosicaoTexto;
}

void Interpretador::atualizarVariavel(int Numero)
{
	Ponteiro Auxiliar = Variaveis;
	string NomeVariavel = "";//nome da variavel à ser atualizada

	for (unsigned int i = 1; i < Resposta.size(); ++i)
	{
		NomeVariavel = NomeVariavel + Resposta[i];
	}

	while (Auxiliar->LinkDireito != Variaveis && NomeVariavel != Auxiliar->LinkDireito->Palavra)//Procura variável na lista
	{
		Auxiliar = Auxiliar->LinkDireito;
	}

	if (NomeVariavel == Auxiliar->LinkDireito->Palavra)
	{
		Auxiliar->LinkDireito->Valor = Numero;//atualiza valor se for encontrado
	}
}

int Interpretador::separarExpressao(void)
{
	unsigned int Index = PosicaoTexto;
	short int PossuiTexto = 0;
	PosicaoAnterior = PosicaoTexto;

	if (Index < Texto.size() && QuantidadeRepeticoes < 5000)
	{
		if (Condicao == "verdade" )
		{
			PossuiTexto = 0;

			while (Index < Texto.size() && Texto[Index] != ';' && Texto[Index] != '}' && Texto[Index] != '{')
			{
				if (isgraph(Texto[Index]))
				{
					PossuiTexto = 1;
				}
				Index++;
			}
				
			Expressao = "";

			if (Index < Texto.size() && Texto[Index] == ';')
			{
				for (unsigned int i = PosicaoTexto; i <= Index; ++i)
				{
					Expressao = Expressao + Texto[i];
				}
				Index++;
				PosicaoTexto = Index;
			}
			else if (Index < Texto.size() && Texto[Index] == '}' && PossuiTexto == 0)
			{
				Condicao = "";
				Index++;
				PosicaoTexto = Index;
				PosicaoAnterior = PosicaoTexto;
				
			}
			else if (Index < Texto.size() && Texto[Index] == '{')
			{
				CodigoDoErro = 14;
			}
			else
			{
				CodigoDoErro = 9;
			}

		}
		else if(Condicao == "falso")
		{
			while (Index < Texto.size() && Texto[Index] != '}')
			{
				Index++;
			}
			
			if (Index < Texto.size())
			{
				Condicao = "";
				Index++;
				PosicaoTexto = Index;
				PosicaoAnterior = PosicaoTexto;
			}
			else
			{
				CodigoDoErro = 9;
			}
			
		}
		else if (Condicao == "Rverdade")
		{
			PossuiTexto = 0;
			while (Index < Texto.size() && Texto[Index] != ';' && Texto[Index] != '}' && Texto[Index] != '{')
			{
				if (isgraph(Texto[Index]))
				{
					PossuiTexto = 1;
				}
				Index++;
			}

			Expressao = "";

			if (Index < Texto.size() && (Texto[Index] == ';' || PosicaoAnterior == PosicaoRepeticao))
			{
				for (unsigned int i = PosicaoTexto; i <= Index; ++i)
				{
					Expressao = Expressao + Texto[i];
				}
				PosicaoTexto = Index + 1;
			}
			else if (Index < Texto.size() && Texto[Index] == '}' && PossuiTexto == 0)
			{
				Condicao = "";
				PosicaoTexto = PosicaoRepeticao;
				PosicaoAnterior = PosicaoRepeticao;
				Index = PosicaoRepeticao;
				QuantidadeRepeticoes++;
			}
			else if (Index < Texto.size() && Texto[Index] == '{')
			{
				CodigoDoErro = 14;
			}
			else
			{
				CodigoDoErro = 9;
			}
		}
		else if (Condicao == "Rfalso")
		{
			while (Index < Texto.size() && Texto[Index] != '}')
			{
				Index++;
			}

			if (Index < Texto.size())
			{
				QuantidadeRepeticoes = 0;
				Condicao = "";
				Index++;
				PosicaoTexto = Index;
				PosicaoAnterior = PosicaoTexto;
			}
			else
			{
				CodigoDoErro = 9;
			}
			
		}

		if (Condicao == "")
		{
			while (Index < Texto.size() && Texto[Index] != ';' && Texto[Index] != '{')
			{
				Index++;
			}

			Expressao = "";
			if (Index < Texto.size())
			{
				for (unsigned int i = PosicaoTexto; i <= Index; ++i)
				{
					Expressao = Expressao + Texto[i];
				}
				Index++;
				PosicaoTexto = Index;
			}
			else
			{
				for (unsigned int i = PosicaoTexto; i <= Index; ++i)
				{
					Expressao = Expressao + Texto[i];
				}
				PosicaoTexto = Index + 1;
				for (unsigned int i = 0; i < Expressao.size(); ++i)
				{
					if (isgraph(Expressao[i]))
					{
						CodigoDoErro = 9;
					}
				}
				if (CodigoDoErro == -1)
				{
					CodigoDoErro = -2;
				}
			}
		}
	}
	else
	{
		CodigoDoErro = 16;
	}

	return CodigoDoErro;
}


int Interpretador::analisarExpressao(void)
{

	CodigoDoErro = al.analisarEscrita(Expressao,Tabela,Variaveis);//realiza analise lexica

	if (CodigoDoErro == -1)
	{
		CodigoDoErro = as.analisarUmaExpressao(Tabela, Variaveis);//analise sintática
		
		if (CodigoDoErro == -1)
		{
			gdr.setTipoExpressao(Tabela->Palavra);
			Resposta = gdr.executarFuncao(Tabela, Variaveis);//gera resultado

			if (Tabela->Tipo == "divisao")
			{
				CodigoDoErro = 17;
			}

			if (CodigoDoErro == -1)
			{
				if (Resposta == "verdade" || Resposta == "falso" || Resposta == "Rverdade" || Resposta == "Rfalso")
				{
					Condicao = Resposta;

					if (Resposta == "Rverdade" || Resposta == "Rfalso")
					{
						PosicaoRepeticao = PosicaoAnterior;
					}
				}
				if (PosicaoTexto >= (int)Texto.size() && (Condicao == "verdade" || Condicao == "Rverdade"))
				{
					CodigoDoErro = 9;
				}
			}
		}
	}

	Tabela = retirarPalavras(Tabela);

	gdr.setTipoExpressao("");

	return CodigoDoErro;
}

Ponteiro Interpretador::retirarPalavras(Ponteiro Lista)
{
	return gdr.esvaziarLista(Lista);
}

void Interpretador::excluirListaDeVariaveis(void)
{
	Variaveis = gdr.esvaziarLista(Variaveis);
}

int Interpretador::retirarComentarios(void)
{
	unsigned int Index = 0;
	int Erro = -1;

	while (Index < Texto.size())
	{
		if (Texto[Index] == '/')
		{
			if (Index + 1 < Texto.size() && Texto[Index + 1] == '*')
			{
				Texto[Index] = ' ';
				Index++;
				if (Index < Texto.size())
				{
					
					do
					{
						Texto[Index] = ' ';
						Index++;
					} while (Index < Texto.size() && Texto[Index] != '*');
					if (Index >= Texto.size() || Index + 1 >= Texto.size() || Texto[Index + 1] != '/')
					{
						Erro = 19;
					}
					else
					{
						Texto[Index] = ' ';
						Texto[Index + 1] = ' ';
						Index += 2;
					}
				}
				else
				{
					Erro = 0;
				}
			}
			
		}
		Index++;
	}

	return Erro;
}