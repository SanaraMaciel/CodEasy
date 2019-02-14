#include "Controle.h"


Controle::Controle()
{


}

Controle::~Controle()
{


}

void Controle::controlarExecucao(void)
{
	CodEasy::MenuInicial mi;
	CodEasy::TelaCodigo tc;
	CodEasy::TelaExecucao te;
	CodEasy::TelaExecucaoInterpretador tei;

	string Nome = "";
	string FolderName = "";
	int    ErroExpressao = -1;
	int    NumeroLidoUsuario = 0;
	string RespostaDeExecucao = "";
	string TextoCodigo = "";
	int    PosicaoAtualTexto = 0;

	while (mi.getStatus() == -1)
	{
		mi.ShowDialog();
	}

	if (mi.getStatus() == 1 || mi.getStatus() == 2)
	{
		Nome = mi.getNomePagina();
		FolderName = mi.getDestino();
		tc.setNome(Nome);
		tc.setfolderName(FolderName);
		tc.setStatus(mi.getStatus());

		while (tc.getStatus() != 0)
		{
			tc.ShowDialog();
			if (tc.getStatus() == 4 || tc.getStatus() == 5)
			{
				Interpretador i;
				ErroExpressao = -1;
				NumeroLidoUsuario = 0;
				RespostaDeExecucao = "";
				TextoCodigo = "";
				PosicaoAtualTexto = 0;

				TextoCodigo = tc.getTextoCodigo();
				i.setTexto(TextoCodigo);
				ErroExpressao = i.retirarComentarios();//Procura por comentários no código

				if (ErroExpressao == -1)
				{
					do
					{
						ErroExpressao = i.separarExpressao();//Separa o código em expressões para serem analisadas

						if (ErroExpressao == -1)
						{
							ErroExpressao = i.analisarExpressao();//realiza as analises
						}

						if (ErroExpressao == -1)
						{
							RespostaDeExecucao = i.getResposta();

							if (RespostaDeExecucao[0] == 'E')
							{
								if (tc.getStatus() == 4)
								{
									te.escreverTexto(RespostaDeExecucao);
								}
								else
								{
									tei.escreverTexto(RespostaDeExecucao);
								}
							}
							else if (RespostaDeExecucao[0] == 'L')
							{
								if (tc.getStatus() == 4)
								{
									te.setValorEmTexto("");
									te.setLeitura(1);//habilitar digitação
									te.ShowDialog();
									te.setLeitura(0);//desabilitar digitação

									if (te.getStatus() == 1)//tela foi fechada sem inserção de valor
									{
										ErroExpressao = 15;
									}
									else
									{
										NumeroLidoUsuario = te.getValorLido();
										i.atualizarVariavel(NumeroLidoUsuario);
									}
								}
								else
								{
									tei.receberExpressao(i.getExpressao());
									tei.setValorEmTexto("");
									tei.setLeitura(1);//habilitar digitação
									tei.ShowDialog();
									tei.setLeitura(0);//desabilitar digitação

									if (tei.getStatus() == 2)//tela foi fechada sem inserção de valor
									{
										ErroExpressao = 15;
									}
									else
									{
										NumeroLidoUsuario = tei.getValorLido();
										i.atualizarVariavel(NumeroLidoUsuario);
									}
								}
							}
						}


						if (tc.getStatus() == 5 && RespostaDeExecucao[0] != 'L' && ErroExpressao == -1)
						{
							tei.receberExpressao(i.getExpressao());
							tei.ShowDialog();
							if (tei.getStatus() == 2)
							{
								ErroExpressao = 20;
							}
						}
						PosicaoAtualTexto = i.getPosicaoTexto();

					} while (PosicaoAtualTexto < (int)TextoCodigo.size() && ErroExpressao == -1);
				}

				i.excluirListaDeVariaveis();

				if (ErroExpressao > -1)
				{
					if (tc.getStatus() == 4)
					{
						te.setLinha(i.getExpressao());
						te.setNumeroLinha(tc.pesquisarLinha(i.getExpressao()));
						te.mostrarErros(ErroExpressao);
						te.ShowDialog();
					}
					else
					{
						tei.setLeitura(2);
						tei.receberExpressao(i.getExpressao());
						tei.setLinha(i.getExpressao());
						tei.setNumeroLinha(tc.pesquisarLinha(i.getExpressao()));
						tei.mostrarErros(ErroExpressao);
						tei.ShowDialog();
						tei.setLeitura(0);
					}

				}
				else
				{
					if (tc.getStatus() == 4)
					{
						te.escreverTexto(" \r\nExecutado com sucesso.");
						te.ShowDialog();
					}
					else
					{
						tei.setLeitura(2);
						tei.escreverTexto(" \r\nExecutado com sucesso.");
						tei.ShowDialog();
						tei.setLeitura(0);
					}

				}

				tc.setStatus(3);
			}
		}
	}
}