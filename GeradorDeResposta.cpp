#include "GeradorDeResposta.h"


GeradorDeResposta::GeradorDeResposta()
{
	TipoExpressao = "";
}


GeradorDeResposta::~GeradorDeResposta()
{
}

void GeradorDeResposta::setTipoExpressao(string Tipo)
{
	TipoExpressao = Tipo;
}

Ponteiro GeradorDeResposta::esvaziarLista(Ponteiro Lista)
{
	return desencadearTodasPalavras(Lista);
}

string GeradorDeResposta::executarFuncao(Ponteiro Tabela, Ponteiro Variaveis)
{
	stringstream NumeroEmTexto;
	string Resposta = "";
	Ponteiro Auxiliar = NULL;

	if (TipoExpressao == "operacao")
	{
		Auxiliar = Variaveis;
		while (Auxiliar->LinkDireito != Variaveis && Tabela->LinkDireito->Palavra != Auxiliar->LinkDireito->Palavra)
		{
			Auxiliar = Auxiliar->LinkDireito;
		}
		
		if (Auxiliar->LinkDireito != Variaveis)
		{
			Auxiliar->LinkDireito->Valor = calcularOperacao(Tabela, Variaveis);
		}
	}
	else if (TipoExpressao == "escrita")
	{
		Resposta = "E";
		Auxiliar = Tabela->LinkDireito;
		while (Auxiliar->LinkDireito != Tabela && Auxiliar->LinkDireito->Palavra != ";")
		{
			if (Auxiliar->LinkDireito->Palavra != "(")
			{
				
				NumeroEmTexto << Auxiliar->LinkDireito->Valor;
				Resposta = Resposta + NumeroEmTexto.str();
				NumeroEmTexto.clear();
				NumeroEmTexto.str("");
			}
			else
			{
				Auxiliar = Auxiliar->LinkDireito;
				while (Auxiliar->LinkDireito != Tabela && Auxiliar->LinkDireito->Palavra != ")")
				{
					for (unsigned int i = 0; i < Auxiliar->LinkDireito->Palavra.size(); ++i)
					{
						if (Auxiliar->LinkDireito->Palavra[i] == '|' && i + 1 < Auxiliar->LinkDireito->Palavra.size()
							&& Auxiliar->LinkDireito->Palavra[i + 1] == '|')
						{
							i++;
							Resposta = Resposta + "\r\n";
						}
						else
						{
							Resposta = Resposta + Auxiliar->LinkDireito->Palavra[i];
						}

					}
					Auxiliar = Auxiliar->LinkDireito;
				}
			}
			Auxiliar = Auxiliar->LinkDireito;
		}

	}
	else if (TipoExpressao == "leitura")
	{
		Auxiliar = Tabela;
		Resposta = "L" + Auxiliar->LinkDireito->LinkDireito->Palavra;
	}
	else if (TipoExpressao == "condicao")
	{
		Auxiliar = Tabela;
		while (Auxiliar->LinkDireito != Tabela && Auxiliar->LinkDireito->Tipo != "logico")
		{
			Auxiliar = Auxiliar->LinkDireito;
		}

		if (Auxiliar->LinkDireito->Palavra == ">")
		{
			if (Auxiliar->Valor > Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "verdade";
			}
			else
			{
				Resposta = "falso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == "<")
		{
			if (Auxiliar->Valor < Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "verdade";
			}
			else
			{
				Resposta = "falso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == ">=")
		{
			if (Auxiliar->Valor >= Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "verdade";
			}
			else
			{
				Resposta = "falso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == "<=")
		{
			if (Auxiliar->Valor <= Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "verdade";
			}
			else
			{
				Resposta = "falso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == "!=")
		{
			if (Auxiliar->Valor != Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "verdade";
			}
			else
			{
				Resposta = "falso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == "==")
		{
			if (Auxiliar->Valor == Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "verdade";
			}
			else
			{
				Resposta = "falso";
			}
		}
	}
	else if (TipoExpressao == "repeticao")
	{
		Auxiliar = Tabela;
		while (Auxiliar->LinkDireito != Tabela && Auxiliar->LinkDireito->Tipo != "logico")
		{
			Auxiliar = Auxiliar->LinkDireito;
		}

		if (Auxiliar->LinkDireito->Palavra == ">")
		{
			if (Auxiliar->Valor > Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "Rverdade";
			}
			else
			{
				Resposta = "Rfalso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == "<")
		{
			if (Auxiliar->Valor < Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "Rverdade";
			}
			else
			{
				Resposta = "Rfalso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == ">=")
		{
			if (Auxiliar->Valor >= Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "Rverdade";
			}
			else
			{
				Resposta = "Rfalso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == "<=")
		{
			if (Auxiliar->Valor <= Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "Rverdade";
			}
			else
			{
				Resposta = "Rfalso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == "!=")
		{
			if (Auxiliar->Valor != Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "Rverdade";
			}
			else
			{
				Resposta = "Rfalso";
			}
		}
		else if (Auxiliar->LinkDireito->Palavra == "==")
		{
			if (Auxiliar->Valor == Auxiliar->LinkDireito->LinkDireito->Valor)
			{
				Resposta = "Rverdade";
			}
			else
			{
				Resposta = "Rfalso";
			}
		}
	}
	else if (TipoExpressao == "inicio")
	{

	}

	return Resposta;
}

int GeradorDeResposta::calcularOperacao(Ponteiro Tabela, Ponteiro Variaveis)
{
	int Resultado = 0,
		ValorParcial = 0;
	Ponteiro Expressao = Tabela;
	Ponteiro Auxiliar = NULL;

	while (Expressao->LinkDireito != Tabela && Expressao->LinkDireito->Palavra != "=")
	{
		Expressao = Expressao->LinkDireito;
	}
	Expressao = Expressao->LinkDireito;

	if (Expressao->LinkDireito->LinkDireito->Palavra == ";")
	{
		Resultado = Expressao->LinkDireito->Valor;
	}
	else
	{
		Auxiliar = Expressao;
		while (Auxiliar->LinkDireito != Tabela && Auxiliar->LinkDireito->Palavra != "^")
		{
			Auxiliar = Auxiliar->LinkDireito;
		}
		if (Auxiliar->LinkDireito->Palavra == "^")
		{
			ValorParcial = (int)pow(Auxiliar->Valor, Auxiliar->LinkDireito->LinkDireito->Valor);
			Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
			Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
		}
		else
		{
			Auxiliar = Expressao;
			while (Auxiliar->LinkDireito != Tabela && Auxiliar->LinkDireito->Palavra != "*" && Auxiliar->LinkDireito->Palavra != "/")
			{
				Auxiliar = Auxiliar->LinkDireito;
			}
			if (Auxiliar->LinkDireito->Palavra == "*")
			{
				ValorParcial = Auxiliar->Valor * Auxiliar->LinkDireito->LinkDireito->Valor;
				Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
				Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
			}
			else if (Auxiliar->LinkDireito->Palavra == "/")
			{
				if (Auxiliar->LinkDireito->LinkDireito->Valor != 0)
				{
					ValorParcial = Auxiliar->Valor / Auxiliar->LinkDireito->LinkDireito->Valor;
					Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
					Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
				}
				else
				{
					Tabela->Tipo = "divisao";
				}
				
			}
			else
			{
				Auxiliar = Expressao;
				while (Auxiliar->LinkDireito != Tabela && Auxiliar->LinkDireito->Palavra != "+" && Auxiliar->LinkDireito->Palavra != "-")
				{
					Auxiliar = Auxiliar->LinkDireito;
				}
				if (Auxiliar->LinkDireito->Palavra == "+")
				{
					ValorParcial = Auxiliar->Valor + Auxiliar->LinkDireito->LinkDireito->Valor;
					Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
					Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
				}
				else if (Auxiliar->LinkDireito->Palavra == "-")
				{
					ValorParcial = Auxiliar->Valor - Auxiliar->LinkDireito->LinkDireito->Valor;
					Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
					Tabela = desencadearNumeros(Tabela, Auxiliar->LinkDireito);
				}
			}
		}
		
		if (Tabela->Tipo != "divisao")
		{
			Auxiliar->Valor = ValorParcial;
			Resultado = calcularOperacao(Tabela, Variaveis);
		}
	}

	return Resultado;
}

