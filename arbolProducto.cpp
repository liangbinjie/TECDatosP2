#include "arbolCiudad.h"
#include "nodoCiudad.h"
#include "nodoPais.h"
#include "arbolPais.h"
#include "arbolMenu.h"
#include "nodoMenu.h"
#include "arbolProducto.h"


ArbolProducto::ArbolProducto() {
	raiz = NULL;
}


void ArbolProducto::insertarProducto(int id, int idPais, int idCiudad, int idRest, int idMenu, string nombre, ArbolPais& aPaises, ArbolCiudad& aCiudades, ArbolRestaurante& aRest, ArbolMenu& aMenu) {
	if(aPaises.existePais(idPais) && aCiudades.existeCiudad(idCiudad, idPais, aPaises) && aRest.existe(idRest, idPais, idCiudad) && aMenu.existe(idMenu, idPais, idCiudad, idRest)){
    if (raiz == NULL) {
		raiz = new NodoProducto(id, idPais, idCiudad, idRest, idMenu, nombre);
		cout << "Nueva ciudad insertada" << nombre<< endl;
    } else {
		if (existeProducto(id, idPais, idCiudad, idRest, idMenu, aPaises, aCiudades, aRest, aMenu)) {
			cout << "Este producto ya existe" << id << endl;
		} else {
            bool Hh= false;
            cout << " Nueva ciudad a insertar" << id<< endl;
			insertarBalanceado(raiz, id, idPais, idCiudad, idRest, idMenu, nombre, Hh);
		}
	}
} else{
    cout << " Incongruencias con la ubicacion" <<endl;
}
}



void ArbolProducto::insertarBalanceado(NodoProducto* &r, int id, int idPais, int idCiudad, int idRest, int idMenu, string nombre, bool& Hh){
    
    
    if(r==NULL){
        r=new NodoProducto(id, idPais, idCiudad, idRest, idMenu, nombre);
        //cout<<r->id<<" igual a Null"<<endl;
        Hh = true;
    }else{
        //cout<<"no Null "<<r->id<<endl;
        if(id<=r->id){
            //cout<< id <<" es menor a "<<r->id<<endl;
            insertarBalanceado(r->izq, id, idPais, idCiudad, idRest, idMenu, nombre, Hh);

        if(Hh){
            //cout <<"hh izquierdo true"<<endl;
            //cout<<r->id<<" "<<r->FB<<endl;
            switch(r->FB){
                case 1: r->FB=0;
                Hh = false;
                break;
                case 0: 
                r->FB  = -1;
                break;
                case -1: 
                NodoProducto* n1 = r->izq;
                if(n1->FB ==-1){
                    RotacionSimpleIzquierda(r, n1);
                }else{
                    RotacionDobleIzquierda(r,n1);
                }
                Hh = false;
                break;
            }
        }
        }else{
            if(id>=r->id){
                //cout<< id <<" es mayor a "<<r->id<<endl;
                insertarBalanceado(r->der, id, idPais, idCiudad, idRest, idMenu, nombre, Hh);

                if(Hh){
                    //cout <<"hh derecho true"<< r->id <<" "<< r->FB<< endl;
                    switch(r->FB){
                        case -1: 
                        r->FB=0;
                        Hh = false;
                        break;
                        case 0: 
                        r->FB=1;
                        break;
                        case 1:
                        NodoProducto* n1 = r->der;
                        cout<<n1->id<<endl;
                        if(n1->FB==1){
                            cout<<"rotacion simple derecha"<< endl;
                            RotacionSimpleDerecha(r, n1);
                        }else{
                            cout<<"rotacion doble derecha"<< endl;
                            RotacionDobleDerecha(r, n1);
                        }
                        Hh=false;

                        break;
                    }
                }
            }
        }
    }
}


