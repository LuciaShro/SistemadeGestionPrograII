#pragma once
#include "productos.h"
#include "devoluciones.h"
#include "proveedores.h"
#include "ArchivoProductos.h"

class ArchivoDevoluciones{
private:
    char _nombreArchivoDevoluciones[50];
public:
    ArchivoDevoluciones(const char *nombreArchivoDevoluciones="archivoDevoluciones.dat");
    bool guardarDevolucion(Devoluciones& devolucion);
    void agregarDevolucion();
    bool ActualizarStockArchivoProductos(Producto& producto);
    bool listarDevoluciones();
    int getCantidadRegistros();

};
