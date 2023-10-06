#include "ArbolCliente.h"
#include <iostream>

Pagina::Pagina() {
    Cuenta = 0;
    for (int i = 0; i <= Max; i++) {
        Ramas[i] = nullptr;
    }
}

ArbolCliente::ArbolCliente() {
    Raiz = nullptr;
}

void ArbolCliente::Insertar(int C1, string nombre) {
    bool EmpujarArriba;
    int X;
    Pagina* Xr = nullptr;
    Empujar(C1, Raiz, EmpujarArriba, X, Xr, nombre, nombre);

    if (EmpujarArriba) {
        Pagina* P = new Pagina;
        P->nombre[0] = nombre;
        P->Cuenta = 1;
        P->Claves[0] = X;
        P->Ramas[0] = Raiz;
        P->Ramas[1] = Xr;
        Raiz = P;
    }
}

void ArbolCliente::RecorridoPreorden() {
    RecorridoPreorden(Raiz);
    std::cout << std::endl;
}

void ArbolCliente::BuscarNodo(int Clave, Pagina* P, bool& Encontrado, int& K) {
    if (Clave < P->Claves[0]) {
        Encontrado = false;
        K = 0;
    } else {
        K = P->Cuenta;
        while (Clave < P->Claves[K - 1] && K > 1) {
            K--;
        }
        Encontrado = (Clave == P->Claves[K - 1]);
    }
}

void ArbolCliente::MeterHoja(int X, Pagina* Xder, Pagina* P, int K, string nombre, string nombreAux) {
    for (int I = P->Cuenta; I >= K + 1; I--) {
        P->Claves[I] = P->Claves[I - 1];
        P->nombre[I] = P->nombre[I - 1];
        P->Ramas[I + 1] = P->Ramas[I];
    }
    
    P->Claves[K] = X;
    P->nombre[K] = nombreAux;
    P->Ramas[K + 1] = Xder;
    P->Cuenta++;
}

void ArbolCliente::DividirNodo(int X, Pagina* Xder, Pagina* P, int K, int& Mda, Pagina*& Mder, string nombre, string nombreAux) {
    int Posmda;
    if (K <= Max / 2) {
        Posmda = Max / 2;
    } else {
        Posmda = Max / 2 + 1;
    }

    Mder = new Pagina;

    for (int I = Posmda + 1; I <= Max; I++) {
        Mder->Claves[I - Posmda - 1] = P->Claves[I - 1];
        Mder->nombre[I - Posmda - 1] = P->nombre[I - 1];
        Mder->Ramas[I - Posmda] = P->Ramas[I];
    }

    Mder->Cuenta = Max - Posmda;
    P->Cuenta = Posmda;

    if (K <= Max / 2) {
        MeterHoja(X, Xder, P, K, nombre, nombreAux);
    } else {
        MeterHoja(X, Xder, Mder, K - Posmda, nombre, nombreAux);
    }

    Mda = P->Claves[P->Cuenta - 1];
    Mder->Ramas[0] = P->Ramas[P->Cuenta];
    P->Cuenta--;
}

void ArbolCliente::Empujar(int C1, Pagina* R, bool& EmpujarArriba, int& Mdna, Pagina*& Xr, string nombre, string nombreAux) {
    if (R == nullptr) {
        EmpujarArriba = true;
        Mdna = C1;
        nombreAux = nombre;
        Xr = nullptr;
    } else {
        bool Esta;
        int K;
        BuscarNodo(C1, R, Esta, K);

        if (Esta) {
            std::cout << "Cliente repetido" << std::endl;
            EmpujarArriba = false;
        } else {
            Empujar(C1, R->Ramas[K], EmpujarArriba, Mdna, Xr, nombre, nombreAux);

            if (EmpujarArriba) {
                if (R->Cuenta < Max) {
                    EmpujarArriba = false;
                    MeterHoja(Mdna, Xr, R, K, nombre, nombreAux);
                } else {
                    EmpujarArriba = true;
                    DividirNodo(Mdna, Xr, R, K, Mdna, Xr, nombre, nombreAux);
                }
            }
        }
    }
}

void ArbolCliente::RecorridoPreorden(Pagina* nodo) {
    if (nodo != nullptr) {
        for (int i = 0; i < nodo->Cuenta; i++) {
            std::cout << nodo->Claves[i] << nodo->nombre[i] << " ";
        }
        for (int i = 0; i <= nodo->Cuenta; i++) {
            RecorridoPreorden(nodo->Ramas[i]);
        }
    }
}

void ArbolCliente::buscar(int id) {
    buscar(Raiz, id);
}

void ArbolCliente::buscar(Pagina* nodo, int id) {
    if (nodo != nullptr) {
        for (int i = 0; i < nodo->Cuenta; i++) {
            if (nodo->Claves[i] == id) {
                cout << "Nombre: " << nodo->nombre[i] << endl;
                cout << "ID: " << nodo->Claves[i] << endl;
                return;
            }
        }
        for (int i = 0; i <= nodo->Cuenta; i++) {
            RecorridoPreorden(nodo->Ramas[i]);
        }
    }
}

void ArbolCliente::modificar(int id, string nombre) {
    modificar(Raiz, id, nombre);
}

void ArbolCliente::modificar(Pagina* nodo, int id, string nombre) {
    if (nodo != nullptr) {
        for (int i = 0; i < nodo->Cuenta; i++) {
            if (nodo->Claves[i] == id) {
                nodo->nombre[i] = nombre;
                cout << "Nombre modificado";
                return;
            }
        }
        for (int i = 0; i <= nodo->Cuenta; i++) {
            RecorridoPreorden(nodo->Ramas[i]);
        }
    }
    cout << "No se encontro el cliente" << endl;
}

void ArbolCliente::cargarCliente() {
	ifstream archivo("Archivos/Clientes.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, name, ';');

        Insertar(idP, name);
    }
    archivo.close();
}


void ArbolCliente::reporte() {
    reporte(Raiz);
}


void ArbolCliente::reporte(Pagina* nodo) {
    ofstream archivo;
    archivo.open ("reportes/clientes.txt");
    if (nodo != nullptr) {
        for (int i = 0; i < nodo->Cuenta; i++) {
            archivo << "ID: " << nodo->Claves[i] << " | Cliente: " << nodo->nombre[i] << endl;
        }
        for (int i = 0; i <= nodo->Cuenta; i++) {
            RecorridoPreorden(nodo->Ramas[i]);
        }
    }
    
    
    archivo.close();
}