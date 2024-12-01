#include <iostream>
#include <cstring>
#include "ArchivoProveedores.h"
using namespace std;

ArchivoProveedores::ArchivoProveedores(){
     strcpy(_nombreProveedores, "Proveedores.dat");
}

bool ArchivoProveedores::GuardarRegistro(const Proveedores &proveedor){
    FILE *pProveedores;
    bool resultado;

    pProveedores = fopen(_nombreProveedores, "ab");

    if(pProveedores == nullptr){
        cout << "EL ARCHIVO NO PUDO SER ABIERTO CORRECTAMENTE " << endl; //titulo de prueba, luego eliminarlo
        return false;
    }

    resultado = fwrite(&proveedor, sizeof(proveedor), 1, pProveedores);

    fclose(pProveedores);

    return resultado;
}

///MODIFICADO
void ArchivoProveedores::FunGuardarRegistro(){
    cout << "INGRESE LA INFORMACIÓN DEL PROVEEDOR " << endl;
    /*FILE *ArchProveedor;*/
    Proveedores proveedor;
    ArchivoProveedores archivoPro;

    /*ArchProveedor=fopen(_nombreProveedores, "ab");
    if(ArchProveedor==nullptr){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }*/
    proveedor.cargar();

    int id = proveedor.getIdproveedor();

    bool result = archivoPro.VerificarRegistroExistente(id);

    if(result){
        cout << "EL USUARIO YA SE ENCUENTRA REGISTRADO EN EL SISTEMA, POR LO QUE NO SE PUEDE VOLVER A INGRESAR " << endl;
    }else{
        if(GuardarRegistro(proveedor)){
            cout << "PROVEEDOR CARGADO CON EXITO" << endl;
        }else{
            cout << "NO SE PUDO CARGAR EL PROVEEDOR" << endl;
        }
    }
    /*fclose(ArchProveedor);*/
}

Proveedores ArchivoProveedores::leerRegistro(int IdProveedor){
    FILE *pProveedores;
    Proveedores proveedor;

    pProveedores = fopen(_nombreProveedores, "rb");

    if(pProveedores == nullptr){
        return proveedor;
    }

    fseek(pProveedores,sizeof(proveedor)*IdProveedor, SEEK_SET);
    fread(&proveedor, sizeof(proveedor), 1, pProveedores);

    fclose(pProveedores);
    return proveedor; // lo agregue porque no retornaba nada
}

int ArchivoProveedores::getCantidadRegistros(){
    int total, cantidad;
    FILE *pProveedores;
    Proveedores proveedor;

    pProveedores = fopen(_nombreProveedores, "rb");
    if(pProveedores == nullptr){
        return 0;
    }

    fseek(pProveedores, 0, SEEK_END);
    total = ftell(pProveedores);
    cantidad = total/sizeof(proveedor);

    fclose(pProveedores);

    return cantidad;
}

void ArchivoProveedores::mostrarProveedor(Proveedores proveedor){
    proveedor.mostrar();
}

void ArchivoProveedores::listarRegistros(){
    FILE *pProvedores;
    Proveedores proveedor;
    ArchivoProveedores archProveedor;

    pProvedores=fopen(_nombreProveedores, "rb");
    if(pProvedores==nullptr){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    for(int i=0; i<archProveedor.getCantidadRegistros();i++){
        cout << "PROVEEDOR " << i+1 << endl;
        archProveedor.mostrarProveedor(archProveedor.leerRegistro(i));

        cout << "--------------------------------------------" << endl;
    }

    fclose(pProvedores);
}


bool ArchivoProveedores::modificarRegistro(int pos, const Proveedores &proveedor){
    FILE *pProveedores;
    bool resultado;

    pProveedores = fopen(_nombreProveedores, "rb+");


    if(pProveedores == nullptr){
        cout << "EL ARCHIVO NO PUDO SER ABIERTO CORRECTAMENTE " << endl; //titulo de prueba, luego eliminarlo
        return false;
    }

    fseek(pProveedores,sizeof(proveedor)*pos,SEEK_SET);

    resultado = fwrite(&proveedor,sizeof(proveedor),1,pProveedores) == 1;

    fclose(pProveedores);

    return resultado;
}

int ArchivoProveedores::buscar(int id){
    FILE *pProveedores;
    Proveedores proveedor;
    int pos = 0;

    pProveedores = fopen(_nombreProveedores, "rb");

    if(pProveedores == nullptr){
        return -1;
    }

    while(fread(&proveedor,sizeof(proveedor), 1, pProveedores)== 1){
        if(proveedor.getIdproveedor() == id){
            fclose(pProveedores);
            return pos; // En este caso, encontramos el ID
        }
        pos++;
    }
    fclose(pProveedores);
    return -1;  // EL ID NO FUE ENCONTRADO EN EL ARCHIVO
}

void ArchivoProveedores::FunModificarRegistro(){
    Proveedores proveedor;
    ArchivoProveedores ArchProveedor;

    int id, pos;

    cout << "INGRESE EL ID DEL CLIENTE QUE DESEA BUSCAR " << endl;
    cin>> id;

    pos = ArchProveedor.buscar(id);

    if(pos!= -1){
        proveedor = ArchProveedor.leerRegistro(pos);
        cout << " INGRESE LA MODIFICACION " << endl;
        proveedor.cargar();

        modificarRegistro(pos, proveedor);
    }else{
        cout << "EL CLIENTE NO HA SIDO ENCONTRADO EN EL SISTEMA" << endl;
    }
}

bool ArchivoProveedores::BajaDeRegistro(){
    Proveedores proveedor;
    ArchivoProveedores archProveedor;
    int id, pos;

    cout <<"INGRESE EL ID DEL CLIENTE QUE DESEA ELIMINAR: " << endl;
    cin >> id;

    pos = archProveedor.buscar(id);

    if(pos == -1){
        cout << "EL CLIENTE NO HA SIDO ENCONTRADO EN EL SISTEMA" << endl;
        return false;
    }

     proveedor = archProveedor.leerRegistro(pos);
     proveedor.setEstado(false);
     return archProveedor.modificarRegistro(pos, proveedor);
}

bool ArchivoProveedores::VerificarRegistroExistente(int id){
    ArchivoProveedores archProveedores;

    int pos = buscar(id);

    if(pos == -1){
        return false;
    }else{
        return true;
    }

}

///AGREGADO
void ArchivoProveedores::BuscarProveedor(int id){
    ArchivoProveedores archProveedor;

    int pos = archProveedor.buscar(id);
    archProveedor.mostrarProveedor(archProveedor.leerRegistro(pos));

}

void ArchivoProveedores::leerRegistros(int idproveedor, int pos, Proveedores &proveedor){
    FILE *ArchiProveedor;

    ArchiProveedor=fopen(_nombreProveedores, "rb");
    if (ArchiProveedor==nullptr){
        cout<< "ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }

    fseek(ArchiProveedor, pos*sizeof(Proveedores), SEEK_SET);

    if(fread(&proveedor, sizeof(Proveedores), 1, ArchiProveedor)==1){
        if(proveedor.getIdproveedor()==idproveedor){
            cout<< "Proveedor encontrado"<<endl;
            cout<< "Marca del proveedor: "<<proveedor.getMarca()<<endl;
        }
        else{
            cout<< "Proveedor no encontrado"<<endl;
        }
    }
    else{
        cout<< "No se pudo leer el archivo"<<endl;
    }

    fclose(ArchiProveedor);
}

