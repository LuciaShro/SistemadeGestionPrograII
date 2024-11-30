#include <iostream>
#include <cstring>
#include "ArchivoDetalleDeVenta.h"
#include "ArchivoProductos.h"
#include "productos.h"
using namespace std;

ArchivoDetalleDeVenta::ArchivoDetalleDeVenta(){
     strcpy(_NombreArchivoDetalle, "DetalleVenta.dat");
}

bool ArchivoDetalleDeVenta::GuardarRegistro(const detalleVenta &detalle){
    FILE *pDetalle;
    bool resultado;

    pDetalle = fopen(_NombreArchivoDetalle, "ab");

    if(pDetalle == nullptr){
        cout << "EL ARCHIVO NO PUDO SER ABIERTO CORRECTAMENTE " << endl; //titulo de prueba, luego eliminarlo
        return false;
    }

    resultado = fwrite(&detalle, sizeof(detalle), 1, pDetalle);

    fclose(pDetalle);

    return resultado;
}

void ArchivoDetalleDeVenta::FunGuardarRegistro(int idVenta){
    bool respuesta =1;
    ArchivoProductos archivoProductos("archivoProductos.dat");
    while(respuesta!=0){
        cout << "DETALLE DE LA VENTA" << endl;
    ArchivoDetalleDeVenta ArchivoDetalle;
    detalleVenta detalle;
    Producto obj;
    Producto &producto = obj;


    detalle.setIDVenta(idVenta);

    ///solicitar el id
    ///buscarlo en archivos productos
    ///lo que te devuelve cargarlo en producto

    producto = BuscarProducto(producto); ///BUSCAR PRODUCTO (LA FUNCION ESTA DEBAJO)

    // probando que se reste el stock
    cout<< "Stock antes de la compra: "<<producto.getStock()<<endl;

    detalle.cargar(producto); //Aca mande lo que se cargo automaticamente en producto
    archivoProductos.actualizarProducto(producto);

    if(ArchivoDetalle.GuardarRegistro(detalle)){
            cout << "DETALLE CARGADO CON EXITO" << endl;
        }else{
            cout << "NO SE PUDO CARGAR EL DETALLE" << endl;
        }
        cout << "---------------------------------------------" << endl;
        cout << "¿DESEA AGREGAR OTRO PRODUCTO A LA COMPRA? 1-Si, 0-No " << endl;
        cin >> respuesta;
        if(!respuesta){
            respuesta = 0;
        }

    }
}

///AGREGUE EL BUSCAR PRODUCTO (EN EL .H TAMBIEN) // MODIFICACION POR LU PAZ PARA LA VALIDACIÓN DEL BUSCAR PRODUCTO
Producto ArchivoDetalleDeVenta::BuscarProducto(Producto &producto){
    ArchivoProductos archivo("archivoProductos.dat");
    int id;
    while (id!=producto.getIDProducto()){
        cout << "Ingrese el id del Producto: ";
        cin >> id;
        for(int i=0;i<archivo.getCantidadRegistros(); i++){
            producto = archivo.leerRegistro(i);
            if(id == producto.getIDProducto()){
                return producto;
            }
        }
    cout<< "Producto no entrado. Intente nuevamente"<<endl;
    }
    return Producto(); // puse como RETURN PRODUCTO ya que sino agrega una advertencia en el log
}

detalleVenta ArchivoDetalleDeVenta::leerRegistro(int IdVenta){
    FILE *pDetalle;
    detalleVenta detalle;

    pDetalle = fopen(_NombreArchivoDetalle, "rb");

    if(pDetalle == nullptr){
        return detalle;
    }

    fseek(pDetalle,sizeof(detalle)*IdVenta, SEEK_SET);
    fread(&detalle, sizeof(detalle), 1, pDetalle);

    fclose(pDetalle);
    return detalle; // lo agrego para que no figure la advertencia de que no retorna nada en el log
}

int ArchivoDetalleDeVenta::getCantidadRegistros(){
    int total, cantidad;
    FILE *pDetalle;
    detalleVenta detalle;

    pDetalle = fopen(_NombreArchivoDetalle, "rb");
    if(pDetalle == nullptr){
        return 0;
    }

    fseek(pDetalle, 0, SEEK_END);
    total = ftell(pDetalle);
    cantidad = total/sizeof(detalle);

    fclose(pDetalle);

    return cantidad;
}

void ArchivoDetalleDeVenta::mostrarDetalle(detalleVenta detalle){
    detalle.mostrar();
}

void ArchivoDetalleDeVenta::listarRegistros(){
    detalleVenta detalle;
    ArchivoDetalleDeVenta archDetalle;

    for(int i=0; i<archDetalle.getCantidadRegistros();i++){
        archDetalle.mostrarDetalle(archDetalle.leerRegistro(i));

        cout << "--------------------------------------------" << endl;
    }
}


bool ArchivoDetalleDeVenta::modificarRegistro(int pos, const detalleVenta &detalle){
    FILE *pDetalle;
    bool resultado;

    pDetalle = fopen(_NombreArchivoDetalle, "rb+");


    if(pDetalle == nullptr){
        cout << "EL ARCHIVO NO PUDO SER ABIERTO CORRECTAMENTE " << endl; //titulo de prueba, luego eliminarlo
        return false;
    }

    fseek(pDetalle,sizeof(detalle)*pos,SEEK_SET);

    resultado = fwrite(&detalle,sizeof(detalle),1,pDetalle) == 1;

    fclose(pDetalle);

    return resultado;
}

int ArchivoDetalleDeVenta::buscar(int id){
    FILE *pDetalle;
    detalleVenta detalle;
    int pos = 0;

    pDetalle = fopen(_NombreArchivoDetalle, "rb");

    if(pDetalle == nullptr){
        return false;
    }

    while(fread(&detalle,sizeof(detalle), 1, pDetalle)== 1){
        if(detalle.getIDVenta() == id){
            break;
        }
        pos++;
    }

    fclose(pDetalle);

    if(detalle.getIDVenta() == id){
        return pos;
    }else{
        return -1;
    }
}

void ArchivoDetalleDeVenta::FunModificarRegistro(){
    detalleVenta detalle;
    ArchivoDetalleDeVenta ArchDetalle;
    Producto producto;

    int id, pos;

    cout << "INGRESE EL ID DE VENTA QUE DESEA BUSCAR EN EL DETALLE" << endl;
    cin>> id;

    pos = ArchDetalle.buscar(id);

    if(pos!= -1){
        detalle = ArchDetalle.leerRegistro(pos);
        cout << " INGRESE LA MODIFICACION " << endl;
        producto.cargar();

        detalle.cargar(producto);

        modificarRegistro(pos, detalle);
    }else{
        cout << "LA VENTA NO SE HA SIDO ENCONTRADA EN EL SISTEMA" << endl;
    }
}

void ArchivoDetalleDeVenta::BuscarDetalle(int id){
    ArchivoDetalleDeVenta archDetalle;

    int pos = archDetalle.buscar(id);
    archDetalle.mostrarDetalle(archDetalle.leerRegistro(pos));
}
