#include "TelaCodigo.h"
using namespace CodEasy;


int TelaCodigo::getStatus(void)
{
	return Status;
}

void TelaCodigo::setStatus(int UmStatus)
{
	Status = UmStatus;
}

void TelaCodigo::setNome(string UmNome)
{
	String ^ Texto = gcnew String(UmNome.c_str());
	Nome = Texto;
	delete(Texto);
}

void TelaCodigo::setfolderName(string UmFolderName)
{
	String ^ Texto = gcnew String(UmFolderName.c_str());
	FolderName = Texto;
	delete(Texto);
}

string TelaCodigo::getTextoCodigo(void)
{
	string TextoConvertido;
	MarshalString(TextoCodigo, TextoConvertido);
	for (unsigned int i = 0; i < TextoConvertido.size(); i++)
	{
		if (!isgraph(TextoConvertido[i]))
		{
			TextoConvertido[i] = ' ';
		}
	}
	return TextoConvertido;
}

int TelaCodigo::pesquisarLinha(string UmaExpressao)
{
	string LinhaAuxiliar = ""; 
	int Index = 0;
	int NumeroLinha = 0,
		ExpressaoEncontrada = 0;

	if (UmaExpressao != "")
	{
		while (!isgraph(UmaExpressao[Index]))
		{
			Index++;
		}
		while ((unsigned)Index < UmaExpressao.size())
		{
			LinhaAuxiliar += UmaExpressao[Index];
			Index++;
		}
		UmaExpressao = LinhaAuxiliar;
	}


	String ^ Texto = gcnew String(UmaExpressao.c_str());
	ExpressaoErro = Texto;
	delete(Texto);
	

	if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
		richTextBox1 = (RichTextBox ^)tabControl1->SelectedTab->Controls["richTextBox"];

	ExpressaoEncontrada = richTextBox1->Find(ExpressaoErro, ExpressaoEncontrada + 1, RichTextBoxFinds::MatchCase);

	int Tamanho = UmaExpressao.size() - 1;
	while (ExpressaoEncontrada == -1 && UmaExpressao != "")
	{
		UmaExpressao[Tamanho] = '\0';
		Tamanho--;
		String ^ Texto = gcnew String(UmaExpressao.c_str());
		ExpressaoErro = Texto;
		delete(Texto);
		ExpressaoEncontrada = richTextBox1->Find(ExpressaoErro, ExpressaoEncontrada + 1, RichTextBoxFinds::MatchCase);

	}

	NumeroLinha = richTextBox1->GetLineFromCharIndex(ExpressaoEncontrada);

	if (UmaExpressao == "")
	{
		NumeroLinha = richTextBox1->Lines->Length;
	}
	else
	{
		NumeroLinha++;
	}

	MostraErro = true;

	Linha = NumeroLinha;
	atualizarNumeroLabel();

	return NumeroLinha;
}

