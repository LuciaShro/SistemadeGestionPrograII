#include <iostream>
#include <cstring>
#include "cliente.h"
#include "vendedor.h"
#include "categoria.h"
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
#include "menu.h"
using namespace std;

int main(){

    ArchivoVendedor vendedor;
    vendedor.FunGuardarRegistro();

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
