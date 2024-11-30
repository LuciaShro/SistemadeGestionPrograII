#include <iostream>
#include "ArchivoVenta.h"
#include "ArchivoDetalleDeVenta.h"
#include "ArchivoVendedor.h"
#include <cstring>
#include "venta.h"

using namespace std;

int contVenta = 0;

ArchivoVenta::ArchivoVenta(){
    strcpy(_nombreArchivoVenta, "Venta.dat");
}

bool ArchivoVenta::GuardarRegistro(const Venta &venta){
    FILE *pVenta;
    bool resultado;

    pVenta = fopen(_nombreArchivoVenta,"ab");

    if(pVenta == nullptr){
        cout << "EL ARCHIVO NO PUDO SER ABIERTO CORRECTAMENTE " << endl; //titulo de prueba, luego eliminarlo
        return false;
    }

    resultado = fwrite(&venta, sizeof(venta),1,pVenta) == 1; //Compara lo que te devuelve fwrite con 1;

    fclose(pVenta);

    return resultado;
}

///MODIFICADO
void ArchivoVenta::FunGuardarRegistro(){
    bool cargar = 1, respuesta;

    while(cargar == 1){
        cout << "REGISTRE LOS DATOS DE UNA NUEVA VENTA " << endl;
        ArchivoDetalleDeVenta archDetalle;
        ArchivoVenta archivoV;
        Venta venta;

        int Nventa = archivoV.ContarVenta();
        venta.setIDVenta(Nventa);
        venta.cargar();

        if(archivoV.GuardarRegistro(venta)){
            cout << "VENTA CARGADA CON EXITO" << endl;
            archDetalle.FunGuardarRegistro(Nventa); //como parametro se envie el id de la venta


            ArchivoVendedor ArchVendedor;
            ArchVendedor.SetComision(Nventa, venta.getIDVendedor());///LLAMO A ARCH.VENDEDOR PARA HACER EL SET DE LA COMISION*/

        }else{
            cout << "NO SE PUDO CARGAR LA VENTA" << endl;
        }

        cout << "---------------------------------------------" << endl;
        cout << "DESEA REGISTRAR UNA NUEVA VENTA? 1-Si, 0-No " << endl;
        cin >> respuesta;
        if(!respuesta){
            cargar = 0;
        }

    }


}

/*void ArchivoVenta::leerRegistros(){
    Venta venta;

    FILE *pVenta;

    pVenta = fopen("venta.dat","rb");

    while(fread(&venta, sizeof(venta),1,pVenta) ==1){
        venta.mostrar();
    }

    fclose(pVenta);

}*/

Venta ArchivoVenta::leerRegistro(int IdVenta){
    FILE *pVenta;
    Venta venta;

    pVenta = fopen(_nombreArchivoVenta, "rb");

    if(pVenta == nullptr){
        return venta;
    }

    //Mueve el cursor                    //A partir de donde te queres mover
    fseek(pVenta,sizeof(venta)*IdVenta, SEEK_SET);

    fread(&venta, sizeof(venta), 1, pVenta);

    fclose(pVenta);
}



int ArchivoVenta::getCantidadRegistros(){
    int total, cantidad;
    FILE *pVenta;
    Venta venta;

    pVenta = fopen(_nombreArchivoVenta, "rb");

    if(pVenta == nullptr){
        return 0;
    }

    fseek(pVenta,0,SEEK_END);
    total = ftell(pVenta); //FTELL te devuelve la cantidad de bites

    cantidad = total / sizeof(venta);

    fclose(pVenta);

    return cantidad;

}

void ArchivoVenta::listarRegistros(){
    Venta venta;
    ArchivoVenta ArchVenta;

    for(int i=0; i<ArchVenta.getCantidadRegistros(); i++){

       ArchVenta.mostrarVenta(ArchVenta.leerRegistro(i));

       cout << "--------------------------------------------" << endl;
    }

}

void ArchivoVenta::mostrarVenta(Venta venta){
    cout<< "ID DE VENTA: "<< venta.getIDVenta() <<endl;
    cout<< "FECHA DE LA VENTA: "<<venta.getFecha()<<endl;
    cout<< "ID DEL CLIENTE: "<< venta.getCliente()<<endl;
    cout<< "ID DEL VENDEDOR: "<<venta.getIDVendedor() <<endl;
    cout<< "FORMA DE PAGO: "<<venta.getFormaDePago()<<endl;
}


bool ArchivoVenta::modificarRegistro(int pos, const Venta &venta){
        FILE *pVenta;
        bool resultado;

        pVenta = fopen(_nombreArchivoVenta,"rb+");

        if(pVenta == nullptr){
            cout << "EL ARCHIVO NO PUDO SER ABIERTO CORRECTAMENTE " << endl; //titulo de prueba, luego eliminarlo
            return false;
        }

        fseek(pVenta,sizeof(venta)*pos, SEEK_SET);

        resultado = fwrite(&venta, sizeof(venta),1,pVenta) == 1; //Compara lo que te devuelve fwrite con 1;

        fclose(pVenta);

        return resultado;

}

void ArchivoVenta::FunModificarRegistro(){
    Venta venta;
    ArchivoVenta archVenta;

    cout << "INGRES EL ID DE VENTA QUE DESEA MODIFICAR " << endl;
    int id;
    cin >> id;

    int pos =archVenta.buscar(id);

    if(pos!= -1){
        venta = archVenta.leerRegistro(pos);

        cout << "MODIFICAR " << endl;


        venta.cargar();

        modificarRegistro(pos,venta);
    }else{
        cout << "LA VENTA NO SE HA SIDO ENCONTRADA EN EL SISTEMA" << endl;
    }
}

int ArchivoVenta::buscar(int id){
    FILE *pVenta;

    Venta venta;
    int pos = 0;

    pVenta = fopen(_nombreArchivoVenta, "rb");

    if(pVenta == nullptr){
        return false;
    }

    while(fread(&venta, sizeof(venta), 1, pVenta) == 1){
        if(venta.getIDVenta() == id){
            break;
        }
        pos++;
    }

    fclose(pVenta);

    if(venta.getIDVenta() == id){
            return pos;
    }else{
        return -1;
    }
}

///AGREGADO
int ArchivoVenta::ContarVenta(){
    ArchivoVenta archVenta;
    bool band = 1;

    int cantidad = archVenta.getCantidadRegistros();

    if(cantidad == 0){
            contVenta++;
    }else{
        band = 0;
        if(band == 0 ){
            contVenta = cantidad+1;
        }else{
            contVenta++;
        }
    }
    return contVenta;
}

///AGREGADO
void ArchivoVenta::BuscarVenta(int id){
    ArchivoVenta archVenta;

    int pos = archVenta.buscar(id);
    archVenta.mostrarVenta(archVenta.leerRegistro(pos));

}
