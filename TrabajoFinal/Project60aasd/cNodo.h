#pragma once

template<class Alma, class Int>
class cNodo {
public:
	cNodo<Alma, Int> *derecha;
	cNodo<Alma, Int>*izquierda;
	int altura;
	Int elemento;
	Alma elementos;
public:
	cNodo() {
		derecha = izquierda = nullptr;
		altura = 1;
	}
};