void ArbolProducto::RotacionDobleIzquierda(NodoProducto* &n, NodoProducto* &n1){
    NodoProducto *n2;
    n2=n1->der;
    n->izq = n2->der;
    n2->der=n;
    n1->der=n2->izq;
    n2->izq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void ArbolProducto::RotacionDobleDerecha(NodoProducto* &n, NodoProducto* &n1){
    NodoProducto *n2;
    //cout<<"entro"<<endl;
    n2=n1->izq;
    //cout<<"n "<<n->id<<" n1 "<<n1->id<<" n2 "<<n2->id<<endl;
    n->der = n2->izq;
    n2->izq=n;
    n1->izq=n2->der;
    n2->der=n1;

    //cout<<"n "<<n->id<<" n1 "<<n1->id<<" n2 "<<n2->id<<endl;
    //cout<<"n "<<n->FB<<" n1 "<<n1->FB<<" n2 "<<n2->FB<<endl;

    if(n2->FB==1){
        //cout<<"ii"<<endl;
        n->FB=-1;
    }else{
        //cout<<"tt"<<endl;
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    //cout<<"n "<<n->id<<" n1 "<<n1->id<<" n2 "<<n2->id<<endl;
    //cout<<"n "<<n->FB<<" n1 "<<n1->FB<<" n2 "<<n2->FB<<endl;
    n=n2;
    
    //cout<<"fin"<<endl;
    //cout<<"n "<<n->id<<" n1 "<<n1->id<<" n2 "<<n2->id<<endl;
    //cout<<"n "<<n->FB<<" n1 "<<n1->FB<<" n2 "<<n2->FB<<endl;
}

void ArbolProducto::RotacionSimpleDerecha(NodoProducto* &n, NodoProducto* &n1){
    n->der=n1->izq;
    n1->izq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void ArbolProducto::RotacionSimpleIzquierda(NodoProducto* &n, NodoProducto* &n1){
    n->izq=n1->der;
    n1->der=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
}


NodoProducto* ArbolProducto::existeAuxProducto(NodoProducto* &r, int id, int idPais, int idCiudad, int idRest, int idMenu) {
    cout<<"oo"<<endl;
    //cout<<r->id<< " " << id<< "    " << r->idPais<<  "    " << idPais<< "    " << r->idCiudad<< "    " << r->idCiudad<< " " << r->idRest<< " " << idRest<< " " << r->idMenu<< " " << idMenu<< endl;
    if ((r == NULL) || ((r->id == id) && (r->idPais == idPais) && (r->idCiudad == idCiudad) && (r->idRest == idRest) && (r->idMenu == idMenu))){
        return r;
    }
    if (id < r->id) {
        return existeAuxProducto(r->izq, id, idPais, idCiudad, idRest, idMenu); 
    } else {
        return existeAuxProducto(r->der, id, idPais, idCiudad, idRest, idMenu);  
    }
}


/*void ArbolMenu::insertar(int clave, int idPais, int idCiudad, int idRest, string nombre, ArbolPais paises, ArbolCiudad ciudades, ArbolRestaurante restaurantes) {
    if (existe(clave, idPais, idCiudad, idRest)) {
        cout << "Este menu ya existe" << endl;
        return;
    }
    if (paises.existePais(idPais) && ciudades.existeCiudad(idCiudad, idPais, paises) && restaurantes.existe(idRest, idPais, idCiudad)) {
        raiz = insertarRec(raiz, clave, idPais, idCiudad, idRest, nombre);
        cout << "Nuevo menu insertado" << endl;
    } else {
        cout << "No existe el restaurante/pais/ciudad" << endl;
    }
}
*/



bool ArbolProducto::existeProducto(int id, int idPais, int idCiudad, int idRest, int idMenu, ArbolPais& aPaises, ArbolCiudad& aCiudades, ArbolRestaurante& aRest, ArbolMenu& aMenu) {
    NodoProducto* buscado = existeAuxProducto(raiz, id, idPais, idCiudad, idRest, idMenu);
    if (buscado == NULL) {
        cout << "jiji"<<endl;
            return false;
        }  else {
            cout << "jiji"<<endl;
            return true;
        }
        
    }



void ArbolProducto::buscarProducto(int id, int idPais, int idCiudad, int idRest, int idMenu, ArbolPais& aPaises, ArbolCiudad& aCiudades, ArbolRestaurante& aRest, ArbolMenu& aMenu) {
    
    cout<<"ii"<<endl;
    if(aPaises.existePais(idPais) && aCiudades.existeCiudad(idCiudad, idPais, aPaises) && aRest.existe(idRest, idPais, idCiudad) && aMenu.existe(idMenu, idPais, idCiudad, idRest)){
        cout <<"holss"<<endl;
        if(existeProducto(id, idPais, idCiudad, idRest, idMenu, aPaises, aCiudades, aRest, aMenu)){
            NodoProducto* buscado = existeAuxProducto(raiz, id, idPais, idCiudad, idRest, idMenu);
            NodoPais* pais = aPaises.punteroPais(idPais);
//            NodoCiudad* ciudad = aCiudades.punteroCiudad(idCiudad);
//            cout << "ID: " << buscado->id  << "\nNombre: " << buscado->nombre << "\nPais: " << pais->nombre <<"\nCiudad: " << ciudad->nombre << "\nRestaurante: " << buscado->idRest << "\nMenu: " << buscado->idMenu << endl;
        } else{
            cout << "gggg"<<endl;
        }

    }else{
        cout << "Incongruencias con la ubicacion" << endl;
    }
    //NodoProducto* buscado = existeAuxProducto(raiz, id, idPais, idCiudad, idRest, idMenu);
    //if (buscado == NULL) {
      //  cout << "No existe este producto" << endl;
    //} else {
      //  cout<<"essss"<<endl;
      //  if(aPaises.existePais(idPais) && aCiudades.existeCiudad(idCiudad, idPais, aPaises) && aRest.existe(idRest, idPais, idCiudad) && aMenu.existe(idMenu, idPais, idCiudad, idRest)){
       //     NodoPais* pais = aPaises.punteroPais(idPais);
       //     NodoCiudad* ciudad = aCiudades.punteroCiudad(idCiudad);
       //     cout << "ID: " << buscado->id  << "\nNombre: " << buscado->nombre << "\nPais: " << pais->nombre <<"\nCiudad: " << ciudad->nombre << "\nRestaurante: " << buscado->idRest << "\nMenu: " << buscado->idMenu << endl;
       // }
   // }
}

/*

NodoCiudad* ArbolCiudad::modificarAux(NodoCiudad* r, int id, int idPais, string nombre) {

    if (r->id == id && r->idPais == idPais) {
    	r->nombre = nombre;
        return r;
    }

    if (id < r->id) {
        return modificarAux(r->izq, id, idPais,nombre);
    } else {
        return modificarAux(r->der, id, idPais,nombre);
    }
}

void ArbolCiudad::modificar(int id, string nombre, int idPais, ArbolPais& aPaises) {
    
    if (!existeCiudad(id, idPais, aPaises)) {
        cout << "No existe esta ciudad" << endl;
    } else {
        if(aPaises.existePais(idPais)){
            NodoCiudad* buscado = modificarAux(raiz, id, idPais, nombre);
    	    cout << "Nombre modificado" << endl;
            cout << "ID: " << buscado->id << "\nNombre: " << buscado->nombre << endl;  
        }
    }
}
*/

void ArbolProducto::preorden(NodoProducto* r) {
	if (r == NULL) {
		return;
	} else {
		cout << r->id << " - ";
		preorden(r->izq);
		preorden(r->der);
	}
}

void ArbolProducto::preorden() {
	preorden(raiz);
	cout << endl;
}

void ArbolProducto::inorden(NodoProducto* r) {
	if (r == NULL) {
		return;
	} else {
		inorden(r->izq);
		cout << r->id << " - ";
		inorden(r->der);
	}
}

void ArbolProducto::inorden() {
	inorden(raiz);
	cout << endl;
}

void ArbolProducto::postorden(NodoProducto* r) {
	if (r == NULL) {
		return;
	} else {
		postorden(r->izq);
		postorden(r->der);
		cout << r->nombre << " - ";
	}
}

void ArbolProducto::postorden() {
	postorden(raiz);
	cout << endl;
}



void ArbolProducto::cargarProductos(ArbolPais& aPaises, ArbolCiudad& aCiudades, ArbolRestaurante& aRests, ArbolMenu& aMenus) {
    string str;
    ifstream archivo;
    archivo.open("Archivos/Productos.txt");
    while (archivo >> str) {
        int cont = 0;
        int idP, idC, idR, idM, id, kcal, precio;
        string name = "", temp;
        for (char& c : str) {
            if (c == ';') {
                if (cont == 0) {
                    idP = stoi(temp);
                } else if (cont == 1) {
                    idC = stoi(temp);
                } else if (cont == 2) {
                    idR = stoi(temp);
                } else if (cont == 3) {
                    idM = stoi(temp);
                } else if (cont == 4) {
                    id = stoi(temp);
                } else if (cont == 5) {
                    name = temp;
                } else if (cont == 6) {
                    kcal = stoi(temp);
                }
                temp = "";
                cont++;
            } else {
                temp += c;
            }
        }
        precio = stoi(temp);
        ArbolProducto::insertarProducto(id, idP, idC, idR, idM, name, aPaises, aCiudades, aRests, aMenus);
    }
    archivo.close();
    str = "";
}


/*void ArbolCiudad::insertarAux(NodoPais* r, int id, string nombre) {
	if (r->id > id) {
		if (r->izq == NULL) {
			r->izq = new NodoCiudad(id, nombre);
            cout<<ra->valor<<"q as"<<endl;
            Hh = true;
		} else {
			insertarAux(r->izq, id, nombre);
		}
	}
	if (r->id < id) {
		if (r->der == NULL) {
			r->der = new NodoCiudad(id, nombre);
		} else {
			insertarAux(r->der, id, nombre);
		}
	}
}
*/
