#include <iostream>
#include <cstring>
#include "Vendedor.h"
#include "persona.h"

using namespace std;

Vendedor::Vendedor(float comision, Fecha fechaIngreso):Persona(_Id, _Apellidos, _Nombres, _Nacimiento, _Telefono, _Mail, _Domicilio){
        _Comisiones=comision;
        _fechaIngreso=fechaIngreso;
}

Vendedor::Vendedor():Persona(1, "Apellido", "Nombre",_Nacimiento, "123456789", "sistema@gestion.com", "Florida"), _Comisiones(0.0), _fechaIngreso(){}

void Vendedor::setComisiones(Venta& venta,detalleVenta& detalleVenta){
    if(getId()==venta.getIDVendedor()){
        _Comisiones=(detalleVenta.getPrecioTotal()*10)/100;
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
    char separador;
    cout<< "------------ "<<"DATOS DEL VENDEDOR"<< " --------------"<<endl;
    Persona::cargar();
    cout<< "FECHA DE INGRESO DEL VENDEDOR: ";
    cin>> dia >> separador >> mes >> separador >> anio;
    setFechaIngreso(dia, mes, anio);
    /*setComisiones(venta, detalleVenta);*/
}

void Vendedor::mostrar(){
    cout<< "------------ "<<"DATOS DEL VENDEDOR"<< " --------------"<<endl;
    Persona::mostrar();
    cout << "Monto de comision: $ " <<getComisiones() << endl;
    cout << "Fecha de ingreso: " <<getFechaIngreso() << endl;
}
