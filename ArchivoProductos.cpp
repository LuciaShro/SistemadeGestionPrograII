#include "ArchivoProductos.h"
#include "ComprasAlProveedor.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ArchivoProductos::ArchivoProductos(const char *nombreArchivoProducto){
    strcpy(_nombreArchivoProductos, nombreArchivoProducto);
}

/*ArchivoProductos::ArchivoProductos(const char *nombreArchivoProducto.dat){
    strcpy(_nombreArchivoProductos.dat, nombreArchivoProducto.dat);
}*/

ArchivoProductos::ArchivoProductos(){}

bool ArchivoProductos::grabarRegistroProducto(Producto producto){
        FILE *ArchivoProducto;
        ArchivoProducto=fopen(_nombreArchivoProductos, "ab");//si no puede hacer la apertura fopen devuelve NULL
        if(ArchivoProducto==NULL) return false;
        int escribir=fwrite(&producto,sizeof(producto),1,ArchivoProducto);
        fclose(ArchivoProducto);
        if (escribir==1){
            cout<< "¡NUEVO PRODUCTO AGREGADO!"<<endl;
            return true;
        }
        return false;
}

void ArchivoProductos::agregarRegistro(){
    ArchivoProductos archivo("archivoProductos.dat");
    Producto productos;
    productos.cargar();
    archivo.grabarRegistroProducto(productos);
}

