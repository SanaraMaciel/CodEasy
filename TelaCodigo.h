#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "NovoProjeto.h"
#include "Sobre.h"


namespace CodEasy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for TelaCodigo
	/// </summary>

	public ref class TelaCodigo : public System::Windows::Forms::Form
	{
	public:
		TelaCodigo(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Status = -1;
			TamanhoTexto = 0;
			TextoCodigo = "";
			Nome = "";
			FolderName = "";
			Caminho = "";
			ExpressaoErro = "";
			MostraErro = false;
			Linha = -1;
		}
		int    getStatus(void);
		void   setStatus(int);
		void   setNome(string);
		void   setfolderName(string);
		string getTextoCodigo();
		void   mudarCorPalavraChave(int, int, int, RichTextBox ^);
		void   mudarCorPreto(int, int, int, RichTextBox ^);
		void   pesquisarPalavra(int, int, RichTextBox^);
		void   alterarTodotexto(int, int, RichTextBox ^);
		void   criarNovoProjeto(void);
		void   abrirProjeto(void);
		void   atualizarNumeroLabel(void);
		int    pesquisarLinha(string);
		void   apagarErro(void);

		void MarshalString(String ^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	private: System::Windows::Forms::ToolStripMenuItem^  selecionarTudoToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator8;
	private: System::Windows::Forms::ToolStripMenuItem^  copiarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  recortarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator9;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TabControl^  Comando;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::RichTextBox^  richTextBoxComando;
	private: System::Windows::Forms::ToolStripMenuItem^  interpretaçãoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabelInterpretar;


	private: System::Windows::Forms::ToolStripMenuItem^  fonteToolStripMenuItem;

	public:
			
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		
		~TelaCodigo()
		{
			if (components)
			{
				delete components;
			}
			delete(SubJanela);
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  arquivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  construirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ferramentasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  novoProjetoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirProjetoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  salvarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  salvarComoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  limparToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  compilarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  comandosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  blogToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripButton5;
	private: System::Windows::Forms::ToolStripMenuItem^  fundoToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		String ^ Nome;
		String ^ FolderName;
		String ^ TextoCodigo;
		String ^ Caminho;
		String ^ ExpressaoErro;
		int      Status;
		int      TamanhoTexto;
		int      Linha;
		bool     MostraErro;

		NovoProjeto ^ SubJanela = gcnew NovoProjeto();

private: System::Windows::Forms::TabPage ^ tabPage1;
private: System::Windows::Forms::RichTextBox ^ richTextBox1;
private: System::Windows::Forms::TabControl ^ tabControl1;
		 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TelaCodigo::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->arquivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->novoProjetoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->abrirProjetoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->salvarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salvarComoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->sairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->limparToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->selecionarTudoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->copiarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->recortarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->construirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->compilarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->interpretaçãoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ferramentasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fundoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator9 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->fonteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ajudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comandosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->blogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel3 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabelInterpretar = (gcnew System::Windows::Forms::ToolStripLabel());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Comando = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBoxComando = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->Comando->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->arquivoToolStripMenuItem,
					this->editarToolStripMenuItem, this->construirToolStripMenuItem, this->ferramentasToolStripMenuItem, this->ajudaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(660, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// arquivoToolStripMenuItem
			// 
			this->arquivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->novoProjetoToolStripMenuItem,
					this->toolStripSeparator5, this->abrirProjetoToolStripMenuItem, this->toolStripSeparator1, this->salvarToolStripMenuItem, this->salvarComoToolStripMenuItem,
					this->toolStripSeparator2, this->sairToolStripMenuItem
			});
			this->arquivoToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->arquivoToolStripMenuItem->Name = L"arquivoToolStripMenuItem";
			this->arquivoToolStripMenuItem->Size = System::Drawing::Size(69, 23);
			this->arquivoToolStripMenuItem->Text = L"Arquivo";
			// 
			// novoProjetoToolStripMenuItem
			// 
			this->novoProjetoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"novoProjetoToolStripMenuItem.Image")));
			this->novoProjetoToolStripMenuItem->Name = L"novoProjetoToolStripMenuItem";
			this->novoProjetoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->novoProjetoToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->novoProjetoToolStripMenuItem->Text = L"Novo Projeto";
			this->novoProjetoToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::novoProjetoToolStripMenuItem_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(207, 6);
			// 
			// abrirProjetoToolStripMenuItem
			// 
			this->abrirProjetoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"abrirProjetoToolStripMenuItem.Image")));
			this->abrirProjetoToolStripMenuItem->Name = L"abrirProjetoToolStripMenuItem";
			this->abrirProjetoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->abrirProjetoToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->abrirProjetoToolStripMenuItem->Text = L"Abrir Projeto";
			this->abrirProjetoToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::abrirProjetoToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(207, 6);
			// 
			// salvarToolStripMenuItem
			// 
			this->salvarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"salvarToolStripMenuItem.Image")));
			this->salvarToolStripMenuItem->Name = L"salvarToolStripMenuItem";
			this->salvarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->salvarToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->salvarToolStripMenuItem->Text = L"Salvar";
			this->salvarToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::salvarToolStripMenuItem_Click);
			// 
			// salvarComoToolStripMenuItem
			// 
			this->salvarComoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"salvarComoToolStripMenuItem.Image")));
			this->salvarComoToolStripMenuItem->Name = L"salvarComoToolStripMenuItem";
			this->salvarComoToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->salvarComoToolStripMenuItem->Text = L"Salvar Como...";
			this->salvarComoToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::salvarComoToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(207, 6);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sairToolStripMenuItem.Image")));
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::S));
			this->sairToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::sairToolStripMenuItem_Click);
			// 
			// editarToolStripMenuItem
			// 
			this->editarToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->limparToolStripMenuItem,
					this->selecionarTudoToolStripMenuItem, this->toolStripSeparator8, this->copiarToolStripMenuItem, this->recortarToolStripMenuItem,
					this->colarToolStripMenuItem
			});
			this->editarToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->editarToolStripMenuItem->Name = L"editarToolStripMenuItem";
			this->editarToolStripMenuItem->Size = System::Drawing::Size(56, 23);
			this->editarToolStripMenuItem->Text = L"Editar";
			// 
			// limparToolStripMenuItem
			// 
			this->limparToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"limparToolStripMenuItem.Image")));
			this->limparToolStripMenuItem->Name = L"limparToolStripMenuItem";
			this->limparToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::L));
			this->limparToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->limparToolStripMenuItem->Text = L"Limpar";
			this->limparToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::limparToolStripMenuItem_Click);
			// 
			// selecionarTudoToolStripMenuItem
			// 
			this->selecionarTudoToolStripMenuItem->Name = L"selecionarTudoToolStripMenuItem";
			this->selecionarTudoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::T));
			this->selecionarTudoToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->selecionarTudoToolStripMenuItem->Text = L"Selecionar Tudo";
			this->selecionarTudoToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::selecionarTudoToolStripMenuItem_Click);
			// 
			// toolStripSeparator8
			// 
			this->toolStripSeparator8->Name = L"toolStripSeparator8";
			this->toolStripSeparator8->Size = System::Drawing::Size(219, 6);
			// 
			// copiarToolStripMenuItem
			// 
			this->copiarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"copiarToolStripMenuItem.Image")));
			this->copiarToolStripMenuItem->Name = L"copiarToolStripMenuItem";
			this->copiarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copiarToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->copiarToolStripMenuItem->Text = L"Copiar";
			this->copiarToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::copiarToolStripMenuItem_Click);
			// 
			// recortarToolStripMenuItem
			// 
			this->recortarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"recortarToolStripMenuItem.Image")));
			this->recortarToolStripMenuItem->Name = L"recortarToolStripMenuItem";
			this->recortarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->recortarToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->recortarToolStripMenuItem->Text = L"Recortar";
			this->recortarToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::recortarToolStripMenuItem_Click);
			// 
			// colarToolStripMenuItem
			// 
			this->colarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"colarToolStripMenuItem.Image")));
			this->colarToolStripMenuItem->Name = L"colarToolStripMenuItem";
			this->colarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->colarToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->colarToolStripMenuItem->Text = L"Colar";
			this->colarToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::colarToolStripMenuItem_Click);
			// 
			// construirToolStripMenuItem
			// 
			this->construirToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->compilarToolStripMenuItem,
					this->interpretaçãoToolStripMenuItem
			});
			this->construirToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->construirToolStripMenuItem->Name = L"construirToolStripMenuItem";
			this->construirToolStripMenuItem->Size = System::Drawing::Size(78, 23);
			this->construirToolStripMenuItem->Text = L"Construir";
			// 
			// compilarToolStripMenuItem
			// 
			this->compilarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"compilarToolStripMenuItem.Image")));
			this->compilarToolStripMenuItem->Name = L"compilarToolStripMenuItem";
			this->compilarToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F9;
			this->compilarToolStripMenuItem->Size = System::Drawing::Size(176, 24);
			this->compilarToolStripMenuItem->Text = L"Executar";
			this->compilarToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::compilarToolStripMenuItem_Click);
			// 
			// interpretaçãoToolStripMenuItem
			// 
			this->interpretaçãoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"interpretaçãoToolStripMenuItem.Image")));
			this->interpretaçãoToolStripMenuItem->Name = L"interpretaçãoToolStripMenuItem";
			this->interpretaçãoToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F10;
			this->interpretaçãoToolStripMenuItem->Size = System::Drawing::Size(176, 24);
			this->interpretaçãoToolStripMenuItem->Text = L"Interpretar";
			this->interpretaçãoToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::interpretaçãoToolStripMenuItem_Click);
			// 
			// ferramentasToolStripMenuItem
			// 
			this->ferramentasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fundoToolStripMenuItem,
					this->toolStripSeparator9, this->fonteToolStripMenuItem
			});
			this->ferramentasToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->ferramentasToolStripMenuItem->Name = L"ferramentasToolStripMenuItem";
			this->ferramentasToolStripMenuItem->Size = System::Drawing::Size(97, 23);
			this->ferramentasToolStripMenuItem->Text = L"Ferramentas";
			// 
			// fundoToolStripMenuItem
			// 
			this->fundoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fundoToolStripMenuItem.Image")));
			this->fundoToolStripMenuItem->Name = L"fundoToolStripMenuItem";
			this->fundoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::C));
			this->fundoToolStripMenuItem->Size = System::Drawing::Size(250, 24);
			this->fundoToolStripMenuItem->Text = L"Cor do Fundo";
			this->fundoToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::fundoToolStripMenuItem_Click);
			// 
			// toolStripSeparator9
			// 
			this->toolStripSeparator9->Name = L"toolStripSeparator9";
			this->toolStripSeparator9->Size = System::Drawing::Size(247, 6);
			// 
			// fonteToolStripMenuItem
			// 
			this->fonteToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fonteToolStripMenuItem.Image")));
			this->fonteToolStripMenuItem->Name = L"fonteToolStripMenuItem";
			this->fonteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::F));
			this->fonteToolStripMenuItem->Size = System::Drawing::Size(250, 24);
			this->fonteToolStripMenuItem->Text = L"Fonte";
			this->fonteToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::fonteToolStripMenuItem_Click);
			// 
			// ajudaToolStripMenuItem
			// 
			this->ajudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->comandosToolStripMenuItem,
					this->toolStripSeparator3, this->blogToolStripMenuItem, this->toolStripSeparator4, this->sobreToolStripMenuItem
			});
			this->ajudaToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->ajudaToolStripMenuItem->Name = L"ajudaToolStripMenuItem";
			this->ajudaToolStripMenuItem->Size = System::Drawing::Size(56, 23);
			this->ajudaToolStripMenuItem->Text = L"Ajuda";
			// 
			// comandosToolStripMenuItem
			// 
			this->comandosToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"comandosToolStripMenuItem.Image")));
			this->comandosToolStripMenuItem->Name = L"comandosToolStripMenuItem";
			this->comandosToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::C));
			this->comandosToolStripMenuItem->Size = System::Drawing::Size(198, 24);
			this->comandosToolStripMenuItem->Text = L"Comandos";
			this->comandosToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::comandosToolStripMenuItem_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(195, 6);
			// 
			// blogToolStripMenuItem
			// 
			this->blogToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blogToolStripMenuItem.Image")));
			this->blogToolStripMenuItem->Name = L"blogToolStripMenuItem";
			this->blogToolStripMenuItem->Size = System::Drawing::Size(198, 24);
			this->blogToolStripMenuItem->Text = L"Blog";
			this->blogToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::blogToolStripMenuItem_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(195, 6);
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sobreToolStripMenuItem.Image")));
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(198, 24);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaCodigo::sobreToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->toolStripButton1,
					this->toolStripSeparator6, this->toolStripButton2, this->toolStripSeparator7, this->toolStripButton3, this->toolStripButton4,
					this->toolStripButton5, this->toolStripLabel3, this->toolStripLabelInterpretar
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 27);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(660, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"Novo Projeto";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &TelaCodigo::toolStripButton1_Click);
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"Abrir Projeto";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &TelaCodigo::toolStripButton2_Click);
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 22);
			this->toolStripButton3->Text = L"Salvar";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &TelaCodigo::toolStripButton3_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(23, 22);
			this->toolStripButton4->Text = L"Salvar como...";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &TelaCodigo::toolStripButton4_Click);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripLabel3
			// 
			this->toolStripLabel3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->toolStripLabel3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripLabel3.Image")));
			this->toolStripLabel3->Name = L"toolStripLabel3";
			this->toolStripLabel3->Size = System::Drawing::Size(140, 22);
			this->toolStripLabel3->Text = L"Executar Programa";
			this->toolStripLabel3->Click += gcnew System::EventHandler(this, &TelaCodigo::toolStripLabel3_Click);
			// 
			// toolStripLabelInterpretar
			// 
			this->toolStripLabelInterpretar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->toolStripLabelInterpretar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripLabelInterpretar.Image")));
			this->toolStripLabelInterpretar->Name = L"toolStripLabelInterpretar";
			this->toolStripLabelInterpretar->Size = System::Drawing::Size(155, 22);
			this->toolStripLabelInterpretar->Text = L"Interpretar Programa";
			this->toolStripLabelInterpretar->Click += gcnew System::EventHandler(this, &TelaCodigo::toolStripLabelInterpretar_Click);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->richTextBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(522, 223);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Location = System::Drawing::Point(3, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(516, 217);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->DrawMode = System::Windows::Forms::TabDrawMode::OwnerDrawFixed;
			this->tabControl1->Location = System::Drawing::Point(127, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(530, 249);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 2;
			this->tabControl1->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &TelaCodigo::tabControl1_DrawItem);
			this->tabControl1->TabIndexChanged += gcnew System::EventHandler(this, &TelaCodigo::tabControl1_TabIndexChanged);
			this->tabControl1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TelaCodigo::tabControl1_KeyPress);
			this->tabControl1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TelaCodigo::tabControl1_MouseDown);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tabControl1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->Comando, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->GrowStyle = System::Windows::Forms::TableLayoutPanelGrowStyle::AddColumns;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 52);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(660, 255);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// Comando
			// 
			this->Comando->Controls->Add(this->tabPage2);
			this->Comando->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Comando->DrawMode = System::Windows::Forms::TabDrawMode::OwnerDrawFixed;
			this->Comando->ItemSize = System::Drawing::Size(96, 18);
			this->Comando->Location = System::Drawing::Point(3, 3);
			this->Comando->Name = L"Comando";
			this->Comando->SelectedIndex = 0;
			this->Comando->Size = System::Drawing::Size(118, 249);
			this->Comando->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->Comando->TabIndex = 3;
			this->Comando->Visible = false;
			this->Comando->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &TelaCodigo::Comando_DrawItem);
			this->Comando->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TelaCodigo::Comando_MouseDown);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBoxComando);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(110, 223);
			this->tabPage2->TabIndex = 0;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// richTextBoxComando
			// 
			this->richTextBoxComando->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxComando->Location = System::Drawing::Point(3, 3);
			this->richTextBoxComando->Name = L"richTextBoxComando";
			this->richTextBoxComando->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedVertical;
			this->richTextBoxComando->Size = System::Drawing::Size(104, 217);
			this->richTextBoxComando->TabIndex = 0;
			this->richTextBoxComando->Text = resources->GetString(L"richTextBoxComando.Text");
			this->richTextBoxComando->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &TelaCodigo::richTextBoxComando_KeyDown);
			this->richTextBoxComando->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TelaCodigo::richTextBoxComando_KeyPress);
			// 
			// TelaCodigo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(660, 307);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"TelaCodigo";
			this->Text = L"TelaCodigo";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &TelaCodigo::TelaCodigo_FormClosed);
			this->Load += gcnew System::EventHandler(this, &TelaCodigo::TelaCodigo_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->Comando->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

private: System::Void TelaCodigo_Load(System::Object^  sender, System::EventArgs^  e) {

		if (Status == 1)//1º Novo projeto
		{
				Status = 3;
				tabControl1->Dock = DockStyle::Fill;
				
				tabControl1->TabPages->Remove(tabControl1->SelectedTab);//remove a tabPage fixa
				criarNovoProjeto();
				if (this->tabControl1->SelectedIndex >= 0)
				{
					atualizarNumeroLabel();
				}
		}
		else if (Status == 2)//1º abrir arquivo
		{
			Status = 3;

			tabControl1->Dock = DockStyle::Fill;
			

			tabControl1->TabPages->Remove(tabControl1->SelectedTab);//remove a tabPage fixa
			abrirProjeto();
			if (this->tabControl1->SelectedIndex >= 0)
			{
				atualizarNumeroLabel();
			}
	}
}
private: System::Void limparToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (this->tabControl1->SelectedIndex >= 0)
				 {
					 if (MessageBox::Show("Deseja limpar ? ", "Limpar", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
					 {
						 RichTextBox ^ textBox;

						 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
							 textBox = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

						 tabControl1->SelectedTab->Controls["richTextBox"]->Text = "";
					 }
				 }
}

private: System::Void abrirProjetoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 abrirProjeto();
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 atualizarNumeroLabel();
			 }
}

