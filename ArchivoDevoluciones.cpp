#include "ArchivoDevoluciones.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ArchivoDevoluciones::ArchivoDevoluciones(const char *nombreArchivoDevoluciones){
    strcpy(_nombreArchivoDevoluciones, nombreArchivoDevoluciones);
}

bool ArchivoDevoluciones::guardarDevolucion(Devoluciones& devolucion){
    FILE *ArchivoDevolucion;
    ArchivoDevolucion=fopen(_nombreArchivoDevoluciones, "ab");
    if(ArchivoDevolucion==nullptr){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    int escribir=fwrite(&devolucion, sizeof(Devoluciones), 1, ArchivoDevolucion);
    fclose(ArchivoDevolucion);
    if (escribir==1){
            cout<< "�NUEVA DEVOLUCION AGREGADA!"<<endl;
            return true;
    }

    return false;
}

void ArchivoDevoluciones::agregarDevolucion(){
    Producto producto;
    int idproducto;

    cout<< "INGRESE EL ID DEL PRODUCTO A DEVOLVER: ";
    cin>>idproducto;
    ArchivoProductos archivoProductos("archivoProductos.dat");
    if (!archivoProductos.buscarPRODUCTOID(idproducto, producto)) {
        cout << "PRODUCTO NO ENCONTRADO" << endl;
        return;
    }
    cout<< "stock antes de la devolucion: "<<producto.getStock()<<endl;
    Devoluciones devolucion;
    devolucion.cargar(producto); // Cargar los detalles de la devoluci�n
    ActualizarStockArchivoProductos(producto);
    archivoProductos.actualizarProducto(producto);

    if (!guardarDevolucion(devolucion)) {
        cout << "ERROR AL GUARDAR DEVOLUCION" << endl;
    }
}

bool ArchivoDevoluciones::ActualizarStockArchivoProductos(Producto& producto){
    FILE *archivoProductos=fopen("archivoProductos.dat", "rb+");
    if(archivoProductos==nullptr){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    Producto ProductoEnArchivo;
    bool productoEncontrado=false;
    while (fread(&ProductoEnArchivo, sizeof(Producto), 1, archivoProductos)==1){
        if (ProductoEnArchivo.getIDProducto()==producto.getIDProducto()){
            fseek(archivoProductos, -sizeof(Producto), SEEK_CUR);
            fwrite(&ProductoEnArchivo, sizeof(Producto), 1, archivoProductos);
            productoEncontrado=true;
            break;
        }
    }
    fclose(archivoProductos);
    if(productoEncontrado==false){
        cout<< "PRODUCTO NO ENCONTRADO"<<endl;
        return false;
    }
    cout<< "STOCK ACTUALIZADO"<<endl;
    return true;
}

int ArchivoDevoluciones::getCantidadRegistros(){
    int total, cantidad;
    Devoluciones devolucion;
    FILE *fDevoluciones;

    fDevoluciones=fopen("archivoDevoluciones.dat", "rb");
    if(fDevoluciones==nullptr){
        cout<< "ERROR AL ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    fseek(fDevoluciones, 0, SEEK_END);
    total=ftell(fDevoluciones);

    if(total==-1){
        fclose(fDevoluciones);
        return 0;
    }

    cantidad=total/sizeof(devolucion);
    fclose(fDevoluciones);

    return cantidad;
}

bool ArchivoDevoluciones::listarDevoluciones(){
    FILE *listadoDevoluciones;
    Producto producto;
    Devoluciones devolucion(producto);
    listadoDevoluciones=fopen(_nombreArchivoDevoluciones, "rb");
    if(listadoDevoluciones==NULL){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    cout<< left
         << setw(25) << "ID DEL PRODUCTO"
         << setw(20) << "ID DEL PROVEEDOR"
         << setw(30) << "FECHA DE DEVOLUCION"
         << setw(30) << "PRODUCTOS A DEVOLVER"
         << setw(30) << "DEVOLUCION"
         << endl;
    cout << string(120, '-') << endl;

    while(fread(&devolucion, sizeof(Devoluciones), 1, listadoDevoluciones)==1){
         cout<< left
         << setw(25) << devolucion.getIDProducto()
         << setw(20) << devolucion.getIDProveedor()
         << setw(30) << devolucion.getIngresoDevolucion()
         << setw(30) << devolucion.getcantidadProductos()
         << setw(30) << devolucion.getDevolucionRealizada()
         << endl;
    cout << string(120, '-') << endl;
    }
    fclose(listadoDevoluciones);
    return true;

}

bool ArchivoDevoluciones::BuscarDevolucionXIdProducto(){
    FILE *buscarDevolucion;
    Devoluciones devolucion;
    buscarDevolucion=fopen(_nombreArchivoDevoluciones, "rb");
    if(buscarDevolucion==nullptr){
        cout<< "No se pudo abrir el archivo"<<endl;
        return false;
    }
    int idProducto;
    cout<< "Ingresar el id producto de la devolucion que desea buscar: ";
    cin>>idProducto;

    bool encontrado=false;

    while(fread(&devolucion, sizeof(Devoluciones), 1, buscarDevolucion)==1){
        if(devolucion.getIDProducto()==idProducto){
            devolucion.mostrar();
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<< "Id producto no encontrado"<<endl;
    }
    fclose(buscarDevolucion);
    return encontrado;
}

bool ArchivoDevoluciones::BuscarDevolucionXMes(){
    FILE *buscarDevolucionF;
    Devoluciones devolucion;
    buscarDevolucionF=fopen(_nombreArchivoDevoluciones, "rb");
    if(buscarDevolucionF==nullptr){
        cout<< "No se pudo abrir el archivo"<<endl;
        return false;
    }
    int mes;
    cout<< "Ingresar el mes que desea buscar: ";
    cin>>mes;

    bool encontrado=false;

    while(fread(&devolucion, sizeof(Devoluciones), 1, buscarDevolucionF)==1){
        if(devolucion.getIngresoDevolucionMes()==mes){
            devolucion.mostrar();
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<< "No se encuentran devoluciones registradas en el mes"<<endl;
    }
    fclose(buscarDevolucionF);
    return encontrado;
}

bool ArchivoDevoluciones::BuscarDevolucionXIdProveedor(){
    FILE *buscarDevolucionProveedor;
    Devoluciones devolucion;
    buscarDevolucionProveedor=fopen(_nombreArchivoDevoluciones, "rb");
    if(buscarDevolucionProveedor==nullptr){
        cout<< "No se pudo abrir el archivo"<<endl;
        return false;
    }
    int idproveedor;
    cout<< "Ingresar Id del proveedor que desea buscar devoluciones: ";
    cin>>idproveedor;

    bool encontrado=false;

    while(fread(&devolucion, sizeof(Devoluciones), 1, buscarDevolucionProveedor)==1){
        if(devolucion.getIDProveedor()==idproveedor){
            devolucion.mostrar();
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<< "No se encuentran devoluciones registradas en el mes"<<endl;
    }
    fclose(buscarDevolucionProveedor);
    return encontrado;
}


