#include <iostream>
using namespace std;


// importando clases
#include "arbolPais.h"
#include "arbolRestaurante.h"
#include "nodoRestaurante.h"
#include "arbolCiudad.h"
#include "arbolMenu.h"
#include "arbolProducto.h"
#include "arbolCliente.h"
#include "compra/fila.h"
#include "compra/listaCompra.h"
#include "listaRest.h"
#include "compra/compra.h"

void menu(ArbolPais paises, ArbolCiudad ciudades, listaRest restaurantes, ArbolMenu menus, ArbolProducto productos, ArbolCliente clientes, ArbolRestaurante rests, fila& Fila, ListaCompra& lCompra, ArbolCiudad reporteCiudades, ListaCompra& lCompra2) {
	cout << endl;
	cout << "Bienvenido, que desea realizar?" << endl;
	cout << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Mostrar" << endl;
    cout << "3. Modificar" << endl;
    cout << "4. Buscar" << endl;
    cout << "5. Comprar" << endl;
    cout << "6. Reportes" << endl;
    cout << "7. Salir" << endl;
    int numPais;
    int opcion;
    cout << "> ";
    cin >> opcion;
    string nombre;
    int codPais, codCiudad, codRest, codMenu, codProducto, codCliente, calorias, precio, pos, cant;
    switch(opcion) {
        case 1:
        	cout << endl;
            cout << "Que deseas insertar?" << endl;
            cout << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurante" << endl;
            cout << "4. Menu" << endl;
            cout << "5. Producto" << endl;
            cout << "6. Clientes" << endl;
			cout << "7. Salir" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                	cout << endl;
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el nombre del pais: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    paises.insertar(codPais, nombre);
                    break;

                case 2:
                	cout << endl;
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: " << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el nombre de la ciudad: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    ciudades.insertar(codCiudad, codPais, nombre, paises);
                    break;

                case 3:
                	cout << endl;
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: " << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: " << endl;
                    cin >> codRest;
                    cout << "Ingrese el nombre del restaurante: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    restaurantes.insertar(codPais, codCiudad, codRest, nombre, paises, ciudades, rests);
                    break;
				
                    
                case 4:
                 	cout << endl;
	                cout << "Ingrese el codigo del pais: " << endl;
	                cin >> codPais;
	                cout << "Ingrese el codigo de la ciudad: " << endl;
	                cin >> codCiudad;
	                cout << "Ingrese el codigo del rest: " << endl;
	                cin >> codRest;
	                cout << "Ingrese el codigo del menu: " << endl;
	                cin >> codMenu;
	                cout << "Ingrese el nombre del menu " << endl;
	                cin.ignore();
	                getline(cin,nombre);
	                menus.insertar(codMenu, codPais, codCiudad, codRest, nombre, paises, ciudades, rests);
//	                menus.insertar(codMenu, codPais, codCiudad, codRest,nombre,paises,ciudades,restaurantes);
	                break;
                

                case 5:
                	cout << endl;
                    cout << "Ingrese el codigo del pais: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: " << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: " << endl;
                    cin >> codRest;
                    cout << "Ingrese el codigo del menu: " << endl;
                    cin >> codMenu;
                    cout << "Ingrese el codigo del producto: " << endl;
                    cin >> codProducto;
                    cout << "Ingrese el nombre del producto: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    cout << "Ingrese la cantidad de caloria del producto: " << endl;
                    cin >> calorias;
                    cout << "Ingrese el precio del producto: " << endl;
                    cin >> precio;
                    cout << "Ingrese la cantidad del producto: " << endl;
                    cin >> cant;
                    productos.insertarProducto(codProducto,codPais, codCiudad, codRest, codMenu, nombre, calorias, precio, cant, paises, ciudades,restaurantes,menus);
                    break;                                                                         //calorias, precio,

                case 6:
                	cout << endl;
                    cout << "Ingrese la identificacion del cliente: " << endl;
                    cin >> codCliente;
                    cout << "Ingrese el nombre del cliente: " << endl;
                    cin.ignore();
                    getline(cin,nombre);
                    clientes.Insertar(codCliente, nombre);
                    break;

				case 7:
					cout << endl;
                    break;
            }
            break;
        
        case 2:
        	cout << endl;
            cout << "Que deseas mostrar?" << endl;
            cout << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurante" << endl;
            cout << "4. Menu" << endl;
            cout << "5. Producto" << endl;
            cout << "6. Clientes" << endl;
			cout << "7. Salir" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                	cout << endl;
					cout << "Preorden: " << endl;
                    paises.preorden();
					cout << "Inorden: " << endl;
                    paises.inorden();
					cout << "Postorden: " << endl;
                    paises.postorden();
					cout << endl;
                    break;
                case 2:
                	cout << endl;
					cout << "Preorden: " << endl;
                    ciudades.preorden();
					cout << "Inorden: " << endl;
                    ciudades.inorden();
					cout << "Postorden: " << endl;
                    ciudades.postorden();
					cout << endl;
                    break;
                case 3:
                	cout << endl;
                    rests.MostrarRN();
                    break;
                
                case 4:
                	cout << endl;
                    menus.mostrar();
                    break;

                
                case 5:
                	cout << endl;
                    productos.mostrar();
                    break;

                case 6:
                	cout << endl;
                    clientes.RecorridoPreorden();
                    break; 

				case 7:
					cout << endl;
					break;
            }
            break;

        case 3:
        	cout << endl;
            cout << "Que deseas MODIFICAR?" << endl;
            cout << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurante" << endl;
            cout << "4. Menu" << endl;
            cout << "5. Producto" << endl;
            cout << "6. Clientes" << endl;
			cout << "7. Salir" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                	cout << endl;
                    cout << "Ingrese el numero del pais que quiere MODIFICAR: ";
                    cin >> numPais;
                    cout << "Ingrese el nuevo nombre que quiere MODIFICAR: ";
                    cin.ignore();
                    getline(cin,nombre);
                    paises.modificar(numPais, nombre);
                    break;
                case 2:
                	cout << endl;
                    cout << "Ingrese el codigo del pais al que pertenece la ciudad: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: ";
                    cin >> codCiudad;
                    cout << "Ingrese el nuevo nombre que quiere MODIFICAR: ";
                    cin.ignore();
                    getline(cin,nombre);
                	ciudades.modificar(codCiudad, nombre, codPais, paises);
                    break;
                case 3:
                	cout << endl;
                    cout << "Ingrese el codigo del pais: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: ";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: ";
                    cin >> codRest;
                    cout << "Ingrese el nuevo nombre del restaurante: ";
                    cin.ignore();
                    getline(cin,nombre);
                    rests.modificar(codRest, codPais, codCiudad, nombre);
                    break;

                case 4:
                	cout << endl;
                    cout << "Ingres el codigo del pais: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: ";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: ";
                    cin >> codRest;
                    cout << "Ingrese el codigo del menu: ";
                    cin >> codMenu;
                    cout << "Ingrese el nuevo nombre del menu: ";
                    cin.ignore();
                    getline(cin,nombre);
                    menus.modificar(codMenu, codPais, codCiudad, codRest, nombre);
                    break;
                
                case 5:
                	cout << endl;
                    cout << "Ingres el codigo del pais: ";
                    cin >> codPais;
                    cout << "Ingrese el codigo de la ciudad: ";
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del rest: ";
                    cin >> codRest;
                    cout << "Ingrese el codigo del menu: ";
                    cin >> codMenu;
                    cout << "Ingrese el codigo del producto: ";
                    cin >> codProducto;
                    cout << "Ingrese el nuevo nombre del producto: ";
                    cin.ignore();
                    getline(cin,nombre);
                    cout << "Ingrese el monto de calorias a modificar: ";
                    cin >> calorias;
                    cout << "Ingrese el precio a modificar: ";
                    cin >> precio;
                    // productos.modificar(codPais, codCiudad, codRest, codMenu, codProducto, nombre, calorias, precio, lPais, lCiudad, lRest, lMenu);
                    break;

                case 6:
                	cout << endl;
                    cout << "Ingrese la identificacion del cliente que desea modificar: ";
                    cin >> codCliente;
                    cout << "Ingrese el nuevo nombre: ";
                    cin >> nombre;
                    clientes.modificar(codCliente, nombre);
                    break; 

				case 7:
					cout << endl;
					break;
            }
            break;
        
        case 4:
        	cout << endl;
            cout << "Que deseas BUSCAR?" << endl;
            cout << endl;
            cout << "1. Pais" << endl;
            cout << "2. Ciudad" << endl;
            cout << "3. Restaurante" << endl;
            cout << "4. Menu" << endl;
            cout << "5. Producto" << endl;
            cout << "6. Clientes" << endl;
            cout << "7. Salir" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                	cout << endl;
                    cout << "Ingrese el numero del pais que quiere mostrar: " << endl;
                    cin >> numPais;
                    paises.buscar(numPais);
                    break;
                case 2:
                	cout << endl;
                    cout << "Ingrese el codigo de pais de la ciudad que quieres buscar: " << endl;
                    cin >> codPais;
                    cout << "Ingrese el codigo de ciudad que deseas buscar: " << endl;
                    cin >> codCiudad;
                    ciudades.buscarCiudad(codCiudad, codPais, paises);
                    break;
                case 3:
                	cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el restaurante" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el restaurante" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el numero del restaurante" << endl;
                    cin >> codRest;
                    rests.BusquedaM(codRest, codPais, codCiudad);
					
                    break;
				
                case 4:
                	cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el menu" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el menu" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el numero del restaurante del que quiere ver el menu" << endl;
                    cin >> codRest;
                    cout << "Ingrese el numero del menu" << endl;
                    cin >> codMenu;
                    menus.buscar(codMenu, codPais, codCiudad, codRest);
                    break;
                case 5:
                	cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el producto" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el producto" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el numero del restaurante del que quiere ver el producto" << endl;
                    cin >> codRest;
                    cout << "Ingrese el numero del menu del que quiere ver el producto" << endl;
                    cin >> codMenu;
                    cout << "Ingrese el numero del producto" << endl;
                    cin >> codProducto;
                    productos.buscarProducto(codPais, codCiudad, codRest, codMenu, codProducto, paises, ciudades, restaurantes, menus);
                    break;
                case 6:
                	cout << endl;
                    cout << "Ingrese la identificacion del cliente: ";
                    cin >> codCliente;
                    clientes.buscar(codCliente);
                    break; 
				case 7:
					cout << endl;
					break;
            }
            break;

        case 5:
        	cout << endl;
        	cout << "Que deseas hacer?" << endl;
        	cout << endl;
        	cout << "1. Hacer fila para comprar" << endl;
        	cout << "2. Atender a cliente" << endl;
            cout << "3. Pagar" << endl;
        	cin >> opcion;
        	switch(opcion) {
        		case 1:
        			cout << endl;
        			if (Fila.largoFila() == 5) {
        				cout << "No se puede hacer mas fila, porque ya esta lleno" << endl;
					} else {
						cout << "Ingrese su identificacion: ";
						cin >> codCliente;
						if (clientes.existe(codCliente)) {
							Fila.encolar(codCliente);
							Fila.imprimir();
						} else {
							cout << "Esta identificacion no existe en la base de datos" << endl;
						}
 					}
 					break;

				case 2:
					cout << endl;
					if (Fila.filaVacia()) {
						cout << "No hay clientes que atender" << endl;
					} else {
						codCliente = Fila.atender();
                        cout << "Ingrese el pais donde se encuentra el restaurante: ";
                        cin >> codPais;
                        cout << "Ingrese la ciudad donde se encuentra el restaurante: ";
                        cin >> codCiudad;
                        cout << "Ingrese el codigo del restaurante: ";
                        cin >> codRest;
                        cout << "Ingrese el id menu que quieres comprar: ";
                        cin >> codMenu;
                        if (menus.existe(codMenu, codPais, codCiudad, codRest)) {
                            string compra = "";
                            int costo = 0;
                            while (true) {
                                productos.mostrarProductosMenu(codPais, codCiudad, codRest, codMenu);
                                int codProd;
                                int cant;
                                cout << "Que desea comprar?: ";
                                cin >> codProd;
                                if (productos.existeProducto(codPais, codCiudad, codRest, codMenu, codProd, paises, ciudades, restaurantes, menus)) {
                                    int precio = productos.getProducto(codProd, codPais, codCiudad, codRest, codMenu);
                                    cout << "Cuantos deseas comprar?" << endl;
                                    cin >> cant;
                                    productos.aumentarCompra(codPais, codCiudad, codRest, codMenu, codProd, paises, ciudades, restaurantes, menus);
                                    compra += "Producto: " + to_string(codProd) + ": $" + to_string(precio * cant) + "\n";
                                    costo += (precio * cant);
                                    cout << "Producto agregado a la compra" << endl;
                                } else {
                                    cout << "Ingrese un producto valido" << endl;
                                }
                                cout << "Desea seguir comprando? y/n" << endl;
                                char seguir;
                                cin >> seguir;
                                if (seguir == 'n') {
                                    cout << compra << endl;
                                    cout << "Para comer aqui o drive thru?\n1) Comer aqui\n2)Drive Thru" << endl;
                                    int op;
                                    cin >> op;  
                                    switch (op)
                                    {
                                    case 1:
                                        lCompra.agregar(codCliente, codPais, codCiudad, codRest, codMenu, compra, false, costo);
                                        lCompra2.agregar(codCliente, codPais, codCiudad, codRest, codMenu, compra, false, costo);
                                        break;
                                    case 2:
                                        costo = costo - ((costo*3)/100);
                                        cout << costo << endl;
                                        lCompra.agregar(codCliente, codPais, codCiudad, codRest, codMenu, compra, true, costo);
                                        lCompra2.agregar(codCliente, codPais, codCiudad, codRest, codMenu, compra, true, costo);
                                        break;
                                    }
                                    cout << "Por favor espere en la fila de pagar" << endl;
                                    lCompra.mostrar();
                                    break;
                                }
                            }

                        } else {
                            cout << "No existe este menu" << endl;
                        }
					}
					break;	

                case 3:
                    cout << endl;
                    lCompra2.pagar();
                    break;
                    	
			}
			
			break;
		
        case 6:
            cout << endl;
            cout << "Reportes" << endl;
            cout << endl;
            cout << "1. Preorden Paises" << endl;
            cout << "2. Preorden Ciudades" << endl;
            cout << "3. Preorden Restaurantes" << endl;
            cout << "4. Preorden Clientes" << endl;
            cout << "5. Compras de un cliente?" << endl;
            cout << "6. Restaurante mas buscado" << endl;
            cout << "7. Preorden Menu" << endl;
            cout << "8. Preorden productos" << endl;
            cout << "9. Menu mas buscado" << endl;
            cout << "10. Producto mas comprado" << endl;
            cout << "11. Factura con mayor monto" << endl;
            cout << "12. Factura con menor monto" << endl;
            cout << "13. Precio de un producto" << endl;
            cout << "> ";
            cin >> opcion;
            switch(opcion) {
                case 1:
                	cout << endl;
                    cout << "Reporte del pais: " << endl;
                    paises.reporte();
                    cout << "Proceso finalizado" << endl;
                    break;
                case 2:
                    cout << endl;
                    cout << "Ingrese el codigo del pais del que quiere ver las ciudades" << endl;
                    cin >> codPais;
                   
                    ciudades.reporteCiudad(codPais, paises, reporteCiudades);
                    reporteCiudades.preorden();
                    reporteCiudades.resetearReportes1();
                    cout << "Proceso finalizado" << endl;
                    break;
                case 3:
                	cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el restaurante" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el restaurante" << endl;
                    cin >> codCiudad;
                    rests.reporte(codPais, codCiudad);
                    cout << "Proceso finalizado" << endl;
                    break;
                case 4:
                	clientes.reporte();
                    cout << "Proceso finalizado" << endl;
                    break;
                case 5:
                	cout << endl;
                    cout << "Ingrese el id de un cliente: "; cin >> codCliente;
                    lCompra.comprasCliente(codCliente);
                    cout << "Proceso finalizado" << endl;
                    break;
                case 6:
                	cout << endl;
                    rests.masBuscado();
                    cout << "Proceso finalizado" << endl;
                    break; 
                case 7:
                    cout << endl;
                    cout << "Ingrese el numero del pais" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el codigo del restaurante" << endl;
                    cin >> codRest;
                    menus.reporte(codPais, codCiudad, codRest);
                    cout << "Proceso finalizado" << endl;
                    break;
                
                case 8:
                    cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver los productos" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver los productos" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el numero del restaurante del que quiere ver los productos" << endl;
                    cin >> codRest;
                    cout << "Ingrese el numero del menu del que quiere ver el producto" << endl;
                    cin >> codMenu;
                    productos.reporteProducto(codPais,codCiudad,codRest,codMenu,paises, ciudades, restaurantes, menus);
                    cout << "Proceso finalizado" << endl;
                break;

                case 9:
                    menus.masBuscado();
                    cout << "Proceso finalizado" << endl;
                    break;

                case 10:
                    productos.productoMasComprado();
                    cout << "Proceso finalizado" << endl;
                    break;
                case 11:
                    lCompra.facturaMontoMasAlto();
                    break;
                case 12:
                    lCompra.facturaMontoMasBajo();
                    break;
                case 13:
                    cout << endl;
                    cout << "Ingrese el numero del pais del que quiere ver el producto" << endl;
                    cin >> codPais;
                    cout << "Ingrese el numero de la ciudad del que quiere ver el producto" << endl;
                    cin >> codCiudad;
                    cout << "Ingrese el numero del restaurante del que quiere ver el producto" << endl;
                    cin >> codRest;
                    cout << "Ingrese el numero del menu del que quiere ver el producto" << endl;
                    cin >> codMenu;
                    cout << "Ingrese el numero del producto" << endl;
                    cin >> codProducto;
                    productos.precio(codPais, codCiudad, codRest, codMenu, codProducto, paises, ciudades, restaurantes, menus);
                    cout << "Proceso finalizado" << endl;
                    break;
            }
            break;
            
    	case 7:
            return;
    }
    menu(paises, ciudades, restaurantes, menus, productos, clientes, rests, Fila, lCompra, reporteCiudades, lCompra2);
}

int main() {
	ArbolPais paises;
	paises.cargarPais();
    ArbolCiudad ciudades;
    ArbolCiudad reporteCiudad;
    ciudades.cargarCiudades(paises);
	listaRest restaurantes;
	ArbolRestaurante rests;
    restaurantes.cargarRest(paises, ciudades, rests);
    ArbolMenu menus;
    menus.cargarMenus(paises, ciudades, rests);
	ArbolProducto productos;
	productos.cargarProductos(paises, ciudades, restaurantes, menus);
    ArbolCliente clientes;
    clientes.cargarCliente();
    fila Fila;
    ListaCompra lCompra, lCompra2;
    system("cls");
	menu(paises, ciudades, restaurantes, menus, productos, clientes, rests, Fila, lCompra, reporteCiudad, lCompra2);
	return 0;
}
