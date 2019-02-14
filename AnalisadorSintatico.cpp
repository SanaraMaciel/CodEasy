#include "AnalisadorSintatico.h"


AnalisadorSintatico::AnalisadorSintatico()
{
}


AnalisadorSintatico::~AnalisadorSintatico()
{
}

int AnalisadorSintatico::analisarUmaExpressao(Ponteiro Tabela, Ponteiro Variaveis)
{
	int Erro = -1,
		Chave = -1;

	Chave = procurarPalavraChave(Tabela,Variaveis);

	if (Chave == -1)//Primeira palavra não é uma palavra chave
	{
		Chave = procurarVariavel(Tabela, Variaveis);
		if (Chave == -1)//Primeira palavra não é uma variavel
		{
			Erro = 1;
		}
		else
		{
			Erro = analisarOperacao(Tabela, Variaveis);
		}
	}
	else
	{
		Erro = analisarFuncao(Chave, Tabela, Variaveis);
	}

	return Erro;
}

int AnalisadorSintatico::procurarPalavraChave(Ponteiro Tabela, Ponteiro Variaveis)
{
	int Chave = -1;

	for (int i = 0; i < 5; ++i)
	{
		if (Tabela->LinkDireito != Tabela && Tabela->LinkDireito->Palavra == PalavraChave[i])
		{
			Chave = i;
		}
	}

	return Chave;
}

int AnalisadorSintatico::procurarVariavel(Ponteiro Tabela, Ponteiro Variaveis)
{
	int Chave = -1;
	Ponteiro Auxiliar = Variaveis->LinkDireito;

	while (Auxiliar != Variaveis && Tabela->LinkDireito != Tabela &&
		   Tabela->LinkDireito->Palavra != Auxiliar->Palavra)
	{
		Auxiliar = Auxiliar->LinkDireito;
	}
	if (Auxiliar != Variaveis && Tabela->LinkDireito != Tabela)
	{
		Chave = 1;
	}

	return Chave;
}

int AnalisadorSintatico::analisarOperacao(Ponteiro Tabela, Ponteiro Variaveis)
{
	int Erro = -1;
	short int PosicaoAnalise = 0;
	Ponteiro Auxiliar = Tabela->LinkDireito->LinkDireito;
	Ponteiro AcharVariavel = NULL;

	if (Auxiliar == Tabela || Auxiliar->Palavra != "=")
	{
		Erro = 2;
	}

	Auxiliar = Auxiliar->LinkDireito;

	while (Auxiliar != Tabela && Erro == -1)
	{
		
		if (PosicaoAnalise == 0)
		{
			
			if (Auxiliar->Tipo != "constante")
			{
				AcharVariavel = Variaveis->LinkDireito;

				while (AcharVariavel != Variaveis && Auxiliar->Palavra != AcharVariavel->Palavra)
				{
					AcharVariavel = AcharVariavel->LinkDireito;
				}

				if (Auxiliar->Palavra != AcharVariavel->Palavra)
				{
					Erro = 6;
				}
				else
				{
					Auxiliar->Valor = AcharVariavel->Valor;
				}
			}

			PosicaoAnalise = 1;
		}
		else if (PosicaoAnalise == 1)
		{
			if (Auxiliar->Palavra == "=" || (Auxiliar->Tipo != "operador" && Auxiliar->Palavra != ";"))
			{
				Erro = 6;
			}
			PosicaoAnalise = 0;
		}
		Auxiliar = Auxiliar->LinkDireito;
	}

	if (Erro == -1 && Tabela->LinkEsquerdo->Palavra != ";")
	{
		Erro = 6;
	}
	else
	{
		Tabela->Palavra = "operacao";//indica que a expressão é uma operação
	}

	return Erro;
}