void TelaCodigo::criarNovoProjeto(void)
{
	Label ^rotulo = gcnew Label();
	rotulo->BackColor = System::Drawing::Color::DarkRed;
	rotulo->ForeColor = System::Drawing::Color::White;
	rotulo->Dock = DockStyle::Left;
	rotulo->Size = System::Drawing::Size(62, 0);
	rotulo->Name = "rotulo";

	TabPage^ tabPage = gcnew TabPage(Nome + ".sl");
	tabControl1->TabPages->Add(tabPage);
	this->tabControl1->SizeMode = TabSizeMode::Normal;
	this->tabControl1->SelectedTab = tabPage;
	tabPage->BackColor = System::Drawing::Color::DarkRed;
	RichTextBox^ richTextBox2 = gcnew RichTextBox;
	richTextBox2->TextChanged += gcnew System::EventHandler(this, &TelaCodigo::TextChangedDinamico);
	richTextBox2->VScroll += gcnew System::EventHandler(this, &TelaCodigo::ScrollDinamico);
	richTextBox2->FontChanged += gcnew System::EventHandler(this, &TelaCodigo::FontChangedDinamico);

	richTextBox2->Controls->Add(rotulo);
	tabPage->Controls->Add(richTextBox2);
	richTextBox2->Location = Point(0, 52);
	richTextBox2->Multiline = true;
	richTextBox2->WordWrap = false;
	richTextBox2->Dock = DockStyle::Fill;
	richTextBox2->Name = "richTextBox";
	richTextBox2->SelectionIndent = 64;
	richTextBox2->SelectionHangingIndent = 48;
	richTextBox2->SelectionRightIndent = 72;
	richTextBox2->Font = gcnew System::Drawing::Font(richTextBox2->Font->Name, 12, richTextBox2->Font->Style, richTextBox2->Font->Unit);
	rotulo->Font = gcnew System::Drawing::Font(richTextBox2->Font->Name, 12, richTextBox2->Font->Style, richTextBox2->Font->Unit);

	RichTextBox^ TextBoxEndereco = gcnew RichTextBox;
	tabPage->Controls->Add(TextBoxEndereco);
	TextBoxEndereco->Location = Point(0, 52);
	TextBoxEndereco->Multiline = true;
	TextBoxEndereco->WordWrap = false;
	TextBoxEndereco->Dock = DockStyle::Fill;
	TextBoxEndereco->Visible = false;
	TextBoxEndereco->Name = "Endereco";
	String ^ Texto = gcnew String(SubJanela->getfolderName().c_str());
	TextBoxEndereco->Text = Texto;

	RichTextBox^ TextBoxNome = gcnew RichTextBox;
	tabPage->Controls->Add(TextBoxNome);
	TextBoxNome->Location = Point(0, 52);
	TextBoxNome->Multiline = true;
	TextBoxNome->WordWrap = false;
	TextBoxNome->Dock = DockStyle::Fill;
	TextBoxEndereco->Visible = false;
	TextBoxNome->Name = "Nome";
	Texto = gcnew String(SubJanela->getNome().c_str());
	TextBoxNome->Text = Texto;
	delete(Texto);

	ImageList^ lstImages = gcnew ImageList;
	tabControl1->ImageList = lstImages;
	tabPage->ImageIndex = 0;
}

void TelaCodigo::abrirProjeto(void)
{
	Stream ^ myStream;
	System::IO::Path;

	OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog;
	openFileDialog1->Filter = "txt files (* .sl) | * .sl | Todos os arquivos (*.*)|*.*";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog1->FileName->Length > 0)
	{
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			Label ^rotulo = gcnew Label();
			rotulo->BackColor = System::Drawing::Color::DarkRed;
			rotulo->ForeColor = System::Drawing::Color::White;
			rotulo->Dock = DockStyle::Left;
			rotulo->Size = System::Drawing::Size(62, 0);
			rotulo->Name = "rotulo";

			StreamReader ^ Reader = gcnew System::IO::StreamReader(openFileDialog1->FileName);
			TabPage^ tabPage = gcnew TabPage;
			tabControl1->TabPages->Add(tabPage);
			this->tabControl1->SizeMode = TabSizeMode::Normal;
			this->tabControl1->SelectedTab = tabPage;
			tabControl1->SelectedTab->Text = Nome + ".sl";
			RichTextBox^ richTextBox2 = gcnew RichTextBox;
			richTextBox2->TextChanged += gcnew System::EventHandler(this, &TelaCodigo::TextChangedDinamico);
			richTextBox2->VScroll += gcnew System::EventHandler(this, &TelaCodigo::ScrollDinamico);
			richTextBox2->FontChanged += gcnew System::EventHandler(this, &TelaCodigo::FontChangedDinamico);

			richTextBox2->Controls->Add(rotulo);
			tabPage->Controls->Add(richTextBox2);
			richTextBox2->Location = Point(0, 52);
			richTextBox2->Multiline = true;
			richTextBox2->WordWrap = false;
			richTextBox2->Name = "richTextBox";
			richTextBox2->Dock = DockStyle::Fill;
			richTextBox2->SelectionIndent = 64;
			richTextBox2->SelectionHangingIndent = 48;
			richTextBox2->SelectionRightIndent = 72;
			richTextBox2->Font = gcnew System::Drawing::Font(richTextBox2->Font->Name, 12, richTextBox2->Font->Style, richTextBox2->Font->Unit);
			rotulo->Font = gcnew System::Drawing::Font(richTextBox2->Font->Name, 12, richTextBox2->Font->Style, richTextBox2->Font->Unit);

			RichTextBox^ TextBoxEndereco = gcnew RichTextBox;
			tabPage->Controls->Add(TextBoxEndereco);
			TextBoxEndereco->Location = Point(0, 52);
			TextBoxEndereco->Multiline = true;
			TextBoxEndereco->WordWrap = false;
			TextBoxEndereco->Dock = DockStyle::Fill;
			TextBoxEndereco->Visible = false;
			TextBoxEndereco->Name = "Endereco";
			TextBoxEndereco->Text = Path::GetDirectoryName(openFileDialog1->FileName);

			RichTextBox^ TextBoxNome = gcnew RichTextBox;
			tabPage->Controls->Add(TextBoxNome);
			TextBoxNome->Location = Point(0, 52);
			TextBoxNome->Multiline = true;
			TextBoxNome->WordWrap = false;
			TextBoxNome->Dock = DockStyle::Fill;
			TextBoxEndereco->Visible = false;
			TextBoxNome->Name = "Nome";
			TextBoxNome->Text = Path::GetFileNameWithoutExtension(openFileDialog1->FileName);

			ImageList^ lstImages = gcnew ImageList;
			tabControl1->ImageList = lstImages;
			tabPage->ImageIndex = 0;

			richTextBox2->LoadFile(openFileDialog1->FileName, RichTextBoxStreamType::PlainText);
			tabControl1->SelectedTab->Text = Path::GetFileName(openFileDialog1->FileName);
			Reader->Close();

			if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
				richTextBox2 = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

			int Tamanho = richTextBox2->Text->Length;
			int PosicaoAnterior = 0;
			PosicaoAnterior = richTextBox2->SelectionStart;

			alterarTodotexto(0, PosicaoAnterior, richTextBox2);
			TamanhoTexto = Tamanho;
			richTextBox2->SelectionStart = PosicaoAnterior;
			richTextBox2->SelectionLength = 0;
		}
		myStream->Close();
	}
}

