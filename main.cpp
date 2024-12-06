#include <iostream>
#include <cstring>
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
#include "menu.h"
using namespace std;

int main(){
//
    ArchivoVenta venta;
    venta.FunGuardarRegistro();
    //venta.listarRegistros();

//    ArchivoVenta venta;
//    venta.VentasXmes();
//
//   ArchivoProductos archivo("archivoProductos");
//    archivo.listarRegistros();
//    archivo.StockVendido();
//
//    ArchivoVenta venta;
//    venta.FunGuardarRegistro();
//    cout << "---------------" << endl;
//    venta.listarRegistros();
//
//cout << "---------------" << endl;
//    ArchivoDetalleDeVenta detalle;
//    detalle.listarRegistros();
//
//    ArchivoCliente cliente;
//    cliente.listarRegistros();

//      ArchivoVendedor vendedor;
//      vendedor.FunGuardarRegistro();

//
//     ArchivoComprasAlProveedor compras("archivoComprasAlProvedor.dat");
//     compras.agregarRegistro();

    /*menuPrincipal();*/
    return 0;

}
