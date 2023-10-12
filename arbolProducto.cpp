#include "arbolProducto.h"

ArbolProducto::ArbolProducto() {
    primero = NULL;
}

bool ArbolProducto::ArbolVacio() {
    return primero == NULL;
}



void ArbolProducto::buscarProducto(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenu){
    NodoProducto *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero;
        while (aux) {
            // cout << aux->codPais << "asd" << endl;
            if (aux->codMenu == pCodMenu && aux->codPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest && aux->codProducto==pCodProducto) {
                cout << "Datos del producto"<<endl;
                cout << "Codigo del pais: "<< aux->codPais<< "  " <<endl;
                cout << "Codigo de la ciudad: "<< aux->codCiudad << endl;
                cout << "Codigo del restaurante: "<< aux->codRest << endl; 
                cout << "Codigo del producto: "<< aux->nombre<< "  "<< aux->codProducto<<endl; 
                cout << "Kcal del producto: "<< aux->kcal<<endl;
                cout << "Precio del producto: "<< aux->precio<<endl;
                cout << "Cantidad: " << aux->cantidad << endl;
                return;
            }
            aux = aux->siguiente;
        }
        cout << "No se encontro el producto" << endl;
    }
}



/*
void ArbolProducto::buscarProducto(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenu){
    NodoProducto *aux;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero;
        while (aux) {
            if (aux->codMenu == pCodMenu && aux->codPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest && aux->codProducto==pCodProducto) {
                cout << "Datos del producto"<<endl;
                cout << "Nombre y codigo del pais: "<< lPaises.punteroPais(pCodPais)->nombre<< "  " << lPaises.punteroPais(pCodPais)->codigoPais<<endl;
                cout << "Nombre y codigo de la ciudad: "<< lCiudades.punteroCiudad(pCodCiudad, pCodPais)->nombre<< "  "<< lCiudades.punteroCiudad(pCodCiudad, pCodPais)->codigoCiudad<<endl;
                cout << "Nombre y codigo del restaurante: "<< aux->coRest << "  "<< lRest.punteroRest(pCodRest, pCodCiudad, pCodPais)->codRest<<endl; 
                cout << "Nombre y codigo del producto: "<< aux->nombre<< "  "<< aux->codProducto<<endl; 
                cout << "Kcal del producto: "<< aux->kcal<<endl;
                cout << "Precio del producto: "<< aux->precio<<endl;
                return;
            }
            aux = aux->siguiente;
        }
        cout << "No se encontro el producto" << endl;
    }
}
*/


void ArbolProducto::precio(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenu){
    NodoProducto *aux;
    ofstream archivo;
    archivo.open ("reportes/precioProducto.txt");
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero;
        while (aux) {
            if (aux->codMenu == pCodMenu && aux->codPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest && aux->codProducto==pCodProducto) {
                archivo << "Datos del producto"<<endl;
                archivo << "Codigo del pais: "<< aux->codPais<< "  " <<endl;
                archivo << "Codigo de la ciudad: "<< aux->codCiudad << endl;
                archivo << "Codigo del restaurante: "<< aux->codRest << endl; 
                archivo << "Codigo del producto: "<< aux->nombre<< "  "<< aux->codProducto<<endl; 
                archivo << "Kcal del producto: "<< aux->kcal<<endl;
                archivo << "Precio del producto: "<< aux->precio<<endl;
                cout << "Cantidad: " << aux->cantidad << endl;
                archivo.close();
                return;
            }
            aux = aux->siguiente;
        }
        cout << "No se encontro el producto" << endl;
    }
}
    

/*
void ArbolProducto::precio(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenu){
    NodoProducto *aux;
    ofstream archivo;
    archivo.open ("reportes/precioProducto.txt");
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero;
        while (aux) {
            if (aux->codMenu == pCodMenu && aux->codPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest && aux->codProducto==pCodProducto) {
                archivo << "Datos del producto"<<endl;
                archivo << "Codigo del pais: "<< lPaises.punteroPais(pCodPais)->nombre<< "  " << lPaises.punteroPais(pCodPais)->codigoPais<<endl;
                archivo << "Codigo del restaurante: "<< lRest.punteroRest(pCodRest, pCodCiudad, pCodPais)->nombre<< "  "<< lRest.punteroRest(pCodRest, pCodCiudad, pCodPais)->codRest<<endl; 
                archivo << "Codigo del producto: "<< aux->nombre<< "  "<< aux->codProducto<<endl; 
                archivo << "Kcal del producto: "<< aux->kcal<<endl;
                archivo << "Precio del producto: "<< aux->precio<<endl;
                archivo.close();
                return;
            }
            aux = aux->siguiente;
        }
        cout << "No se encontro el producto" << endl;
    }
}
    
*/

