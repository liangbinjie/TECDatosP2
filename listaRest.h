#ifndef LISTAREST_H
#define LISTAREST_H

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "arbolCiudad.h"
#include "arbolPais.h"
#include "arbolRestaurante.h"

class nodoRest {
    private:
        int id;
        int idPais;
        int idCiudad;
        string nombre;
        nodoRest* siguiente;
        friend class listaRest;
    public:
        nodoRest(int id, int idPais, int idCiudad, string nombre);

};

// typedef nodoRest* pnodoRest;

class listaRest {
    private:
        nodoRest* head;
    
    public:
        listaRest();
        void insertar(int id, int idPais, int idCiudad, string nombre, ArbolPais &paises, ArbolCiudad &ciudades, ArbolRestaurante& restaurantes);
        bool existe(nodoRest* aux);
        bool existePP(int id, int idPais, int idCiudad);
        void cargarRest(ArbolPais &paises, ArbolCiudad &ciudades, ArbolRestaurante& restaurantes);
};

#endif
