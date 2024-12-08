#include <iostream>
#include "menu.h"
#include "cliente.h"
#include "vendedor.h"
#include "proveedores.h"
#include "persona.h"
#include "venta.h"
#include "FECHA.h"
#include "productos.h"
#include "detalleVenta.h"
#include "devoluciones.h"
#include "ComprasAlProveedor.h"
#include "ArchivoProductos.h"
#include "ArchivoComprasAlProveedor.h"
#include "ArchivoDevoluciones.h"
#include "ArchivoVendedor.h"
#include "ArchivoProveedores.h"
#include "ArchivoVenta.h"
#include "ArchivoDetalleDeVenta.h"
#include "ArchivoCliente.h"

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
        mostrarCentrado(" 1 - VENTAS",6);
        mostrarCentrado(" 2 - PRODUCTOS",7);
        mostrarCentrado(" 3 - VENDEDORES",8);
        mostrarCentrado(" 4 - CLIENTES",9);
        mostrarCentrado(" 5 - PROVEEDORES",10);
        mostrarCentrado(" 6 - INFORMES", 11);
//        mostrarCentrado(" 7 - INFORMES", 12);
//        mostrarCentrado(" 8 - CONFIGURACIONES",13);
        mostrarCentrado(" 0 - SALIR",13);
        mostrarCentrado("Seleccione una opcion para avanzar: ", 18);
        cin >> opcion;

        switch (opcion){
            case 1: system("cls"); menuVentas(); break;
            case 2: system("cls"); menuProductos(); break;
            case 3: system("cls"); menuVendedores(); break;
            case 4: system("cls"); menuClientes(); break;
            case 5: system("cls"); menuProveedores(); break; //devoluciones va dentro
            case 6: system("cls"); menuInformes(); break;

            case 0: cout << "  Saliendo del sistema..."; break;
            default:
            rlutil::setColor(rlutil::RED);
            cout << "  Numero de Opcion invalida, por favor intente nuevamente." << endl;
            rlutil::anykey(); // esto es para cuando queremos que muestre el mensaje de incorrecto y luego introduzca la opcion nuevamente
            rlutil::setColor(rlutil::BLACK);
        }
    }while(opcion !=0);
}

