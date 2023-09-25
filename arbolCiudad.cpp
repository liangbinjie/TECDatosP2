#include "arbolCiudad.h"

ArbolCiudad::ArbolCiudad() {
	raiz = NULL;
}

void ArbolCiudad::insertar(int id, string nombre) {
	if (raiz == NULL) {
		raiz = new NodoCiudad(id, nombre);
		cout << "Nueva ciudad insertada" << nombre<< endl;
	} else {
		//if (existe(id)) {
		//	cout << "Esta ciudad ya existe" << endl;
		//} else {
            bool Hh= false;
            cout << " Insertar   Nueva ciudad insertada" << nombre<< endl;
			insertarBalanceado(raiz, id, nombre, Hh);
		}
	}
//}



void ArbolCiudad::insertarBalanceado(NodoCiudad* &r, int id, string nombre, bool& Hh){
    
    
    if(r==NULL){
        r=new NodoCiudad(id, nombre);
        cout<<r->id<<" igual a Null"<<endl;
        Hh = true;
    }else{
        cout<<"no Null "<<r->id<<endl;
        if(id<r->id){
            cout<< id <<" es menor a "<<r->id<<endl;
            insertarBalanceado(r->izq, id, nombre, Hh);

        if(Hh){
            cout <<"hh izquierdo true"<<endl;
            cout<<r->id<<" "<<r->FB<<endl;
            switch(r->id){
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
            if(id>r->id){
                cout<< id <<" es mayor a "<<r->id<<endl;
                insertarBalanceado(r->der, id, nombre, Hh);

                if(Hh){
                    cout <<"hh derecho true"<< r->id <<" "<< r->FB<< endl;
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
    cout<<"entro"<<endl;
    n2=n1->izq;
    cout<<"n "<<n->id<<" n1 "<<n1->id<<" n2 "<<n2->id<<endl;
    n->der = n2->izq;
    n2->izq=n;
    n1->izq=n2->der;
    n2->der=n1;

    cout<<"n "<<n->id<<" n1 "<<n1->id<<" n2 "<<n2->id<<endl;
    cout<<"n "<<n->FB<<" n1 "<<n1->FB<<" n2 "<<n2->FB<<endl;

    if(n2->FB==1){
        cout<<"ii"<<endl;
        n->FB=-1;
    }else{
        cout<<"tt"<<endl;
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    cout<<"n "<<n->id<<" n1 "<<n1->id<<" n2 "<<n2->id<<endl;
    cout<<"n "<<n->FB<<" n1 "<<n1->FB<<" n2 "<<n2->FB<<endl;
    n=n2;
    cout<<"fin"<<endl;
    cout<<"n "<<n->id<<" n1 "<<n1->id<<" n2 "<<n2->id<<endl;
    cout<<"n "<<n->FB<<" n1 "<<n1->FB<<" n2 "<<n2->FB<<endl;
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


void ArbolCiudad::preorden(NodoCiudad* r) {
	if (r == NULL) {
		return;
	} else {
		cout << r->nombre << " - ";
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
		cout << r->nombre << " - ";
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