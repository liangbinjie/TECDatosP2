#ifndef ARBOLPRODUCTO_H
#define ARBOLPRODUCTO_H

#include <iostream>
using namespace std;

#include "nodoPais.h"
#include "arbolPais.h"
#include "NodoCiudad.h"
#include "NodoProducto.h"
#include <fstream>
#include <string>
#include <sstream>

class ArbolProducto {
	private:
		NodoProducto* raiz;
		
		//void insertarBalanceado(NodoCiudad* r, int id, string nombre, bool Hh, int x);
        //void insertar(int id, string nombre);
		//NodoPais* buscarAux(NodoPais* r, int id);
		void postorden(NodoProducto* r);
		void inorden(NodoProducto* r);
		void preorden(NodoProducto* r);
		NodoProducto* existeAuxProducto(NodoProducto* r, int id, int idPais, int idCiudad, int idMenu);
		//NodoPais* existeAux(NodoPais* r, int id);
		NodoCiudad* modificarAux(NodoCiudad* r, int id, int idPais, string nombre);
	public:
		ArbolProducto();
        void insertarBalanceado(NodoProducto* &r, int id, int idPais, int idCiudad, int idMenu, string nombre, bool& Hh);
        void insertarProducto(int id, int idPais, int idCiudad, int idMenu, string nombre, ArbolPais& aPaises, ArbolCiudad& aCiudades);
		void RotacionDobleIzquierda(NodoProducto* &n, NodoProducto* &n1);
        void RotacionDobleDerecha(NodoProducto* &n, NodoProducto* &n1);
        void RotacionSimpleDerecha(NodoProducto* &n, NodoProducto* &n1);
        void RotacionSimpleIzquierda(NodoProducto* &n, NodoProducto* &n1);
		bool existeProducto(int id, int idPais, int idCiudad, int idMenu, ArbolPais& aPaises, ArbolCiudad& aCiudades);

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
