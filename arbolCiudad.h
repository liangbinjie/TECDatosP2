#ifndef ARBOLCIUDAD_H
#define ARBOLCIUDAD_H

#include <iostream>
using namespace std;

#include "nodoPais.h"
#include "arbolPais.h"
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
		NodoCiudad* existeAuxCiudad(NodoCiudad* r, int id, int idPais);
		//NodoPais* existeAux(NodoPais* r, int id);
		NodoCiudad* modificarAux(NodoCiudad* r, int id, int idPais, string nombre);
	public:
		ArbolCiudad();
        void insertarBalanceado(NodoCiudad* &r, int id, int idPais, string nombre, bool& Hh);
        void insertar(int id, int idPais, string nombre, ArbolPais& aPaises);
		void RotacionDobleIzquierda(NodoCiudad* &n, NodoCiudad* &n1);
        void RotacionDobleDerecha(NodoCiudad* &n, NodoCiudad* &n1);
        void RotacionSimpleDerecha(NodoCiudad* &n, NodoCiudad* &n1);
        void RotacionSimpleIzquierda(NodoCiudad* &n, NodoCiudad* &n1);
		bool existeCiudad(int id, int idPais, ArbolPais& aPaises);

		//void insertar(int id, string nombre);
		void cargarCiudades(ArbolPais& aPaises);
		void buscarCiudad(int id, int idPais, ArbolPais& aPaises);
		//bool existe(int id);
		void modificar(int id, string nombre, int idPais, ArbolPais& aPaises);
		
		void preorden();
		void inorden();
		void postorden();
		
		
};

#endif
