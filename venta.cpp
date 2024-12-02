#include "venta.h"
#include <cstring>
#include <iostream>
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
#include "rlutil.h"

using namespace std;

Venta::Venta(){
    _IDVenta=0;
    Cliente _cliente;
    _idVendedor=0;
    strcpy(_formaDePago, "fp");
    Fecha _fecha;
}

Venta::Venta(int idVenta, Cliente cliente, int idVendedor, char* fp, Fecha fecha){
    _IDVenta=idVenta;
    _cliente=cliente;
    _idVendedor=idVendedor;
    strcpy(_formaDePago, fp);
    _fecha=fecha;
}

void Venta::setIDVenta(int id){
    _IDVenta=id;
}

void Venta::setCliente(int idCliente){
  _cliente.setId(idCliente);
}

void Venta::setIDVendedor(int idVendedor){
    _idVendedor=idVendedor;
}

void Venta::setFormaDePago(int fp){
    switch(fp){
    case 1:
            strcpy(_formaDePago,"Efectivo");
        break;
    case 2:
        strcpy(_formaDePago,"Debito");
        break;
    case 3:
        strcpy(_formaDePago,"Credito");
        break;
    case 4:
        strcpy(_formaDePago,"Billetera Virtual");
        break;
    }
}

void Venta::setFecha(int dia, int mes, int anio){
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
    _fecha.setDia(dia);
}

int Venta::getIDVenta(){
    return _IDVenta;
}

int Venta::getCliente(){
   return _cliente.getId();
}

int Venta::getIDVendedor(){
    return _idVendedor;
}

const char* Venta::getFormaDePago(){
    return _formaDePago;
}

std::string Venta::getFecha(){
    return _fecha.toString();
}

int Venta::getMesVenta(){
    return _fecha.getMes();
}

int Venta::getAnioVenta(){
    return _fecha.getAnio();
}
// MODIFICADO 27-11-2024 - LU PAZ
void Venta::cargar(){
    int dia, mes, anio, idcliente, intentos;
    /*char separador;*/
    ArchivoVendedor archVendedor;
    ArchivoCliente cliente;

    cout<< "INGRESAR LA FECHA DE LA VENTA: ";
    rlutil::locate(32,2);
    cout<< "  /  /   ";
    rlutil::locate(32,2);
    cin>>dia;
    rlutil::locate(35,2);
    cin>>mes;
    rlutil::locate(38,2);
    cin>>anio;
    /*cin>> dia >> separador >> mes >> separador >> anio;*/
    setFecha(dia, mes, anio);

    cout<< "INGRESE LA FORMA DE PAGO(1-Efectivo, 2-Debito, 3-Credito, 4-Billetera Virtual): ";
    int formaDePago;
    cin>>formaDePago;
    while(intentos!=3){
        if(formaDePago >= 1 && formaDePago<=4){
            setFormaDePago(formaDePago);
            break;
        }else{
            cout << "INGRESO INCORRECTO, VUELVA A INTENTARLO " << endl;
            cout << "---------------------------------------------" << endl;
            intentos++;
            if(intentos == 3){return;}
            cout<< "INGRESE LA FORMA DE PAGO(1-Efectivo, 2-Debito, 3-Credito, 4-Billetera Virtual): ";
            cin>>formaDePago;
        }
    }



    cout << "--------------------------------" << endl;
    cout<< "INGRESE LOS DATOS DEL CLIENTE: ";

    idcliente= cliente.FunGuardarRegistro();
    if(idcliente!=-1){
        _cliente.setId(idcliente);
    }
    else {
        cout<< "No se pudo registrar el cliente"<<endl;
    }


    cout<< "INGRESE EL DNI DEL VENDEDOR: ";
    while(true){
        cin>>_idVendedor;
        if(cin.fail()|| _idVendedor<0 || archVendedor.buscar(_idVendedor)==-1){
        cout<< "INGRESAR UN DNI VALIDO"<<endl;
        cout<< "INGRESE EL DNI DEL VENDEDOR: ";
        cin.clear();
        cin.ignore();
    }
    else{
        Vendedor vendedor;
        detalleVenta detalle;
        setIDVendedor(_idVendedor);

        int posVendedor = archVendedor.buscar(getIDVendedor());
        vendedor = archVendedor.leerRegistro(posVendedor);

        vendedor.setComisiones(getIDVendedor(), detalle);

        break;
    }
    }
}


void Venta::mostrar(){
    cout<< "FECHA DE LA VENTA: "<<getFecha()<<endl;
    cout<< "ID DE VENTA: "<< getIDVenta() <<endl;
    cout<< "ID DEL CLIENTE: "<< getCliente()<<endl;
    cout<< "ID DEL VENDEDOR: "<<_idVendedor<<endl;
    cout<< "FORMA DE PAGO: "<<getFormaDePago()<<endl;
}

bool Venta::escribirDisco(int pos){
}

bool Venta::leerDisco(int pos){
}
