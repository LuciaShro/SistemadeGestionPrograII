#pragma once
#include "ComprasAlProveedor.h"
#include "ArchivoProductos.h"

class ArchivoComprasAlProveedor {
private:
    char _nombreArchivoComprasAlProveedor[100];
public:
    ArchivoComprasAlProveedor();
    ArchivoComprasAlProveedor(const char *nombreArchivoComprasAlProveedor="archivoComprasAlProveedor.dat");
    bool guardarComprasAlProveedor(ComprasAlProveedor& comprasProveedor);
    bool listarCompras();
    void agregarRegistro();
    bool ActualizacionStockArchivoProductos(Producto& producto);

    bool BuscarCompras();
};
