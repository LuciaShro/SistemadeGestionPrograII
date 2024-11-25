#include <iostream>
#include "menu.h"
#include "ArchivoProductos.h"
#include "ArchivoComprasAlProveedor.h"
#include "ArchivoDevoluciones.h"

using namespace std;

void mostrarCentrado(const std::string& texto, int fila) {
    rlutil::locate((115 - texto.length()) / 2, fila);  // Ancho fijo de 115 columnas
    std::cout << texto;
}

void menuPrincipal(){
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    int opcion;
    do {
        rlutil::cls();
        mostrarCentrado("----------------------",3);
        mostrarCentrado("----------------------",5);
        mostrarCentrado("MENU PRINCIPAL", 4);
        mostrarCentrado(" 1 - CLIENTES",6);
        mostrarCentrado(" 2 - VENTAS",7);
        mostrarCentrado(" 3 - VENDEDORES",8);
        mostrarCentrado(" 4 - PRODUCTOS",9);
        mostrarCentrado(" 5 - PROVEEDORES",10);
        mostrarCentrado(" 6 - DEVOLUCIONES", 11);
        mostrarCentrado(" 7 - INFORMES", 12);
        mostrarCentrado(" 8 - CONFIGURACIONES",13);
        mostrarCentrado(" 9 - SALIR",14);
        mostrarCentrado("Seleccione una opcion para avanzar: ", 18);
        cin >> opcion;

        switch (opcion){
            case 1: menuClientes(); break;
            case 2: menuVentas(); break;
            case 3: menuVendedores(); break;
            case 4: menuProductos(); break;
            case 5: menuProveedores(); break;
            case 6: menuDevoluciones(); break;
            case 7: menuInformes(); break;
            case 8: menuConfiguraciones(); break;
            case 9: cout << "  Saliendo del sistema..."; break;
            default:
            rlutil::setColor(rlutil::RED);
            cout << "  Numero de Opcion invalida, por favor intente nuevamente." << endl;
            rlutil::anykey(); // esto es para cuando queremos que muestre el mensaje de incorrecto y luego introduzca la opcion nuevamente
            rlutil::setColor(rlutil::BLACK);

        }
    }while(opcion !=9);
}

