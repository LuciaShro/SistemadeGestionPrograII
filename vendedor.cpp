#include <iostream>
#include <cstring>
#include "Vendedor.h"
#include "persona.h"

using namespace std;

Vendedor::Vendedor(float comision, float comisionPagada, Fecha fechaIngreso):Persona(_Id, _Apellidos, _Nombres, _Nacimiento, _Telefono, _Mail, _Domicilio){
        _Comisiones=comision;
        _ComisionPagada=comisionPagada;
        _fechaIngreso=fechaIngreso;
}

Vendedor::Vendedor():Persona(1, "Apellido", "Nombre",_Nacimiento, "123456789", "sistema@gestion.com", "Florida"), _Comisiones(0.0), _ComisionPagada(0.0), _fechaIngreso(){}

void Vendedor::setComisiones(float comisiones){
    if(comisiones>0){
        _Comisiones = comisiones;
    }
}

void Vendedor::setComisionPagada(float comisionPagada){
    _ComisionPagada=comisionPagada;
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
    cout<< "MONTO DE COMISION: ";
    cin>>_Comisiones;
}

void Vendedor::mostrar(){
    cout<< "------------ "<<"DATOS DEL VENDEDOR"<< " --------------"<<endl;
    Persona::mostrar();
    cout << "Monto de comision: " <<getComisiones() << endl;
    cout << "Fecha de ingreso: " <<getFechaIngreso() << endl;
}

bool Vendedor::escribirDisco(int pos){}

bool Vendedor::leerDisco(int pos){}
