#pragma once
#include "cNodo.h"

template<class T>
class cLista {
private:
	cNodo<T>*inicio;
	int n;
public:
	////////////////////////////////////////////////////////////////////////////////////////
	class cIterador {
		cNodo<T>*temp;
	public:
		cIterador(cNodo<T>*temp = nullptr) { this->temp = temp; }
		~cIterador() {}

		void operator ++() { temp = temp->siguiente; }
		bool operator !=(cIterador it) { return temp != it.temp; }
		T operator *() { return temp->valor; }
	};
	////////////////////////////////////////////////////////////////////////////////////////
	cIterador inicial() { return cIterador(inicio); }
	cIterador ultimo() { return cIterador(nullptr); }
	////////////////////////////////////////////////////////////////////////////////////////
	cLista() { inicio = nullptr; n = 0; }
	~cLista() {
		cNodo<T>* temp;
		while (inicio != nullptr) {
			temp = inicio;
			inicio = inicio->siguiente;
			temp = nullptr;
			delete temp;
		}
		inicio = nullptr;
		delete inicio;
	}
	////////////////////////////////////////////////////////////////////////////////////////
	void InsertarInicio(T valor) {
		cNodo<T>*Nodo = new cNodo<T>(valor);
		if (inicio == nullptr) { inicio = Nodo;}
		else { Nodo->siguiente = inicio; }
		n++;
		inicio = Nodo;		
		Nodo = nullptr;
		delete Nodo;		
	}
	int GET_n() { return n; }

};