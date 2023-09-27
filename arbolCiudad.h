#ifndef ARBOLCIUDAD_H
#define ARBOLCIUDAD_H

#include <iostream>
using namespace std;

#include "NodoCiudad.h"
#include <fstream>
#include <string>
#include <sstream>

class ArbolCiudad {
	private:
		NodoCiudad* raiz;
		
		//void insertarBalanceado(NodoCiudad* r, int id, string nombre, bool Hh, int x);
        //void insertar(int id, string nombre);
		//NodoPais* buscarAux(NodoPais* r, int id);
		void postorden(NodoCiudad* r);
		void inorden(NodoCiudad* r);
		void preorden(NodoCiudad* r);
		NodoCiudad* existeAux(NodoCiudad* r, int id);
		//NodoPais* existeAux(NodoPais* r, int id);
		//NodoPais* modificarAux(NodoPais* r, int id, string nombreNuevo);
	public:
		ArbolCiudad();
        void insertarBalanceado(NodoCiudad* &r, int id, string nombre, bool& Hh);
        void insertar(int id, int idPais, string nombre);
		void RotacionDobleIzquierda(NodoCiudad* &n, NodoCiudad* &n1);
        void RotacionDobleDerecha(NodoCiudad* &n, NodoCiudad* &n1);
        void RotacionSimpleDerecha(NodoCiudad* &n, NodoCiudad* &n1);
        void RotacionSimpleIzquierda(NodoCiudad* &n, NodoCiudad* &n1);
		bool existe(int id);

		//void insertar(int id, string nombre);
		//void cargarPais();
		//void buscar(int id);
		//bool existe(int id);
		//void modificar(int id, string nombreNuevo);
		
		void preorden();
		void inorden();
		void postorden();
		
		
};

#endif
