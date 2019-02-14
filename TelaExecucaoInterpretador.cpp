#include "TelaExecucaoInterpretador.h"

using namespace CodEasy;

void TelaExecucaoInterpretador::setTexto(string UmTexto)
{
	String ^ Texto = gcnew String(UmTexto.c_str());
	TextoRecebido = Texto;
	delete(Texto);
}

void TelaExecucaoInterpretador::setValorEmTexto(string UmValor)
{
	String ^ Texto = gcnew String(UmValor.c_str());
	ValorEmTexto = Texto;
	delete(Texto);
}

void TelaExecucaoInterpretador::setLeitura(int UmValor)
{
	Leitura = UmValor;
}

int TelaExecucaoInterpretador::getValorLido()
{
	int Valor = 0;
	Valor = Convert::ToInt32(ValorEmTexto);

	return Valor;
}

void TelaExecucaoInterpretador::setStatus(int UmValor)
{
	Status = UmValor;
}

int TelaExecucaoInterpretador::getStatus()
{
	return Status;
}

void TelaExecucaoInterpretador::setNumeroLinha(int UmNumero)
{
	NumeroLinha = UmNumero;
}

void TelaExecucaoInterpretador::mostrarErros(int NumeroErro)
{
	String ^ Texto;
	string Erros[21];
	Erros[0] = "Erro lexico.";
	Erros[1] = "Erro sintatico.";
	Erros[2] = "Esperado sinal de igualdade.";
	Erros[3] = "Variavel nao declarada ou operacao impossivel.";
	Erros[4] = "Falta de parenteses.";
	Erros[5] = "Tipo nao especificado.";
	Erros[6] = "Operacao impossivel.";
	Erros[7] = "Argumentos Invalidos.";
	Erros[8] = "Argumentos da funcao invalidos ou variavel nao declarada.";
	Erros[9] = "Nao encontrado finalizador de linha.";
	Erros[10] = "Definicao incorreta de variavel.";
	Erros[11] = "Uma Variavel ja foi definida com este nome.";
	Erros[12] = "Esperado um operador logico.";
	Erros[14] = "Excesso de argumentos ou argumentos invalidos.";
	Erros[15] = "Não inserido valor de leitura.";
	Erros[16] = "Excesso de Repetições, possível loop infinito.";
	Erros[17] = "Impossível dividir por 0.";
	Erros[18] = "Ocorreu estouro do limite de tamanho da variável.";
	Erros[19] = "Não encontrado finalizador de comentários \"*/\"";
	Erros[20] = "Finalizado pelo usuário.";

	Texto = gcnew String(Erros[NumeroErro].c_str());
	textBoxExecucao->Text = "Ocorreu um erro na execução\r\n\r\nMotivo do Erro: " + TextoRecebido + Texto + "\r\nLocal onde ocorreu o erro: " + Expressao +
		"\r\nLinha onde ocorreu o erro: " + NumeroLinha;
	this->Visible = false;
}

void TelaExecucaoInterpretador::escreverTexto(string UmaResposta)
{
	unsigned int i = 1;
	string Resposta = "";
	String ^ Texto;
	while (i < UmaResposta.size())
	{
		Resposta = Resposta + UmaResposta[i];
		i++;
	}

	Texto = gcnew String(Resposta.c_str());
	textBoxExecucao->Text = textBoxExecucao->Text + Texto;
}

void TelaExecucaoInterpretador::setLinha(string UmaExpressao)
{
	bool TextoVazio = true;
	for (int i = 0; (unsigned)i < UmaExpressao.size(); ++i)
	{
		if (isgraph(UmaExpressao[i]))
		{
			TextoVazio = false;
		}
	}
	if (TextoVazio)
	{
		UmaExpressao = "Expressão Nula";
	}
	String ^ Texto;
	Texto = gcnew String(UmaExpressao.c_str());
	Expressao = Texto;
}

void TelaExecucaoInterpretador::receberExpressao(string UmaExpressao)
{
	String ^ Texto;
	Texto = gcnew String(UmaExpressao.c_str());
	textBoxCodigo->Text += Texto + "\n\r";
}
