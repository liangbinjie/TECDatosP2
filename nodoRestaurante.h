#ifndef NODORESTAURANTE_H
#define NODORESTAURANTE_H

#include <iostream>
using namespace std;

class NodoRestaurante {
    public:
        int idPais;
        int idCiudad;
        int valor;
        string nombre;
        int cont; // contador para busquedas
        NodoRestaurante *padre;
        NodoRestaurante *Hizq;
        NodoRestaurante *Hder;
        int color;

        friend class ArbolRestaurante;
};

typedef NodoRestaurante *pnodoRest;

#endif