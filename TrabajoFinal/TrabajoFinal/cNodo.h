#pragma once

template<class T>
class cNodo {
public:
	cNodo<T>*siguiente;
	T valor;
public:
	cNodo(T valor=0,cNodo<T>*siguiente = nullptr){
		this->valor = valor;
		this->siguiente = siguiente;
	}
	~cNodo(){}
};