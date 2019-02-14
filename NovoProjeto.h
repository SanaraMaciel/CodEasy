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
	

	/// <summary>
	/// Summary for NovoProjeto
	/// </summary>
	public ref class NovoProjeto : public System::Windows::Forms::Form
	{
	public:
		NovoProjeto(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			StatusNovoProjeto = -1;
			Nome = "";
			folderName = "C:\\";
		}
		string getNome(void);
		string getfolderName(void);
		int    getStatusNovoProjeto(void);
		void   setStatusNovoProjeto(int);

		void MarshalString(String ^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	private: System::Windows::Forms::Button^  button1;
	public:
	private: System::Windows::Forms::RichTextBox^  richTextBoxLocal;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBoxNome;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


	public:

	public:

	public:

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	protected:
		
		~NovoProjeto()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	protected:







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int      StatusNovoProjeto;
		String ^ Nome;
		String ^ folderName;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NovoProjeto::typeid));
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBoxLocal = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBoxNome = (gcnew System::Windows::Forms::RichTextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(1, 322);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(10, 10);
			this->richTextBox3->TabIndex = 7;
			this->richTextBox3->Text = L"";
			this->richTextBox3->Visible = false;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.27F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(449, 253);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NovoProjeto::button1_Click);
			// 
			// richTextBoxLocal
			// 
			this->richTextBoxLocal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxLocal->Location = System::Drawing::Point(94, 249);
			this->richTextBoxLocal->Multiline = false;
			this->richTextBoxLocal->Name = L"richTextBoxLocal";
			this->richTextBoxLocal->Size = System::Drawing::Size(325, 27);
			this->richTextBoxLocal->TabIndex = 1;
			this->richTextBoxLocal->Text = L"";
			this->richTextBoxLocal->TextChanged += gcnew System::EventHandler(this, &NovoProjeto::richTextBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(344, 298);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Criar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &NovoProjeto::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 252);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Local:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(449, 298);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Cancelar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &NovoProjeto::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 196);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nome:";
			// 
			// richTextBoxNome
			// 
			this->richTextBoxNome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxNome->Location = System::Drawing::Point(94, 193);
			this->richTextBoxNome->Multiline = false;
			this->richTextBoxNome->Name = L"richTextBoxNome";
			this->richTextBoxNome->Size = System::Drawing::Size(325, 27);
			this->richTextBoxNome->TabIndex = 0;
			this->richTextBoxNome->Text = L"";
			this->richTextBoxNome->TextChanged += gcnew System::EventHandler(this, &NovoProjeto::richTextBox2_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(548, 176);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// NovoProjeto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(549, 332);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->richTextBoxNome);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBoxLocal);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox3);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"NovoProjeto";
			this->Text = L"NovoProjeto";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &NovoProjeto::NovoProjeto_FormClosed);
			this->Load += gcnew System::EventHandler(this, &NovoProjeto::NovoProjeto_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		FolderBrowserDialog^ folderBrowserDialog1;
		folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

		// mostra o FolderBrowserDialog.
		System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			 folderName = folderBrowserDialog1->SelectedPath;
			 richTextBoxLocal->Text = folderName;
		}
		delete(folderBrowserDialog1);
	}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	       richTextBoxLocal->Text = folderName;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	richTextBox3->Text = "";

	if (Nome == "")
	{
		Nome = "NovoProjeto";
	}
	
	if (System::IO::File::Exists(folderName + "\\" + Nome + ".sl"))
	{
		MessageBox::Show("Arquivo já existe no local escolhido, escolha outro nome!", "Advertência", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	else
	{
		richTextBox3->SaveFile(String::Concat
		(System::Environment::GetFolderPath
		(System::Environment::SpecialFolder::MyComputer), folderName, "\\", Nome,
		".sl"), RichTextBoxStreamType::PlainText);

		StatusNovoProjeto = 1;
		this->Visible = false;
	}
}

private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	Nome = richTextBoxNome->Text;
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	
	StatusNovoProjeto = -1;
	this->Close();
}

private: System::Void NovoProjeto_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

	StatusNovoProjeto = -1;
	this->Close();
}

private: System::Void NovoProjeto_Load(System::Object^  sender, System::EventArgs^  e) {

	richTextBoxNome->Focus();
	richTextBoxNome->Text = "";
	richTextBoxLocal->Text = this->folderName;
	richTextBoxNome->TabIndex = 0;
}
};
}
