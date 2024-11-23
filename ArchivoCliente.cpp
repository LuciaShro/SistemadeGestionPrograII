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

    resultado = fwrite(&cliente, sizeof(cliente), 1, pCliente)== 1;

    if(!resultado){
        cout<< "Error. No se pudo escribir en el archivo"<<endl;
    } // agrego esto para verificar que se haya escribido en el archivo

    fclose(pCliente);

    return resultado;
}

///MODIFICADO
void ArchivoCliente::FunGuardarRegistro(){
    cout << "INFORMACION DEL CLIENTE " << endl;
    ArchivoCliente  ArchCliente;
    Cliente cliente;
    int dni;

    while(true){
        cout <<"INGRESE EL DNI: ";
        cin>>dni;
        if(cin.fail() || dni<0){
        cout<< "DNI INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cin.clear();
        cin.ignore();
    }
    else{
        break;
    }
    }

    bool result = ArchCliente.VerificarRegistroExistente(dni);


    if(result){
        cout<< "EL USUARIO YA SE ENCUENTRA REGISTRADO EN EL SISTEMA"<<endl;
        return;
    }

     cliente.setId(dni);
     cliente.cargar();

     if(GuardarRegistro(cliente)){
        cout<< "CLIENTE CARGADO CON EXITO"<<endl;
     }
     else {
        cout<< "ERROR AL CARGAR EL CLIENTE"<<endl;
     }

    /*if(result){
        cout << "EL USUARIO YA SE ENCUENTRA REGISTRADO EN EL SISTEMA, POR LO QUE NO SE PUEDE VOLVER A INGRESAR " << endl;
    }else{
        if(GuardarRegistro(cliente)){
            cout << "CLIENTE CARGADO CON EXITO" << endl;
        }else{
            cout << "NO SE PUDO CARGAR EL CLIENTE" << endl;
        }
    }*/
}

Cliente ArchivoCliente::leerRegistro(int IdCliente){
    FILE *pCliente;
    Cliente cliente;

    /*ArchivoCliente archCliente;*/ // lo saco porque en ningun momento lo utilizamos

    pCliente = fopen(_nombreArchivoCliente, "rb");

    if(pCliente == nullptr){
        return cliente;
    }

    fseek(pCliente,sizeof(cliente)*IdCliente, SEEK_SET);
    fread(&cliente, sizeof(cliente), 1, pCliente);

    fclose(pCliente);
    return cliente;
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
    /*FILE *pCliente;*/ // lo comento porque en ningun momento se utiliza
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
        return -1;
    }

    while(fread(&cliente,sizeof(cliente), 1, pCliente)== 1){
        if(cliente.getId() == id){
            fclose(pCliente); // una vez que encuentra el registro, se cierra el archivo
            return pos;
        }
        pos++;
    }

    fclose(pCliente);
    return -1;
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

    int pos = buscar(id);

    if(pos == -1){
        return false;
    }else{
        return true;
    }
}
///AGREGADO
/*void ArchivoCliente::BuscarCliente(int id){
    ArchivoCliente archCliente;

    int pos = archCliente.buscar(id);
    archCliente.mostrarCliente(archCliente.leerRegistro(pos));
}*/

// MODIFICACION DE BUSCAR CLIENTE PARA QUE NO TENGA QUE PASAR POR PARAMETRO NINGUN ID

bool ArchivoCliente::BuscarCliente(){
    FILE *buscarCliente;
    Cliente cliente;

    buscarCliente=fopen(_nombreArchivoCliente, "rb");
    if(buscarCliente==nullptr){
        cout<< "ERROR AL ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    int id;
    cout<< "INGRESAR EL DNI DEL CLIENTE A BUSCAR: ";
    cin>>id;
    while(fread(&cliente, sizeof(Cliente), 1, buscarCliente)==1){
        if(cliente.getId()==id){
            cliente.mostrar();
            fclose(buscarCliente);
            return true;
        }
    }
    cout<< "CLIENTE NO ENCONTRADO"<<endl;
    fclose(buscarCliente);
    return false;
}
