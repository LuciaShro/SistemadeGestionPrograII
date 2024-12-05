#pragma once
#include "Cliente.h"

class ArchivoCliente{
public:
    ArchivoCliente();
    bool GuardarRegistro(const Cliente &cliente);
    int FunGuardarRegistro();
    Cliente leerRegistro(int IdCliente); ///(Listado buscar)
    void listarRegistros(); ///Listado General
    int getCantidadRegistros();
    void mostrarCliente(Cliente cliente);
    bool modificarRegistro(int pos, const Cliente &cliente);
    void FunModificarRegistro();
    int buscar(int id);
    bool BajaDeRegistro();
    bool VerificarRegistroExistente(int id);
    /*void BuscarCliente(int id);*/
    bool BuscarCliente();
    void MostrarNombreyApellido(int dni);
    bool ActualizacionPuntaje(Cliente& cliente);
    bool ActualizacionPuntajeResta(Cliente& cliente); // NUEVA FUNCION (lu paz)

    bool ClienteEstadoInactivo(int idCliente, Cliente& cliente);

private:
    char _nombreArchivoCliente[100];
};
