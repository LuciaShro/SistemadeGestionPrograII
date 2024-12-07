#include <iostream>
#include <cstring>
#include "Proveedores.h"
#include "ArchivoProveedores.h"
#include <cstring>
using namespace std;


Proveedores::Proveedores(){
    _Idproveedor = 1;
    strcpy(_Marca, "marca");
    _Estado= true;
    strcpy(_Contacto, "contacto");
    strcpy(_Direccion, "direccion");
}

Proveedores::Proveedores(int id, const char* marca, bool estado, const char* contacto, const char* direccion){
    _Idproveedor=id;
    strcpy(_Marca, marca);
    _Estado=estado;
    strcpy(_Contacto, contacto);
    strcpy(_Direccion, direccion);
}

void Proveedores::setIdproveedor(int id){
    if(id > 0){
        _Idproveedor = id;
    }
}

void Proveedores::setMarca(const char* marca){
    strcpy(_Marca, marca);
}

void Proveedores::setEstado(bool estado){
    _Estado=estado;
}

void Proveedores::setContacto(const char* contacto){
    strcpy(_Contacto, contacto);
}

void Proveedores::setDireccionSucursal(const char* direccion){
    strcpy(_Direccion, direccion);
}

int Proveedores::getIdproveedor(){
    return _Idproveedor;
}

const char* Proveedores::getMarca(){
    return _Marca;
}

const char* Proveedores::getEstado(){
    if(_Estado){
        return "PROVEEDOR ACTIVO";
    }
    else {
        return "NO TRABAJA MAS CON NOSOTROS";
    }
}

const char* Proveedores::getContacto(){
    return _Contacto;
}

const char* Proveedores::getDireccionSucursal(){
  return _Direccion;
}

void Proveedores::cargar(){
    ArchivoProveedores prov;
    cout<< "INGRESAR EL ID DEL PROVEEDOR: ";
    while(true){
        cin>>_Idproveedor;
        if(cin.fail() || _Idproveedor<=0){
        cout<< "INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cout<< "INGRESAR EL ID DEL PROVEEDOR: ";
        cin.clear();
        cin.ignore();
    }
    else if(prov.buscar(_Idproveedor)!=-1){
        cout<< "El ID de proveedor que intentas ingresar ya se encuentra registrado en sistema. Intenta nuevamente"<<endl;
        cout<< "Ingresar el ID del Proveedor: ";
    }
    else{
        break;
    }
    }
    cout<< "INGRESAR LA MARCA: ";
    cin.ignore();
    cin.getline(_Marca, 50);
    /*cout<< "INGRESAR EL ESTADO(0-INACTIVO, 1-ACTIVO): ";
    cin>>_Estado;*/
    cout<< "INGRESAR EL MEDIO DE CONTACTO: ";
    cin.ignore();
    cin.getline(_Contacto, 50);
    cout<< "INGRESAR LA DIRECCION DEL LOCAL/SUCURSAL: ";
    cin.getline(_Direccion, 100);

    setEstado(1);
}

void Proveedores::mostrar(){
    cout<< "ID DEL PROVEEDOR: "<<getIdproveedor()<<endl;
    cout<< "MARCA: "<<getMarca()<<endl;
    cout<< "ESTADO DEL PROVEEDOR: "<<getEstado()<<endl;
    cout<< "MEDIO DE CONTACTO: "<<getContacto()<<endl;
    cout<< "DIRECCION DEL LOCAL/SUCURSAL: "<<getDireccionSucursal()<<endl;

}

bool Proveedores::escribirDisco(int pos){}

bool Proveedores::leerDisco(int pos){}
