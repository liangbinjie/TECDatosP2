#include "listaCompra.h"

ListaCompra::ListaCompra() {
    primero = NULL;
}

void ListaCompra::agregar(int idCliente, int cp, int cc, int cr, int cm, string productos, bool dt, int costo) {
    if (primero == NULL) {
		primero = new NodoCompra(idCliente, cp, cc, cr, cm, productos, dt, costo);
	} else {
		pNodoCompra aux = primero;
		while (aux->siguiente != NULL) {
			aux = aux->siguiente;
		}
		aux->siguiente = new NodoCompra(idCliente, cp, cc, cr, cm, productos, dt, costo);
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

void ListaCompra::pagar() {
    if (primero == NULL) {
        cout << "No hay compras" << endl;
    } else {
        ofstream archivo;
        archivo.open("factura/" + to_string(primero->idCliente) + ".txt");
        cout << "Pagas en efectivo o tarjeta?\n1) Efectivo\n2) Tarjeta\n> " << endl;
        int op;
        cin >> op;
        switch (op) {
            case 1:
                archivo << "Pedido de cliente: " << primero->idCliente << "\n" << primero->productos << "\nSubtotal: $"<< primero->costo << "Pagado con efectivo 1%"<< "\nTotal: $" << primero->costo * 0.99 <<  endl;
                cout << "Pedido de cliente: " << primero->idCliente << "\n" << primero->productos << "\nSubtotal: $"<< primero->costo << "\nPagado con efectivo 1%"<< "\nTotal: $" << primero->costo * 0.99 <<  endl;
                break;
            case 2:
                archivo << "Pedido de cliente: " << primero->idCliente << "\n" << primero->productos << "\nSubtotal: $"<< primero->costo << "\nPagado con tarjeta 3%"<< "\nTotal: $" << primero->costo * 0.97 <<  endl;
                cout << "Pedido de cliente: " << primero->idCliente << "\n" << primero->productos << "\nSubtotal: $"<< primero->costo << "\nPagado con tarjeta 3%"<< "\nTotal: $" << primero->costo * 0.97 <<  endl;
                break;
        } 
		
		int idTemp = primero->idCliente;
		if (primero->siguiente == NULL) {
			pNodoCompra temp = primero;
			primero = NULL;
			delete temp;
		} else {
			pNodoCompra aux = primero;
			primero = primero->siguiente;
			delete aux;
		}
        archivo.close();
	}
}

void ListaCompra::facturaMontoMasAlto() {
    if (primero == NULL) {
        cout << "No hay compras" << endl;
    } else {
        pNodoCompra aux = primero;
        pNodoCompra aux2;
        int mayor = primero->costo;
        while (aux) {
            if (aux->costo > mayor) {
                aux2 = aux;
            }
            aux = aux->siguiente;
        }

        ofstream archivo;
        archivo.open("reportes/compraMasAlta.txt");
        archivo << aux2->idCliente << endl;
        archivo << "Monto: $" << aux2->costo << endl;
        archivo << "Compra: " << aux2->productos << endl;
    }
}

void ListaCompra::facturaMontoMasBajo() {
    if (primero == NULL) {
        cout << "No hay compras" << endl;
    } else {
        pNodoCompra aux = primero;
        pNodoCompra aux2;
        int menor = primero->costo;
        while (aux) {
            if (aux->costo < menor) {
                aux2 = aux;
            }
            aux = aux->siguiente;
        }

        ofstream archivo;
        archivo.open("reportes/compraMasBaja.txt");
        archivo << aux2->idCliente << endl;
        archivo << "Monto: $" << aux2->costo << endl;
        archivo << "Compra: " << aux2->productos << endl;
    }
}

void ListaCompra::comprasCliente(int idCliente) {
    if (primero == NULL) {
        cout << "No hay compras" << endl;
    } else {

        ofstream archivo;
        archivo.open("reportes/comprasDeCliente.txt");
        archivo << "Compra de " << idCliente << endl;
        pNodoCompra aux = primero;
        string compra = "";
        while (aux) {
            if (aux->idCliente == idCliente) {
                compra += aux->productos + "\n";
            }
            aux = aux->siguiente;
        }
        archivo << compra << endl;
    }
}