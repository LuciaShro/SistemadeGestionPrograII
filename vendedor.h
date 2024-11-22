#pragma once
#include "persona.h"
#include "FECHA.h"
#include "venta.h"
#include "detalleVenta.h"

class Vendedor:public Persona{
public:
    Vendedor();
    Vendedor(float comision, Fecha fechaIngreso);
    void setComisiones(Venta& venta, detalleVenta& detalleVenta);
    void setFechaIngreso(int dia, int mes, int anio);
    void setComisionTotalDelMes();

    float getComisionTotalDelMes();
    float getComisiones();
    std::string getFechaIngreso();

    void cargar();
    void mostrar();
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
private:
    float _Comisiones;
    Fecha _fechaIngreso;
};