bool ArbolProducto::existeProducto(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ArbolPais& lPais, ArbolCiudad& lCiudad, listaRest& lRest, ArbolMenu& lMenuRest ) {
    NodoProducto* aux = primero;
    if (primero==NULL){
        cout << "No hay elementos" << endl;
    }else{
        aux = primero;
        while(aux!=NULL) {
            if (aux->codProducto==pCodProducto) {
                if (aux->codPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest && aux->codMenu==pCodMenu) {
                    return true;
                }
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

void ArbolProducto::reporteProducto(){
    NodoProducto *aux;
    ofstream archivo;
    archivo.open ("reportes/Productos.txt");
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        aux = primero;
        while (aux) {
                archivo << aux->codProducto <<"  "<< aux->nombre<<endl;
                archivo.close();
                return;
            
            aux = aux->siguiente;
        }
    }
}

void ArbolProducto::insertarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, int cant, ArbolPais& lPais, ArbolCiudad& lCiudad, listaRest& lRest, ArbolMenu& lMenuRest ) {
    // if (lMenuRest.existe(codMenu, codPais, codCiudad, codRest)) {
      
        if (ArbolVacio()) {
            primero = new NodoProducto( codPais,  codCiudad,  codRest,  codMenu,  codProducto,  nombre,  kcal,  precio, cant);
        } else {
            if(existeProducto(codPais, codCiudad, codRest, codMenu, codProducto, lPais, lCiudad, lRest, lMenuRest)){
                cout <<"Este producto ya existe en el menu, no se puede insertar" << endl;
            } else {
                NodoProducto* aux = primero;
                while (aux->siguiente!=NULL) {
                aux = aux->siguiente;
                }  
                aux->siguiente = new NodoProducto(codPais, codCiudad, codRest, codMenu, codProducto,  nombre,  kcal,  precio, cant);
                aux->siguiente->anterior = aux;
                cout << "Producto insertado" << endl;
            }
        }
    // } else {
    //     cout << "Incongruencias con la ubicacion" << endl;
    // }
}

void ArbolProducto::cargarProductos(ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenu){
    ifstream archivo("Archivos/Productos.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP, idC, idR, idM, id, kcal, precio;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, temp, ';');
        idC = stoi(temp);

        getline(ss, temp, ';');
        idR = stoi(temp);

        getline(ss, temp, ';');
        idM = stoi(temp);

        getline(ss, temp, ';');
        id = stoi(temp);

        getline(ss, name, ';');

        getline(ss, temp, ';');
        kcal = stoi(temp);

        getline(ss, temp, ';');
        precio = stoi(temp);

        getline(ss, temp, ';');
        int cant = stoi(temp);

        ArbolProducto::insertarProducto(idP, idC, idR, idM, id, name, kcal, precio, cant, lPaises, lCiudades, lRest, lMenu);
    }

    archivo.close();
}

void ArbolProducto::mostrar() {
    NodoProducto *aux;
    if (primero==NULL)
        cout << "No hay elementos";  
    else {
        cout << endl;
        aux = primero;
        while(aux) {
        std::cout << "ID PRODUCTO: " << aux->codProducto << ", Nombre: " << aux->nombre<< " -> ";
        aux = aux->siguiente;
        }
         cout << endl;
    }
}

void ArbolProducto::modificarProducto(int codPais, int codCiudad, int codRest, int codMenu, int codProducto, string nombre, int kcal, int precio, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenu){
    NodoProducto *aux = primero;
    if (primero==NULL) {
        cout << "No hay elementos" << endl;
    } else {
        while (aux!=NULL) {
            // cout << aux->codMenu;
            if (aux->codPais == codPais && aux->codCiudad == codCiudad && aux->codRest == codRest && aux->codMenu == codMenu) {
                aux->nombre = nombre;
                aux->kcal = kcal;
                aux->precio = precio;
                cout << "Producto modificado" << endl;
                return;
            }
            aux = aux->siguiente;
        }
    }
    cout << "No se encontro el producto" << endl;
    return;
}

void ArbolProducto::mostrarProductosMenu(int codPais, int codCiudad, int codRest, int codMenu) {
    if (primero==NULL) {
        cout << "No hay productos en la base de datos" << endl;
    } else {
        pNodoProducto aux = primero;
        while (aux) {
            if (aux->codCiudad == codCiudad && aux->codPais == codPais && aux->codRest == codRest && aux->codMenu == codMenu) {
                cout << "- " << aux->codProducto << ". " << aux->nombre << endl;
            }
            aux = aux->siguiente;
        }
    }
}

void ArbolProducto::productoMasComprado() {
    if (primero==NULL) {
        cout << "No hay productos en la base de datos" << endl;
    } else {
        ofstream archivo;
        archivo.open("reportes/productoMasBuscado.txt");
        pNodoProducto aux = primero;
        pNodoProducto temp = primero;
        int mayor = primero->contador;
        while (aux) {
            if (aux->contador > mayor) {
                temp = aux;
            }
            aux = aux->siguiente;
        }
        archivo << "Producto mas comprado: " << endl;
        archivo << temp->nombre << endl;
        archivo << temp->codProducto << endl;
        archivo << "Compras: " << temp->contador << endl;
        archivo.close();
    }
}

void ArbolProducto::aumentarCompra(int pCodPais, int pCodCiudad, int pCodRest, int pCodMenu, int pCodProducto, ArbolPais& lPaises, ArbolCiudad& lCiudades, listaRest& lRest, ArbolMenu& lMenu){
    NodoProducto* aux = primero;
    if (primero==NULL){
        cout << "No hay elementos" << endl;
    }else{
        aux = primero;
        while(aux!=NULL) {
            if (aux->codProducto==pCodProducto) {
                if (aux->codPais == pCodPais && aux->codCiudad == pCodCiudad && aux->codRest == pCodRest && aux->codMenu==pCodMenu) {
                    aux->contador++;
                    return;
                }
            }
            aux = aux->siguiente;
        }
    }
}