private: System::Void salvarComoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		RichTextBox ^ richTextBoxEndereco;
		RichTextBox ^ richTextBoxNome;
		if (this->tabControl1->SelectedIndex >= 0)
		{
			if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
				richTextBox1 = (RichTextBox ^)tabControl1->SelectedTab->Controls["richTextBox"];

			if (tabControl1->SelectedTab->Controls->ContainsKey("Endereco"))
				richTextBoxEndereco = (RichTextBox ^)tabControl1->SelectedTab->Controls["Endereco"];

			if (tabControl1->SelectedTab->Controls->ContainsKey("Nome"))
				richTextBoxNome = (RichTextBox ^)tabControl1->SelectedTab->Controls["Nome"];

			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
			saveFileDialog1->Filter = "txt files (*.sl)|*.sl |All files (*.*)|*.*";
			saveFileDialog1->FilterIndex = 1;
			saveFileDialog1->RestoreDirectory = true;
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
				saveFileDialog1->FileName->Length > 0)
			{
				richTextBox1->SaveFile(saveFileDialog1->FileName, RichTextBoxStreamType::PlainText);

				Caminho = saveFileDialog1->FileName;
			}
		}	
}

private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e) {

		RichTextBox ^ richTextBoxEndereco;
		RichTextBox ^ richTextBoxNome;

		if (this->tabControl1->SelectedIndex >= 0)
		{
			if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
				richTextBox1 = (RichTextBox ^)tabControl1->SelectedTab->Controls["richTextBox"];

			if (tabControl1->SelectedTab->Controls->ContainsKey("Endereco"))
				richTextBoxEndereco = (RichTextBox ^)tabControl1->SelectedTab->Controls["Endereco"];

			if (tabControl1->SelectedTab->Controls->ContainsKey("Nome"))
				richTextBoxNome = (RichTextBox ^)tabControl1->SelectedTab->Controls["Nome"];

			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
			saveFileDialog1->Filter = "txt files (*.sl)|*.sl |All files (*.*)|*.*";
			saveFileDialog1->FilterIndex = 1;
			saveFileDialog1->RestoreDirectory = true;
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
				saveFileDialog1->FileName->Length > 0)
			{
				richTextBox1->SaveFile(saveFileDialog1->FileName, RichTextBoxStreamType::PlainText);
				Caminho = saveFileDialog1->FileName;
			}
		}
}

