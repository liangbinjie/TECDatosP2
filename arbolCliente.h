#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H

#include <fstream>

#include "nodoCliente.h"
#include <sstream>

class ArbolCliente {
private:
    NodoCliente* primero;

public:
    ArbolCliente();

    void insertar(int id, std::string nombre);
    bool existeCliente(int id);
    void mostrar();
    bool eliminar(int id);
    void cargarCliente();
    bool buscarCliente(int id);
    void modificarNombre(int id, string nombre);
    void reporteClientes();
};

#endif
