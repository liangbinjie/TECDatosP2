#ifndef NODOCIUDAD_H
#define NODOCIUDAD_H

#include <iostream>
using namespace std;

class NodoCiudad {
	public:
		int id;
		int idPais;
        int FB;
		string nombre;
		NodoCiudad* izq;
		NodoCiudad* der;
		friend class arbolCiudad;

		NodoCiudad();
		NodoCiudad(int id, int idPais, string nombre);
		
};

typedef NodoCiudad* pnodoCiudad;


#endif