private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e) {
				 RichTextBox ^ richTextBoxEndereco;
				 RichTextBox ^ richTextBoxNome;

				 if (this->tabControl1->SelectedIndex >= 0)
				 {
					 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
						richTextBox1 = (RichTextBox ^)tabControl1->SelectedTab->Controls["richTextBox"];

					 if (tabControl1->SelectedTab->Controls->ContainsKey("Endereco"))
						 richTextBoxEndereco = (RichTextBox ^)tabControl1->SelectedTab->Controls["Endereco"];

					 if (tabControl1->SelectedTab->Controls->ContainsKey("Nome"))
						 richTextBoxNome = (RichTextBox ^)tabControl1->SelectedTab->Controls["Nome"];

					 System::Windows::Forms::DialogResult result;
					 result = MessageBox::Show(this, "Deseja salvar?", "Salvar", MessageBoxButtons::YesNo);
					 if (result == ::System::Windows::Forms::DialogResult::Yes)
					 {
						 if (Caminho == "")
						 {
							 richTextBox1->SaveFile(String::Concat(System::Environment::GetFolderPath
								 (System::Environment::SpecialFolder::MyComputer), richTextBoxEndereco->Text /*FolderName*/, "\\", richTextBoxNome->Text/*Nome*/,
								 ".sl"), RichTextBoxStreamType::PlainText);
							 MessageBox::Show("Salvo com sucesso!");
						 }
						 else
						 {
							 richTextBox1->SaveFile(String::Concat
								 (System::Environment::GetFolderPath
								 (System::Environment::SpecialFolder::MyComputer),
								 Caminho), RichTextBoxStreamType::PlainText);
							 MessageBox::Show("Salvo com sucesso!");
						 }
					 }
				 }
}

