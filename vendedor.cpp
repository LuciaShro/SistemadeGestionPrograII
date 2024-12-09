#include <iostream>
#include <cstring>
#include "Vendedor.h"
#include "persona.h"
#include "rlutil.h"

using namespace std;

Vendedor::Vendedor(float comision, Fecha fechaIngreso):Persona(){
        _Comisiones=comision;
        _fechaIngreso=fechaIngreso;
}

Vendedor::Vendedor():Persona(1, "Apellido", "Nombre",_Nacimiento, "123456789", "sistema@gestion.com", "Florida"), _Comisiones(0.0), _fechaIngreso(){}

void Vendedor::setComisiones(int idVendedor,detalleVenta& detalleVenta){
    if(getId()==idVendedor){
        _Comisiones+=(detalleVenta.getPrecioTotal()*10)/100;
    }
    else {
        cout<< "no es valido"<<endl;
    }
}

void Vendedor::setFechaIngreso(int dia, int mes, int anio){
    _fechaIngreso.setDia(dia);
    _fechaIngreso.setMes(mes);
    _fechaIngreso.setAnio(anio);
}

float Vendedor::getComisiones(){
    return _Comisiones;
}

std::string Vendedor::getFechaIngreso(){
    return _fechaIngreso.toString();
}

void Vendedor::cargar(){
    int dia, mes, anio;
    /*char separador;*/
    Persona::cargar();
    cout<< "FECHA DE INGRESO DEL VENDEDOR: ";
    rlutil::locate(31,8);
    cout<< "  /  /   ";
    rlutil::locate(31,8);
    cin>>dia;
    rlutil::locate(34,8);
    cin>>mes;
    rlutil::locate(37,8);
    cin>>anio;

    /*cin>> dia >> separador >> mes >> separador >> anio;*/
    setFechaIngreso(dia, mes, anio);
    /*setComisiones(venta, detalleVenta);*/
}

void Vendedor::mostrar(){
    cout<< "------------ "<<"DATOS DEL VENDEDOR"<< " --------------"<<endl;
    Persona::mostrar();
    cout << "Monto de comision: $ " <<getComisiones() << endl;
    cout << "Fecha de ingreso: " <<getFechaIngreso() << endl;
}

/*bool Vendedor::escribirDisco(int pos){}

bool Vendedor::leerDisco(int pos){}*/
