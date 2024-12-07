#include "Cliente.h"
#include "ArchivoCliente.h"
#include <iostream>
#include <cstring>
using namespace std;

Cliente::Cliente(int puntaje):Persona(_Id, _Apellidos, _Nombres, _Nacimiento, _Telefono, _Mail, _Domicilio){
    _Puntaje=puntaje;
}

Cliente::Cliente():Persona(1, "Apellido", "Nombre", _Nacimiento, "123456789", "sistema@gestion.com.ar", "Florida 1234"), _Puntaje(0){
}

void Cliente::setPuntaje(int Puntaje){
    if(_Puntaje>0){
        _Puntaje=Puntaje;
    }
}

int Cliente::getPuntaje(){
    return _Puntaje;
}

void Cliente::agregarPuntos(int puntos) {
        _Puntaje += puntos;
        cout << "Puntos agregados"<<endl;
}

/*void Cliente::agregarPuntos(){
    _Puntaje+=puntos;
    cout<< "Puntos agregados. Puntaje actual: "<<_Puntaje<<endl;
}*/

bool Cliente::PuntajeMeta()
{
    ArchivoCliente archCliente;
    if(_Puntaje>0)
    {
        if(_Puntaje >=100)
        {
            int intentos = 0;
            int resto;
            while(intentos!=3)
            {
                cout << "¿EL CLIENTE DESEA CANJEAR SUS PUNTOS? " << endl;
                cout << " 1- Si / 2- No " << endl;
                int respuesta;
                cin >> respuesta;

                switch(respuesta)
                {
                case 0:
                cout << "Genial sus puntos quedan guardados para ser utulizados en una proxima ocasion " << endl;
                return false;
                case 1:
                    resto = _Puntaje - 100;
                    _Puntaje = resto;
                    intentos = 3;
                    cout << "¡Sus puntos han sido canjeados! " << endl;
                    cout <<"Cantidad de puntos que quedan disponibles: " << getPuntaje() << endl;
                    archCliente.ActualizacionPuntajeResta(*this);
                    return true;
                default:
                    intentos++;
                    if(intentos == 3)
                    {
                        cout << "Llego al limite de intentos vuelva a intentarlo mas tarde " << endl;
                    }else{
                        cout << "Parece ser que los datos ingresado son incorrectos :( , vuelva a intentarlo " << endl;
                    }
                    /*break;*/
                }
                system("pause");
                system("cls");
            }
        }

    }
    return false;
}

void Cliente::cargar()
{
    /*cout<< "------------ "<<"DATOS DEL CLIENTE"<< " --------------"<<endl;*/
    Persona::cargar();
}

void Cliente::mostrar()
{
    cout<< "------------ "<<"DATOS DEL CLIENTE"<< " --------------"<<endl;
    Persona::mostrar();
    cout<< "EL CLIENTE "<<" "<<Persona::getId()<<" "<<"TIENE UN PUNTAJE DE: "<<getPuntaje()<<endl;
}

bool Cliente::escribirDisco(int pos) {}

bool Cliente::leerDisco(int pos) {}
