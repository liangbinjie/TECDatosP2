#ifndef ARBOLMENU_H
#define ARBOLMENU_H

#include "nodoMenu.h"
using namespace std;
#include <fstream>
#include <sstream>
#include "arbolRestaurante.h"
#include "arbolCiudad.h"
#include "arbolPais.h"

class ArbolMenu {
	public:
		ArbolMenu();
		void insertar(int clave, int idPais, int idCiudad, int idRest, string nombre, ArbolPais paises, ArbolCiudad ciudades, ArbolRestaurante restaurantes);
		void mostrar();
		bool existe(int clave, int idPais, int idCiudad, int idRest);
		void buscar(int clave, int idPais, int idCiudad, int idRest);
		void modificar(int clave, int idPais, int idCiudad, int idRest, string nuevoNombre);
		void cargarMenus(ArbolPais paises, ArbolCiudad ciudades, ArbolRestaurante rests);
		void reporte();
	
	private:
		NodoMenu* raiz;
		NodoMenu* sesgar(NodoMenu* nodo);
		NodoMenu* dividir(NodoMenu* nodo);
		NodoMenu* insertarRec(NodoMenu* nodo, int clave, int idPais, int idCiudad, int idRest, string nombre);
		void mostrarRec(NodoMenu* nodo, int profundidad);
		bool existeRec(NodoMenu* nodo, int clave, int idPais, int idCiudad, int idRest);
		void buscarRec(NodoMenu* nodo, int clave, int idPais, int idCiudad, int idRest);
		void modificar(NodoMenu* nodo, int clave, int idPais, int idCiudad, int idRest, string nuevoNombre);
		void reporte(NodoMenu* nodo, int profundidad, ofstream& archivo);
		
		
};

#endif
