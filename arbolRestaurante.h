#ifndef ARBOLRESTAURANTE_H
#define ARBOLRESTAURANTE_H

#include <iostream>
using namespace std;

#include <fstream>
#include <sstream>

#include "nodoRestaurante.h"
#include "arbolCiudad.h"
#include "arbolPais.h"

class ArbolRestaurante {
    private:
        pnodoRest raiz;
        pnodoRest TNULL;
    
        void initializeNULLNode(pnodoRest nodo, pnodoRest padre);
        void preOrden(pnodoRest nodo);
        void inOrden(pnodoRest nodo);
        void postOrden(pnodoRest nodo);
        pnodoRest Busqueda(pnodoRest nodo, int id, int idPais, int idCiudad);
        void rbModificar(pnodoRest uRaiz, pnodoRest vValor);
        void insertarBalanceado(pnodoRest NodoEva);
        void MostrarRN(pnodoRest raiz, string indent, bool ultimo);
        pnodoRest existeAux(pnodoRest nodo, int id, int idPais, int idCiudad);
        void modificarAux(pnodoRest nodo, int id, int idPais, int idCiudad, string nuevoNombre);

    public:
        ArbolRestaurante();
        void preordenM();
        void inordenM();
        void postorderM();
        void BusquedaM(int id, int idPais, int idCiudad);
        bool existe(int id, int idPais, int idCiudad);
        pnodoRest minimo(pnodoRest nodo);
        pnodoRest maximo(pnodoRest nodo);
        pnodoRest successor(pnodoRest nodo);
        pnodoRest predecessor(pnodoRest nodo);
        void RotacionIzquierda(pnodoRest nodo);
        void RotacionDerecha(pnodoRest nodo);
        void insertar(int idPais, int idCiudad, int valornuevo, string nombre, ArbolPais &paises, ArbolCiudad &ciudades);
        pnodoRest getRaiz();
        void MostrarRN();
        void cargarRests(ArbolPais &paises, ArbolCiudad &ciudades);
        void modificar(int id, int idPais, int idCiudad, string nuevoNombre);
};

#endif 