void menuClientes() {
    system("cls");
    int opcion, id;
    ArchivoCliente cliente;

    do {
        cout << endl << "============ CLIENTES ============" << endl << endl;
        cout << "  1 - Registrar nuevo Cliente" <<endl;
        cout << "  2 - Listado de Clientes" << endl;
        cout << "  3 - Consultar Cliente" << endl;
        cout << "  4 - Modificar Informacion" << endl;
        cout << "  5 - Eliminar Vendedor " << endl;
        cout << "  0 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: cliente.FunGuardarRegistro(); break;
            case 2: cliente.listarRegistros(); break;
            case 3: cout << "Ingrese el ID del vendedor que desea consultar "; cin>> id; cliente.leerRegistro(id); break;
            case 4: cliente.FunModificarRegistro(); break;
            case 5: cliente.BajaDeRegistro(); break;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); menuPrincipal(); break;
        }
    } while(opcion!=0);
}
void menuVendedores() {
    int opcion, id;
    ArchivoVendedor vendedor;
    do {
        cout << endl << "============ VENDEDORES ============" << endl << endl;
        cout << "  1 - Registrar Vendedor" <<endl;
        cout << "  2 - Listar Vendedores" << endl;
        cout << "  3 - Consultar Vendedor" << endl;
        cout << "  4 - Modificar Informacion" << endl;
        cout << "  5 - Eliminar Vendedor " << endl;
        cout << "  0 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: vendedor.FunGuardarRegistro(); break;
            case 2: vendedor.listarRegistros(); break;
            case 3: cout << "Ingrese el ID del vendedor que desea consultar"; cin >> id; vendedor.leerRegistro(id); break;
            case 4: vendedor.FunModificarRegistro(); break;
            case 5: vendedor.BajaDeRegistro(); break;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); menuPrincipal(); break;
        }
    } while(opcion!=0);
}
void menuVentas() {
    int opcion, id;
    ArchivoVenta venta;
    do {
        cout << endl << "============ VENTAS ============" << endl << endl;
        cout << "  1 - Registrar Ventas" <<endl;
        cout << "  2 - Listar Ventas" << endl;
        cout << "  3 - Consultar Ventas" << endl;
        cout << "  0 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: venta.FunGuardarRegistro(); break;
            case 2: venta.listarRegistros(); break;
            case 3: cout << "Ingrese el ID de la venta que desee buscar "; cin>> id; venta.leerRegistro(id); break;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); menuPrincipal(); break;
        }
    } while(opcion!=0);
}
void menuProveedores() {
    int opcion, id;
    ArchivoProveedores proveedores;
    ArchivoComprasAlProveedor compras("ArchivoComprasAlProveedor.dat");
    ArchivoDevoluciones devoluciones;
    do {
        cout << endl << "===================PROVEEDORES=====================" << endl << endl;
        cout << "  1 - Registrar Proveedor" <<endl;
        cout << "  2 - Listar Proveedores" << endl;
        cout << "  3 - Consultar Proveedores" << endl;
        cout << "  4 - Eliminar Proveedor " << endl << endl;

        cout << endl << "============ COMPRAS AL PROVEEDOR =================" << endl << endl;
        cout << "  5 - Realizar una compra al proveedor " << endl;
        cout << "  6 - Listar compras al proveedor " << endl << endl;

        cout << endl << "============ DEVOLUCIONES AL PROVEEDOR ============" << endl << endl;
        cout << "  7 - Realizar una devolucion al proveedor " << endl;
        cout << "  8 - Devoluciones al proveedor " << endl << endl;

        cout << "===================================================" << endl << endl;

        cout << "  0 - Volver al Menu Principal" << endl << endl << endl;

        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: ; break;
            case 2: proveedores.FunGuardarRegistro(); break;
            case 3: proveedores.listarRegistros(); break;
            case 4: cout << "Ingrese el ID del proveedor que desee eliminar del listado: "; cin >> id; proveedores.leerRegistro(id); break;

            case 5: compras.agregarRegistro(); break;
            case 6: compras.listarCompras(); break;

            case 7: devoluciones.agregarDevolucion(); break;
            case 8: devoluciones.listarDevoluciones(); break;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); menuPrincipal(); break;
        }
    } while(opcion!=0);
}
void menuProductos() {
    int opcion, id;
    ArchivoProductos archivo("archivoProductos.dat");
    do {
        cout << endl << "============ PRODUCTOS ============" << endl << endl;
        cout << "  1 - Registrar Producto" <<endl;
        cout << "  2 - Listar Producto" << endl;
        cout << "  3 - Consultar Producto" << endl;
        cout << "  4 - Modificar precio del producto " << endl;
        cout << "  5 - Dar de baja un registro " << endl;
        cout << "  0 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: archivo.agregarRegistro(); break;
            case 2: archivo.listarRegistros(); break;
            case 3: archivo.buscarProductoPorID(); break;
            case 4: archivo.modificarPrecioProducto(); break;
            case 5: archivo.BajaRegistroProducto(); break;
            cout << endl;
            case 0: cout << "Volviendo al menu principal... " << endl;
            system("cls"); menuPrincipal();
            break;
        }
    } while(opcion!=0);
}
//void menuDevoluciones() {
//    int opcion;
//    do {
//        cout << endl << "============ DEVOLUCIONES ============" << endl << endl;
//        cout << "  1 - Registrar Devolucion" <<endl;
//        cout << "  2 - Volver al Menu Principal" << endl;
//        cout << endl << "  Seleccione una opcion: " ;
//        cin >> opcion;
//
//        switch(opcion) {
//            case 1: cout << "Aqui registre a su nuevo devolucion" << endl; break;
//            case 2: cout << "Volviendo al menu principal... " << endl; break;
//        }
//    } while(opcion!=2);
//}
void menuInformes(){
    int opcion;
    ArchivoVenta venta;
    ArchivoProductos productos("archivoProductos.dat");
    do {
        cout << endl << "============ INFORMES ============" << endl << endl;
        cout << "  1 - Informe Ventas" << endl;
        cout << "  2 - Informe Productos" << endl;
        cout << "  0 - Volver al Menu Principal" << endl << endl;
        cout << endl << "  Seleccione una opcion: " ; cin >> opcion;

        switch(opcion) {
            case 1: system("cls"); venta.InformeVentaxAnio(); break;
            case 2: system("cls"); productos.InformeProductos(); break;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); menuPrincipal(); break;
        }

        cout << endl;

//        cout << "Presiona cualquier tecla para continuar..." << std::endl;
//        cin.get(); // Espera una entrada del usuario

        system("pause");
        system("cls");
    } while(opcion!=0);
}

//void menuConfiguraciones(){
//    int opcion;
//    do {
//        cout << endl << "============ CONFIGURACIONES ============" << endl << endl;
//        cout << "  1 - Imprimir Listado de Productos" <<endl;
//        cout << "  2 - Copia de Seguridad" << endl;
//        cout << "  3 - a confirmar" << endl;
//        cout << "  4 - Volver al Menu Principal" << endl;
//        cout << endl << "  Seleccione una opcion: " ;
//        cin >> opcion;
//
//        switch(opcion) {
//            case 1: cout << "Aqui tiene el listado de productos" << endl; break;
//            case 2: cout << "Aqui tiene la copia de seguridad" << endl; break;
//            case 3: cout << "Seguimos trabajando en ello..." << endl; break;
//            case 4: cout << "Volviendo al menu principal... " << endl; break;
//        }
//    } while(opcion!=4);
//}
