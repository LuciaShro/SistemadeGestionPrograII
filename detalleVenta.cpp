#include "detalleVenta.h"
#include "Cliente.h"
#include "productos.h"
#include <iostream>
using namespace std;


/*detalleVenta::detalleVenta(){
    _IDVenta=0;
    _IDProducto=0;
    _cantidad=0;
    _precioUnitario=0.0f;
}

detalleVenta::detalleVenta(int idVenta, int idProducto, int cantidad, float precioUnitario, Cliente cliente){
    _IDVenta=idVenta;
    _IDProducto=idProducto;
    _cantidad=cantidad;
    _precioUnitario=precioUnitario;
    ContarPuntos(cliente, idVenta);
    _puntosGanados = 0;
}*/

detalleVenta::detalleVenta(){
     _IDProducto = 1;
    _cantidad = 1;
    _precioUnitario = 1;
    _precioTotal = 1;
}

detalleVenta::detalleVenta(Producto& producto, int cantidad){
    _IDProducto = producto.getIDProducto();
    _cantidad = cantidad;
    _precioUnitario = producto.getPrecio();
    _precioTotal = 0;
}

void detalleVenta::setIDVenta(int idVenta){
    _IDVenta=idVenta;
}

void detalleVenta::setIDProducto(Producto producto){
        int idProducto=producto.getIDProducto();
        if(idProducto > 0){
            _IDProducto = idProducto;
        }

}

void detalleVenta::setCantidad(int cantidad){
    if(cantidad > 0){
        _cantidad=cantidad;
    }
}

void detalleVenta::setPuntosGanados(int puntosGanados){
    if(puntosGanados > 0){
        _puntosGanados=puntosGanados;
    }
}

/*void detalleVenta::setPrecioUnitario(Producto producto){
        int precioUnitario=producto.getPrecio();
        if(precioUnitario > 0){
            _precioUnitario = precioUnitario;
        }
}*/

void detalleVenta::setPrecioTotal(Producto producto){
    if(_IDProducto==producto.getIDProducto()){
        if(_cantidad>0 && producto.getPrecio()>0){
            _precioTotal=_cantidad*producto.getPrecio();
        }
        else {
            cout<< "CANTIDAD O PRECIO NO VALIDO"<<endl;
        }
    }
    else {
        cout<< "EL ID NO COINCIDE"<<endl;
        }
}

int detalleVenta::getIDVenta(){
    return _IDVenta;
}

int detalleVenta::getIDProducto(){
    return _IDProducto;
}

int detalleVenta::getCantidad(){
    return _cantidad;
}

float detalleVenta::getPrecioUnitario(){
    return _precioUnitario;
}

/*float detalleVenta::CalcularTotal(){
    return _cantidad*_precioUnitario;
}*/

void detalleVenta::ContarPuntos(Cliente& cliente, int idVenta){
    if(getIDVenta()==idVenta){
        _puntosGanados=_cantidad*5;
        cliente.setPuntaje(cliente.getPuntaje() + _puntosGanados);
}
}

int detalleVenta::getPuntosGanados(){
    return _puntosGanados;
}

float detalleVenta::getPrecioTotal(){
    return _precioTotal;
}

void detalleVenta::actualizarPuntaje(Cliente& cliente) {
        _puntosGanados = _cantidad * 5;
        cliente.agregarPuntos(_puntosGanados);
        if(cliente.getPuntaje()>100){
            cliente.PuntajeMeta();
        }
}

void detalleVenta::RestarStock(Producto& producto, int idProducto, int cantidad){
    if(producto.getIDProducto() == idProducto){
        int stockAnterior = producto.getStock();
        int stockAcutal = stockAnterior - cantidad;
        producto.setStock(stockAcutal);
    }else{
        cout << "EL ID DEL PRODUCTO INGRESADO NO COINCIDE CON EL INGRESADO" << endl;
    }
}
// MODIFICADO
void detalleVenta::cargar(Producto& producto){
    /*cout<< "ID de VENTA: ";
    while(true){
        cin>>_IDVenta;
        if(cin.fail()){
        cout<< "INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cout<< "INGRESAR EL ID DE VENTA: ";
        cin.clear();
        cin.ignore();
    }
    else{
        break;
    }
    }*/
    /*cout<< "ID de PRODUCTO: ";
    while(true){
=======

///MODIFICADO
void detalleVenta::cargar(Producto &producto){
    cout<< "ID de VENTA: " << getIDVenta() << endl;

    _IDProducto = producto.getIDProducto(); ///Declare el id que recibo del producto que ya viene cargado

    cout<< "ID de PRODUCTO: " << getIDProducto() << endl; //Aca se muestra

    /*while(true){
>>>>>>> 8321dac17b18d8f0763e7c718cfeb684d89bd30c
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
    }*/
    cout<< "ID de VENTA: " << getIDVenta() << endl;

    _IDProducto = producto.getIDProducto(); ///Declare el id que recibo del producto que ya viene cargado

    cout<< "ID de PRODUCTO: " << getIDProducto() << endl; //Aca se muestra

    //esto siguiria igual
    cout<< "CANTIDAD: ";
    while(true){
        cin>>_cantidad;
        if(cin.fail()){
        cout<< "INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cout<< "CANTIDAD: ";
        cin.clear();
        cin.ignore();
    }
    else{
        break;
    }
    }

    RestarStock(producto, getIDProducto(), _cantidad);
    setPrecioTotal(producto);
}

void detalleVenta::mostrar(){
    cout<< "--------------"<< "DETALLE DE VENTA"<< "--------------"<<endl;
    cout<< "ID DE VENTA: "<<getIDVenta()<<endl;
    cout<< "ID DE PRODUCTO: "<<getIDProducto()<<endl;
    cout<< "CANTIDAD: "<<getCantidad()<<endl;
    if(_precioTotal>0){
        cout<< "PRECIO TOTAL: $ "<<getPrecioTotal()<<endl;
    }
    else{
        cout<< "EL ID NO COINCIDE CON EL INGRESADO"<<endl;
    }
}

/*bool detalleVenta::escribirDisco(int pos){
}

bool detalleVenta::leerDisco(int pos){
}*/