int AnalisadorSintatico::analisarFuncao(int Chave, Ponteiro Tabela, Ponteiro Variaveis)
{
	int Erro = -1,
		PosicaoAnalise = 0;
	Ponteiro Auxiliar = NULL;
	Ponteiro EncontrarVariavel = NULL;

	if (Tabela->LinkDireito != Tabela && Tabela->LinkDireito->LinkDireito != Tabela)
	{
		Auxiliar = Tabela->LinkDireito->LinkDireito;
	}
	else
	{
		Erro = 8;
	}

	if (Erro == -1)
	{
		switch (Chave)
		{
		case 0://inteiro

			if (Auxiliar->Tipo != "identificador")
			{
				Erro = 10;
			}
			if (Auxiliar->LinkDireito->Palavra != ";" || Auxiliar->LinkDireito->LinkDireito != Tabela)
			{
				Erro = 10;
			}
			else
			{
				EncontrarVariavel = Variaveis;
				while (EncontrarVariavel->LinkDireito != Variaveis &&
					EncontrarVariavel->LinkDireito->Palavra != Auxiliar->Palavra)
				{
					EncontrarVariavel = EncontrarVariavel->LinkDireito;
				}

				if (EncontrarVariavel->LinkDireito->Palavra != Auxiliar->Palavra)//Se não existe ainda a variável, criar
				{
					Variaveis = encadearPalavra(Variaveis, Auxiliar->Palavra, Auxiliar->Tipo, Auxiliar->Valor);
				}
				else
				{
					Erro = 11;
				}
			}
			if (Erro == -1)
			{
				Tabela->Palavra = "variavel";
			}

			break;

		case 1://escrever
			
			if (Auxiliar->Palavra != "(")
			{
				EncontrarVariavel = Variaveis;
				while (EncontrarVariavel->LinkDireito != Variaveis &&
					EncontrarVariavel->LinkDireito->Palavra != Auxiliar->Palavra)
				{
					EncontrarVariavel = EncontrarVariavel->LinkDireito;
				}

				if (EncontrarVariavel->LinkDireito == Variaveis)
				{
					Erro = 8;
				}
				else
				{
					Auxiliar = Auxiliar->LinkDireito;
				}

			}
			else
			{
				while (Auxiliar != Tabela && Auxiliar->Palavra != ")")
				{
					Auxiliar = Auxiliar->LinkDireito;
				}

				if (Auxiliar == Tabela)
				{
					Erro = 4;
				}
				else
				{
					Auxiliar = Auxiliar->LinkDireito;
				}
			}


			while (Auxiliar != Tabela && Erro == -1 && Tabela->Palavra != "escrita")
			{
				if (Auxiliar->Palavra != "(" && Auxiliar->Palavra != ";")
				{
					EncontrarVariavel = Variaveis;
					while (EncontrarVariavel->LinkDireito != Variaveis &&
						EncontrarVariavel->LinkDireito->Palavra != Auxiliar->Palavra)
					{
						EncontrarVariavel = EncontrarVariavel->LinkDireito;
					}

					if (EncontrarVariavel->LinkDireito == Variaveis)
					{
						Erro = 8;
					}
					else
					{
						Auxiliar = Auxiliar->LinkDireito;
					}

				}
				else if (Auxiliar->Palavra == "(")
				{
					while (Auxiliar != Tabela && Auxiliar->Palavra != ")")
					{
						Auxiliar = Auxiliar->LinkDireito;
					}

					if (Auxiliar == Tabela)
					{
						Erro = 4;
					}
					else
					{
						Auxiliar = Auxiliar->LinkDireito;
					}
				}
				else
				{
					if (Erro == -1 && Auxiliar->Palavra == ";")
					{
						Tabela->Palavra = "escrita";
					}
					else
					{
						Erro = 7;
					}
				}
			} 
			break;
		case 2://ler

			EncontrarVariavel = Variaveis;
			while (EncontrarVariavel->LinkDireito != Variaveis &&
				EncontrarVariavel->LinkDireito->Palavra != Auxiliar->Palavra)
			{
				EncontrarVariavel = EncontrarVariavel->LinkDireito;
			}

			if (EncontrarVariavel->LinkDireito == Variaveis || Auxiliar->LinkDireito->Palavra != ";")
			{
				Erro = 8;
			}
			if (Erro == -1)
			{
				Tabela->Palavra = "leitura";
			}
			break;
		case 3://se
			while (Auxiliar != Tabela && Erro == -1 && PosicaoAnalise != 3)
			{
				if (PosicaoAnalise == 0)
				{
					EncontrarVariavel = Variaveis;
					while (EncontrarVariavel->LinkDireito != Variaveis &&
						EncontrarVariavel->LinkDireito->Palavra != Auxiliar->Palavra)
					{
						EncontrarVariavel = EncontrarVariavel->LinkDireito;
					}

					if (EncontrarVariavel->LinkDireito == Variaveis)
					{
						Erro = 8;
					}
					PosicaoAnalise = 1;
				}
				else if (PosicaoAnalise == 1)
				{
					if (Auxiliar->Tipo != "logico")
					{
						Erro = 12;
					}
					PosicaoAnalise = 2;
				}
				else if (PosicaoAnalise == 2)
				{
					EncontrarVariavel = Variaveis;
					while (EncontrarVariavel->LinkDireito != Variaveis &&
						EncontrarVariavel->LinkDireito->Palavra != Auxiliar->Palavra)
					{
						EncontrarVariavel = EncontrarVariavel->LinkDireito;
					}

					if (EncontrarVariavel->LinkDireito == Variaveis && Auxiliar->Tipo != "constante")
					{
						Erro = 8;
					}

					PosicaoAnalise = 3;
				}

				Auxiliar = Auxiliar->LinkDireito;
			}
			if (Auxiliar == Tabela)
			{
				Erro = 9;
			}
			else if (PosicaoAnalise == 3 && Auxiliar->Palavra != "{")
			{
				Erro = 14;
			}

			if (Erro == -1)
			{
				Tabela->Palavra = "condicao";
			}
			break;
		case 4://enquanto
			while (Auxiliar != Tabela && Erro == -1 && PosicaoAnalise != 3)
			{
				if (PosicaoAnalise == 0)
				{
					EncontrarVariavel = Variaveis;
					while (EncontrarVariavel->LinkDireito != Variaveis &&
						EncontrarVariavel->LinkDireito->Palavra != Auxiliar->Palavra)
					{
						EncontrarVariavel = EncontrarVariavel->LinkDireito;
					}

					if (EncontrarVariavel->LinkDireito == Variaveis)
					{
						Erro = 8;
					}
					PosicaoAnalise = 1;
				}
				else if (PosicaoAnalise == 1)
				{
					if (Auxiliar->Tipo != "logico")
					{
						Erro = 12;
					}
					PosicaoAnalise = 2;
				}
				else if (PosicaoAnalise == 2)
				{
					EncontrarVariavel = Variaveis;
					while (EncontrarVariavel->LinkDireito != Variaveis &&
						EncontrarVariavel->LinkDireito->Palavra != Auxiliar->Palavra)
					{
						EncontrarVariavel = EncontrarVariavel->LinkDireito;
					}

					if (EncontrarVariavel->LinkDireito == Variaveis && Auxiliar->Tipo != "constante")
					{
						Erro = 8;
					}

					PosicaoAnalise = 3;
				}

				Auxiliar = Auxiliar->LinkDireito;
			}
			if (Auxiliar == Tabela)
			{
				Erro = 9;
			}
			else if (PosicaoAnalise == 3 && Auxiliar->Palavra != "{")
			{
				Erro = 14;
			}

			if (Erro == -1)
			{
				Tabela->Palavra = "repeticao";
			}
			break;
		}
	}
	
	return Erro;
}