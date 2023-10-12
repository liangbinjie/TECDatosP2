#ifndef ARBOLPRODUCTO_H
#define ARBOLPRODUCTO_H

#include <iostream>
#include "nodoProducto.h"
#include "arbolPais.h"
#include "arbolCiudad.h"
#include "listaRest.h"
#include "arbolMenu.h"
#include <sstream>
using namespace std;
#include <fstream>

typedef NodoProducto *pNodoProducto;

class ArbolProducto {
    private:
        pNodoProducto primero;
    
    public:
        ArbolProducto();
        // ListaProducto()

        bool ArbolVacio();
        void insertarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, int cant, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRests, ArbolMenu& lMenus);
        bool existeProducto(int pCodPais, int pCodCiudad, int pCodRes, int pCodMenu, int pCodProducto, ArbolPais& lPais, ArbolCiudad& lCiudad, listaRest& lRest, ArbolMenu& lMenuRest);
        void buscarProducto(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenuRest);
        void mostrar();
		void reporteProducto(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenu);
        void cargarProductos(ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRests, ArbolMenu& lMenus);
        void modificarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenu);
        void mostrarProductosMenu(int codPais, int codCiudad, int codRest, int codMenu);
        void precio(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenuRest);
        void productoMasComprado();
        void aumentarCompra(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ArbolPais& lPais, ArbolCiudad& lCiudad, listaRest& lRest, ArbolMenu& lMenuRest );
        int getProducto(int id, int idP, int idC, int idR, int idM);
};

#endif