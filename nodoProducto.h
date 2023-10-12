#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H

#include <iostream>
using namespace std;

class NodoProducto {
    private:
        NodoProducto* siguiente;
        NodoProducto *anterior;
        int codPais;
        int codCiudad;
        int codRest;
        int codMenu;
        int codProducto;
        string nombre;
        int kcal;
        int precio;
        int cantidad;
        int contador;

        friend class ArbolProducto;
    
    public:
        NodoProducto(int cp, int cc, int cr, int cm, int cpro, string nombre, int kc, int p, int cant);
        NodoProducto(int cp, int cc, int cr, int cm, int cpro, string nombre, int kc, int p, int cant, NodoProducto* sigNodo);
};

#endif
