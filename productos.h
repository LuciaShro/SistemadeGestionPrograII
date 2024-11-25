#pragma once
#include <string>
#include "FECHA.h"

class Producto{
    public:
        Producto();
        Producto (int id, char* nombre, float precio, int stock, char* descripcion);
        void setIDProducto(int id);
        void setNombre(char* nombre);
        void setPrecio(float precio);
        void setStock(int stock);
        void setDescripcion(char* descripcion);
        /*void setFecha(int dia, int mes, int anio);*/

        void actualizarStock(int stockNuevo);
        /*std::string getFecha();*/
        int getIDProducto();
        const char* getNombre();
        float getPrecio();
        int getStock();
        const char* getDescripcion();
        void cargar();
        void mostrar();
        bool escribirDisco(int pos);
        bool leerDisco(int pos);

    private:
        int _IDProducto;
        char _nombre[100];
        float _precio;
        /*Fecha _fecha;*/
        int _stock;
        char _descripcion[200];

};