private: System::Void fundoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (this->tabControl1->SelectedIndex >= 0)
				 {
					 ColorDialog^ colorDialog1 = gcnew ColorDialog;

					 colorDialog1->Color = richTextBox1->SelectionColor;

					 if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
						 colorDialog1->Color != richTextBox1->SelectionColor)
					 {
						 RichTextBox ^ textBox;

						 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
							 textBox = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

						 tabControl1->SelectedTab->Controls["richTextBox"]->BackColor = colorDialog1->Color;

					 }
				 }
}

private: System::Void salvarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		RichTextBox ^ richTextBoxEndereco;
		RichTextBox ^ richTextBoxNome;

		if (this->tabControl1->SelectedIndex >= 0)
		{
			if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
				richTextBox1 = (RichTextBox ^)tabControl1->SelectedTab->Controls["richTextBox"];

			if (tabControl1->SelectedTab->Controls->ContainsKey("Endereco"))
				richTextBoxEndereco = (RichTextBox ^)tabControl1->SelectedTab->Controls["Endereco"];

			if (tabControl1->SelectedTab->Controls->ContainsKey("Nome"))
				richTextBoxNome = (RichTextBox ^)tabControl1->SelectedTab->Controls["Nome"];

			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(this, "Deseja salvar?", "Salvar", MessageBoxButtons::YesNo);
			if (result == ::System::Windows::Forms::DialogResult::Yes)
			{
				if (Caminho == "")
				{
					richTextBox1->SaveFile(String::Concat
						(System::Environment::GetFolderPath
						(System::Environment::SpecialFolder::MyComputer), richTextBoxEndereco->Text /*FolderName*/, "\\", richTextBoxNome->Text/*Nome*/,
						".sl"), RichTextBoxStreamType::PlainText);
					MessageBox::Show("Salvo com sucesso!");
				}
				else
				{
					richTextBox1->SaveFile(String::Concat
						(System::Environment::GetFolderPath
						(System::Environment::SpecialFolder::MyComputer),
						Caminho), RichTextBoxStreamType::PlainText);
					MessageBox::Show("Salvo com sucesso!");
				}
			}
		}
}

