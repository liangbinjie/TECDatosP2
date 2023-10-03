#include "arbolRestaurante.h"

void ArbolRestaurante::initializeNULLNode(pnodoRest nodo, pnodoRest padre) {
    nodo->valor = 0;
    nodo->padre = padre;
    nodo->Hizq= nullptr;
    nodo->Hder = nullptr;
    nodo->color = 0;
}

void ArbolRestaurante::preOrden(pnodoRest nodo) {
    if (nodo != TNULL) {
      cout << nodo->valor << " ";
      preOrden(nodo->Hizq);
      preOrden(nodo->Hder);
    }
}

void ArbolRestaurante::inOrden(pnodoRest nodo) {
    if (nodo != TNULL) {
      inOrden(nodo->Hizq);
      cout << nodo->valor << " ";
      inOrden(nodo->Hder);
    }
}

void ArbolRestaurante::postOrden(pnodoRest nodo) {
    if (nodo != TNULL) {
      postOrden(nodo->Hizq);
      postOrden(nodo->Hder);
      cout << nodo->valor << " ";
    }
}


pnodoRest ArbolRestaurante::Busqueda(pnodoRest nodo, int id, int idPais, int idCiudad) {
    if (nodo == TNULL || (id == nodo->valor && idPais == nodo->idPais && idCiudad == nodo->idCiudad)) {
      return nodo;
    }

    if (id < nodo->valor) {
      return Busqueda(nodo->Hizq, id, idPais, idCiudad);
    }
    return Busqueda(nodo->Hder, id, idPais, idCiudad);
}

pnodoRest ArbolRestaurante::existeAux(pnodoRest nodo, int id, int idPais, int idCiudad) {
    if (nodo == TNULL || (id == nodo->valor && idPais == nodo->idPais && idCiudad == nodo->idCiudad)) {
      return nodo;
    }

    if (id < nodo->valor) {
      return Busqueda(nodo->Hizq, id, idPais, idCiudad);
    }
    return Busqueda(nodo->Hder, id, idPais, idCiudad);
}

void ArbolRestaurante::rbModificar(pnodoRest uRaiz, pnodoRest vValor) {
    if (raiz->padre == nullptr) {
      raiz = vValor;
    } else if (uRaiz == uRaiz->padre->Hizq) {
      uRaiz->padre->Hizq = vValor;
    } else {
      uRaiz->padre->Hder = vValor;
    }
    vValor->padre = uRaiz->padre;
}

void ArbolRestaurante::insertarBalanceado(pnodoRest NodoEva) {
    pnodoRest uValor;
    while (NodoEva->padre->color == 1) {
      if (NodoEva->padre == NodoEva->padre->padre->Hder) {
        uValor = NodoEva->padre->padre->Hizq;
        if (uValor->color == 1) {
          uValor->color = 0;
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          NodoEva = NodoEva->padre->padre;
        } else {
          if (NodoEva == NodoEva->padre->Hizq) {
            NodoEva = NodoEva->padre;
            RotacionDerecha(NodoEva);
          }
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          RotacionIzquierda(NodoEva->padre->padre);
        }
      } else {
        uValor = NodoEva->padre->padre->Hder;

        if (uValor->color == 1) {
          uValor->color = 0;
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          NodoEva = NodoEva->padre->padre;
        } else {
          if (NodoEva == NodoEva->padre->Hder) {
            NodoEva = NodoEva->padre;
            RotacionIzquierda(NodoEva);
          }
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          RotacionDerecha(NodoEva->padre->padre);
        }
      }
      if (NodoEva == raiz) {
        break;
      }
    }
    raiz->color = 0;
}

void ArbolRestaurante::MostrarRN(pnodoRest raiz, string indent, bool ultimo) {
    if (raiz != TNULL) {
      cout << indent;
      if (ultimo) {
        cout << "Derecha----";
        indent += "   ";
      } else {
        cout << "Izquierda----";
        indent += "|  ";
      }

      string sColor = raiz->color ? "Rojo" : "Negro";
      cout << raiz->valor << "(" << sColor << ")" << endl;
      MostrarRN(raiz->Hizq, indent, false);
      MostrarRN(raiz->Hder, indent, true);
    }
}

ArbolRestaurante::ArbolRestaurante() {
    TNULL = new NodoRestaurante;
    TNULL->color = 0;
    TNULL->Hizq = nullptr;
    TNULL->Hder = nullptr;
    raiz = TNULL;
}

void ArbolRestaurante::preordenM() {
  preOrden(this->raiz);
}

void ArbolRestaurante::inordenM() {
  inOrden(this->raiz);
}

void ArbolRestaurante::postorderM() {
  postOrden(this->raiz);
}

void ArbolRestaurante::BusquedaM(int id, int idPais, int idCiudad) {
  NodoRestaurante* buscado = Busqueda(this->raiz, id, idPais, idCiudad);
  if (!existe(id, idPais, idCiudad)) {
    cout << "No se encontro este restaurante" << endl;
  } else {
    cout << "ID Restaurante: " << buscado->valor << "\nNombre: " << buscado->nombre << "\nID pais: " << buscado->idPais << "\nID ciudad: " << buscado->idCiudad << endl;
  }
}

bool ArbolRestaurante::existe(int id, int idPais, int idCiudad) {
  NodoRestaurante* buscado = Busqueda(this->raiz, id, idPais, idCiudad);
  if (buscado->valor == -1 || buscado == NULL) {
    return false;
  } else {
    return true;
  }
}

