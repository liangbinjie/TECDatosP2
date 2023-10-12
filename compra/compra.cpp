#include "compra.h"


compraN::compraN() {
    id = 0;
    nombre = "";
    cant = 0;
    precio = 0;
    siguiente = NULL;
}

compraN::compraN(int id, string nombre, int cant, int precio) {
    id = id;
    nombre = nombre;
    cant = cant;
    precio = precio;
    siguiente = NULL;
}


pago::pago() {
    head = NULL;
}

void pago::insertar(ppago n) {
    n = head;
    if (head == NULL) {
        head = n;
    } else {
        ppago aux = head;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = n;
    }
}