#pragma once
#include "Almacenador.h"
#include <msclr\marshal_cppstd.h>
#include "cLista.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Resumen de Buscador
	/// </summary>
	public ref class Buscador : public System::Windows::Forms::Form
	{
	public:
		Buscador(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Buscador()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  BtnBuscador;
	private: System::Windows::Forms::TextBox^  TxtBuscador;
	protected:

	protected:

	private: System::Windows::Forms::Label^  lblTitulo;
	private: System::Windows::Forms::Label^  lblArchivo;
	private: System::Windows::Forms::ListBox^  lstArchi;

	private: System::Windows::Forms::Button^  BtnEsc;
	





	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BtnBuscador = (gcnew System::Windows::Forms::Button());
			this->TxtBuscador = (gcnew System::Windows::Forms::TextBox());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblArchivo = (gcnew System::Windows::Forms::Label());
			this->lstArchi = (gcnew System::Windows::Forms::ListBox());
			this->BtnEsc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// BtnBuscador
			// 
			this->BtnBuscador->BackColor = System::Drawing::Color::Red;
			this->BtnBuscador->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnBuscador->ForeColor = System::Drawing::Color::White;
			this->BtnBuscador->Location = System::Drawing::Point(522, 96);
			this->BtnBuscador->Name = L"BtnBuscador";
			this->BtnBuscador->Size = System::Drawing::Size(119, 29);
			this->BtnBuscador->TabIndex = 0;
			this->BtnBuscador->Text = L"Buscar Carpeta\r\n";
			this->BtnBuscador->UseVisualStyleBackColor = false;
			this->BtnBuscador->Click += gcnew System::EventHandler(this, &Buscador::BtnBuscador_Click);
			// 
			// TxtBuscador
			// 
			this->TxtBuscador->Location = System::Drawing::Point(72, 102);
			this->TxtBuscador->Name = L"TxtBuscador";
			this->TxtBuscador->Size = System::Drawing::Size(444, 20);
			this->TxtBuscador->TabIndex = 1;
			// 
			// lblTitulo
			// 
			this->lblTitulo->BackColor = System::Drawing::Color::Red;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"MV Boli", 24.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(0, 0);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(655, 68);
			this->lblTitulo->TabIndex = 2;
			this->lblTitulo->Text = L"FILEEXP";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblArchivo
			// 
			this->lblArchivo->AutoSize = true;
			this->lblArchivo->Location = System::Drawing::Point(20, 104);
			this->lblArchivo->Name = L"lblArchivo";
			this->lblArchivo->Size = System::Drawing::Size(46, 13);
			this->lblArchivo->TabIndex = 3;
			this->lblArchivo->Text = L"Archivo:";
			// 
			// lstArchi
			// 
			this->lstArchi->FormattingEnabled = true;
			this->lstArchi->Location = System::Drawing::Point(12, 162);
			this->lstArchi->Name = L"lstArchi";
			this->lstArchi->Size = System::Drawing::Size(629, 303);
			this->lstArchi->TabIndex = 4;
			// 
			// BtnEsc
			// 
			this->BtnEsc->BackColor = System::Drawing::Color::Red;
			this->BtnEsc->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnEsc->ForeColor = System::Drawing::Color::White;
			this->BtnEsc->Location = System::Drawing::Point(312, 128);
			this->BtnEsc->Name = L"BtnEsc";
			this->BtnEsc->Size = System::Drawing::Size(89, 32);
			this->BtnEsc->TabIndex = 5;
			this->BtnEsc->Text = L"Escanear";
			this->BtnEsc->UseVisualStyleBackColor = false;
			this->BtnEsc->Click += gcnew System::EventHandler(this, &Buscador::BtnEsc_Click);
			// 
			// Buscador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(653, 470);
			this->Controls->Add(this->lstArchi);
			this->Controls->Add(this->BtnEsc);
			this->Controls->Add(this->lblArchivo);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->TxtBuscador);
			this->Controls->Add(this->BtnBuscador);
			this->Name = L"Buscador";
			this->Text = L"Buscador";
			this->Load += gcnew System::EventHandler(this, &Buscador::Buscador_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		
	private: System::Void Buscador_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void BtnBuscador_Click(System::Object^  sender, System::EventArgs^  e) {

		FolderBrowserDialog ^Archivo = gcnew FolderBrowserDialog();
		String^ file;



		if (Archivo->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			file = Archivo->SelectedPath;
			TxtBuscador->Text = "" + file;
		}
		else {
			TxtBuscador->Text = "";
		}

		//De String^ a string
			//asd = msclr::interop::marshal_as<std::string>(TxtBuscador->Text);
			//nuevo->SET_Nombre(asd);
		//De string a String^
			//lblTitulo->Text = "" + msclr::interop::marshal_as<String ^>(nuevo->GET_Nombre());
	}


	private: System::Void BtnEsc_Click(System::Object^  sender, System::EventArgs^  e) {
		if (TxtBuscador->Text != "") {
			cLista<cAlmacenador>List;
			lstArchi->Items->Clear();
			DirectoryInfo ^di = gcnew DirectoryInfo(TxtBuscador->Text);

			for each (auto item in di->GetFiles())
			{
				cAlmacenador nuevo;

				/////////////////////////////////////////////////////////////////////////////////////////////////
				int EliminaExte = item->Name->LastIndexOf(".");
				String ^Nombre = item->Name->Substring(0, EliminaExte);

				string nombre1 = msclr::interop::marshal_as<string>(Nombre);

				string inicio = msclr::interop::marshal_as<string>(item->Name->Substring(0, 1));
				string ultima = msclr::interop::marshal_as<string>(item->Name->Substring(nombre1.length() - 1, 1));

				/////////////////////////////////////////////////////////////////////////////////////////////////
				nuevo.SET_Nombre(msclr::interop::marshal_as<string>(Nombre));
				nuevo.SET_Contiene(EliminaExte);
				nuevo.SET_LetraInicial(inicio);
				nuevo.SET_LetraFinal(ultima);
				/////////////////////////////////////////////////////////////////////////////////////////////////
				nuevo.SET_Anio(item->CreationTime.Year);
				nuevo.SET_Mes(item->CreationTime.Month);
				nuevo.SET_Dia(item->CreationTime.Day);
				////////////////////////////////////////////////////////
				String ^Extension = item->Extension;
				double Tamanio = item->Length;
				////////////////////////////////////////////////////////]
				nuevo.SET_Extension(msclr::interop::marshal_as<string>(Extension));
				nuevo.SET_Tamaño(Tamanio);
				////////////////////////////////////////////////////////]
				List.InsertarInicio(nuevo);
				//lblTitulo->Text = "" + msclr::interop::marshal_as<String ^>(nuevo.GET_LetraInicial());
			}

			ShowList(List);
		}
		
	}
	
	int nl = 0;
	String^ name;
	template<class T>
	void ShowList(cLista<T>l) {
		cLista<T>::cIterador it;
		for (it = l.inicial(); it != l.ultimo(); it++) {
			nl = (*it).GET_Contiene();
			name = msclr::interop::marshal_as<String^>((*it).GET_Nombre());
			if (nl <= 8) {
				name += "		";
			}
			if (nl > 8) {
				name += "	";
			}
			lstArchi->Items->Add(name + "	" + (*it).GET_Anio() + " - " + (*it).GET_Mes() + " - " + (*it).GET_Dia()
				+ "	" + (*it).GET_Tamanio() + "	" + msclr::interop::marshal_as<String^>((*it).GET_Extension())
				+ "	" + msclr::interop::marshal_as<String^>((*it).GET_LetraInicial()) + "	" + msclr::interop::marshal_as<String^>((*it).GET_LetraFinal()) + "	" + (*it).GET_Contiene());
		}
	}

	
};
}
