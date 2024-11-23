#pragma once
#include "detalleVenta.h"
#include "productos.h"

class ArchivoDetalleDeVenta{
public:
    ArchivoDetalleDeVenta();
    bool GuardarRegistro(const detalleVenta &detalle);
    void FunGuardarRegistro(int idVenta);
    detalleVenta leerRegistro(int IdVenta); ///(Listado buscar)
    void listarRegistros(); ///Listado General
    int getCantidadRegistros();
    void mostrarDetalle(detalleVenta detalle);
    bool modificarRegistro(int pos, const detalleVenta &detalle);
    void FunModificarRegistro();
    int buscar(int id);
    Producto BuscarProducto(Producto &producto);

private:
    char _NombreArchivoDetalle[100];
};
