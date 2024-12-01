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

    /*ArchivoDevoluciones devolucion;
    devolucion.listarDevoluciones();
    devolucion.BuscarDevolucionXIdProducto();*/


    ArchivoDetalleDeVenta detalle;
    detalle.listarRegistros();


    ArchivoProductos archivo("archivoProductos.dat");
    archivo.listarRegistros();

    /*menuPrincipal();*/
    return 0;

}