bool ArchivoProductos::listarRegistros(){
    FILE *listadoProductos;
    Producto producto;
    listadoProductos=fopen("archivoProductos.dat", "rb");
    if(listadoProductos==NULL){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    cout << left << setw(10) << "ID"
         << setw(30) << "NOMBRE"
         << setw(35) << "DESCRIPCION"
         << setw(12) << "PRECIO"
         << setw(15) << "STOCK"
         /*<< setw(17) << "FECHA"*/
         << endl;
    cout << string(110, '-') << endl;


    while(fread(&producto, sizeof(Producto), 1, listadoProductos)==1){

             cout << left << setw(10) << producto.getIDProducto()
             << setw(30) << producto.getNombre()
             << setw(35) << producto.getDescripcion()
             << setw(12) << fixed << setprecision(2) << producto.getPrecio()
             << setw(15) << producto.getStock()
            /* << setw(17) << producto.getFecha()*/
             << endl;
    }
    fclose(listadoProductos);
    return true;
}

bool ArchivoProductos::buscarProductoPorID(){
    FILE *buscarProducto;
    Producto producto;
    buscarProducto=fopen(_nombreArchivoProductos, "rb");
    /*buscarProducto=fopen("ArchivoProductos.dat", "rb");*/
    if(buscarProducto==NULL){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    int id;
    cout<< "INGRESAR EL ID DEL PRODUCTO A BUSCAR: ";
    cin>>id;
    while(fread(&producto, sizeof(Producto), 1, buscarProducto)==1){
        if(producto.getIDProducto()==id){
            producto.mostrar();
            fclose(buscarProducto);
            return true;
        }
    }
    cout<< "PRODUCTO NO ENCONTRADO"<<endl;
    fclose(buscarProducto);
    return false;
}

bool ArchivoProductos::buscarProductoPorNombre(){
    FILE *buscarProductoNombre;
    Producto producto;
    buscarProductoNombre=fopen(_nombreArchivoProductos, "rb");
    buscarProductoNombre=fopen("ArchivoProductos.dat", "rb");
    if(buscarProductoNombre==NULL){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    char nombre[100];
    cout<< "INGRESAR EL NOMBRE DEL PRODUCTO A BUSCAR: ";
    cin.getline(nombre, 100);
    while(fread(&producto, sizeof(Producto), 1, buscarProductoNombre)==1){
        if(strcmp(producto.getNombre(), nombre) == 0){
            producto.mostrar();
            fclose(buscarProductoNombre);
            return true;
        }
    }
    cout<< "PRODUCTO NO ENCONTRADO"<<endl;
    fclose(buscarProductoNombre);
    return false;
}
// MODIFICADO LU PAZ - 30/11/2024
bool ArchivoProductos::modificarPrecioProducto(){
    FILE *modificarPrecio;
    Producto producto;
    modificarPrecio=fopen(_nombreArchivoProductos, "rb+");
    if(modificarPrecio==NULL){
        cout<< "NO PUDO ABRIRSE EL ARCHIVO"<<endl;
        return false;
    }
    int id;
    cout<< "INGRESAR EL ID DEL PRODUCTO PARA MODIFICAR EL PRECIO: ";
    cin>>id;
    while(fread(&producto, sizeof(Producto), 1, modificarPrecio)==1){
        if(producto.getIDProducto()==id){
        producto.mostrar();
        float NuevoPrecio;
        cout<< "INGRESAR EL NUEVO PRECIO: ";
        cin>>NuevoPrecio;
        producto.setPrecio(NuevoPrecio);

        long posicionActual=ftell(modificarPrecio);

        fseek(modificarPrecio, posicionActual-sizeof(Producto), SEEK_SET);
        fwrite(&producto, sizeof(producto), 1, modificarPrecio);
        cout<< "PRODUCTO MODIFICADO"<<endl;
        producto.mostrar();

        fclose(modificarPrecio);
        return true;

    }
    }

    cout<< "PRODUCTO NO ENCONTRADO"<<endl;
    fclose(modificarPrecio);
    return false;
}

bool ArchivoProductos::buscarPRODUCTOID(int id, Producto& producto){
    FILE *buscarProducto;
    buscarProducto=fopen(_nombreArchivoProductos, "rb");
    if(buscarProducto==NULL){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    while(fread(&producto, sizeof(Producto), 1, buscarProducto)==1){
        if(producto.getIDProducto()==id){
            fclose(buscarProducto);
            return true;
        }
    }
    cout<< "PRODUCTO NO ENCONTRADO"<<endl;
    fclose(buscarProducto);
    return false;
}
// MODIFICACION LU PAZ - 30/11/2024
bool ArchivoProductos::actualizarProducto(Producto& producto){
    FILE *archivo=fopen(_nombreArchivoProductos, "rb+");
    if(archivo==nullptr){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO PRODUCTOS"<<endl;
        return false;
    }
    Producto prod;
    while(fread(&prod, sizeof(Producto), 1, archivo)==1){
        if(prod.getIDProducto()==producto.getIDProducto()){

            long posicionActual=ftell(archivo);

            fseek(archivo, posicionActual-sizeof(Producto), SEEK_SET);
            fwrite(&producto, sizeof(Producto), 1, archivo);
            fclose(archivo);
            return true;
    }

    }
    fclose(archivo);
    return false;
}

int ArchivoProductos::getCantidadRegistros(){
    int total, cantidad;
    Producto producto;
    FILE *fProductos;

    fProductos=fopen(_nombreArchivoProductos, "rb");
    if(fProductos==nullptr){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO DE PRODUCTOS"<<endl;
        return -1;
    }

    fseek(fProductos, 0, SEEK_END);
    total=ftell(fProductos);

    if(total==-1){
        fclose(fProductos);
        return 0;
    }

    cantidad=total/sizeof(producto);
    fclose(fProductos);

    return cantidad;
}


///CREE ESTA FUN. PARA QUE SEA UTILIZADA EN ARCH.DETALLE YA QUE ERA NECESARIA (lu schiro)
Producto ArchivoProductos::leerRegistro(int idProducto){
    FILE *pProducto;
    Producto producto;

    pProducto = fopen(_nombreArchivoProductos, "rb");

    if(pProducto == nullptr){
        return producto;
    }

    fseek(pProducto,sizeof(producto)*idProducto, SEEK_SET);
    fread(&producto, sizeof(producto), 1, pProducto);

    fclose(pProducto);
}

// AGREGADO HOY 30-11-2024

int ArchivoProductos::buscar(int id){
    FILE *pProductos;
    Producto producto;
    int pos = 0;

    pProductos = fopen(_nombreArchivoProductos, "rb");

    if(pProductos == nullptr){
        return -1;
    }

    while(fread(&producto,sizeof(producto), 1, pProductos)== 1){
        if(producto.getIDProducto() == id){
            fclose(pProductos);
            return pos; // En este caso, encontramos el ID
        }
        pos++;
    }
    fclose(pProductos);
    return -1;  // EL ID NO FUE ENCONTRADO EN EL ARCHIVO
}
