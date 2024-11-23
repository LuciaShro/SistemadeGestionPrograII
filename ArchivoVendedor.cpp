#include "ArchivoVendedor.h"
#include "ArchivoVenta.h"
#include "ArchivoDetalleDeVenta.h"
#include <cstring>
#include <iostream>
using namespace std;

ArchivoVendedor::ArchivoVendedor(){
    strcpy(_nombreArchivoVendedor, "Vendedor.dat");
}

bool ArchivoVendedor::GuardarRegistro(const Vendedor &vendedor){
    FILE *pVendedor;
    bool resultado;

    pVendedor = fopen(_nombreArchivoVendedor, "ab");

    if(pVendedor == nullptr){
        cout << "EL ARCHIVO NO PUDO SER ABIERTO CORRECTAMENTE " << endl; //titulo de prueba, luego eliminarlo
        return false;
    }

    resultado = fwrite(&vendedor,sizeof(Vendedor), 1, pVendedor) == 1;

    if(!resultado){
        cout<< "Error. No se pudo escribir en el archivo"<<endl;
    }

    fclose(pVendedor);

    return resultado;
}

void ArchivoVendedor::FunGuardarRegistro(){
    cout << "INGRESE LA INFORMACION DEL VENDEDOR " << endl;
    ArchivoVendedor  ArchVendedor;

    Vendedor vendedor;
    /*Producto producto;
    Venta venta;
    detalleVenta detalle;

    producto.cargar();
    venta.cargar();
    detalle.cargar(producto);*/  // Lo comento (lu paz) para ver la manera de que no se tenga que cargar estos datos

    vendedor.cargar();

    bool result = ArchVendedor.VerificarRegistroExistente(vendedor.getId());

    if(result){
        cout << "EL USUARIO YA SE ENCUENTRA REGISTRADO EN EL SISTEMA " << endl;
    }else{
        if(GuardarRegistro(vendedor)){
            cout << "VENDEDOR CARGADO CON EXITO" << endl;
        }else{
            cout << "NO SE PUDO CARGAR EL VENDEDOR" << endl;
        }
    }
}

Vendedor ArchivoVendedor::leerRegistro(int IdVendedor){
    FILE *pVendedor;
    Vendedor vendedor;

    pVendedor = fopen(_nombreArchivoVendedor, "rb");

    if(pVendedor == nullptr){
        return vendedor;
    }

    fseek(pVendedor,sizeof(vendedor)*IdVendedor, SEEK_SET);
    fread(&vendedor,sizeof(vendedor), 1, pVendedor);

    fclose(pVendedor);
}

int ArchivoVendedor::getCantidadRegistros(){
    FILE *pVendedor;
    int total, cantidad;
    Vendedor vendedor;

    pVendedor = fopen(_nombreArchivoVendedor, "rb");

    if(pVendedor == nullptr){
        return 0;
    }

    fseek(pVendedor,0, SEEK_END);
    total = ftell(pVendedor);
    cantidad = total / sizeof(vendedor);

    fclose(pVendedor);

    return cantidad;
}

void ArchivoVendedor::mostrarVendedor(Vendedor vendedor){
    vendedor.mostrar();
}

void ArchivoVendedor::listarRegistros(){
    //FILE *pVendedor;
    ArchivoVendedor archVendedor;
    Vendedor vendedor;

    for(int i=0; i<archVendedor.getCantidadRegistros(); i++){
        archVendedor.mostrarVendedor(archVendedor.leerRegistro(i));
    }

    cout << "--------------------------------------------" << endl;
}

bool ArchivoVendedor::modificarRegistro(int pos, const Vendedor &vendedor){
    FILE *pVendedor;

    pVendedor = fopen(_nombreArchivoVendedor, "rb+");

    if(pVendedor == nullptr){
        return false;
    }

    fseek(pVendedor,sizeof(vendedor)*pos, SEEK_SET);
    bool resultado = fwrite(&vendedor,sizeof(vendedor),1,pVendedor) == 1;

    fclose(pVendedor);

    return resultado;
}

int ArchivoVendedor::buscar(int id){
    FILE *pVendedor;
    Vendedor vendedor;
    int pos = 0;

    pVendedor = fopen(_nombreArchivoVendedor,"rb");

    if(pVendedor == nullptr){
        return -1;
    }

    while(fread(&vendedor,sizeof(vendedor),1,pVendedor) == 1){
        if(vendedor.getId() == id){
            fclose(pVendedor);
            return pos; // modifico que una vez que se encuentra el ID se cierre el archivo (lu paz)
        }
        pos++;
    }

    fclose(pVendedor); // cierre del archivo y retorna -1 en caso de no encontrar el ID
    return -1;

}

void ArchivoVendedor::FunModificarRegistro(){
    int id, pos;
    ArchivoVendedor archVendedor;
    Vendedor vendedor;
    /*Producto producto;
    Venta venta;
    detalleVenta detalle;

    producto.cargar();
    venta.cargar();
    detalle.cargar(producto);*/ // Lu Paz lo comenta para realizarlo de otra manera y que no se tengan que cargar todos los datos

    cout << "INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR" << endl;
    cin >> id;

    pos = archVendedor.buscar(id);

    if(pos!= -1){
        vendedor = archVendedor.leerRegistro(pos);
        cout << " INGRESE LA MODIFICACION " << endl;
        vendedor.cargar();
        modificarRegistro(pos, vendedor);
    }else{
        cout << "EL VENDEDOR NO HA SIDO ENCONTRADA EN EL SISTEMA" << endl;
    }
}

bool ArchivoVendedor::BajaDeRegistro(){
    Vendedor vendedor;
    ArchivoVendedor archvendedor;
    int id, pos;

    cout <<"INGRESE EL ID DEL CLIENTE QUE DESEA ELIMINAR: " << endl;
    cin >> id;

    pos = archvendedor.buscar(id);

    if(pos == -1){
        cout << "EL CLIENTE NO HA SIDO ENCONTRADO EN EL SISTEMA" << endl;
        return false;
    }

     vendedor = archvendedor.leerRegistro(pos);
     vendedor.setEstado(false);
     return archvendedor.modificarRegistro(pos, vendedor);
}


bool ArchivoVendedor::VerificarRegistroExistente(int id){
    ArchivoVendedor archVendedor;

    /*cout << "INGRESE EL ID DEL REGISTRO QUE DESEA CONSULTAR " << endl;
    cin >> id;*/ // Lo comento para que no me salte esto cuando estoy cargando los datos (lu paz)

    int pos = buscar(id); // lo cambie
    if(pos == -1){
        return false;
    }else{
        return true;
    }

}

///AGREGADO
void ArchivoVendedor::BuscarVendedor(int id){
    ArchivoVendedor archVendedor;

    int pos = archVendedor.buscar(id);
    archVendedor.mostrarVendedor(archVendedor.leerRegistro(pos));
}
