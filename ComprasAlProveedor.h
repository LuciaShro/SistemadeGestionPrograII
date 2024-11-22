#pragma once
#include "proveedores.h"
#include "productos.h"
#include "devoluciones.h"
#include "ArchivoProveedores.h"

class ComprasAlProveedor {
private:
    Proveedores _proveedor;
    Producto _producto;
    Fecha _fecha;
    int _CantidadProductos;
    float _PrecioUnitario;
    float _PrecioTotal;

public:
    ComprasAlProveedor();
    ComprasAlProveedor(Producto& producto);
    ComprasAlProveedor(Producto& producto, int CantidadProductos, float PrecioUnitario, float PrecioTotal);
    void setCantidadProductos(int CantidadProductos);
    void setPrecioUnitario(float PrecioUnitario);
    void setPrecioTotal(float PrecioTotal);
    void setFechaDeCompra(int dia, int mes, int anio);

    const char* getMarca();
    const char* getNombreProducto();
    int getIdProveedor();
    int getIdProducto();
    int getCantidadProductos();
    float getPrecioUnitario();
    float getPrecioTotal();
    std::string getFechaDeCompra();
    void SumaDeStock(Producto& producto);

    void cargar(Producto& producto);
    void mostrar();
};
