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
#include "ArchivoCliente.h"
#include "ArchivoDetalleDeVenta.h"
#include "menu.h"
using namespace std;

int main(){

    //ArchivoVendedor vendedor;
    //vendedor.FunGuardarRegistro();
    //vendedor.listarRegistros();
//
    ArchivoDetalleDeVenta detalle;
    //ArchivoVenta venta;
    //venta.FunGuardarRegistro();
    cout << "---------------------------------" << endl;
   detalle.listarRegistros();


    //venta.listarRegistros();

    /*ArchivoCliente cliente;
    cliente.FunGuardarRegistro();
    cliente.listarRegistros();*/


//  ArchivoProductos producto("archivoProductos.dat");
//   producto.listarRegistros();

    /*ArchivoProveedores archivoPro;
    for(int i=0; i<7; i++){
        archivoPro.FunGuardarRegistro();
    }
    archivoPro.listarRegistros();*/
    /*ArchivoProductos archivo("archivoProductos.dat");
    archivo.listarRegistros();*/

   /*ArchivoComprasAlProveedor archivoCOMPRAS("archivoComprasAlProveedor.dat");

   archivoCOMPRAS.agregarRegistro();

    archivoCOMPRAS.listarCompras();*/

    /*archivo.listarRegistros();*/

    /*ArchivoDevoluciones devolucion("archivoDevoluciones.dat");
    devolucion.agregarDevolucion();
    devolucion.listarDevoluciones();*/
   /* system("cls");
    archivo.listarRegistros();*/

    /*menuPrincipal();*/
    return 0;

}




