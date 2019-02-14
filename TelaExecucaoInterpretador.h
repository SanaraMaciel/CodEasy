#pragma once

#include <iostream>
using namespace std;
#include <string>

namespace CodEasy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for TelaExecucaoInterpretador
	/// </summary>
	const int WM_VSCROLL2 = 0x115;
	const int SB_BOTTOM2 = 7;

	[DllImport("user32.dll")]
	extern int SendMessageA(IntPtr hWnd, int wMsg, IntPtr wParam, int lParam);

	public ref class TelaExecucaoInterpretador : public System::Windows::Forms::Form
	{
	public:
		TelaExecucaoInterpretador(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			TextoRecebido = "";
			ValorEmTexto = "";
			Expressao = "";
			ValorLido = 0;
			Leitura = 0;
			Status = -1;
			NumeroLinha = -1;
		}
		void mostrarErros(int);
		void escreverTexto(string);
		int  getValorLido(void);
		void setValorEmTexto(string);
		void setTexto(string);
		void receberExpressao(string);
		void setLeitura(int);
		void setStatus(int);
		int  getStatus(void);
		void setLinha(string);
		void setNumeroLinha(int);

		void MarshalString(String ^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TelaExecucaoInterpretador()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		String ^ TextoRecebido;
		String ^ ValorEmTexto;
		String ^ Expressao;
		int ValorLido,
			Leitura,
			Status,
			NumeroLinha;
	private: System::Windows::Forms::RichTextBox^  textBoxExecucao;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  textBoxCodigo;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TelaExecucaoInterpretador::typeid));
			this->textBoxExecucao = (gcnew System::Windows::Forms::RichTextBox());
			this->textBoxCodigo = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxExecucao
			// 
			this->textBoxExecucao->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxExecucao->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxExecucao->Location = System::Drawing::Point(12, 34);
			this->textBoxExecucao->Name = L"textBoxExecucao";
			this->textBoxExecucao->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->textBoxExecucao->Size = System::Drawing::Size(560, 171);
			this->textBoxExecucao->TabIndex = 0;
			this->textBoxExecucao->Text = L"";
			this->textBoxExecucao->TextChanged += gcnew System::EventHandler(this, &TelaExecucaoInterpretador::textBoxExecucao_TextChanged);
			this->textBoxExecucao->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &TelaExecucaoInterpretador::textBoxExecucao_KeyDown);
			this->textBoxExecucao->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TelaExecucaoInterpretador::textBoxExecucao_KeyPress);
			// 
			// textBoxCodigo
			// 
			this->textBoxCodigo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxCodigo->Location = System::Drawing::Point(12, 228);
			this->textBoxCodigo->Name = L"textBoxCodigo";
			this->textBoxCodigo->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->textBoxCodigo->Size = System::Drawing::Size(560, 171);
			this->textBoxCodigo->TabIndex = 1;
			this->textBoxCodigo->Text = L"";
			this->textBoxCodigo->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &TelaExecucaoInterpretador::textBoxCodigo_KeyDown);
			this->textBoxCodigo->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TelaExecucaoInterpretador::textBoxCodigo_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Execução";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 208);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Código";
			// 
			// TelaExecucaoInterpretador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 411);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxCodigo);
			this->Controls->Add(this->textBoxExecucao);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"TelaExecucaoInterpretador";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TelaExecucao";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &TelaExecucaoInterpretador::TelaExecucaoInterpretador_FormClosed);
			this->Load += gcnew System::EventHandler(this, &TelaExecucaoInterpretador::TelaExecucaoInterpretador_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TelaExecucaoInterpretador_Load(System::Object^  sender, System::EventArgs^  e) {
				 SendMessageA(textBoxExecucao->Handle, WM_VSCROLL2, (IntPtr)SB_BOTTOM2, 0);
				 Status = 1;
				 textBoxExecucao->SelectionStart = textBoxExecucao->Text->Length;
				 textBoxExecucao->SelectionLength = 0;
				 SendMessageA(textBoxCodigo->Handle, WM_VSCROLL2, (IntPtr)SB_BOTTOM2, 0);
				 textBoxCodigo->SelectionStart = textBoxCodigo->Text->Length;
				 textBoxCodigo->SelectionLength = 0;
	}
private: System::Void TelaExecucaoInterpretador_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 Status = 2;
			 textBoxCodigo->Text = "";
			 textBoxExecucao->Text = "";
}
private: System::Void textBoxExecucao_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 SendMessageA(textBoxCodigo->Handle, WM_VSCROLL2, (IntPtr)SB_BOTTOM2, 0);
			 textBoxCodigo->SelectionStart = textBoxCodigo->Text->Length;
			 textBoxCodigo->SelectionLength = 0;
}
private: System::Void textBoxExecucao_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (ValorEmTexto->Length == 0 || Leitura != 1)
			 {
				 e->Handled = true;
			 }
}
private: System::Void textBoxExecucao_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (Leitura == 1)
			 {
				 if (ValorEmTexto->Length >= 9)
				 {
					 e->Handled = true;
				 }
				 if (e->KeyChar < '0' || e->KeyChar > '9')
				 {
					 if (e->KeyChar == 8 || e->KeyChar == 13 || (e->KeyChar == '-' && ValorEmTexto->Length == 0))
					 {
						 e->Handled = false;
						 if (e->KeyChar == 13)
						 {
							 if (ValorEmTexto->Length > 0 && ValorEmTexto != "-")
							 {
								 ValorLido = Convert::ToInt32(ValorEmTexto);
								 Status = 0;
								 this->Visible = false;
							 }
							 else
							 {
								 e->Handled = true;
							 }

						 }
						 else if (e->KeyChar == 8)
						 {
							 string UmValor;
							 if (ValorEmTexto->Length != 0)
							 {
								 MarshalString(ValorEmTexto, UmValor);
								 UmValor[UmValor.size() - 1] = '\0';
								 String ^ Auxiliar = gcnew String(UmValor.c_str());
								 ValorEmTexto = Auxiliar;
								 delete(Auxiliar);
							 }
							 else
							 {
								 e->Handled = true;
							 }
						 }
						 else
						 {
							 ValorEmTexto = "-";
						 }
					 }
					 else
					 {
						 e->Handled = true;
					 }
				 }
				 else if (ValorEmTexto->Length < 9)
				 {
					 String ^ Numero;
					 switch (e->KeyChar)
					 {
					 case '0':
						 Numero = "0";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 case '1':
						 Numero = "1";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 case '2':
						 Numero = "2";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 case '3':
						 Numero = "3";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 case '4':
						 Numero = "4";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 case '5':
						 Numero = "5";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 case '6':
						 Numero = "6";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 case '7':
						 Numero = "7";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 case '8':
						 Numero = "8";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 case '9':
						 Numero = "9";
						 ValorEmTexto = ValorEmTexto + Numero;
						 break;
					 default:
						 break;
					 }

				 }
			 }
			 else
			 {
				 e->Handled = true;
				 if (e->KeyChar == 13 && Leitura != 2)
				 {
					 this->Visible = false;
				 }
			 }
}
private: System::Void textBoxCodigo_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 e->Handled = true;
}
private: System::Void textBoxCodigo_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 e->Handled = true;
}
};
}
