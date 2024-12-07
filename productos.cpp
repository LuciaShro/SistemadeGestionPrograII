#include "productos.h"
#include "ArchivoVenta.h"
#include <limits>
#include <cstring>
#include <iostream>
using namespace std;

Producto::Producto(){
        _IDProducto=0;
        strcpy(_nombre, "nombre");
        _precio=0.0f;
        _stock=0;
        strcpy( _descripcion, "descripcion");
}

Producto::Producto(int id, char* nombre, float precio, int stock, char* descripcion){
    setIDProducto(id);
    strcpy(_nombre, nombre);
    _precio=precio;
    _stock=stock;
    strcpy(_descripcion, descripcion);
    /*_fecha=fecha;*/
}

void Producto::setIDProducto(int id){
        if(id > 0){
            _IDProducto=id;
        }
}

void Producto::setNombre(char* nombre){
    strcpy(_nombre, nombre);
}

void Producto::setPrecio(float precio){
        if(precio > 0){
            _precio=precio;
        }
}

void Producto::setStock(int stock){
    if(stock >= 0) {
    _stock=stock;
    }
}

void Producto::setDescripcion(char* descripcion){
        strcpy(_descripcion, descripcion);
}

void Producto::setEstado(bool estado){
    _Estado = estado;
}

/*void Producto::setFecha(int dia, int mes, int anio){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
}*/

/*std::string Producto::getFecha(){
    return _fecha.toString();
}*/

int Producto::getIDProducto(){
    return _IDProducto;
}

const char* Producto::getNombre(){
    return _nombre;
}

float Producto::getPrecio(){
    return _precio;
}

int Producto::getStock(){
    return _stock;
}

const char* Producto::getDescripcion(){
    return _descripcion;
}

const char* Producto::getEstado(){
    if(_Estado){
        return "ACTIVO";
    }
    else {
        return "INACTIVO";
    }
}

void Producto::actualizarStock(int nuevoStock){
     if(nuevoStock >= 0) {
        _stock = nuevoStock;
    }
}

void Producto::cargar(){
    /*char separador;*/
    float precio;
    cout << "-----------------" << "INFORMACION DEL PRODUCTO"<< "-----------------" <<endl;
    cout<< "INGRESAR EL ID DEL PRODUCTO: ";
    while(true){
        cin>>_IDProducto;
        if(cin.fail()){
        cout<< "INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cout<< "INGRESAR EL ID DEL PRODUCTO: ";
        cin.clear();
        cin.ignore();
    }
    else{
        break;
    }
    }
    cin.ignore();
    cout<< "INGRESAR NOMBRE DEL PRODUCTO: ";
    cin.getline(_nombre, 100);
    cout<< "INDICAR DESCRIPCION DEL PRODUCTO: ";
    cin.getline(_descripcion, 200);
    cout<< "INGRESAR EL PRECIO: $ ";
    cin>>precio;
    setPrecio(precio);
    /*cout<< "INGRESAR EL STOCK: ";
    cin>>stock;
    setStock(stock);*/
    /*cout<< "INDICAR FECHA: ";
    cin>> dia >> separador >> mes >> separador >> anio;
    setFecha(dia, mes, anio);*/
    setEstado(1);
}

void Producto::mostrar(){
    cout << "-----------------" << "INFORMACION DEL PRODUCTO"<< "-----------------" <<endl;
    cout<< "ID DEL PRODUCTO: "<<getIDProducto()<<endl;
    cout<< "NOMBRE DEL PRODUCTO: "<<getNombre()<<endl;
    cout<< "DESCRIPCION DEL PRODUCTO: "<<getDescripcion()<<endl;
    cout<< "PRECIO: $ "<<getPrecio()<<endl;
    cout<< "STOCK DEL PRODUCTO: "<<getStock()<<endl;
    cout<< "ESTADO DEL PRODUCTO: "<<getEstado()<<endl;
   /* cout<< "FECHA: "<<getFecha()<<endl;*/
}
