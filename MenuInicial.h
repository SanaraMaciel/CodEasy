#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Sobre.h"
#include "NovoProjeto.h"


namespace CodEasy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuInicial
	/// </summary>
	public ref class MenuInicial : public System::Windows::Forms::Form
	{
	public:
		MenuInicial(void)
		{
			InitializeComponent();

			this->StartPosition = FormStartPosition::CenterScreen;
			//
			//TODO: Add the constructor code here
			//
			Status = -1;
		}

		int    getStatus(void);
		string getNomePagina(void);
		string getDestino(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuInicial()
		{
			if (components)
			{
				delete components;
			}
			delete(SubJanela);
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuStrip;

	protected:

	private: System::Windows::Forms::ToolStripMenuItem^  novoProjetoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirProjetoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  salvarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  salvarComoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;

	private: System::Windows::Forms::ToolStripMenuItem^  editarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  contruirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  compilarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ferramentasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  comandoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
	private: System::Windows::Forms::ToolStripMenuItem^  blogToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;

	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel3;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel2;

	private: System::Windows::Forms::ToolStripMenuItem^  limparToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  corDoTextoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  corDaTelaToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int Status;
	private: System::Windows::Forms::ToolStripMenuItem^  selecionarTudoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator8;
	private: System::Windows::Forms::ToolStripMenuItem^  copiarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  recortarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colarToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  interpretarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel4;
			 NovoProjeto ^SubJanela = gcnew NovoProjeto();


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuInicial::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuStrip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->novoProjetoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->abrirProjetoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->salvarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salvarComoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->sairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->limparToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->selecionarTudoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->copiarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->recortarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contruirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->compilarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->interpretarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ferramentasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->corDoTextoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->corDaTelaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ajudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->comandoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->blogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel3 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel4 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->menuStrip, this->editarToolStripMenuItem,
					this->contruirToolStripMenuItem, this->ferramentasToolStripMenuItem, this->ajudaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(656, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuStrip
			// 
			this->menuStrip->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->novoProjetoToolStripMenuItem,
					this->toolStripMenuItem1, this->abrirProjetoToolStripMenuItem, this->toolStripSeparator3, this->salvarToolStripMenuItem, this->salvarComoToolStripMenuItem,
					this->toolStripSeparator4, this->sairToolStripMenuItem
			});
			this->menuStrip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(69, 23);
			this->menuStrip->Text = L"Arquivo";
			// 
			// novoProjetoToolStripMenuItem
			// 
			this->novoProjetoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"novoProjetoToolStripMenuItem.Image")));
			this->novoProjetoToolStripMenuItem->Name = L"novoProjetoToolStripMenuItem";
			this->novoProjetoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->novoProjetoToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->novoProjetoToolStripMenuItem->Text = L"Novo Projeto";
			this->novoProjetoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuInicial::novoProjetoToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(207, 6);
			// 
			// abrirProjetoToolStripMenuItem
			// 
			this->abrirProjetoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"abrirProjetoToolStripMenuItem.Image")));
			this->abrirProjetoToolStripMenuItem->Name = L"abrirProjetoToolStripMenuItem";
			this->abrirProjetoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->abrirProjetoToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->abrirProjetoToolStripMenuItem->Text = L"Abrir Projeto";
			this->abrirProjetoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuInicial::abrirProjetoToolStripMenuItem_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(207, 6);
			// 
			// salvarToolStripMenuItem
			// 
			this->salvarToolStripMenuItem->Enabled = false;
			this->salvarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"salvarToolStripMenuItem.Image")));
			this->salvarToolStripMenuItem->Name = L"salvarToolStripMenuItem";
			this->salvarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->salvarToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->salvarToolStripMenuItem->Text = L"Salvar";
			// 
			// salvarComoToolStripMenuItem
			// 
			this->salvarComoToolStripMenuItem->Enabled = false;
			this->salvarComoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"salvarComoToolStripMenuItem.Image")));
			this->salvarComoToolStripMenuItem->Name = L"salvarComoToolStripMenuItem";
			this->salvarComoToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->salvarComoToolStripMenuItem->Text = L"Salvar como...";
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(207, 6);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sairToolStripMenuItem.Image")));
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::S));
			this->sairToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuInicial::sairToolStripMenuItem_Click);
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
			this->limparToolStripMenuItem->Enabled = false;
			this->limparToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"limparToolStripMenuItem.Image")));
			this->limparToolStripMenuItem->Name = L"limparToolStripMenuItem";
			this->limparToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::L));
			this->limparToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->limparToolStripMenuItem->Text = L"Limpar";
			// 
			// selecionarTudoToolStripMenuItem
			// 
			this->selecionarTudoToolStripMenuItem->Enabled = false;
			this->selecionarTudoToolStripMenuItem->Name = L"selecionarTudoToolStripMenuItem";
			this->selecionarTudoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::T));
			this->selecionarTudoToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->selecionarTudoToolStripMenuItem->Text = L"Selecionar Tudo";
			// 
			// toolStripSeparator8
			// 
			this->toolStripSeparator8->Name = L"toolStripSeparator8";
			this->toolStripSeparator8->Size = System::Drawing::Size(219, 6);
			// 
			// copiarToolStripMenuItem
			// 
			this->copiarToolStripMenuItem->Enabled = false;
			this->copiarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"copiarToolStripMenuItem.Image")));
			this->copiarToolStripMenuItem->Name = L"copiarToolStripMenuItem";
			this->copiarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copiarToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->copiarToolStripMenuItem->Text = L"Copiar";
			// 
			// recortarToolStripMenuItem
			// 
			this->recortarToolStripMenuItem->Enabled = false;
			this->recortarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"recortarToolStripMenuItem.Image")));
			this->recortarToolStripMenuItem->Name = L"recortarToolStripMenuItem";
			this->recortarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->recortarToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->recortarToolStripMenuItem->Text = L"Recortar";
			// 
			// colarToolStripMenuItem
			// 
			this->colarToolStripMenuItem->Enabled = false;
			this->colarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"colarToolStripMenuItem.Image")));
			this->colarToolStripMenuItem->Name = L"colarToolStripMenuItem";
			this->colarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->colarToolStripMenuItem->Size = System::Drawing::Size(222, 24);
			this->colarToolStripMenuItem->Text = L"Colar";
			// 
			// contruirToolStripMenuItem
			// 
			this->contruirToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->compilarToolStripMenuItem,
					this->interpretarToolStripMenuItem
			});
			this->contruirToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->contruirToolStripMenuItem->Name = L"contruirToolStripMenuItem";
			this->contruirToolStripMenuItem->Size = System::Drawing::Size(72, 23);
			this->contruirToolStripMenuItem->Text = L"Contruir";
			// 
			// compilarToolStripMenuItem
			// 
			this->compilarToolStripMenuItem->Enabled = false;
			this->compilarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"compilarToolStripMenuItem.Image")));
			this->compilarToolStripMenuItem->Name = L"compilarToolStripMenuItem";
			this->compilarToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F9;
			this->compilarToolStripMenuItem->Size = System::Drawing::Size(176, 24);
			this->compilarToolStripMenuItem->Text = L"Executar";
			// 
			// interpretarToolStripMenuItem
			// 
			this->interpretarToolStripMenuItem->Enabled = false;
			this->interpretarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"interpretarToolStripMenuItem.Image")));
			this->interpretarToolStripMenuItem->Name = L"interpretarToolStripMenuItem";
			this->interpretarToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F10;
			this->interpretarToolStripMenuItem->Size = System::Drawing::Size(176, 24);
			this->interpretarToolStripMenuItem->Text = L"Interpretar";
			// 
			// ferramentasToolStripMenuItem
			// 
			this->ferramentasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->corDoTextoToolStripMenuItem,
					this->corDaTelaToolStripMenuItem
			});
			this->ferramentasToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->ferramentasToolStripMenuItem->Name = L"ferramentasToolStripMenuItem";
			this->ferramentasToolStripMenuItem->Size = System::Drawing::Size(97, 23);
			this->ferramentasToolStripMenuItem->Text = L"Ferramentas";
			// 
			// corDoTextoToolStripMenuItem
			// 
			this->corDoTextoToolStripMenuItem->Enabled = false;
			this->corDoTextoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"corDoTextoToolStripMenuItem.Image")));
			this->corDoTextoToolStripMenuItem->Name = L"corDoTextoToolStripMenuItem";
			this->corDoTextoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::C));
			this->corDoTextoToolStripMenuItem->Size = System::Drawing::Size(243, 24);
			this->corDoTextoToolStripMenuItem->Text = L"Cor do Texto";
			// 
			// corDaTelaToolStripMenuItem
			// 
			this->corDaTelaToolStripMenuItem->Enabled = false;
			this->corDaTelaToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"corDaTelaToolStripMenuItem.Image")));
			this->corDaTelaToolStripMenuItem->Name = L"corDaTelaToolStripMenuItem";
			this->corDaTelaToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::F));
			this->corDaTelaToolStripMenuItem->Size = System::Drawing::Size(243, 24);
			this->corDaTelaToolStripMenuItem->Text = L"Fonte";
			// 
			// ajudaToolStripMenuItem
			// 
			this->ajudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->comandoToolStripMenuItem,
					this->toolStripSeparator6, this->blogToolStripMenuItem, this->toolStripSeparator7, this->sobreToolStripMenuItem
			});
			this->ajudaToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->ajudaToolStripMenuItem->Name = L"ajudaToolStripMenuItem";
			this->ajudaToolStripMenuItem->Size = System::Drawing::Size(56, 23);
			this->ajudaToolStripMenuItem->Text = L"Ajuda";
			// 
			// comandoToolStripMenuItem
			// 
			this->comandoToolStripMenuItem->Enabled = false;
			this->comandoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"comandoToolStripMenuItem.Image")));
			this->comandoToolStripMenuItem->Name = L"comandoToolStripMenuItem";
			this->comandoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::C));
			this->comandoToolStripMenuItem->Size = System::Drawing::Size(198, 24);
			this->comandoToolStripMenuItem->Text = L"Comandos";
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(195, 6);
			// 
			// blogToolStripMenuItem
			// 
			this->blogToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blogToolStripMenuItem.Image")));
			this->blogToolStripMenuItem->Name = L"blogToolStripMenuItem";
			this->blogToolStripMenuItem->Size = System::Drawing::Size(198, 24);
			this->blogToolStripMenuItem->Text = L"Blog ";
			this->blogToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuInicial::blogToolStripMenuItem_Click);
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(195, 6);
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sobreToolStripMenuItem.Image")));
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(198, 24);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuInicial::sobreToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->toolStripButton1,
					this->toolStripSeparator1, this->toolStripButton2, this->toolStripSeparator2, this->toolStripButton3, this->toolStripButton4,
					this->toolStripSeparator5, this->toolStripLabel3, this->toolStripLabel4
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 27);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(656, 25);
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
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MenuInicial::toolStripButton1_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(23, 22);
			this->toolStripButton2->Text = L"Abrir Projeto";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MenuInicial::toolStripButton2_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Enabled = false;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(23, 22);
			this->toolStripButton3->Text = L"Salvar Projeto";
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Enabled = false;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(23, 22);
			this->toolStripButton4->Text = L"Salvar como...";
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripLabel3
			// 
			this->toolStripLabel3->Enabled = false;
			this->toolStripLabel3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->toolStripLabel3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripLabel3.Image")));
			this->toolStripLabel3->Name = L"toolStripLabel3";
			this->toolStripLabel3->Size = System::Drawing::Size(140, 22);
			this->toolStripLabel3->Text = L"Executar Programa";
			// 
			// toolStripLabel4
			// 
			this->toolStripLabel4->Enabled = false;
			this->toolStripLabel4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->toolStripLabel4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripLabel4.Image")));
			this->toolStripLabel4->Name = L"toolStripLabel4";
			this->toolStripLabel4->Size = System::Drawing::Size(155, 22);
			this->toolStripLabel4->Text = L"Interpretar Programa";
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(111, 22);
			this->toolStripLabel1->Text = L"Compilar Programa";
			// 
			// toolStripLabel2
			// 
			this->toolStripLabel2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripLabel2.Image")));
			this->toolStripLabel2->Name = L"toolStripLabel2";
			this->toolStripLabel2->Size = System::Drawing::Size(127, 22);
			this->toolStripLabel2->Text = L"Compilar Programa";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 52);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(656, 251);
			this->tabControl1->TabIndex = 3;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->richTextBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(648, 225);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(642, 219);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->richTextBox1->Location = System::Drawing::Point(3, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(642, 219);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// MenuInicial
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(656, 303);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MenuInicial";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Nova Pagina - CodEasy 2015";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MenuInicial::MenuInicial_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MenuInicial::MenuInicial_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MenuInicial_Load(System::Object^  sender, System::EventArgs^  e) {
		tabPage1->Text = "Novo Projeto";
}

private: System::Void novoProjetoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		SubJanela->ShowDialog();
		Status = SubJanela->getStatusNovoProjeto();
		this->Visible = false;
		
}

private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {

	SubJanela->ShowDialog();
	Status = SubJanela->getStatusNovoProjeto();
	this->Visible = false;	
}

private: System::Void abrirProjetoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	Status = 2;
	this->Visible = false;
	
}
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {

	Status = 2;
	this->Visible = false;

}

private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	if (MessageBox::Show("Deseja encerrar o projeto?", "Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
	{
		Status = 0;
		this->Visible = false;
	}
}

private: System::Void MenuInicial_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

	if (MessageBox::Show("Deseja encerrar o projeto?", "Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
	{
		Status = 0;
		this->Visible = false;
	}
}
private: System::Void sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Sobre ^ JanelaSobre = gcnew Sobre();
			 JanelaSobre->ShowDialog();
			 delete(JanelaSobre);
}
private: System::Void blogToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

    System::Diagnostics::Process::Start("http://codeasyinterpretadorpuro.blogspot.com");

}
};
}
