#include "listaCompra.h"

ListaCompra::ListaCompra() {
    primero = NULL;
}

void ListaCompra::agregar(int idCliente, int cp, int cc, int cr, int cm, string productos, bool dt) {
    if (primero == NULL) {
		primero = new NodoCompra(idCliente, cp, cc, cr, cm, productos, dt);
	} else {
		pNodoCompra aux = primero;
		while (aux->siguiente != NULL) {
			aux = aux->siguiente;
		}
		aux->siguiente = new NodoCompra(idCliente, cp, cc, cr, cm, productos, dt);
	}
	cout << "Compra en lista" << endl;
}

void ListaCompra::mostrar() {
    if (primero == NULL) {
        cout << "no hay compras" << endl;
    } else {
        pNodoCompra aux = primero;
        while (aux) {
            cout << "Cliente: " << aux->idCliente << " | Compra: " << aux->productos << endl;
            aux = aux->siguiente;
        }
    }
}
