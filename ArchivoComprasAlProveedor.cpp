#include "ArchivoComprasAlProveedor.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ArchivoComprasAlProveedor::ArchivoComprasAlProveedor(const char *nombreArchivoComprasAlProveedor){
    strcpy(_nombreArchivoComprasAlProveedor, nombreArchivoComprasAlProveedor);
}

bool ArchivoComprasAlProveedor::guardarComprasAlProveedor(ComprasAlProveedor& comprasProveedor){
    FILE *ArchivoComprasAlProveedor;
    ArchivoComprasAlProveedor=fopen(_nombreArchivoComprasAlProveedor, "ab");
    if(ArchivoComprasAlProveedor==nullptr){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    int escribir=fwrite(&comprasProveedor, sizeof(ComprasAlProveedor), 1, ArchivoComprasAlProveedor);
    fclose(ArchivoComprasAlProveedor);
    if (escribir==1){
            cout<< "¡NUEVA COMPRA AL PROVEEDOR AGREGADA!"<<endl;
            return true;
    }

    return false;
}

void ArchivoComprasAlProveedor::agregarRegistro(){
    Producto producto;
    int idproducto;
    int op;

    cout<< "INGRESE EL ID DEL PRODUCTO QUE VA A COMPRAR: ";
    cin>>idproducto;

    ArchivoProductos archivoProductos("archivoProductos.dat");
    if (!archivoProductos.buscarPRODUCTOID(idproducto, producto)) {
        cout << "¿DESEA AGREGAR UN NUEVO PRODUCTO?"<< "1-SI/2-NO"<<endl;

        while(true){
         cin>>op;
         if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Opcion invalida. Intente nuevamente (1-SI / 2-NO): ";
            continue;
         }
         if(op==1){
            archivoProductos.agregarRegistro();
            if (!archivoProductos.buscarPRODUCTOID(idproducto, producto)) {
                cout << "NO SE PUDO ENCONTRAR EL PRODUCTO AGREGADO" << endl;
                return;
            }
            break;
         }
         else if(op==2){
            cout<< "Operacion cancelada"<<endl;
            system("pause");
            system("cls");
            return;
        }
        else {
                cout << "Opción incorrecta. Intente nuevamente (1-SI / 2-NO): ";
            }
}
 }
 cout<< "Producto encontrado. Procediendo con la compra..."<<endl;
 system("pause");
 system("cls");

    cout<< "stock antes de la compra: "<<producto.getStock()<<endl;
    ComprasAlProveedor compras;
    compras.cargar(producto); // Cargar los detalles de la devolución
    ActualizacionStockArchivoProductos(producto);
    archivoProductos.actualizarProducto(producto);

    if (!guardarComprasAlProveedor(compras)) {
        cout << "ERROR AL GUARDAR DEVOLUCION" << endl;
    }
}

bool ArchivoComprasAlProveedor::listarCompras(){
    FILE *listadoCompras;
    Producto producto;
    ComprasAlProveedor compras(producto);
    listadoCompras=fopen(_nombreArchivoComprasAlProveedor, "rb");

    if(listadoCompras==NULL){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }

    cout << left
         << setw (18)<< "ID DE PRODUCTO"
         << setw (25)<< "NOMBRE DEL PRODUCTO"
         << setw (20)<< "ID DE PROVEEDOR"
         << setw (20)<< "MARCA"
         << setw(20) << "FECHA DE COMPRA"
         << setw(10) << "CANTIDAD"
         << setw(15) << "P. UNITARIO"
         << setw(15) << "P. TOTAL"
         << endl;
    cout << string(145, '-') << endl;


    while(fread(&compras, sizeof(ComprasAlProveedor), 1, listadoCompras)==1){
        cout << left
         << setw (18)<< compras.getIdProducto()
         << setw (25)<< compras.getNombreProducto()
         << setw (20)<< compras.getIdProveedor()
         << setw (20)<< compras.getMarca()
         << setw(20) << compras.getFechaDeCompra()
         << setw(10) << compras.getCantidadProductos()
         << setw(15) << fixed << setprecision(2)<<compras.getPrecioUnitario()
         << setw(15) << fixed << setprecision(2)<<compras.getPrecioTotal()
         << endl;
    /*cout << string(145, '-') << endl;*/
    }
    fclose(listadoCompras);
    return true;
}

bool ArchivoComprasAlProveedor::ActualizacionStockArchivoProductos(Producto& producto){
        FILE *archivoProductosActualizacion;
        archivoProductosActualizacion=fopen("archivoProductos.dat", "rb+");
        if(archivoProductosActualizacion==nullptr){
            cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
        Producto productoActualizacion;

        bool productoActualizado=false;
        while(fread(&productoActualizacion, sizeof(Producto), 1, archivoProductosActualizacion)==1){
        if(productoActualizacion.getIDProducto()==producto.getIDProducto()){


        productoActualizacion.setStock(producto.getStock());

        fseek(archivoProductosActualizacion, -sizeof(Producto), SEEK_CUR);
        fwrite(&productoActualizacion, sizeof(Producto), 1, archivoProductosActualizacion);
        cout<< "STOCK ACTUALIZADO"<<endl;
        productoActualizado=true;
        break;
    }
    }
    fclose(archivoProductosActualizacion);
    if(!productoActualizado){
        cout<< "PRODUCTO NO ACTUALIZADO"<<endl;
        return false;
    }
    cout<< "PRODUCTO ACTUALIZADO"<<endl;
    return true;
}

bool ArchivoComprasAlProveedor::BuscarCompras(){
    FILE *buscarCompras;
    ComprasAlProveedor compras;
    buscarCompras=fopen(_nombreArchivoComprasAlProveedor, "rb");
    if(buscarCompras==nullptr){
        cout<< "No se pudo abrir el archivo"<<endl;
        return false;
    }
    int idprov;
    cout<< "Ingresar el ID del proveedor que queres buscar: ";
    cin>>idprov;

    bool encontrado=false;
    while(fread(&compras, sizeof(ComprasAlProveedor), 1, buscarCompras)==1){
        if(compras.getIdProveedor()==idprov){
            compras.mostrar();
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<< "Id proveedor no encontrado"<<endl;
    }
    fclose(buscarCompras);
    return encontrado;
}


