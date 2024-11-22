#include <iostream>
#include <cstring>
#include "ArchivoCliente.h"
using namespace std;

ArchivoCliente::ArchivoCliente(){
     strcpy(_nombreArchivoCliente, "Cliente.dat");
}

bool ArchivoCliente::GuardarRegistro(const Cliente &cliente){
    FILE *pCliente;
    bool resultado;

    pCliente = fopen(_nombreArchivoCliente, "ab");

    if(pCliente == nullptr){
        cout << "EL ARCHIVO NO PUDO SER ABIERTO CORRECTAMENTE " << endl; //titulo de prueba, luego eliminarlo
        return false;
    }

    resultado = fwrite(&cliente, sizeof(cliente), 1, pCliente);

    fclose(pCliente);

    return resultado;
}

///MODIFICADO
void ArchivoCliente::FunGuardarRegistro(){
    cout << "INFORMACION DEL CLIENTE " << endl;
    ArchivoCliente  ArchCliente;
    Cliente cliente;
    int dni;

    cout <<"INGRESE EL DNI " << endl;
    cin >> dni;
    cliente.setId(dni);

    bool result = ArchCliente.VerificarRegistroExistente(cliente.getId());

    if(result){
        cout << "EL USUARIO YA SE ENCUENTRA REGISTRADO EN EL SISTEMA, POR LO QUE NO SE PUEDE VOLVER A INGRESAR " << endl;
    }else{
        if(ArchCliente.GuardarRegistro(cliente)){
            cliente.cargar();
            cout << "CLIENTE CARGADO CON EXITO" << endl;
        }else{
            cout << "NO SE PUDO CARGAR EL CLIENTE" << endl;
        }
    }
}

Cliente ArchivoCliente::leerRegistro(int IdCliente){
    FILE *pCliente;
    Cliente cliente;

    ArchivoCliente archCliente;

    pCliente = fopen(_nombreArchivoCliente, "rb");

    if(pCliente == nullptr){
        return cliente;
    }

    fseek(pCliente,sizeof(cliente)*IdCliente, SEEK_SET);
    fread(&cliente, sizeof(cliente), 1, pCliente);

    fclose(pCliente);
}

int ArchivoCliente::getCantidadRegistros(){
    int total, cantidad;
    FILE *pCliente;
    Cliente cliente;

    pCliente = fopen(_nombreArchivoCliente, "rb");
    if(pCliente == nullptr){
        return 0;
    }

    fseek(pCliente, 0, SEEK_END);
    total = ftell(pCliente);
    cantidad = total/sizeof(cliente);

    fclose(pCliente);

    return cantidad;
}

void ArchivoCliente::mostrarCliente(Cliente cliente){
    cliente.mostrar();
}

void ArchivoCliente::listarRegistros(){
    FILE *pCliente;
    Cliente cliente;
    ArchivoCliente archCliente;

    for(int i=0; i<archCliente.getCantidadRegistros();i++){
        cout << "CLIENTE " << i+1 << endl;
        archCliente.mostrarCliente(archCliente.leerRegistro(i));

        cout << "--------------------------------------------" << endl;
    }
}


bool ArchivoCliente::modificarRegistro(int pos, const Cliente &cliente){
    FILE *pCliente;
    bool resultado;

    pCliente = fopen(_nombreArchivoCliente, "rb+");


    if(pCliente == nullptr){
        cout << "EL ARCHIVO NO PUDO SER ABIERTO CORRECTAMENTE " << endl; //titulo de prueba, luego eliminarlo
        return false;
    }

    fseek(pCliente,sizeof(cliente)*pos,SEEK_SET);

    resultado = fwrite(&cliente,sizeof(cliente),1,pCliente) == 1;

    fclose(pCliente);

    return resultado;
}

int ArchivoCliente::buscar(int id){
    FILE *pCliente;
    Cliente cliente;
    int pos = 0;

    pCliente = fopen(_nombreArchivoCliente, "rb");

    if(pCliente == nullptr){
        return false;
    }

    while(fread(&cliente,sizeof(cliente), 1, pCliente)== 1){
        if(cliente.getId() == id){
            break;
        }
        pos++;
    }

    fclose(pCliente);

    if(cliente.getId() == id){
        return pos;
    }else{
        return -1;
    }
}

void ArchivoCliente::FunModificarRegistro(){
    Cliente cliente;
    ArchivoCliente ArchCliente;

    int id, pos;

    cout << "INGRESE EL ID DEL CLIENTE QUE DESEA BUSCAR " << endl;
    cin>> id;

    pos = ArchCliente.buscar(id);

    if(pos!= -1){
        cliente = ArchCliente.leerRegistro(pos);
        cout << " INGRESE LA MODIFICACION " << endl;
        cliente.cargar();

        modificarRegistro(pos, cliente);
    }else{
        cout << "EL CLIENTE NO HA SIDO ENCONTRADO EN EL SISTEMA" << endl;
    }
}

bool ArchivoCliente::BajaDeRegistro(){
    Cliente cliente;
    ArchivoCliente archCliente;
    int id, pos;

    cout <<"INGRESE EL ID DEL CLIENTE QUE DESEA ELIMINAR: " << endl;
    cin >> id;

    pos = archCliente.buscar(id);

    if(pos == -1){
        cout << "EL CLIENTE NO HA SIDO ENCONTRADO EN EL SISTEMA" << endl;
        return false;
    }

     cliente = archCliente.leerRegistro(pos);
     cliente.setEstado(false);
     return archCliente.modificarRegistro(pos, cliente);
}

bool ArchivoCliente::VerificarRegistroExistente(int id){
    ArchivoCliente archCliente;

    int pos = archCliente.buscar(id);

    if(pos == -1){
        return false;
    }else{
        return true;
    }
}
///AGREGADO
void ArchivoCliente::BuscarCliente(int id){
    ArchivoCliente archCliente;

    int pos = archCliente.buscar(id);
    archCliente.mostrarCliente(archCliente.leerRegistro(pos));
}