void TelaCodigo::apagarErro(void)
{
	if (this->tabControl1->SelectedIndex >= 0)
	{
		RichTextBox ^ richtextbox4;
		Label ^ rotulo1;
		Label ^ rotulo3;

		if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
			richtextbox4 = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

		if (richtextbox4->Controls->ContainsKey("rotulo"))
			rotulo1 = (Label^)richtextbox4->Controls["rotulo"];

		if (rotulo1->Controls->ContainsKey("RotuloErro"))
			rotulo3 = (Label^)rotulo1->Controls["RotuloErro"];
		delete(rotulo3);
	}
}

void TelaCodigo::atualizarNumeroLabel(void)
{
	float ValorY = 0;
	RichTextBox ^ richtextbox4 = gcnew RichTextBox();
	Label ^ rotulo3 = gcnew Label();
	rotulo3->Name = "RotuloErro";

	Label ^ rotulo1 = gcnew Label();

	if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
		richtextbox4 = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

	if (richtextbox4->Controls->ContainsKey("rotulo"))
		rotulo1 = (Label^)richtextbox4->Controls["rotulo"];

	Point pos = Point(0, 0);
	int firstIndex = richtextbox4->GetCharIndexFromPosition(pos);
	int firstLine = richtextbox4->GetLineFromCharIndex(firstIndex);

	pos.X = ClientRectangle.Width;
	pos.Y = ClientRectangle.Height;
	int lastIndex = richtextbox4->GetCharIndexFromPosition(pos);
	int lastLine = richtextbox4->GetLineFromCharIndex(lastIndex);

	pos = richtextbox4->GetPositionFromCharIndex(lastIndex);


	if (Linha == -1)
	{
		if (rotulo1->Controls->ContainsKey("RotuloErro"))
			rotulo3 = (Label^)rotulo1->Controls["RotuloErro"];
		delete(rotulo3);
	}

	rotulo1->Text = "";
	for (int i = firstLine; i <= lastLine +1; i++)
	{
		if (Linha == -1)
		{
			rotulo1->Text += i + 1 + "\n";
		}
		else
		{
			if (i == Linha - 1)
			{
				if (ValorY < rotulo1->Font->Height * 6)
				{
					ValorY += rotulo1->Font->Height - 12;
				}
				else if (ValorY > rotulo1->Font->Height * 14 && ValorY < rotulo1->Font->Height * 29)
				{
					ValorY += rotulo1->Font->Height + 8;
				}
				else
				{
					ValorY += rotulo1->Font->Height - 4;
				}

				rotulo1->Text += i + 1 + "\n";
				rotulo3->BackColor = System::Drawing::Color::Red;
				rotulo3->Size = System::Drawing::Size(10, 10);
				rotulo3->Location = Point(50, ValorY);
				rotulo1->Controls->Add(rotulo3);
			}
			else
			{
				rotulo1->Text += i + 1 + "\n";
				ValorY += rotulo1->Font->Height;
			}
		}
	}
}

