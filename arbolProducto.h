#ifndef ARBOLPRODUCTO_H
#define ARBOLPRODUCTO_H

#include <iostream>
using namespace std;

#include "nodoPais.h"
#include "arbolPais.h"
#include "NodoCiudad.h"
#include "NodoProducto.h"
#include "listaRest.h"
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
		NodoProducto* existeAuxProducto(NodoProducto* &r, int id, int idPais, int idCiudad, int idRest, int idMenu);
		//NodoPais* existeAux(NodoPais* r, int id);
		NodoCiudad* modificarAux(NodoCiudad* r, int id, int idPais, string nombre);
	public:
		ArbolProducto();
        void insertarBalanceado(NodoProducto* &r, int id, int idPais, int idCiudad, int idRest, int idMenu, string nombre, bool& Hh);
        void insertarProducto(int id, int idPais, int idCiudad, int idRest, int idMenu, string nombre, ArbolPais& aPaises, ArbolCiudad& aCiudades, listaRest& aRest, ArbolMenu& aMenu);
		void RotacionDobleIzquierda(NodoProducto* &n, NodoProducto* &n1);
        void RotacionDobleDerecha(NodoProducto* &n, NodoProducto* &n1);
        void RotacionSimpleDerecha(NodoProducto* &n, NodoProducto* &n1);
        void RotacionSimpleIzquierda(NodoProducto* &n, NodoProducto* &n1);
		bool existeProducto(int id, int idPais, int idCiudad, int idRest, int idMenu, ArbolPais& aPaises, ArbolCiudad& aCiudad, listaRest& aRest, ArbolMenu& aMenu);

		//void insertar(int id, string nombre);
		void cargarProductos(ArbolPais& aPaises, ArbolCiudad& aCiudades, listaRest& aRest, ArbolMenu& aMenus);
		void buscarProducto(int id, int idPais, int idCiudad, int idRest, int idMenu, ArbolPais& aPaises, ArbolCiudad& aCiudad, listaRest& aRest, ArbolMenu& aMenu);
		//bool existe(int id);
		void modificar(int id, string nombre, int idPais, ArbolPais& aPaises);
		
		void preorden();
		void inorden();
		void postorden();
		
		
};

#endif
