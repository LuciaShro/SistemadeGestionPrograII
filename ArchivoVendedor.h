#pragma once
#include "vendedor.h"
#include "productos.h"
#include "persona.h"

class ArchivoVendedor{
public:
    ArchivoVendedor();
    bool GuardarRegistro(const Vendedor &vendedor);
    void FunGuardarRegistro();
    Vendedor leerRegistro(int IdVendedor); ///(Listado buscar)
    void listarRegistros(); ///Listado General
    int getCantidadRegistros();
    void mostrarVendedor(Vendedor vendedor);
    bool modificarRegistro(int pos, const Vendedor &vendedor);
    void FunModificarRegistro();
    int buscar(int id);
    bool BajaDeRegistro();
    bool VerificarRegistroExistente(int id);
    void BuscarVendedor(int id);
    void SetComision(int idVenta, int idVendedor);

private:
     char _nombreArchivoVendedor[100];
};

