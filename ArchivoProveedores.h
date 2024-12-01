#pragma once
#include "proveedores.h"

class ArchivoProveedores{
public:
    ArchivoProveedores();
    bool GuardarRegistro(const Proveedores &proveedores);
    void FunGuardarRegistro();
    Proveedores leerRegistro(int IdProveedor); ///(Listado buscar)
    void listarRegistros(); ///Listado General
    int getCantidadRegistros();
    void mostrarProveedor(Proveedores proveedores);
    bool modificarRegistro(int pos, const Proveedores &proveedores);
    void FunModificarRegistro();
    int buscar(int id);
    bool BajaDeRegistro();
    bool VerificarRegistroExistente(int id);
    void BuscarProveedor(int id);

    void leerRegistros(int idproveedor, int pos, Proveedores &proveedor);
private:
    char _nombreProveedores[100];
};
