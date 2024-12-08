#pragma once
#include "venta.h"

class ArchivoVenta{
public:
    ArchivoVenta();
    bool GuardarRegistro(const Venta &venta);///Listo
    void FunGuardarRegistro();
    Venta leerRegistro(int IdVenta); ///(Listado) LISTO
    void listarRegistros(); ///Listo
    int getCantidadRegistros(); ///Listo
    void mostrarVenta(Venta venta); ///Listo
    bool modificarRegistro(int pos, const Venta &venta);///Listo
    void FunModificarRegistro(); ///Listo
    int buscar(int id);///Listo

    int ContarVenta();
    void BuscarVenta(int id);
    bool BuscarVentasXMes();

    float VentasXmes(); // Total de dinero acumulado por mes dependiendo el anio
    float InformeVentaxMes();
    float InformeVentaxAnio(); // Total recaudado dependiendo el anio que ingreses
    void ListarFactura(int idRegistroVenta); //Muestra la factura de compra, segun el id de venta y detalle;
    void ListarHistorialDeFacturas();
private:
    char _nombreArchivoVenta[50];
};