pnodoRest ArbolRestaurante::minimo(pnodoRest nodo) {
  while (nodo->Hizq != TNULL) {
    nodo = nodo->Hizq;
  }
  return nodo;
}

pnodoRest ArbolRestaurante::maximo(pnodoRest nodo) {
  while (nodo->Hder != TNULL) {
    nodo = nodo->Hder;
  }
  return nodo;
}

pnodoRest ArbolRestaurante::successor(pnodoRest nodo) {
  if (nodo->Hder != TNULL) {
    return minimo(nodo->Hder);
  }

  pnodoRest y = nodo->padre;
  while (y != TNULL && nodo == y->Hder) {
    nodo = y;
    y = y->padre;
  }
  return y;
}

pnodoRest ArbolRestaurante::predecessor(pnodoRest nodo) { ////////////////////////////////AQUI
  if (nodo->Hizq != TNULL) {
    return maximo(nodo->Hizq);
  }

  pnodoRest y = nodo->padre;
  while (y != TNULL && nodo == y->Hizq) {
    nodo = y;
    y = y->padre;
  }

  return y;
}

void ArbolRestaurante::RotacionIzquierda(pnodoRest nodo) {
  pnodoRest y = nodo->Hder;
  nodo->Hder = y->Hizq;
  if (y->Hizq != TNULL) {
    y->Hizq->padre = nodo;
  }
  y->padre = nodo->padre;
  if (nodo->padre == nullptr) {
    this->raiz = y;
  } else if (nodo == nodo->padre->Hizq) {
    nodo->padre->Hizq = y;
  } else {
    nodo->padre->Hder = y;
  }
  y->Hizq = nodo;
  nodo->padre = y;
}

void ArbolRestaurante::RotacionDerecha(pnodoRest nodo) {
  pnodoRest y = nodo->Hizq;
  nodo->Hizq = y->Hder;
  if (y->Hder != TNULL) {
    y->Hder->padre= nodo;
  }
  y->padre = nodo->padre;
  if (nodo->padre == nullptr) {
    this->raiz = y;
  } else if (nodo == nodo->padre->Hder) {
    nodo->padre->Hder = y;
  } else {
    nodo->padre->Hizq= y;
  }
  y->Hder = nodo;
  nodo->padre = y;
}

void ArbolRestaurante::insertar(int idPais, int idCiudad, int valornuevo, string nombre, ArbolPais &paises, ArbolCiudad &ciudades) {
  // revisa si existe este restaurante
  if (existe(valornuevo, idPais, idCiudad)) {
    cout << "Este restaurante ya existe" << endl;
    return;
  }
  if (!ciudades.existeCiudad(idCiudad, idPais, paises)) {
    cout << "Ubicacion no existe" << endl;
    return;
  }
  pnodoRest nodo = new NodoRestaurante;
  nodo->padre = nullptr;
  nodo->valor = valornuevo;
  nodo->idPais = idPais;
  nodo->idCiudad = idCiudad;
  nodo->nombre = nombre;
  nodo->Hizq = TNULL;
  nodo->Hder = TNULL;
  nodo->color = 1;

  pnodoRest y = nullptr;
  pnodoRest x = this->raiz;

  while (x != TNULL) {
    y = x;
    if (nodo->valor < x->valor) {
      x = x->Hizq;
    } else {
      x = x->Hder;
    }
  }

  nodo->padre = y;
  if (y == nullptr) {
    raiz = nodo;
  } else if (nodo->valor< y->valor) {
    y->Hizq = nodo;
  } else {
    y->Hder = nodo;
  }

  if (nodo->padre== nullptr) {
    nodo->color = 0;
    return;
  }

  if (nodo->padre->padre == nullptr) {
    return;
  }

  insertarBalanceado(nodo);
}

pnodoRest ArbolRestaurante::getRaiz() {
  return this->raiz;
}

void ArbolRestaurante::MostrarRN() {
  if (raiz) {
    MostrarRN(this->raiz, "", true);
  }
}

void ArbolRestaurante::cargarRests(ArbolPais &paises, ArbolCiudad &ciudades) {
    ifstream archivo("Archivos/Restaurantes.txt");
    string line;
    
    while (getline(archivo, line)) {
        stringstream ss(line);
        string temp;
        int idP, idC, idR;
        string name;

        getline(ss, temp, ';');
        idP = stoi(temp);

        getline(ss, temp, ';');
        idC = stoi(temp);

        getline(ss, temp, ';');
        idR = stoi(temp);

        getline(ss, name, ';');

       insertar(idP, idC, idR, name, paises, ciudades);
    }

    archivo.close();
}


void ArbolRestaurante::modificar(int id, int idPais, int idCiudad, string nuevoNombre) {
  if (existe(id, idPais, idCiudad)) {
    modificarAux(this->raiz, id, idPais, idCiudad, nuevoNombre);
    return;
  } else {
    cout << "No existe este restaurante" << endl;
    return;
  }
}


void ArbolRestaurante::modificarAux(pnodoRest nodo, int id, int idP, int idC, string nuevo) {
    if (nodo == TNULL || (id == nodo->valor && idP == nodo->idPais && idC == nodo->idCiudad)) {
      nodo->nombre = nuevo;
      cout << "Nombre modificado a: " << nuevo << endl;
      return;
    }

    if (id < nodo->valor) {
      return modificarAux(nodo->Hizq, id, idP, idC, nuevo);
    }
    return modificarAux(nodo->Hder, id, idP, idC, nuevo);
}
