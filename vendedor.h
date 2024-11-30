#pragma once
#include "persona.h"
#include "FECHA.h"
#include "venta.h"
#include "detalleVenta.h"

class Vendedor:public Persona{
public:
    Vendedor();
    Vendedor(float comision, Fecha fechaIngreso);
    void setComisiones(int idVendedor, detalleVenta& detalleVenta);
    void setFechaIngreso(int dia, int mes, int anio);
    void setComisionTotalDelMes();
    void setComisionXMes(float comisionxmes);

    float getComisionTotalDelMes();
    float getComisiones();
    std::string getFechaIngreso();
    float getComisionXMes();

    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
private:
    float _Comisiones;
    float _comisionXmes[12];
    Fecha _fechaIngreso;
};