void TelaCodigo::mudarCorPalavraChave(int posicao, int qtd, int pos, RichTextBox ^textBox1)
{

	textBox1->SelectionStart = posicao;
	textBox1->SelectionLength = qtd;
	textBox1->SelectionColor = System::Drawing::Color::Red;
	textBox1->SelectionStart = pos;
	textBox1->SelectionLength = 0;
	textBox1->SelectionColor = System::Drawing::Color::Black;

}

void TelaCodigo::mudarCorPreto(int posicao, int qtd, int pos, RichTextBox ^textBox1)
{
	textBox1->SelectionStart = posicao;
	textBox1->SelectionLength = qtd;
	textBox1->SelectionColor = System::Drawing::Color::Black;
	textBox1->SelectionStart = pos;
	textBox1->SelectionLength = 0;
	textBox1->SelectionColor = System::Drawing::Color::Black;

}

void TelaCodigo::pesquisarPalavra(int PosicaoInicial, int PosicaoAnterior, RichTextBox ^textBox1)
{
	int posicao = 0;
	int PosicaoFinal = 0;
	int Index = 0;
	String^ str = textBox1->Text;
	string UmTexto;
	bool Maiuscula = false,
		CaracterInvalido = false;
	int CaracterAscii = 0;

	MarshalString(str, UmTexto);

	if (textBox1->Text->Length >= 1)
	{
		if (PosicaoInicial > 0 && PosicaoInicial <= textBox1->Text->Length)
		{
			PosicaoInicial--;
		}
		CaracterAscii = UmTexto[PosicaoInicial];
		if (CaracterAscii < 0 || CaracterAscii > 127)
		{
			CaracterInvalido = true;
		}
		while ((CaracterAscii > 0 && CaracterAscii < 127) && (PosicaoInicial > 0 && (PosicaoInicial <= textBox1->Text->Length) && (isgraph(UmTexto[PosicaoInicial]))))
		{
			PosicaoInicial--;
			CaracterAscii = UmTexto[PosicaoInicial];
			if (CaracterAscii < 0 || CaracterAscii > 127)
			{
				CaracterInvalido = true;
			}
		}

		if (PosicaoInicial > 0)
		{
			PosicaoInicial++;
			PosicaoFinal = PosicaoInicial;
			PosicaoInicial--;
		}
		else
		{
			PosicaoFinal = PosicaoInicial;
		}

		CaracterAscii = UmTexto[PosicaoFinal];
		if (CaracterAscii < 0 || CaracterAscii > 127)
		{
			CaracterInvalido = true;
		}
		while ((CaracterAscii > 0 && CaracterAscii < 127) && (PosicaoFinal < (int)UmTexto.size() && isgraph(UmTexto[PosicaoFinal])))
		{
			PosicaoFinal++;
			CaracterAscii = UmTexto[PosicaoFinal];
			if (CaracterAscii < 0 || CaracterAscii > 127)
			{
				CaracterInvalido = true;
			}
		}
		if (!CaracterInvalido)
		{
			for (int i = PosicaoInicial; i < PosicaoFinal; ++i)
			{
				if (isupper(UmTexto[i]))
				{
					Maiuscula = true;
				}
			}

			if (!Maiuscula)
			{

				posicao = textBox1->Find("inteiro", PosicaoInicial, PosicaoFinal, RichTextBoxFinds::NoHighlight);
				Index = posicao;

				while (Index >= 0 && UmTexto[Index] != '(' && UmTexto[Index] != ';' && UmTexto[Index] != ')')
				{
					Index--;
				}

				if (Index < 0 || UmTexto[Index] != '(')
				{
					if (posicao > -1 && ((posicao + 7 < (int)UmTexto.size() && (ispunct(UmTexto[posicao + 7]) || !isgraph(UmTexto[posicao + 7]))) || posicao + 6 < (int)UmTexto.size()) &&
						((posicao - 1 >= 0 && (ispunct(UmTexto[posicao - 1]) || !isgraph(UmTexto[posicao - 1]))) || posicao == 0))
					{
						mudarCorPalavraChave(posicao, 7, PosicaoAnterior, textBox1);
						if (posicao - 1 >= 0 && ispunct(UmTexto[posicao - 1]))
						{
							mudarCorPreto(posicao - 1, 1, PosicaoAnterior, textBox1);
						}
					}
					else
					{
						posicao = textBox1->Find("se", PosicaoInicial, PosicaoFinal, RichTextBoxFinds::NoHighlight);

						Index = posicao;

						while (Index >= 0 && UmTexto[Index] != '(' && UmTexto[Index] != ';' && UmTexto[Index] != ')')
						{
							Index--;
						}

						if (Index < 0 || UmTexto[Index] != '(')
						{
							if (posicao > -1 && ((posicao + 2 < (int)UmTexto.size() && (ispunct(UmTexto[posicao + 2]) || !isgraph(UmTexto[posicao + 2]))) || posicao + 1 < (int)UmTexto.size()) &&
								((posicao - 1 >= 0 && (ispunct(UmTexto[posicao - 1]) || !isgraph(UmTexto[posicao - 1]))) || posicao == 0))
							{
								mudarCorPalavraChave(posicao, 2, PosicaoAnterior, textBox1);
								if (posicao - 1 >= 0 && ispunct(UmTexto[posicao - 1]))
								{
									mudarCorPreto(posicao - 1, 1, PosicaoAnterior, textBox1);
								}
							}
							else
							{
								posicao = textBox1->Find("enquanto", PosicaoInicial, PosicaoFinal, RichTextBoxFinds::NoHighlight);

								Index = posicao;
								while (Index >= 0 && UmTexto[Index] != '(' && UmTexto[Index] != ';' && UmTexto[Index] != ')')
								{
									Index--;
								}

								if (Index < 0 || UmTexto[Index] != '(')
								{
									if (posicao > -1 && ((posicao + 8 < (int)UmTexto.size() && (ispunct(UmTexto[posicao + 8]) || !isgraph(UmTexto[posicao + 8]))) || posicao + 7 < (int)UmTexto.size()) &&
										((posicao - 1 >= 0 && (ispunct(UmTexto[posicao - 1]) || !isgraph(UmTexto[posicao - 1]))) || posicao == 0))
									{
										mudarCorPalavraChave(posicao, 8, PosicaoAnterior, textBox1);
										if (posicao - 1 >= 0 && ispunct(UmTexto[posicao - 1]))
										{
											mudarCorPreto(posicao - 1, 1, PosicaoAnterior, textBox1);
										}
									}
									else
									{
										posicao = textBox1->Find("ler", PosicaoInicial, PosicaoFinal, RichTextBoxFinds::NoHighlight);

										Index = posicao;
										while (Index >= 0 && UmTexto[Index] != '(' && UmTexto[Index] != ';' && UmTexto[Index] != ')')
										{
											Index--;
										}

										if (Index < 0 || UmTexto[Index] != '(')
										{
											if (posicao > -1 && ((posicao + 3 < (int)UmTexto.size() && (ispunct(UmTexto[posicao + 3]) || !isgraph(UmTexto[posicao + 3]))) || posicao + 2 < (int)UmTexto.size()) &&
												((posicao - 1 >= 0 && (ispunct(UmTexto[posicao - 1]) || !isgraph(UmTexto[posicao - 1]))) || posicao == 0))
											{
												mudarCorPalavraChave(posicao, 3, PosicaoAnterior, textBox1);
												if (posicao - 1 >= 0 && ispunct(UmTexto[posicao - 1]))
												{
													mudarCorPreto(posicao - 1, 1, PosicaoAnterior, textBox1);
												}
											}
											else
											{
												posicao = textBox1->Find("escrever", PosicaoInicial, PosicaoFinal, RichTextBoxFinds::NoHighlight);

												Index = posicao;
												while (Index >= 0 && UmTexto[Index] != '(' && UmTexto[Index] != ';' && UmTexto[Index] != ')')
												{
													Index--;
												}

												if (Index < 0 || UmTexto[Index] != '(')
												{
													if (posicao > -1 && ((posicao + 8 < (int)UmTexto.size() && (ispunct(UmTexto[posicao + 8]) || !isgraph(UmTexto[posicao + 8]))) || posicao + 7 < (int)UmTexto.size()) &&
														((posicao - 1 >= 0 && (ispunct(UmTexto[posicao - 1]) || !isgraph(UmTexto[posicao - 1]))) || posicao == 0))
													{
														mudarCorPalavraChave(posicao, 8, PosicaoAnterior, textBox1);
														if (posicao - 1 >= 0 && ispunct(UmTexto[posicao - 1]))
														{
															mudarCorPreto(posicao - 1, 1, PosicaoAnterior, textBox1);
														}
													}
													else
													{
														mudarCorPreto(PosicaoInicial, PosicaoFinal - PosicaoInicial + 1, PosicaoAnterior, textBox1);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void TelaCodigo::alterarTodotexto(int PosicaoInicial, int posicaoAnterior, RichTextBox ^textBox1)
{
	String^ str = textBox1->Text;
	string UmTexto;
	bool Maiuscula = false;
	int Index = 0,
		Tamanho = 0;
	MarshalString(str, UmTexto);
	posicaoAnterior = textBox1->SelectionStart;



	if (textBox1->Text->Length > 1)
	{
		mudarCorPreto(0, textBox1->Text->Length - 1, posicaoAnterior, textBox1);

		while (PosicaoInicial > -1)
		{
			if (textBox1->Text->Length > PosicaoInicial && PosicaoInicial > -1)
			{
				PosicaoInicial = textBox1->Find("inteiro", PosicaoInicial, textBox1->Text->Length, RichTextBoxFinds::NoHighlight);
				if (PosicaoInicial > -1)
				{
					for (int i = PosicaoInicial; i < PosicaoInicial + 7; ++i)
					{
						if (isupper(UmTexto[i]))
						{
							Maiuscula = true;
						}
					}
					if (!Maiuscula)
					{
						mudarCorPalavraChave(PosicaoInicial, 7, posicaoAnterior, textBox1);
						if (PosicaoInicial - 1 >= 0 && (!ispunct(UmTexto[PosicaoInicial - 1]) && isgraph(UmTexto[PosicaoInicial - 1])))
						{
							mudarCorPreto(PosicaoInicial, 7, posicaoAnterior, textBox1);
						}
						if ((unsigned)PosicaoInicial + 7 < UmTexto.size() && (!ispunct(UmTexto[PosicaoInicial + 7]) && isgraph(UmTexto[PosicaoInicial + 7])))
						{
							mudarCorPreto(PosicaoInicial, 7, posicaoAnterior, textBox1);
						}
					}
					Maiuscula = false;
					PosicaoInicial++;
				}

			}

		}
		PosicaoInicial = 0;
		while (PosicaoInicial > -1)
		{
			if (textBox1->Text->Length > PosicaoInicial && PosicaoInicial > -1)
			{
				PosicaoInicial = textBox1->Find("se", PosicaoInicial, textBox1->Text->Length, RichTextBoxFinds::NoHighlight);
				if (PosicaoInicial > -1)
				{
					for (int i = PosicaoInicial; i < PosicaoInicial + 2; ++i)
					{
						if (isupper(UmTexto[i]))
						{
							Maiuscula = true;
						}
					}
					if (!Maiuscula)
					{
						mudarCorPalavraChave(PosicaoInicial, 2, posicaoAnterior, textBox1);
						if (PosicaoInicial - 1 >= 0 && (!ispunct(UmTexto[PosicaoInicial - 1]) && isgraph(UmTexto[PosicaoInicial - 1])))
						{
							mudarCorPreto(PosicaoInicial, 2, posicaoAnterior, textBox1);
						}
						if ((unsigned)PosicaoInicial + 2 < UmTexto.size() && (!ispunct(UmTexto[PosicaoInicial + 2]) && isgraph(UmTexto[PosicaoInicial + 2])))
						{
							mudarCorPreto(PosicaoInicial, 2, posicaoAnterior, textBox1);
						}
					}
					Maiuscula = false;
					PosicaoInicial++;
				}
			}

		}
		PosicaoInicial = 0;
		while (PosicaoInicial > -1)
		{
			if (textBox1->Text->Length > PosicaoInicial && PosicaoInicial > -1)
			{
				PosicaoInicial = textBox1->Find("enquanto", PosicaoInicial, textBox1->Text->Length, RichTextBoxFinds::NoHighlight);
				if (PosicaoInicial > -1)
				{
					for (int i = PosicaoInicial; i < PosicaoInicial + 8; ++i)
					{
						if (isupper(UmTexto[i]))
						{
							Maiuscula = true;
						}
					}

					if (!Maiuscula)
					{
						mudarCorPalavraChave(PosicaoInicial, 8, posicaoAnterior, textBox1);
						if (PosicaoInicial - 1 >= 0 && (!ispunct(UmTexto[PosicaoInicial - 1]) && isgraph(UmTexto[PosicaoInicial - 1])))
						{

							mudarCorPreto(PosicaoInicial, 8, posicaoAnterior, textBox1);
						}
						if ((unsigned)PosicaoInicial + 8 < UmTexto.size() && (!ispunct(UmTexto[PosicaoInicial + 8]) && isgraph(UmTexto[PosicaoInicial + 8])))
						{

							mudarCorPreto(PosicaoInicial, 8, posicaoAnterior, textBox1);
						}
					}
					Maiuscula = false;
					PosicaoInicial++;
				}
			}

		}

		PosicaoInicial = 0;
		while (PosicaoInicial > -1)
		{
			if (textBox1->Text->Length > PosicaoInicial && PosicaoInicial > -1)
			{
				PosicaoInicial = textBox1->Find("ler", PosicaoInicial, textBox1->Text->Length, RichTextBoxFinds::NoHighlight);
				if (PosicaoInicial > -1)
				{
					for (int i = PosicaoInicial; i < PosicaoInicial + 3; ++i)
					{
						if (isupper(UmTexto[i]))
						{
							Maiuscula = true;
						}
					}

					if (!Maiuscula)
					{
						mudarCorPalavraChave(PosicaoInicial, 3, posicaoAnterior, textBox1);
						if (PosicaoInicial - 1 >= 0 && (!ispunct(UmTexto[PosicaoInicial - 1]) && isgraph(UmTexto[PosicaoInicial - 1])))
						{
							mudarCorPreto(PosicaoInicial, 3, posicaoAnterior, textBox1);
						}
						if ((unsigned)PosicaoInicial + 3 < UmTexto.size() && (!ispunct(UmTexto[PosicaoInicial + 3]) && isgraph(UmTexto[PosicaoInicial + 3])))
						{
							mudarCorPreto(PosicaoInicial, 3, posicaoAnterior, textBox1);
						}
					}
					Maiuscula = false;
					PosicaoInicial++;
				}
			}
		}

		PosicaoInicial = 0;
		while (PosicaoInicial > -1)
		{
			if (textBox1->Text->Length > PosicaoInicial && PosicaoInicial > -1)
			{
				PosicaoInicial = textBox1->Find("escrever", PosicaoInicial, textBox1->Text->Length, RichTextBoxFinds::NoHighlight);
				if (PosicaoInicial > -1)
				{
					for (int i = PosicaoInicial; i < PosicaoInicial + 8; ++i)
					{
						if (isupper(UmTexto[i]))
						{
							Maiuscula = true;
						}
					}

					if (!Maiuscula)
					{
						mudarCorPalavraChave(PosicaoInicial, 8, posicaoAnterior, textBox1);
						if (PosicaoInicial - 1 >= 0 && (!ispunct(UmTexto[PosicaoInicial - 1]) && isgraph(UmTexto[PosicaoInicial - 1])))
						{
							mudarCorPreto(PosicaoInicial, 8, posicaoAnterior, textBox1);
						}
						if ((unsigned)PosicaoInicial + 8 < UmTexto.size() && (!ispunct(UmTexto[PosicaoInicial + 8]) && isgraph(UmTexto[PosicaoInicial + 8])))
						{
							mudarCorPreto(PosicaoInicial, 8, posicaoAnterior, textBox1);
						}
					}
					Maiuscula = false;
					PosicaoInicial++;
				}
			}
		}
		PosicaoInicial = 0;

		while (PosicaoInicial > -1)
		{
			if (textBox1->Text->Length > PosicaoInicial && PosicaoInicial > -1)
			{
				PosicaoInicial = textBox1->Find("(", PosicaoInicial, textBox1->Text->Length, RichTextBoxFinds::NoHighlight);
				if (PosicaoInicial > -1)
				{
					Index = PosicaoInicial;

					while ((unsigned)Index < UmTexto.size() && UmTexto[Index] != ')' && UmTexto[Index] != ';' && UmTexto[Index] != ')')
					{
						Index++;
					}
					Tamanho = Index - PosicaoInicial;

					mudarCorPreto(PosicaoInicial, Tamanho, posicaoAnterior, textBox1);
					PosicaoInicial++;
				}
			}
		}
	}
}