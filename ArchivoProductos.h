#pragma once
#include "productos.h"

 class ArchivoProductos {
 private:
     char _nombreArchivoProductos[100];
 public:
    ArchivoProductos();
    ArchivoProductos(const char *nombreArchivoProducto="archivoProductos.dat");
    void agregarRegistro();
    //ArchivoProductos(const char *nombreArchivoProducto);
    bool grabarRegistroProducto(Producto producto);
    bool listarRegistros();
    bool buscarProductoPorID();
    bool buscarPRODUCTOID(int id, Producto& producto);
    bool buscarProductoPorNombre();
    bool modificarPrecioProducto();
    bool actualizarProducto(Producto& producto);
    int getCantidadRegistros();
    Producto leerRegistro(int idProducto);  ///FUN. NUEVA

    ///FUNCIONES NUEVAS LU.S
    /*void StockVendido();
    void FunModificarVectorStockVendido(Producto producto, int idVenta, int stock);
    bool modificarRegistro(int pos, const Producto &producto);*/

    int InformeProductos();

    int buscar(int id);
};
