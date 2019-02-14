#include "AnalisadorLexico.h"


AnalisadorLexico::AnalisadorLexico()
{
	Topo = NULL;
	srand((unsigned)time(NULL));
}


AnalisadorLexico::~AnalisadorLexico()
{
}

int AnalisadorLexico::analisarEscrita(string UmTexto, Ponteiro Tabela, Ponteiro Variaveis)
{
	unsigned int Index = 0;
	int Erro = -1;
	string Palavra = "";//palavra que será guardada
	
	while (Index < UmTexto.size() && Erro == -1)
	{
		if (Topo != NULL && Topo->Link != NULL && Topo->Palavra == "(")
		{
			while (Index < UmTexto.size() && UmTexto[Index] != ')')
			{
				Palavra = Palavra + UmTexto[Index];
				Index++;
			}
			Topo = empilharPalavras(Topo, Palavra);
		}
		else
		{
			while (Index < UmTexto.size() && (!isgraph(UmTexto[Index]) || UmTexto[Index] == '\r\n'))
			{
				Index++;
			}

			if (Index < UmTexto.size() && isdigit(UmTexto[Index]))
			{
				while (Index < UmTexto.size() && isgraph(UmTexto[Index]) && !ispunct(UmTexto[Index]) && Erro == -1)
				{
					if (isdigit(UmTexto[Index]))
					{
						Palavra = Palavra + UmTexto[Index];
					}
					else
					{
						Erro = 0;
					}
					if (Palavra.size() > 9)
					{
						Erro = 18;
					}
					Index++;
				}
				if (Erro == -1)
				{
					Topo = empilharPalavras(Topo, Palavra);
				}
			}
			else if (Index < UmTexto.size() && ispunct(UmTexto[Index]))
			{
				if (UmTexto[Index] == '-' || UmTexto[Index] == '+' || UmTexto[Index] == '*' ||
					UmTexto[Index] == '/' || UmTexto[Index] == '=' || UmTexto[Index] == '^' ||
					UmTexto[Index] == '(' || UmTexto[Index] == ')' || UmTexto[Index] == '{' ||
					UmTexto[Index] == '}' || UmTexto[Index] == ';' || UmTexto[Index] == '<' ||
					UmTexto[Index] == '>' || UmTexto[Index] == '!')
				{
					if (Index < UmTexto.size() && (UmTexto[Index] == '>' || UmTexto[Index] == '<' || UmTexto[Index] == '=' || UmTexto[Index] == '!'))
					{
						Palavra = Palavra + UmTexto[Index];
						Index++;

						if (Index < UmTexto.size() && ispunct(UmTexto[Index]) && UmTexto[Index] == '=')
						{
							Palavra = Palavra + UmTexto[Index];
							Index++;
						}
					}
					else
					{
						Palavra = UmTexto[Index];
						Index++;
					}

					Topo = empilharPalavras(Topo, Palavra);
				}
				else
				{
					Erro = 0;
				}

			}
			else if (Index < UmTexto.size())
			{

				while (Index < UmTexto.size() && isgraph(UmTexto[Index]) && !ispunct(UmTexto[Index]))
				{
					Palavra = Palavra + UmTexto[Index];
					Index++;
				}

				Topo = empilharPalavras(Topo, Palavra);

			}

			Palavra = "";
		}
		
	 }
	
	if (Erro == -1 && Topo != NULL)
	{
		Erro = analisarPalavras(Tabela,Variaveis);
	}

	while (Topo != NULL)
	{
		Topo = desempilharPalavras(Topo, &Palavra);
	}

	return Erro;
}

int AnalisadorLexico::analisarPalavras(Ponteiro Tabela, Ponteiro Variaveis)
{
	int Erro = -1;
	string Palavra = "", 
		   Tipo = "";
	int Valor = 0;
	Ponteiro Auxiliar = NULL;

	while (Topo != NULL && Erro == -1)
	{
		Topo = desempilharPalavras(Topo, &Palavra);

		if (Palavra != ";" && Palavra != "(" && Palavra != ")" && Palavra != "{" && Palavra != "}")
		{
			if (Palavra != "+" && Palavra != "-" && Palavra != "/" && Palavra != "*" && Palavra != "=" && Palavra != "^")
			{
				if (Palavra != "<" && Palavra != ">" && Palavra != "==" && Palavra != "!=" && Palavra != ">=" && Palavra != "<=")
				{
					if (!isdigit(Palavra[0]))
					{
						if (Palavra != PalavraChave[0] && Palavra != PalavraChave[1] && Palavra != PalavraChave[2] && Palavra != PalavraChave[3] && Palavra != PalavraChave[4] && Palavra != PalavraChave[5])
						{
							Auxiliar = Variaveis;
							while (Auxiliar->LinkDireito != Variaveis && Palavra != Auxiliar->LinkDireito->Palavra)
							{
								Auxiliar = Auxiliar->LinkDireito;
							}
							if (Auxiliar->LinkDireito != Variaveis)//encontrou a variavel criada
							{
								Tipo = "identificador";
								Valor = Auxiliar->LinkDireito->Valor;
								Tabela = encadearPalavra(Tabela, Palavra, Tipo, Valor);
							}
							else if (Topo != NULL && Topo->Palavra == "inteiro" && !ispunct(Palavra[0]))
							{
								Tipo = "identificador";
								Valor = rand();
								Tabela = encadearPalavra(Tabela, Palavra, Tipo, Valor);
							}
							else
							{
								Tipo = "texto";
								Valor = 0;
								Tabela = encadearPalavra(Tabela, Palavra, Tipo, Valor);
							}
							
						}
						else
						{
							Tipo = "palavrachave";
							Valor = 0;
							Tabela = encadearPalavra(Tabela, Palavra, Tipo, Valor);
						}

					}
					else
					{
						Tipo = "constante";
						Valor = stoi(Palavra);
						Tabela = encadearPalavra(Tabela, Palavra, Tipo, Valor);
					}

				}
				else
				{
					Tipo = "logico";
					Valor = 0;
					Tabela = encadearPalavra(Tabela, Palavra, Tipo, Valor);

				}
			}
			else
			{
				if ((Palavra == "-" || Palavra == "+") && (Tabela->LinkDireito->Tipo == "constante" || Tabela->LinkDireito->Tipo == "identificador") &&
					(Topo->Palavra == "=" || Topo->Palavra == ">=" || Topo->Palavra == "<=" || Topo->Palavra == "==" ||
					Topo->Palavra == "!=" || Topo->Palavra == ">" || Topo->Palavra == "<"))
				{
					if (Tabela->LinkDireito->Tipo == "identificador" && Palavra == "-")
					{
						Auxiliar = Variaveis;
						while (Auxiliar->LinkDireito != Variaveis && Tabela->LinkDireito->Palavra != Auxiliar->LinkDireito->Palavra)
						{
							Auxiliar = Auxiliar->LinkDireito;
						}
						if (Auxiliar->LinkDireito != Variaveis)
						{
							Auxiliar->LinkDireito->Valor = Auxiliar->LinkDireito->Valor * -1;
						}
					}
					else if (Palavra == "-")
					{
						Tabela->LinkDireito->Valor = Tabela->LinkDireito->Valor * -1;
					}
				}
				else
				{
					Tipo = "operador";
					Valor = 0;
					Tabela = encadearPalavra(Tabela, Palavra, Tipo, Valor);
				}
			}
		}
		else
		{
			Tipo = "pontuação";
			Valor = 0;
			Tabela = encadearPalavra(Tabela, Palavra, Tipo, Valor);
		}
	}

	return Erro;
}