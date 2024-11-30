#include "persona.h"
#include <cstring>
#include <iostream>
using namespace std;

Persona::Persona(){
    _Id=0;
    strcpy(_Apellidos, "Apellidos");
    strcpy(_Nombres, "Nombres");
    strcpy (_Telefono, "123456789");
    strcpy(_Mail, "sistema@gestion.com.ar");
    strcpy(_Domicilio, "Vicente Lopez 1234");
}

Persona::Persona(int id, const char* apellidos, const char* nombres, Fecha nacimiento, const char* telefono, const char* mail, const char* domicilio){
    _Id=id;
    strcpy(_Apellidos, apellidos);
    strcpy(_Nombres, nombres);
    _Nacimiento=nacimiento;
    strcpy (_Telefono, telefono);
    strcpy(_Mail, mail);
    strcpy(_Domicilio, domicilio);
}

void Persona::setId(int id){
    if(id > 0){
        _Id = id;
    }

}

void Persona::setApellidos(const char* apellidos){
    strcpy(_Apellidos, apellidos);
}

void Persona::setNombres(const char* nombres){
    strcpy(_Nombres, nombres);
}

void Persona::setEstado(bool estado){
    _Estado = estado;
}

void Persona::setTelefono(const char* telefono){
    while(ValidacionTelefono(telefono)==false){
        cout<< "TELEFONO INVALIDO"<<endl;
        cout<< "INGRESAR NUEVAMENTE EL TELEFONO: ";
        cin>>_Telefono;
    }
    if(ValidacionTelefono(telefono)){
        strcpy(_Telefono, telefono);
    }
}

void Persona::setMail(const char* mail){
    strcpy(_Mail, mail);
}

void Persona::setDomicilio(const char* domicilio){
    strcpy(_Domicilio, domicilio);
}

void Persona::setNacimiento(int dia, int mes, int anio){
    _Nacimiento.setDia(dia);
    _Nacimiento.setMes(mes);
    _Nacimiento.setAnio(anio);
}

int Persona::getId(){
    return _Id;
}

const char* Persona::getApellidos(){
    return _Apellidos;
}

const char* Persona::getNombres(){
    return _Nombres;
}

string Persona::getNacimiento(){
    return _Nacimiento.toString();
}

const char* Persona::getEstado(){
    if(_Estado){
        return "ACTIVO";
    }
    else {
        return "INACTIVO";
    }
}

const char* Persona::getTelefono(){
    return _Telefono;
}

const char* Persona::getMail(){
    return _Mail;
}

const char* Persona::getDomicilio(){
    return _Domicilio;
}

bool Persona::ValidacionTelefono(const char* telefono){
    int i, cont =0;
    int numeros=strlen(telefono);
    if(numeros==8 || numeros==10){
        for (i=0; i<numeros; i++){
            if (isdigit(telefono[i])){
                cont++;
            }
        }
      return true;
    }else{return false;}
}

///AGREGADO RECIENTEMENTE
void Persona::CargarClienteSinRegistro(){
    cout << "DNI: ";
    while(true){
        cin>>_Id;
        if(cin.fail() || _Id<0){
        cout<< "INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cout<< "INGRESAR EL DNI: ";
        cin.clear();
        cin.ignore();
    }
    else{
        break;
    }
    }
    cin.ignore();
    /*cin>>_Id;*/
    cout<< "NOMBRE: ";
    cin.getline(_Nombres, 100);

    cout<< "APELLIDO: ";
    cin.getline(_Apellidos, 100);

    setNacimiento(1, 1, 2024);

    setEstado(0);
}

void Persona::cargar(){
    int dia, mes, anio;
    char separador;

    cout<< "DNI: ";
    while(true){
        cin>>_Id;
        if(cin.fail() || _Id<0){
        cout<< "INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cout<< "INGRESAR EL DNI: ";
        cin.clear();
        cin.ignore();
    }
    else{
        cin.ignore();
        break;
    }
    }

    /*cin>>_Id;
    cin.ignore();*/
    cout<< "NOMBRE: ";
    cin.getline(_Nombres, 100);

    cout<< "APELLIDO: ";
    cin.getline(_Apellidos, 100);

    cout<< "NACIMIENTO: ";
    cin>> dia >> separador >> mes >> separador >> anio;
    setNacimiento(dia, mes, anio);

    cout<< "TELEFONO: ";
    cin.ignore();
    /*cin>>_Telefono;*/
    cin.getline(_Telefono, 11);
    setTelefono(_Telefono);

    cout<< "MAIL: ";
    /*cin>>_Mail;*/
    cin.getline(_Mail, 100);

    /*cout<< "(0-INACTIVO, 1-ACTIVO): ";
    cin>>_Estado;*/
    setEstado(1);
}

void Persona::mostrar(){
    cout<< "EL DNI ES: "<<getId()<<endl;
    cout<< "EL NOMBRE ES: "<<getNombres()<<endl;
    cout<< "EL APELLIDO ES: "<<getApellidos()<<endl;
    cout<< "EL NACIMIENTO ES: "<<getNacimiento()<<endl;
    cout<< "EL TELEFONO ES: "<<getTelefono()<<endl;
    cout<< "EL MAIL ES: "<<getMail()<<endl;
    cout<< "EL ESTADO DE LA PERSONA ES: "<<getEstado()<<endl;
}

bool Persona::escribirDisco(int pos){}

bool Persona::leerDisco(int pos){}