private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		SubJanela->setStatusNovoProjeto(-1);
		SubJanela->ShowDialog();

		if (SubJanela->getStatusNovoProjeto() == 1)
		{
			setNome(SubJanela->getNome());
			setfolderName(SubJanela->getfolderName());

			criarNovoProjeto();
			if (this->tabControl1->SelectedIndex >= 0)
			{
				atualizarNumeroLabel();
			}
		}	
}

private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	if (MessageBox::Show("Deseja encerrar o projeto?", "Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
	{
		Status = 0;
		this->Visible = false;
	}

}
private: System::Void tabControl1_DrawItem(System::Object^  sender, System::Windows::Forms::DrawItemEventArgs^  e) {

	e->Graphics->DrawString("X", e->Font, Brushes::Black, e->Bounds.Right - (float)15, e->Bounds.Top + (float)4);
	e->Graphics->DrawString(this->tabControl1->TabPages[e->Index]->Text, e->Font, Brushes::Black, e->Bounds.Left + (float)12, e->Bounds.Top + (float)4);
	e->DrawFocusRectangle();

}
private: System::Void tabControl1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Looping entre as tabs.
	for (int i = 0; i < this->tabControl1->TabPages->Count; i++)
	{
		Rectangle r = tabControl1->GetTabRect(i);
		//pegar posição do "x".
		Rectangle ^ closeButton = gcnew Rectangle(r.Right - 15, r.Top + 4, 9, 7);
		if (closeButton->Contains(e->Location))
		{
			if (MessageBox::Show("Deseja fechar o Projeto?", "Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
			{
				this->tabControl1->TabPages->RemoveAt(i);
				break;
			}
		}
	}
}
private: System::Void novoProjetoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	SubJanela->setStatusNovoProjeto(-1);
	SubJanela->ShowDialog();

	if (SubJanela->getStatusNovoProjeto() == 1)
	{
		setNome(SubJanela->getNome());
		setfolderName(SubJanela->getfolderName());
	
		criarNovoProjeto();
		if (this->tabControl1->SelectedIndex >= 0)
		{
			atualizarNumeroLabel();
		}
	}
}

private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			 abrirProjeto();
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 atualizarNumeroLabel();
			 }
}

