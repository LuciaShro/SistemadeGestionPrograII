#include "devoluciones.h"
#include <cstring>
#include <string>
#include <iostream>
#include "productos.h"

using namespace std;

Devoluciones::Devoluciones(){}

Devoluciones::Devoluciones(Producto& producto):_idProducto(producto){}

void Devoluciones::setIDProducto(int id){
    if(id>0){
        _idProducto.setIDProducto(id);
    }
}

void Devoluciones::setIngresoDevolucion(int dia, int mes, int anio){
    _ingresoDevolucion.setDia(dia);
    _ingresoDevolucion.setMes(mes);
    _ingresoDevolucion.setAnio(anio);
}

void Devoluciones::setIDProveedor(int idProveedor){
    if(idProveedor>0){
        _idProveedor.setIdproveedor(idProveedor);
    }
}

void Devoluciones::setDevolucionRealizada(bool DevolucionRealizada){
    _DevolucionRealizada=DevolucionRealizada;
}

void Devoluciones::setcantidadProductos(int cantidadProductos){
        _cantidadProductos=cantidadProductos;
}

int Devoluciones::getIDProducto(){
    return _idProducto.getIDProducto();
}

string Devoluciones::getIngresoDevolucion(){
    return _ingresoDevolucion.toString();
}

int Devoluciones::getIDProveedor(){
    return _idProveedor.getIdproveedor();
}

const char* Devoluciones::getDevolucionRealizada(){
    if(_DevolucionRealizada){
        return "REALIZADA";
    }
    else {
        return "NO REALIZADA";
    }
}

int Devoluciones::getcantidadProductos(){
    return _cantidadProductos;
}

void Devoluciones::DevolucionExitosa(Producto& producto){
    if(_DevolucionRealizada==1){
                 int stockActual = producto.getStock();
                 int cantidadADevolver = getcantidadProductos();
                 int nuevoStock = stockActual - cantidadADevolver;
                 if(nuevoStock<0){
                    cout<< "ERROR"<<endl;
                 }
                 producto.actualizarStock(nuevoStock);
                 cout<< "LA DEVOLUCION FUE REALIZADA CON EXITO"<<endl;
    }
    else {
        cout<< "LA DEVOLUCION FUE CANCELADA EXITOSAMENTE"<<endl;
    }
}

void Devoluciones::ComparacionID(Producto& producto){
    if(producto.getIDProducto()== _idProducto.getIDProducto()){
            cout<< "El producto coincide, procediendo con la devolucion...."<<endl;
            system("cls");
            DevolucionExitosa(producto);
            mostrar();
    }else{
        cout << "EL PRODUCTO "<<_idProducto.getIDProducto()<<"NO COINCIDE"<< endl;
    }
}

void Devoluciones::realizarDevolucion(Producto& producto){
    int cantidadProductos;
    cout<< "¿CUANTOS PRODUCTOS DEL ID "<<_idProducto.getIDProducto()<<" DESEA REALIZAR LA DEVOLUCION?"<<endl;
    while(true){
        cin>>cantidadProductos;
        if(cantidadProductos<=0){
            cout<< "INCORRECTO. DEBE INGRESAR UN NUMERO MAYOR A 0"<<endl;
        }
        else if (cantidadProductos>producto.getStock()){
                cout<< "Es invalido, te recuerdo que el producto "<<_idProducto.getIDProducto()<< " tiene un stock actual de "<<producto.getStock()<<endl;
        }
        else {
            break;
        }
        cout<< "¿CUANTOS PRODUCTOS DEL ID "<<_idProducto.getIDProducto()<<" DESEA REALIZAR LA DEVOLUCION?"<<endl;
    }
    setcantidadProductos(cantidadProductos);
}

void Devoluciones::cargar(Producto& producto){
    int id, idproveedor, dia, mes, anio;
    bool confirmacion;
    char separador;
    cout<< "-------------"<<"DEVOLUCIONES AL PROVEEDOR"<< "-------------"<<endl;
    cout<< "INGRESAR EL ID DEL PRODUCTO: ";
    while(true){
        cin>>id;
        if(cin.fail()|| id!=producto.getIDProducto()){
        cout<< "INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cout<< "INGRESAR EL ID DEL PRODUCTO: ";
        cin.clear();
        cin.ignore();
    }
    else {
        break;
    }
    }
     _idProducto.setIDProducto(id);
    cout<< "INGRESAR EL ID DEL PROVEEDOR: ";
    while(true){
        cin>>idproveedor;
        if(cin.fail()|| idproveedor!=_idProveedor.getIdproveedor()){
        cout<< "INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cout<< "INGRESAR EL ID DEL PROVEEDOR: ";
        cin.clear();
        cin.ignore();
    }
    else{
        break;
    }
    }
    _idProveedor.setIdproveedor(idproveedor);
    cout<< "INGRESAR FECHA DE DEVOLUCION: ";
    cin>> dia >> separador >> mes >> separador >> anio;
    setIngresoDevolucion(dia, mes, anio);
    /*cout<< "¿CUANTOS PRODUCTOS DEL ID "<<_idProducto.getIDProducto()<<" DESEA REALIZAR LA DEVOLUCION?"<<endl;
    cin>>cantidadProductos;*/
    realizarDevolucion(producto);
    cout<< "¿DESEA FINALIZAR LA DEVOLUCION? "<< "0-NO 1-SI "<<endl;
    cin>>confirmacion;
    if(confirmacion==1){
        setDevolucionRealizada(1);
        ComparacionID(producto);
    }
    else {
        setDevolucionRealizada(0);
        cout<< "LA DEVOLUCION FUE CANCELADA"<<endl;
    }
    /*DevolucionExitosa():*/
}



void Devoluciones::mostrar(){
    cout<< "-------------"<<"DEVOLUCIONES AL PROVEEDOR"<< "-------------"<<endl;
    cout<< "ID DEL PRODUCTO: "<<getIDProducto()<<endl;
    cout<< "ID DEL PROVEEDOR: "<<getIDProveedor()<<endl;
    cout<< "FECHA DE DEVOLUCION: "<<getIngresoDevolucion()<<endl;
    cout<< "CANTIDAD DE PRODUCTOS A DEVOLVER: "<<getcantidadProductos()<<endl;
    cout<< "DEVOLUCION: "<<getDevolucionRealizada()<<endl;

    /*cout<< "STOCK ACTUAL: "<<_idProducto.getStock()<<endl;*/
}

/*bool Devoluciones::leerDisco(int pos){
}

bool Devoluciones::escribirDisco(int pos){
}*/
