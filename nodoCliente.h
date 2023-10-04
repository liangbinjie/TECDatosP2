#ifndef NODOCLIENTE_H
#define NODOCLIENTE_H

#include <iostream>

using namespace std;

#define MAX 4
#define MIN 2

class NodoBtree {
	public:
		int val[MAX + 1], count;
		string nombre;
		NodoBtree* link[MAX + 1];

		void insertar(int val, string nombre);
		void busqueda(int val, int* pos, NodoBtree* minodo);
		void desplegar(NodoBtree* minodo);
		void modificar(int val, int* pos, NodoBtree* minodo, string nuevonombre);

	private:
		NodoBtree* crearnodo(int val, string nombre, NodoBtree* hijo);
		void Colocarnodo(int val, int pos, NodoBtree* node, NodoBtree* hijo);
		void PartirNodo(int val, int* pval, int pos, NodoBtree* node, NodoBtree* hijo, NodoBtree** NuevoNodo);
		int SetValorNodo(int val, int* pval, NodoBtree* node, NodoBtree** hijo);
		void copySuccessor(NodoBtree* minodo, int pos);
		void removeVal(NodoBtree* minodo, int pos);
		void doRightShift(NodoBtree* minodo, int pos);
		void doLeftShift(NodoBtree* minodo, int pos);
		void UnirNodos(NodoBtree* minodo, int pos);
		void AjustarNodo(NodoBtree* minodo, int pos);

};

NodoBtree* root;

#endif