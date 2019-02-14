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
	/// Summary for TelaExecucao
	/// </summary>
	const int WM_VSCROLL = 0x115;
	const int SB_BOTTOM = 7;

	[DllImport("user32.dll")]
	extern int SendMessageA(IntPtr hWnd, int wMsg, IntPtr wParam, int lParam);

	public ref class TelaExecucao : public System::Windows::Forms::Form
	{
	public:
		TelaExecucao(void)
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
			NumeroLinha = 0;
		}
		void mostrarErros(int);
		void escreverTexto(string);
		int  getValorLido(void);
		void setValorEmTexto(string);
		void setTexto(string);
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
		~TelaExecucao()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:

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

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(560, 287);
			this->textBox1->TabIndex = 0;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TelaExecucao::textBox1_KeyPress);
			// 
			// TelaExecucao
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 311);
			this->Controls->Add(this->textBox1);
			this->Name = L"TelaExecucao";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TelaExecucao";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &TelaExecucao::TelaExecucao_FormClosed);
			this->Load += gcnew System::EventHandler(this, &TelaExecucao::TelaExecucao_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
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
				 }
	}
	private: System::Void TelaExecucao_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 textBox1->Text = "";
	}
private: System::Void TelaExecucao_Load(System::Object^  sender, System::EventArgs^  e) {
			 SendMessageA(textBox1->Handle, WM_VSCROLL, (IntPtr)SB_BOTTOM, 0);
			 Status = 1;
			 textBox1->SelectionStart = textBox1->Text->Length;
			 textBox1->SelectionLength = 0;
}
};
}
