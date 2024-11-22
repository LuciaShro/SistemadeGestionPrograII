#pragma once
#include "Cliente.h"

class ArchivoCliente{
public:
    ArchivoCliente();
    bool GuardarRegistro(const Cliente &cliente);
    void FunGuardarRegistro();
    Cliente leerRegistro(int IdCliente); ///(Listado buscar)
    void listarRegistros(); ///Listado General
    int getCantidadRegistros();
    void mostrarCliente(Cliente cliente);
    bool modificarRegistro(int pos, const Cliente &cliente);
    void FunModificarRegistro();
    int buscar(int id);
    bool BajaDeRegistro();
    bool VerificarRegistroExistente(int id);
    void BuscarCliente(int id);
private:
    char _nombreArchivoCliente[100];
};