private: System::Void TelaCodigo_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

	if (MessageBox::Show("Deseja encerrar o projeto?", "Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
	{
		Status = 0;
		this->Visible = false;
	}
}

private: System::Void compilarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 apagarErro();
				 Linha = -1;
				 RichTextBox ^ textBoxCodigo = gcnew RichTextBox;
				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
					 textBoxCodigo = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

				 if (textBoxCodigo->Text != "")
				 {
					 String ^ Auxiliar = textBoxCodigo->Text;
					 int Valor = Convert::ToInt32(Auxiliar[0]);
					 int i = 0;
					 int CodigoVazio = 1;

					 while (i < Auxiliar->Length)
					 {
						 if (isgraph(Auxiliar[i]))
						 {
							 CodigoVazio = 0;
						 }
						 i++;
					 }
					 if (CodigoVazio == 0)
					 {
						 i = 0;
						 while (i < Auxiliar->Length && Valor < 127)
						 {
							 Valor = Convert::ToInt32(Auxiliar[i]);
							 i++;
						 }

						 if (i >= Auxiliar->Length)
						 {
							 TextoCodigo = Auxiliar;
							 Status = 4;
							 this->Visible = false;
						 }
						 else
						 {
							 MessageBox::Show("Não é permitida a utilização de acentos e caracteres especiais!!!", "ERRO",
								 MessageBoxButtons::OK, MessageBoxIcon::Error);
						 }
					 }
					 else
					 {
						 MessageBox::Show("Não existe código para analisar!!!", "ERRO",
							 MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }

				 }
				 else
				 {
					 MessageBox::Show("Não existe código para analisar!!!", "ERRO",
						 MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			 }
			 
}

private: System::Void selecionarTudoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 RichTextBox ^ textBox;

				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
					 textBox = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];
				 textBox->Focus();
				 textBox->SelectAll();
				 tabControl1->SelectedTab->Controls["richTextBox"];
			 }
			 
}

private: System::Void copiarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 RichTextBox ^ textBox;

				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
					 textBox = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

				 textBox->Focus();
				 textBox->Copy();
				 tabControl1->SelectedTab->Controls["richTextBox"];
			 }
			 
}

private: System::Void recortarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 RichTextBox ^ textBox;

				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
					 textBox = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

				 textBox->Focus();
				 textBox->Cut();
				 tabControl1->SelectedTab->Controls["richTextBox"];
			 }
			
}

private: System::Void colarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 RichTextBox ^ textBox;

				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
					 textBox = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];
				 textBox->Focus();
				 textBox->Paste();
				 tabControl1->SelectedTab->Controls["richTextBox"];
			 }
}

private: System::Void fonteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 FontDialog^ fontDialog1 = gcnew FontDialog;

				 fontDialog1->Font = richTextBox1->SelectionFont;

				 if (fontDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
					 fontDialog1->Font != richTextBox1->SelectionFont)
				 {
					 RichTextBox ^ textBox;
					 Label ^ Rotulo1;

					 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
						 textBox = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

					 tabControl1->SelectedTab->Controls["richTextBox"]->Font = fontDialog1->Font;

					 if (textBox->Controls->ContainsKey("rotulo"))
						 Rotulo1 = (Label^)textBox->Controls["rotulo"];

					 Rotulo1->Font = fontDialog1->Font;

					 int Tamanho = textBox->Text->Length;
					 int PosicaoAnterior = 0;
					 PosicaoAnterior = textBox->SelectionStart;

					 alterarTodotexto(0, PosicaoAnterior, textBox);
					 TamanhoTexto = Tamanho;
					 textBox->SelectionStart = PosicaoAnterior;
					 textBox->SelectionLength = 0;
				 }
			 } 
}

