#pragma once
#include "string"

using namespace std;

class cAlmacenamiento {
private:
	//////////////////
	string nombre;
	int contiene;
	//////////////////
	int anio;
	int mes;
	int dia;
	//////////////////
	string extension;
	double tamanio;
	/////////////////
	char letrainicial;
	char letrafinal;
	
public:
	cAlmacenamiento() {
		/////////////////////////////
		nombre = "";
		contiene = 0;
		letrainicial = ' ';
		letrafinal = ' ';
		/////////////////////////////
		anio = 0;
		mes = 0;
		dia = 0;
		/////////////////////////////
		extension = "";
		tamanio = 0;
	}
	~cAlmacenamiento() {}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	void SET_Nombre(string nombre) { this->nombre = nombre; }
	void SET_Contiene(int contiene) { this->contiene = contiene; }
	void SET_LetraInicial(string letrastring) {
		if (letrastring == "") { letrainicial = ' '; }
		else { letrainicial = letrastring[0]; }
	}
	void SET_LetraFinal(string letrastring) {
		if (letrastring == "") { letrafinal = ' '; }
		else { letrafinal = letrastring[letrastring.length() - 1]; }
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	string GET_Nombre() { return nombre; }
	int GET_Contiene() { return contiene; }
	char GET_LetraInicial() { return letrainicial; }
	char GET_LetraFinal() { return letrafinal; }
	/////////////////////////////////////////////////////////////////////////////////////////////////
	void SET_Anio(int anio) { this->anio = anio; }
	void SET_Mes(int mes) { this->mes = mes; }
	void SET_Dia(int dia) { this->dia = dia; }
	/////////////////////////////////////////////////////////////////////////////////////////////////
	int GET_Anio() { return anio; }
	int GET_Mes() { return mes; }
	int GET_Dia() { return dia; }
	/////////////////////////////////////////////////////////////////////////////////////////////////
	void SET_Tamanio(double tamanio) { this->tamanio = tamanio; }
	void SET_Extension(string extension) { this->extension = extension; }
	/////////////////////////////////////////////////////////////////////////////////////////////////
	double GET_Tamanio() { return tamanio; }
	string GET_Extension() { return extension; }
};