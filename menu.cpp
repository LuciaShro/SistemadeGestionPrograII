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

//void menuPrincipal(){
//    rlutil::setBackgroundColor(rlutil::WHITE);
//    rlutil::setColor(rlutil::BLACK);
//    int opcion;
//    do {
//        rlutil::cls();
//        mostrarCentrado("----------------------",3);
//        mostrarCentrado("----------------------",5);
//        mostrarCentrado("MENU PRINCIPAL", 4);
//        mostrarCentrado(" 1 - VENTAS",6);
//        mostrarCentrado(" 2 - PRODUCTOS",7);
//        mostrarCentrado(" 3 - VENDEDORES",8);
//        mostrarCentrado(" 4 - CLIENTES",9);
//        mostrarCentrado(" 5 - PROVEEDORES",10);
//        mostrarCentrado(" 6 - INFORMES", 11);
////        mostrarCentrado(" 7 - INFORMES", 12);
////        mostrarCentrado(" 8 - CONFIGURACIONES",13);
//        mostrarCentrado(" 0 - SALIR",13);
//        mostrarCentrado("Seleccione una opcion para avanzar: ", 18);
//
//        cin>> opcion;
//
//        switch (opcion){
//            case 1: system("cls"); menuVentas(); break;
//            case 2: system("cls"); menuProductos(); break;
//            case 3: system("cls"); menuVendedores(); break;
//            case 4: system("cls"); menuClientes(); break;
//            case 5: system("cls"); menuProveedores(); break; //devoluciones va dentro
//            case 6: system("cls"); menuInformes(); break;
//
//            case 0: cout << endl << "                                             Saliendo del sistema..." << endl; break;
//            default:
//            rlutil::setColor(rlutil::RED);
//            cout << "  Numero de Opcion invalida, por favor intente nuevamente." << endl;
//            rlutil::anykey(); // esto es para cuando queremos que muestre el mensaje de incorrecto y luego introduzca la opcion nuevamente
//            rlutil::setColor(rlutil::BLACK);
//        }
//    }while(opcion !=0);
//}

void menuPrincipal(){
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    int opcion;
    bool ciclo = true;
    while(ciclo!=false){
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
        if(cin.fail()||opcion<0){
           cin.clear();/// limpia el estado de error
           cin.ignore(10000,'\n');/// lo que hace es ignorar (borrar) el caracter, hasta el salto de l�nea
           cout<<"ENTRADA INVALIDA, PORFAVOR, INGRESE UN NUMERO (ENTERO)."<<endl;
           system("pause");
        }else{
            switch (opcion){
            case 1: system("cls"); menuVentas(); break;
            case 2: system("cls"); menuProductos(); break;
            case 3: system("cls"); menuVendedores(); break;
            case 4: system("cls"); menuClientes(); break;
            case 5: system("cls"); menuProveedores(); break; //devoluciones va dentro
            case 6: system("cls"); menuInformes(); break;

            case 0: cout << endl << "                                             Saliendo del sistema..." << endl; ciclo = false; break;
            default:
            rlutil::setColor(rlutil::RED);
            cout << "  Numero de Opcion invalida, por favor intente nuevamente." << endl;
            rlutil::anykey(); // esto es para cuando queremos que muestre el mensaje de incorrecto y luego introduzca la opcion nuevamente
            rlutil::setColor(rlutil::BLACK);
            }
        }

    };
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
            case 1: system("cls"); cliente.FunGuardarRegistro(); system("pause"); break;
            case 2: system("cls"); cliente.listarRegistros(); system("pause"); break;
            case 3: system("cls"); cliente.BuscarCliente(); system("pause"); break;
            case 4: system("cls"); cliente.FunModificarRegistro(); system("pause"); break;
            case 5: system("cls"); cliente.BajaDeRegistro(); system("pause"); break;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); break;
        }
        system("cls");
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
            case 1: system("cls"); vendedor.FunGuardarRegistro(); system("pause"); break;
            case 2: system("cls"); vendedor.listarRegistros(); system("pause"); break;
            case 3: system("cls"); cout << "Ingrese el ID del vendedor que desea consultar: "; cin >> id;
            while(true){
                cout << "Ingrese el ID del vendedor que desea consultar: "; cin >> id;
                if(id>0){
                vendedor.BuscarVendedor(id); system("pause");
                break;
                }
            }
            break;
            case 4: system("cls"); vendedor.FunModificarRegistro(); system("pause"); break;
            case 5: system("cls"); vendedor.BajaDeRegistro();system("pause"); break;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); break;
        }
        system("cls");
    } while(opcion!=0);
}
void menuVentas() {
    int opcion, id;
    ArchivoVenta venta;
    do {
        cout << endl << "============ VENTAS ============" << endl << endl;
        cout << "  1 - Registrar Ventas" <<endl;
        cout << "  2 - Listar Ventas" << endl; ///VER SI SOLO MOSTRAR LAS VENTAS O LAS FACTURAS
        cout << "  3 - Consultar Ventas" << endl;
        cout << "  4 - Historial de Facturas " << endl;
        cout << "  0 - Volver al Menu Principal" << endl;
        cout << endl << "  Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
            case 1: system("cls"); venta.FunGuardarRegistro(); system("pause"); break;
            case 2: system("cls"); venta.listarRegistros(); system("pause"); break;
            case 3: system("cls");
            while(true){
                     cout << "Ingrese el ID de la venta que desee buscar "; cin>> id;
                    if(id>0){
                    venta.BuscarVenta(id); system("pause"); break;
                    }
                }
            break;
            case 4: system("cls"); venta.ListarHistorialDeFacturas();  system("pause"); break;
            case 0:cout << "Volviendo al menu principal... " << endl; system("cls"); break;
        }

        system("cls");
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
            case 1: system("cls"); proveedores.FunGuardarRegistro(); system("pause"); break;
            case 2: system("cls"); proveedores.listarRegistros(); system("pause"); break;
            case 3: system("cls");
               while(true){
                    cout << "Ingrese el ID que desea buscar: "; cin >> id;
                    if(id>0){
                    proveedores.BuscarProveedor(id); system("pause");
                    break;
                    }
                }
            break;
            case 4: system("cls"); proveedores.BajaDeRegistro(); system("pause"); break;

            case 5: system("cls"); compras.agregarRegistro(); system("pause"); break;
            case 6: system("cls"); compras.listarCompras(); system("pause"); break;

            case 7: system("cls"); devoluciones.agregarDevolucion(); system("pause"); break;
            case 8: system("cls"); devoluciones.listarDevoluciones(); system("pause"); break;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); break;
        }
        system("cls");
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
            case 1: system("cls"); archivo.agregarRegistro(); system("pause"); break;
            case 2: system("cls"); archivo.listarRegistros(); system("pause"); break;
            case 3: system("cls"); archivo.buscarProductoPorID(); system("pause"); break;
            case 4: system("cls"); archivo.modificarPrecioProducto(); system("pause"); break;
            case 5: system("cls"); archivo.BajaRegistroProducto(); system("pause"); break;
            cout << endl;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); break;
        }
        system("cls");
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
            case 1: system("cls"); venta.InformeVentaxAnio(); system("pause"); break;
            case 2: system("cls"); productos.InformeProductos(); system("pause"); break;
            case 0: cout << "Volviendo al menu principal... " << endl; system("cls"); break;
        }

        cout << endl;

//        cout << "Presiona cualquier tecla para continuar..." << std::endl;
//        cin.get(); // Espera una entrada del usuario

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
