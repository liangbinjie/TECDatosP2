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
        pnodoRest Busqueda(pnodoRest nodo, int numbuscado);
        void rbModificar(pnodoRest uRaiz, pnodoRest vValor);
        void insertarBalanceado(pnodoRest NodoEva);
        void MostrarRN(pnodoRest raiz, string indent, bool ultimo);

    public:
        ArbolRestaurante();
        void preordenM();
        void inordenM();
        void postorderM();
        pnodoRest BusquedaM(int numbuscado);
        pnodoRest minimo(pnodoRest nodo);
        pnodoRest maximo(pnodoRest nodo);
        pnodoRest successor(pnodoRest nodo);
        pnodoRest predecessor(pnodoRest nodo);
        void RotacionIzquierda(pnodoRest nodo);
        void RotacionDerecha(pnodoRest nodo);
        void insertar(int valornuevo);
        pnodoRest getRaiz();
        void MostrarRN();
};

#endif 