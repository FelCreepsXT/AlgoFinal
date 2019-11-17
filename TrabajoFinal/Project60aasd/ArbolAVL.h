#pragma once
#include "ArbolAVL.h"
#include "cNodo.h"

using namespace std;

template<class Alma,class Int>
class ArbolAVL {
private:
	cNodo<Alma, Int>*raiz;
	void(*procesar)(Alma);

	int _altura(cNodo<Alma, Int>*&nodo) {
		if (nodo == nullptr)return 0;
		return nodo->altura;
	}

	int _max(int a, int b) { return (a > b) ? a : b; }

	void rotaDerecha(cNodo<Alma, Int>*a, cNodo<Alma, Int>*&b, cNodo<Alma, Int>*&c) {
		c = b;
		a->izquierda = b->derecha;
		c->derecha = a;
	}

	void rotaIzquierda(cNodo<Alma, Int>*a, cNodo<Alma, Int>*&b, cNodo<Alma, Int>*&c) {
		c = b;
		a->derecha = b->izquierda;
		c->izquierda = a;
	}

	void Nivelar(cNodo<Alma, Int>*Padre, cNodo<Alma, Int>*&Izquierda, cNodo<Alma, Int>*&Derecha) {
		if (Izquierda == nullptr && Derecha == nullptr) { Padre->altura = 1; return; }
		else {
			if (Izquierda != nullptr) { Nivelar(Izquierda, Izquierda->izquierda, Izquierda->derecha); }
			if (Derecha != nullptr) { Nivelar(Derecha, Derecha->izquierda, Derecha->derecha); }
			int altI = _altura(Izquierda);
			int altD = _altura(Derecha);
			Padre->altura = 1 + _max(altI, altD);
		}
	}

	void _insertar(cNodo<Alma,Int>*&nodo, Alma elementos, Int elemento) {
		if (nodo == nullptr) {
			nodo = new cNodo < Alma, Int>();
			nodo->elementos = elementos;
			nodo->elemento = elemento;
		}
		else if (elemento >= nodo->elemento) { _insertar(nodo->derecha, elementos, elemento); }
		else if (elemento < nodo->elemento) { _insertar(nodo->izquierda, elementos, elemento); }
		//////////////////////////////////////////////////////////////////////////////////////////
		int hi = _altura(nodo->izquierda);
		int hd = _altura(nodo->derecha);
		int d = hd - hi;
		bool nivelado = false;
		//////////////////////////////////////////////////////////////////////////////////////////
		if (d < -1) {
			int hni = _altura(nodo->izquierda->izquierda);
			int hnd = _altura(nodo->izquierda->derecha);

			if (hni >= hnd) { rotaDerecha(nodo, nodo->izquierda, nodo); }
			else {
				rotaIzquierda(nodo->izquierda, nodo->izquierda->derecha, nodo->izquierda);
				rotaDerecha(nodo, nodo->izquierda, nodo);
			}
			Nivelar(raiz, raiz->izquierda, raiz->derecha);
			nivelado = true;
		}
		//////////////////////////////////////////////////////////////////////////////////////////
		if (d > 1) {
			int hni = _altura(nodo->derecha->izquierda);
			int hnd = _altura(nodo->derecha->derecha);

			if (hnd >= hni) { rotaIzquierda(nodo, nodo->derecha, nodo); }
			else {
				rotaDerecha(nodo->derecha, nodo->derecha->izquierda, nodo->derecha);
				rotaIzquierda(nodo, nodo->derecha, nodo);
			}
			Nivelar(raiz, raiz->izquierda, raiz->derecha);
			nivelado = true;
		}
		//////////////////////////////////////////////////////////////////////////////////////////
		if (nivelado == false) { nodo->altura = 1 + _max(hd, hi); }
	}

	void _inOrder(cNodo<Alma, Int>*&nodo) {
		if (nodo == nullptr)return;
		_inOrder(nodo->izquierda);
		procesar(nodo->elementos);
		_inOrder(nodo->derecha);
	}

public:
	ArbolAVL(void(*pf)(Alma)) {
		raiz = nullptr;
		procesar = pf;
	}

	void Insertar(Alma es, Int e) { _insertar(raiz,es, e); }
	void inOrder() { _inOrder(raiz); }
};