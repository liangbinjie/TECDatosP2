#ifndef ARBOLRESTAURANTE_H
#define ARBOLRESTAURANTE_H

#include <iostream>
using namespace std;

#include "nodoRestaurante.h"

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

    public:
        ArbolRestaurante();
        void preordenM();
        void inordenM();
        void postorderM();
        void BusquedaM(int id, int idPais, int idCiudad);
        pnodoRest minimo(pnodoRest nodo);
        pnodoRest maximo(pnodoRest nodo);
        pnodoRest successor(pnodoRest nodo);
        pnodoRest predecessor(pnodoRest nodo);
        void RotacionIzquierda(pnodoRest nodo);
        void RotacionDerecha(pnodoRest nodo);
        void insertar(int idPais, int idCiudad, int valornuevo, string nombre);
        pnodoRest getRaiz();
        void MostrarRN();
};

#endif 