private: System::Void toolStripLabel3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 apagarErro();
				 Linha = -1;
				 RichTextBox ^ textBoxCodigo;
				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
					 textBoxCodigo = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

				 if (textBoxCodigo->Text != "")
				 {
					 String ^ Auxiliar = textBoxCodigo->Text;
					 int Valor = Convert::ToInt32(Auxiliar[0]);
					 int i = 0;
					 int CodigoVazio = 1;

					 while (i < Auxiliar->Length)
					 {
						 if (isgraph(Auxiliar[i]))
						 {
							 CodigoVazio = 0;
						 }
						 i++;
					 }
					 if (CodigoVazio == 0)
					 {
						 i = 0;
						 while (i < Auxiliar->Length && Valor < 127)
						 {
							 Valor = Convert::ToInt32(Auxiliar[i]);
							 i++;
						 }

						 if (i >= Auxiliar->Length)
						 {
							 TextoCodigo = Auxiliar;
							 Status = 4;
							 this->Visible = false;
						 }
						 else
						 {
							 MessageBox::Show("Não é permitida a utilização de acentos e caracteres especiais!!!", "ERRO",
								 MessageBoxButtons::OK, MessageBoxIcon::Error);
						 }
					 }
					 else
					 {
						 MessageBox::Show("Não existe código para analisar!!!", "ERRO",
							 MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }

				 }
				 else
				 {
					 MessageBox::Show("Não existe código para analisar!!!", "ERRO",
						 MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			 }
}
private: System::Void tabControl1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 RichTextBox ^ textBoxCodigo;
				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
				 {
					 textBoxCodigo = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

					 if (e->KeyChar > 127 || e->KeyChar == 26)
					 {
						 e->Handled = true;
					 }
				 }
					 
			 }
}
private: System::Void sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Sobre ^ JanelaSobre = gcnew Sobre();
			 JanelaSobre->ShowDialog();
			 delete(JanelaSobre);
}
private: System::Void comandosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int Posicao = 0;
			 Comando->Visible = true;
			 this->Comando->Size = System::Drawing::Size(165, 0);
			 this->Comando->ItemSize = System::Drawing::Size(162, 0);
			 this->tabControl1->Size = System::Drawing::Size(492, 0);

			 ImageList^ lstImages = gcnew ImageList;
			 Comando->ImageList = lstImages;
			 tabPage2->Text = L"Comandos";
			 tabPage2->ImageIndex = 0;

			 Posicao = richTextBoxComando->Find("inteiro", 110, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 7, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("escrever", 0, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 8, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("ler", 0, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 3, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("se", 400, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 2, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("enquanto", 0, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 8, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("+", 0, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 1, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("-", 200, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 1, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("*", 0, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 1, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("/", 0, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 1, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("^", 0, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 1, 0, richTextBoxComando);

			 Posicao = richTextBoxComando->Find("Definição de variáveis", 0, richTextBoxComando->Text->Length - 1, RichTextBoxFinds::NoHighlight);
			 mudarCorPalavraChave(Posicao, 22, 0, richTextBoxComando);
}
private: System::Void Comando_DrawItem(System::Object^  sender, System::Windows::Forms::DrawItemEventArgs^  e) {
			 e->Graphics->DrawString("X", e->Font, Brushes::Black, e->Bounds.Right - (float)15, e->Bounds.Top + (float)4);
			 e->Graphics->DrawString(this->Comando->TabPages[e->Index]->Text, e->Font, Brushes::Black, e->Bounds.Left + (float)50, e->Bounds.Top + (float)4);
			 e->DrawFocusRectangle();
}
private: System::Void Comando_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 for (int i = 0; i < this->Comando->TabPages->Count; i++)
			 {
				 Rectangle r = Comando->GetTabRect(i);
				 //Getting the position of the "x" mark.
				 Rectangle ^ closeButton = gcnew Rectangle(r.Right - 15, r.Top + 4, 9, 7);
				 if (closeButton->Contains(e->Location))
				 {
					 tabControl1->Dock = DockStyle::Fill;
					 this->Comando->Visible = false;
					 break;
				 }
			 }
}
private: System::Void richTextBoxComando_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (e->KeyChar > 0 || e->KeyChar <= 0)
			 {
				 e->Handled = true;
			 }
}
private: System::Void richTextBoxComando_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 e->Handled = true;
}
private: System::Void interpretaçãoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 apagarErro();
				 Linha = -1;
				 RichTextBox ^ textBoxCodigo = gcnew RichTextBox;
				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
					 textBoxCodigo = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

				 if (textBoxCodigo->Text != "")
				 {
					 String ^ Auxiliar = textBoxCodigo->Text;
					 int Valor = Convert::ToInt32(Auxiliar[0]);
					 int i = 0;
					 int CodigoVazio = 1;

					 while (i < Auxiliar->Length)
					 {
						 if (isgraph(Auxiliar[i]))
						 {
							 CodigoVazio = 0;
						 }
						 i++;
					 }
					 if (CodigoVazio == 0)
					 {
						 i = 0;
						 while (i < Auxiliar->Length && Valor < 127)
						 {
							 Valor = Convert::ToInt32(Auxiliar[i]);
							 i++;
						 }

						 if (i >= Auxiliar->Length)
						 {
							 TextoCodigo = Auxiliar;
							 Status = 5;
							 this->Visible = false;
						 }
						 else
						 {
							 MessageBox::Show("Não é permitida a utilização de acentos e caracteres especiais!!!", "ERRO",
								 MessageBoxButtons::OK, MessageBoxIcon::Error);
						 }
					 }
					 else
					 {
						 MessageBox::Show("Não existe código para analisar!!!", "ERRO",
							 MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }

				 }
				 else
				 {
					 MessageBox::Show("Não existe código para analisar!!!", "ERRO",
						 MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			 }
}
private: void TextChangedDinamico(System::Object^  sender, System::EventArgs^  e) {
			 RichTextBox ^ textBox1;
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 Linha = -1;
				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
				 {
					 textBox1 = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

					 int Tamanho = textBox1->Text->Length;
					 int PosicaoInicial = 0, PosicaoAnterior = 0;
					 PosicaoAnterior = textBox1->SelectionStart;
					 PosicaoInicial = textBox1->SelectionStart;

					 pesquisarPalavra(PosicaoInicial, PosicaoAnterior, textBox1);
					 if (TamanhoTexto + 1 == Tamanho || (Tamanho - 1 >= 0 && TamanhoTexto - 1 == Tamanho))
					 {
						 if (PosicaoInicial - 1 >= 0)
						 {
							 pesquisarPalavra(PosicaoInicial - 1, PosicaoAnterior, textBox1);
						 }
					 }
					 else
					 {
						 if (TamanhoTexto - Tamanho > 10 || Tamanho - TamanhoTexto > 10)
						 {
							 alterarTodotexto(0, PosicaoAnterior, textBox1);
						 }

					 }
					 TamanhoTexto = Tamanho;
					 textBox1->SelectionStart = PosicaoAnterior;
					 textBox1->SelectionLength = 0;
				 }
				 atualizarNumeroLabel();
			 }
			 
		 }
private: void ScrollDinamico(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 RichTextBox ^ richtextbox4;

				 Label ^ rotulo1;

				 if (MostraErro)
				 {
					 MostraErro = false;
				 }
				 else
				 {
					 Linha = -1;
				 }

				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
					 richtextbox4 = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

				 if (richtextbox4->Controls->ContainsKey("rotulo"))
					 rotulo1 = (Label^)richtextbox4->Controls["rotulo"];

				 int d = richtextbox4->GetPositionFromCharIndex(0).Y % (richtextbox4->Font->Height + 1);
				 rotulo1->Location = Point(0, d);

				 atualizarNumeroLabel();
			 }
	}

private: System::Void FontChangedDinamico(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 Linha = -1;
				 atualizarNumeroLabel();
				 ScrollDinamico(nullptr, nullptr);
			 }
}
private: System::Void tabControl1_TabIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 RichTextBox ^ richtextbox4;
				 Linha = -1;
				 if (tabControl1->SelectedTab->Controls->ContainsKey("Nome"))
					 richtextbox4 = (RichTextBox^)tabControl1->SelectedTab->Controls["Nome"];

				 tabControl1->SelectedTab->Text = richtextbox4->Text + ".sl";
			 }
}
private: System::Void toolStripLabelInterpretar_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->tabControl1->SelectedIndex >= 0)
			 {
				 apagarErro();
				 Linha = -1;
				 RichTextBox ^ textBoxCodigo = gcnew RichTextBox;
				 if (tabControl1->SelectedTab->Controls->ContainsKey("richTextBox"))
					 textBoxCodigo = (RichTextBox^)tabControl1->SelectedTab->Controls["richTextBox"];

				 if (textBoxCodigo->Text != "")
				 {
					 String ^ Auxiliar = textBoxCodigo->Text;
					 int Valor = Convert::ToInt32(Auxiliar[0]);
					 int i = 0;
					 int CodigoVazio = 1;

					 while (i < Auxiliar->Length)
					 {
						 if (isgraph(Auxiliar[i]))
						 {
							 CodigoVazio = 0;
						 }
						 i++;
					 }
					 if (CodigoVazio == 0)
					 {
						 i = 0;
						 while (i < Auxiliar->Length && Valor < 127)
						 {
							 Valor = Convert::ToInt32(Auxiliar[i]);
							 i++;
						 }

						 if (i >= Auxiliar->Length)
						 {
							 TextoCodigo = Auxiliar;
							 Status = 5;
							 this->Visible = false;
						 }
						 else
						 {
							 MessageBox::Show("Não é permitida a utilização de acentos e caracteres especiais!!!", "ERRO",
								 MessageBoxButtons::OK, MessageBoxIcon::Error);
						 }
					 }
					 else
					 {
						 MessageBox::Show("Não existe código para analisar!!!", "ERRO",
							 MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }

				 }
				 else
				 {
					 MessageBox::Show("Não existe código para analisar!!!", "ERRO",
						 MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			 }
}
private: System::Void blogToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	System::Diagnostics::Process::Start("http://codeasyinterpretadorpuro.blogspot.com");
}
};
}