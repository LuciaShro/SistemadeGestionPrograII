#pragma once
#include <string>
#include "FECHA.h"
#include "detalleVenta.h"

class Venta{
    public:
        Venta();
        Venta(int idVenta, Cliente cliente, int idVendedor, char* fp, Fecha fecha);
        void setIDVenta(int id);
        void setCliente(int idCliente);
        void setIDVendedor(int idVendedor);
        void setFormaDePago(int fp);
        void setFecha(int dia, int mes, int anio);

        int getIDVenta();
        std::string getFecha();
        int getMesVenta();
        int getAnioVenta();
        int getCliente();
        int getIDVendedor();
        const char* getFormaDePago();

        bool cargar();
        void mostrar();
        bool escribirDisco(int pos);
        bool leerDisco(int pos);

    private:
        int _IDVenta;
        Cliente _cliente;
        int _idVendedor;
        char _formaDePago[50];
        Fecha _fecha;
};
