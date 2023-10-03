#include <string>
#include <sstream>

#include "nodoPais.h"
#include "arbolPais.h"
#include "NodoCiudad.h"
#include "NodoProducto.h"
#include "arbolCliente.h"
#include "NodoCliente.h"
#include <fstream>


class ArbolCliente {
	private:
		NodoCliente* root;
		
        NodoCliente* crearnodo(int val, NodoCliente* hijo);
		//void insertarBalanceado(NodoCiudad* r, int id, string nombre, bool Hh, int x);
        //void insertar(int id, string nombre);
		//NodoPais* buscarAux(NodoPais* r, int id);
		//void postorden(NodoProducto* r);
		//void inorden(NodoProducto* r);
		//void preorden(NodoProducto* r);
		//NodoProducto* existeAuxProducto(NodoProducto* r, int id, int idPais, int idCiudad, int idMenu);
		//NodoPais* existeAux(NodoPais* r, int id);
		//NodoCiudad* modificarAux(NodoCiudad* r, int id, int idPais, string nombre);
	public:
		ArbolCliente();
        void Colocarnodo(int val, int pos, NodoCliente* node, NodoCliente* hijo);
        void PartirNodo(int val, int* pval, int pos, NodoCliente* node, NodoCliente* hijo, NodoCliente** NuevoNodo);
        int SetValorNodo(int val, int* pval, NodoCliente* node, NodoCliente** hijo);
        void insertar(int val);
        void copySuccessor(NodoCliente* minodo, int pos);
        void removeVal(NodoCliente* minodo, int pos);
        void doRightShift(NodoCliente* minodo, int pos);
        void doLeftShift(NodoCliente* minodo, int pos);
        void UnirNodos(NodoCliente* minodo, int pos);
        void AjustarNodo(NodoCliente* minodo, int pos);
        int BorrarDeNodo(int val, NodoCliente* minodo);
        void borrado(int val, NodoCliente* minodo);
        void busqueda(int val, int* pos, NodoCliente* minodo);
        void desplegar(NodoCliente* minodo);
        //void insertarBalanceado(NodoProducto* &r, int id, int idPais, int idCiudad, int idMenu, string nombre, bool& Hh);
        //void insertarProducto(int id, int idPais, int idCiudad, int idMenu, string nombre, ArbolPais& aPaises, ArbolCiudad& aCiudades);
		//void RotacionDobleIzquierda(NodoProducto* &n, NodoProducto* &n1);
        //void RotacionDobleDerecha(NodoProducto* &n, NodoProducto* &n1);
        //void RotacionSimpleDerecha(NodoProducto* &n, NodoProducto* &n1);
        //void RotacionSimpleIzquierda(NodoProducto* &n, NodoProducto* &n1);
		//bool existeProducto(int id, int idPais, int idCiudad, int idMenu, ArbolPais& aPaises, ArbolCiudad& aCiudades);

		//void insertar(int id, string nombre);
		//void cargarCiudades(ArbolPais& aPaises);
		//void buscarCiudad(int id, int idPais, ArbolPais& aPaises);
		//bool existe(int id);
		//void modificar(int id, string nombre, int idPais, ArbolPais& aPaises);
		
		//void preorden();
		//void inorden();
		//void postorden();
		
		
};

#endif
