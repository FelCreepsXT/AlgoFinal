#include <iostream>
#include <conio.h>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "ArbolAVL.h"
#include "cAlmacenamiento.h"

using namespace std;
using namespace System;
using namespace System::IO;


void Imprime(cAlmacenamiento ele) {

	cout << "**************************************************" << endl;
	cout << "Nombre => " << ele.GET_Nombre() << endl;
	cout << "Contiene => " << ele.GET_Contiene() << endl;
	cout << "Primera Letra => " << ele.GET_LetraInicial() << endl;
	cout << "Ultima letra => " << ele.GET_LetraFinal() << endl;
	cout << "Anio => " << ele.GET_Anio() << endl;
	cout << "Mes => " << ele.GET_Mes() << endl;
	cout << "Dia => " << ele.GET_Dia() << endl;
	cout << "Extension => " << ele.GET_Extension() << endl;
	cout << "Tamanio(KB) => " << ele.GET_Tamanio() << "KB" << endl;
	cout << "Tamanio(MB) => " << ele.GET_Tamanio()/1024  << " MB"<< endl;
	cout << "Tamanio(GB) => " << ele.GET_Tamanio()/1048578 << " GB" << endl;
	cout << "**************************************************" << endl << endl << endl;
}

template<class Alma,class Int>
void Escanea(String^ carpeta,ArbolAVL<Alma,Int>*&arbol)
{
	auto files = Directory::GetFiles(carpeta,"*",SearchOption::AllDirectories);
	int archivos;
	
	
	for each  (auto item in files)
	{
		cAlmacenamiento almacen;
		almacen.SET_Nombre(msclr::interop::marshal_as<string>(Path::GetFileNameWithoutExtension(item)));
		almacen.SET_Contiene(msclr::interop::marshal_as<string>(Path::GetFileNameWithoutExtension(item)).length());
		almacen.SET_LetraInicial(msclr::interop::marshal_as<string>(Path::GetFileNameWithoutExtension(item)));
		almacen.SET_LetraFinal(msclr::interop::marshal_as<string>(Path::GetFileNameWithoutExtension(item)));
		///////////////////////////////////////////////////////
		almacen.SET_Anio(FileInfo(item).CreationTime.Year);
		almacen.SET_Mes(FileInfo(item).CreationTime.Month);
		almacen.SET_Dia(FileInfo(item).CreationTime.Day);
		///////////////////////////////////////////////////////
		almacen.SET_Extension(msclr::interop::marshal_as<string>(FileInfo(item).Extension));
		almacen.SET_Tamanio(FileInfo(item).Length);

		arbol->Insertar(almacen, almacen.GET_Tamanio());
		archivos++;
	}
	cout << endl << endl;
	if (archivos >= 1000) { cout << "Hay un total de " << archivos / 1000 << " x 1000 archivos." << endl; }
	else { cout << "Hay un total de " << archivos << " archivos." << endl; }
	cout << "El arbol fue llenado correctamente." << endl;
}

void Titulo(){
	int a = 18;
	int b = 5;
	Console::SetCursorPosition(a, b-1);
	cout << "o----------------------------------------------------------------------------------o" << endl;
	Console::SetCursorPosition(a, b);
	cout << "|  **********   **********   *            **********      **********   **      **  |" << endl;
	Console::SetCursorPosition(a, b+1);
	cout << "|  **               **       *            **              **            **    **   |" << endl;
	Console::SetCursorPosition(a, b+2);
	cout << "|  **               **       *            **              **             **  **    |" << endl;
	Console::SetCursorPosition(a, b+3);
	cout << "|  **               **       *            **              **              ****     |" << endl;
	Console::SetCursorPosition(a, b+4);
	cout << "|  **********       **       *            **********      **********       **      |" << endl;
	Console::SetCursorPosition(a, b+5);
	cout << "|  **               **       *            **********      **********       **      |" << endl;
	Console::SetCursorPosition(a, b+6);
	cout << "|  **               **       *            **              **              ****     |" << endl;
	Console::SetCursorPosition(a, b+7);
	cout << "|  **               **       *            **              **             **  **    |" << endl;
	Console::SetCursorPosition(a, b+8);
	cout << "|  **               **       *            **              **            **    **   |" << endl;
	Console::SetCursorPosition(a, b+9);
	cout << "|  **           **********   **********   **********      **********   **      **  |" << endl;
	Console::SetCursorPosition(a, b + 10);
	cout << "o----------------------------------------------------------------------------------o" << endl;
	cout << endl << endl << endl;
	Console::SetCursorPosition(28, 15);
	cout << "°                                                                 °" << endl;
	Console::SetCursorPosition(28, 16);
	cout << "|  Bienvenido, este proyecto es un explorar una ruta de archivo.  |" << endl;
	Console::SetCursorPosition(28, 17);
	cout << "|  \t\t\tPresione una tecla para continuar.            |" << endl;
	Console::SetCursorPosition(28, 18);
	cout << "°-----------------------------------------------------------------°" << endl;
	Console::SetCursorPosition(0, 20);
	cout << "\t\to---------------------------------------------------------------------------------------o" << endl;
	Console::SetCursorPosition(0, 21);
	cout << "\t\to  Este programa se encarga de encontrar todos los elementos de un archivo              o" << endl;
	Console::SetCursorPosition(0, 22);
	cout << "\t\to  Todo estos datos ingresan a una nodo que posteriormente son enviados a una ArbolAVL  o" << endl;
	Console::SetCursorPosition(0, 23);
	cout << "\t\to  Finalmente son imprimidos de forma ordenada dependiendo el tamanio                   o" << endl;
	Console::SetCursorPosition(0, 24);
	cout << "\t\to---------------------------------------------------------------------------------------o" << endl;
	_getch();
	system("cls");
}