void menuClientes() {
    system("cls");
    int opcion;
    do {
        cout << endl << "============ CLIENTES ============" << endl << endl;
        cout << "  1 - Registrar nuevo Cliente" <<endl;
        cout << "  2 - Listado de Clientes" << endl;
        cout << "  3 - Consultar Cliente" << endl;
        cout << "  4 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "Ingrese los datos del nuevo cliente " << endl; break;
            case 2: cout << "Listado de clientes: " << endl; break;
            case 3: cout << "Ingrese el ID del cliente: " << endl; break;
            case 4: cout << "Volviendo al menu principal... " << endl; break;
        }
    } while(opcion!=4);
}
void menuVendedores() {
    int opcion;
    do {
        cout << endl << "============ VENDEDORES ============" << endl << endl;
        cout << "  1 - Registrar Vendedor" <<endl;
        cout << "  2 - Listar Vendedores" << endl;
        cout << "  3 - Consultar Vendedor" << endl;
        cout << "  4 - Modificar Informacion" << endl;
        cout << "  5 - Eliminar Vendedor " << endl;
        cout << "  6 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "Registre al nuevo vendedor" << endl; break;
            case 2: cout << "Listado de vendedores: " << endl; break;
            case 3: cout << "Ingrese el ID del vendedor que desea consultar su puntaje " << endl; break;
            case 4: cout << "Ingrese el ID del Vendedor que desee eliminar del listado de empleados: " << endl; break;
            case 5: cout << "Ingrese el ID del Vendedor que desee Modificar " << endl; break;
            case 6: cout << "Volviendo al menu principal... " << endl; break;
        }
    } while(opcion!=4);
}
void menuVentas() {
    int opcion;
    do {
        cout << endl << "============ VENTAS ============" << endl << endl;
        cout << "  1 - Registrar Ventas" <<endl;
        cout << "  2 - Listar Ventas" << endl;
        cout << "  3 - Consultar Ventas" << endl;
        cout << "  4 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "Registre la nueva venta: " << endl; break;
            case 2: cout << "Listado de ventas" << endl; break;
            case 3: cout << "Ingrese el ID de la venta que desee buscar " << endl; break;
            case 4: cout << "Volviendo al menu principal... " << endl; break;
        }
    } while(opcion!=4);
}
void menuProveedores() {
    int opcion;
    ArchivoComprasAlProveedor compras("ArchivoComprasAlProveedor.dat");
    ArchivoDevoluciones devoluciones;
    do {
        cout << endl << "============ PROVEEDORES ============" << endl << endl;
        cout << "  1 - Registrar Proveedor" <<endl;
        cout << "  2 - Listar Proveedores" << endl;
        cout << "  3 - Consultar Proveedores" << endl;
        cout << "  4 - Eliminar Proveedor " << endl;
        cout << "  5 - Realizar una compra al proveedor " << endl;
        cout << "  6 - Listar compras al proveedor " << endl;
        cout << "  7 - Realizar una devolucion al proveedor " << endl;
        cout << "  8 - Devoluciones al proveedor " << endl;
        cout << "  9 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "Registre a su nuevo proveedor: " << endl; break;
            case 2: cout << "Listado de proveedores actuales" << endl; break;
            case 3: cout << "Ingrese el ID del proveedor que desee buscar: " << endl; break;
            case 4: cout << "Ingrese el ID del proveedor que desee eliminar del listado: " << endl; break;
            case 5: cout<< "Ingresar compra al proveedor: "<<endl;
            compras.agregarRegistro();
            break;
            case 6: cout<< "Listado de compras al proveedor: "<<endl;
            compras.listarCompras();
            break;
            case 7: cout<< "Realizar una devolucion: "<<endl;
            devoluciones.agregarDevolucion();
            break;
            case 8: cout<< "Listado devoluciones: "<<endl;
            devoluciones.listarDevoluciones();
            break;
            case 9: cout << "Volviendo al menu principal... " << endl; break;
        }
    } while(opcion!=9);
}
void menuProductos() {
    int opcion;
    ArchivoProductos archivo("archivoProductos.dat");
    do {
        cout << endl << "============ PRODUCTOS ============" << endl << endl;
        cout << "  1 - Registrar Producto" <<endl;
        cout << "  2 - Listar Producto" << endl;
        cout << "  3 - Consultar Producto" << endl;
        cout << "  4 - Modificar precio del producto " << endl;
        cout << "  5 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "Registre el nuevo producto: " << endl;
            archivo.agregarRegistro(); break;
            case 2: cout << "Listado de productos: " <<endl;
            cout<< archivo.listarRegistros()<<endl; break;
            case 3: cout << "Ingrese el ID del producto que desee buscar: " << endl;
            cout<< archivo.buscarProductoPorID()<<endl; break;
            case 4: cout << "Ingrese el ID del producto que desee modificar precio del listado:" << endl;
            cout<< archivo.modificarPrecioProducto()<<endl; break;
            case 5: cout << "Volviendo al menu principal... " << endl;
            menuPrincipal();
            break;
        }
    } while(opcion!=5);
}
void menuDevoluciones() {
    int opcion;
    do {
        cout << endl << "============ DEVOLUCIONES ============" << endl << endl;
        cout << "  1 - Registrar Devolucion" <<endl;
        cout << "  2 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "Aqui registre a su nuevo devolucion" << endl; break;
            case 2: cout << "Volviendo al menu principal... " << endl; break;
        }
    } while(opcion!=2);
}
void menuInformes() {
    int opcion;
    do {
        cout << endl << "============ INFORMES ============" << endl << endl;
        cout << "  1 - informes Clientes" <<endl;
        cout << "  2 - Informes Ventas" << endl;
        cout << "  3 - Informes Vendedores" << endl;
        cout << "  4 - Informes Proveedores" << endl;
        cout << "  5 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "Informe de cliente:" << endl; break;
            case 2: cout << "Informe de ventas: " << endl; break;
            case 3: cout << "Informe de vendedores: " << endl; break;
            case 4: cout << "Informe de proveedores: " << endl; break;
            case 5: cout << "Volviendo al menu principal... " << endl; break;
        }
    } while(opcion!=5);
}
void menuConfiguraciones() {
    int opcion;
    do {
        cout << endl << "============ CONFIGURACIONES ============" << endl << endl;
        cout << "  1 - Imprimir Listado de Productos" <<endl;
        cout << "  2 - Copia de Seguridad" << endl;
        cout << "  3 - a confirmar" << endl;
        cout << "  4 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "Aqui tiene el listado de productos" << endl; break;
            case 2: cout << "Aqui tiene la copia de seguridad" << endl; break;
            case 3: cout << "Seguimos trabajando en ello..." << endl; break;
            case 4: cout << "Volviendo al menu principal... " << endl; break;
        }
    } while(opcion!=4);
}
