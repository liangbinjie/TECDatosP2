#ifndef COMPRA_H
#define COMPRA_H
using namespace std;
#include <iostream>
class compraN {
    // nodo compra pago
    private:
        int id;
        string nombre;
        int cant;
        int precio;
        compraN* siguiente;

        friend class pago;
    public:
        compraN();
        compraN(int id, string nombre, int cant, int precio);

};

typedef compraN *ppago;

class pago {
    private:
        ppago head;

        friend class listaCompra;
    public:
        pago();
        void insertar(ppago);
};

#endif