void Creditos() {
	cout << "\to-----------------------------------------------------------------------------------------------------o" << endl;
	cout << "\t| Este programa fue codificado para poder cumplir el trabajo final de Algoritmo y Estructura de Datos |" << endl;
	cout << "\t| Los integrantes son:                                                                                |" << endl;
	cout << "\t|                 Luciano Lopez                                                                       |" << endl;
	cout << "\t|                 Wilmer Zevallos                                                                     |" << endl;
	cout << "\to-----------------------------------------------------------------------------------------------------o" << endl;
	_getch();
	system("cls");
}


void Ejecutor() {
	Titulo();
	ArbolAVL<cAlmacenamiento, int>*arbol;

	string direccion;
	bool verdad = true;
	int opcion;
	char temp[10];

	while (verdad) {
		system("cls");
		cout << endl << endl;
		cout << "\t\t\t\t\to--------------------------------o" << endl;
		cout << "\t\t\t\t\t|     File-Ex en un ArbolAVL     |" << endl;
		cout << "\t\t\t\t\to--------------------------------o" << endl;
		cout << "\t\t\t\t\t| 1.- Ingresar Ruta del Archivo. |" << endl;
		cout << "\t\t\t\t\t| 2.- Imprime arbol.             |" << endl;
		cout << "\t\t\t\t\t| 3.- Creditos.                  |" << endl;
		cout << "\t\t\t\t\t| 4.- Salir.                     |" << endl;
		cout << "\t\t\t\t\to--------------------------------o" << endl;
		cout << "\t\tIngrese una opcion => "; cin >> opcion;

		cin.getline(temp, 10);
		switch (opcion){
		case 1: {
			arbol = new ArbolAVL<cAlmacenamiento, int>(Imprime);
			cout << endl;
			Console::SetCursorPosition(0, 12);
			cout << "\to------------------------------------------------------------------------------------------------------o" << endl;
			Console::SetCursorPosition(0, 14);
			cout << "\to------------------------------------------------------------------------------------------------------o" << endl;
			Console::SetCursorPosition(0, 13);
			cout << "\to  Ingrese la dirrecion a escanear: "; getline(cin, direccion);
			if (direccion == "") { cout << "Coloque una direccion"; }
			else {
				if (Directory::Exists(msclr::interop::marshal_as<String^>(direccion))) {
					Escanea(msclr::interop::marshal_as<String^>(direccion),arbol);
				}
				else {
					Console::SetCursorPosition(0, 16);
					cout << "\tLa direccion no existe";
				}
			}
			_getch();

			break;
			}
		case 2: {
			system("cls");
			cout << "\t\t\t\t\t\t====================" << endl;
			cout << "\t\t\t\t\t\to Arbol en InOrder o" << endl;
			cout << "\t\t\t\t\t\t====================" << endl;
			cout << endl << endl;
			arbol->inOrder();
			_getch();
			break;
			}
		case 3: {
			Creditos();
			break;
			}
		case 4: {
			verdad = false;
			break;
			}
		default: {
			break;
			}
		}
	}
	cout << "\t\tGracias por usar el programa, hasta pronto" << endl;

	_getch();
}

int main() {
	Ejecutor();
	return 0;
}