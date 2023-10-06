#ifndef ARBOLCLIENTE_H
#define ARBOLCLIENTE_H

const int Max = 4; // Tama?o m¨¢ximo del nodo

#include <iostream>
using namespace std;

#include <fstream>
#include <sstream>

class Pagina {
public:
    string nombre[Max];
    int Cuenta;
    int Claves[Max];
    Pagina* Ramas[Max + 1];

    Pagina();
};

class ArbolCliente {
public:
    ArbolCliente();
    
    void Insertar(int C1, string nombre);
    void RecorridoPreorden();
    void cargarCliente();
    void buscar(int id);
    void modificar(int id, string nombreNuevo);

private:
    Pagina* Raiz;
    const static int Max = 4;

    void BuscarNodo(int Clave, Pagina* P, bool& Encontrado, int& K);
    void MeterHoja(int X, Pagina* Xder, Pagina* P, int K, string nombre, string nAux);
    void DividirNodo(int X, Pagina* Xder, Pagina* P, int K, int& Mda, Pagina*& Mder, string nombre, string nAux);
    void Empujar(int C1, Pagina* R, bool& EmpujarArriba, int& Mdna, Pagina*& Xr, string nombre, string nombreAux);
    void RecorridoPreorden(Pagina* nodo);
    void buscar(Pagina* nodo, int id);
    void modificar(Pagina* nodo, int id, string nuevoNombre);
};

#endif

