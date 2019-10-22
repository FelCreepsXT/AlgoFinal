#pragma once
#include<string>

using namespace std;

class cAlmacenador {
public:
	//////////////////
	string nombre;
	int contiene;
	string letrainicial;
	string letrafinal;
	//////////////////
	int anio;
	int mes;
	int dia;
	//////////////////
	string extension;
	double tamanio;
public:
	cAlmacenador() {
		/////////////////////////////
		nombre = "";
		contiene = 0;
		letrainicial = "";
		letrafinal = "";
		/////////////////////////////
		anio = 0;
		mes = 0;
		dia = 0;
		/////////////////////////////
		extension = "";
		tamanio = 0;	
	}
	~cAlmacenador() {}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	void SET_Nombre(string nombre) { this->nombre = nombre; }
	void SET_Contiene(int contiene) { this->contiene = contiene; }
	void SET_LetraInicial(string letrainicial) { this->letrainicial = letrainicial; }
	void SET_LetraFinal(string letrafinal) { this->letrafinal = letrafinal; }
	/////////////////////////////////////////////////////////////////////////////////////////////////
	string GET_Nombre() { return nombre; }
	int GET_Contiene() { return contiene; }
	string GET_LetraInicial() { return letrainicial; }
	string GET_LetraFinal() { return letrafinal; }
	/////////////////////////////////////////////////////////////////////////////////////////////////
	void SET_Anio(int anio) { this->anio = anio; }
	void SET_Mes(int mes) { this->mes = mes; }
	void SET_Dia(int dia) { this->dia = dia; }
	/////////////////////////////////////////////////////////////////////////////////////////////////
	int GET_Anio() { return anio; }
	int GET_Mes() { return mes; }
	int GET_Dia() { return dia; }
	/////////////////////////////////////////////////////////////////////////////////////////////////
	void SET_Tamaño(double tamanio) { this->tamanio = tamanio; }
	void SET_Extension(string extension) { this->extension = extension; }	
	/////////////////////////////////////////////////////////////////////////////////////////////////
	double GET_Tamanio() { return tamanio; }
	string GET_Extension() { return extension; }
};
	