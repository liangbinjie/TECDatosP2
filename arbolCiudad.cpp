#include "arbolCiudad.h"
#include "nodoPais.h"
#include "arbolPais.h"

ArbolCiudad::ArbolCiudad() {
	raiz = NULL;
}

void ArbolCiudad::insertar(int id, int idPais, string nombre, ArbolPais& aPaises) {
	if (raiz == NULL) {
		raiz = new NodoCiudad(id, idPais, nombre);
		cout << "Nueva ciudad insertada" << nombre<< endl;
	} else {
		if (existeCiudad(id, idPais, aPaises)) {
			cout << "Esta ciudad ya existe" << id << endl;
		} else {
            bool Hh= false;
            cout << " Insertar   Nueva ciudad insertada" << id<< endl;
			insertarBalanceado(raiz, id, idPais, nombre, Hh);
		}
	}
}



void ArbolCiudad::insertarBalanceado(NodoCiudad* &r, int id, int idPais, string nombre, bool& Hh){
    
    
    if(r==NULL){
        r=new NodoCiudad(id, idPais, nombre);
        //cout<<r->id<<" igual a Null"<<endl;
        Hh = true;
    }else{
        //cout<<"no Null "<<r->id<<endl;
        if(id<=r->id){
            //cout<< id <<" es menor a "<<r->id<<endl;
            insertarBalanceado(r->izq, id, idPais, nombre, Hh);

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
                NodoCiudad* n1 = r->izq;
                if(n1->FB ==-1){
                    cout<<"rotacion simple izquierda"<< endl;
                    RotacionSimpleIzquierda(r, n1);
                }else{
                    cout<<"rotacion doble izquierda"<< endl;
                    RotacionDobleIzquierda(r,n1);
                }
                Hh = false;
                break;
            }
        }
        }else{
            if(id>=r->id){
                //cout<< id <<" es mayor a "<<r->id<<endl;
                insertarBalanceado(r->der, id, idPais, nombre, Hh);

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
                        cout<<"caso 1 der"<<endl;
                        NodoCiudad* n1 = r->der;
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


void ArbolCiudad::RotacionDobleIzquierda(NodoCiudad* &n, NodoCiudad* &n1){
    NodoCiudad *n2;
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

void ArbolCiudad::RotacionDobleDerecha(NodoCiudad* &n, NodoCiudad* &n1){
    NodoCiudad *n2;
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

void ArbolCiudad::RotacionSimpleDerecha(NodoCiudad* &n, NodoCiudad* &n1){
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

void ArbolCiudad::RotacionSimpleIzquierda(NodoCiudad* &n, NodoCiudad* &n1){
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


NodoCiudad* ArbolCiudad::existeAuxCiudad(NodoCiudad* r, int id, int idPais) {
    
    if (r == NULL || (r->id == id && r->idPais == idPais)) {
        return r;
    }
    if (id < r->id) {
        return existeAuxCiudad(r->izq, id, idPais); 
    } else {
        return existeAuxCiudad(r->der, id, idPais);  
    }
}


bool ArbolCiudad::existeCiudad(int id, int idPais, ArbolPais& aPaises) {
    cout<<"entro"<<endl;
    NodoCiudad* buscado = existeAuxCiudad(raiz, id, idPais);
    if (buscado == NULL) {
        if(aPaises.existePais(idPais)){
            cout<<"si existe"<<endl;
            return false;
        }  else {
            return true;
        } 
    } else {
            return true;
        } 
        
    }



void ArbolCiudad::buscarCiudad(int id, int idPais, ArbolPais& aPaises) {
    NodoCiudad* buscado = existeAuxCiudad(raiz, id, idPais);
    if (buscado == NULL) {
        cout << "No existe esta ciudad" << endl;
    } else {
        if(aPaises.existePais(idPais)){
            NodoPais* pais = aPaises.punteroPais(idPais);
            cout << "ID: " << buscado->id  << "\nNombre: " << buscado->nombre << "\nPais: " << pais->nombre << endl;
        }
    }
}



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



void ArbolCiudad::preorden(NodoCiudad* r) {
	if (r == NULL) {
		return;
	} else {
		cout << r->id << " - ";
		preorden(r->izq);
		preorden(r->der);
	}
}

void ArbolCiudad::preorden() {
	preorden(raiz);
	cout << endl;
}

void ArbolCiudad::inorden(NodoCiudad* r) {
	if (r == NULL) {
		return;
	} else {
		inorden(r->izq);
		cout << r->id << " - ";
		inorden(r->der);
	}
}

void ArbolCiudad::inorden() {
	inorden(raiz);
	cout << endl;
}

void ArbolCiudad::postorden(NodoCiudad* r) {
	if (r == NULL) {
		return;
	} else {
		postorden(r->izq);
		postorden(r->der);
		cout << r->nombre << " - ";
	}
}

void ArbolCiudad::postorden() {
	postorden(raiz);
	cout << endl;
}

void ArbolCiudad::cargarCiudades(ArbolPais& aPaises) {
    string str;
    ifstream archivo;
    archivo.open("Archivos/Ciudades.txt");
    while (archivo >> str) {
        int cont = 0;
        int idP,idC;
        string name = "", temp;
        for (char& c : str) {
            if (c == ';') {
                if (cont == 0) {
                    idP = stoi(temp);
                } else if (cont == 1) {
                    idC = stoi(temp);
                }
                temp = "";
                cont++;
            } else {
                temp += c;
            }
        }
        name = temp;
        insertar(idC, idP, name, aPaises);
    }
    archivo.close();
    str="";
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