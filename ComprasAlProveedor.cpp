#include "ComprasAlProveedor.h"
#include <cstring>
#include <iostream>
#include "rlutil.h"
using namespace std;

ComprasAlProveedor::ComprasAlProveedor(){}

ComprasAlProveedor::ComprasAlProveedor(Producto& producto):_producto(producto){
}

ComprasAlProveedor::ComprasAlProveedor(Producto& producto, int CantidadProductos, float PrecioUnitario, float PrecioTotal): _producto(producto){
    _CantidadProductos=CantidadProductos;
    _PrecioUnitario=PrecioUnitario;
    _PrecioTotal=PrecioTotal;
}

void ComprasAlProveedor::setCantidadProductos(int CantidadProductos){
    if(CantidadProductos > 0){
        _CantidadProductos=CantidadProductos;
    }
}

void ComprasAlProveedor::setPrecioUnitario(float PrecioUnitario){
    if(PrecioUnitario > 0){
        _PrecioUnitario=PrecioUnitario;
    }
}

void ComprasAlProveedor::setPrecioTotal(float PrecioTotal){
    if(PrecioTotal > 0){
        _PrecioTotal=PrecioTotal;
    }
}

void ComprasAlProveedor::setFechaDeCompra(int dia, int mes, int anio){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
}

int ComprasAlProveedor::getCantidadProductos(){
    return _CantidadProductos;
}

float ComprasAlProveedor::getPrecioUnitario(){
    return _PrecioUnitario;
}

float ComprasAlProveedor::getPrecioTotal(){
    return _CantidadProductos*_PrecioUnitario;
}

string ComprasAlProveedor::getFechaDeCompra(){
    return _fecha.toString();
}

int ComprasAlProveedor::getIdProducto(){
    return _producto.getIDProducto();
}

int ComprasAlProveedor::getIdProveedor(){
    return _proveedor.getIdproveedor();
}

const char* ComprasAlProveedor::getMarca(){
    return _proveedor.getMarca();
}

const char* ComprasAlProveedor::getNombreProducto(){
    return _producto.getNombre();
}

void ComprasAlProveedor::SumaDeStock(Producto& producto){
    if(producto.getIDProducto()==_producto.getIDProducto()){
        int stockAnterior=producto.getStock();
        int stockActual=stockAnterior+_CantidadProductos;
        producto.setStock(stockActual);
    }
    else {
        cout<< "ID DE PRODUCTO NO ENCONTRADO"<<endl;
    }
}

void ComprasAlProveedor::cargar(Producto& producto){
    int idproveedor, idproducto, dia, mes, anio;
    char nombreproveedor[50], nombreproducto[50];
    cout<< "FECHA DE COMPRA: ";
    rlutil::locate(18,3);
    cout<< "  /  /   ";
    rlutil::locate(18,3);
    cin>>dia;
    rlutil::locate(21,3);
    cin>>mes;
    rlutil::locate(24,3);
    cin>>anio;



    /*cin>> dia >> separador >> mes >> separador >> anio;*/
    setFechaDeCompra(dia, mes, anio);

    ArchivoProveedores archivoProveedor;
    cout<< "ID DEL PROVEEDOR: ";
    while(true){
        cin>>idproveedor;
        if(cin.fail()){
        cout<< "INCORRECTO. INTENTA NUEVAMENTE"<<endl;
        cout<< "INGRESAR EL ID DEL PROVEEDOR: ";
        cin.clear();
        cin.ignore();
    }
    else {
         if(archivoProveedor.VerificarRegistroExistente(idproveedor)){
           _proveedor.setIdproveedor(idproveedor);
           Proveedores proveedor;
                int pos = archivoProveedor.buscar(idproveedor);  // Buscar en el archivo el proveedor
                if (pos != -1) {
                    archivoProveedor.leerRegistros(idproveedor, pos); // Leer el proveedor de la posición encontrada
                    _proveedor.setMarca(proveedor.getMarca());  // Asignar la marca automáticamente
                }

            break;
         }
         else {
            cout<< "PROVEEDOR INEXISTENTE. INTENTA NUEVAMENTE"<<endl;
            cout<< "ID DEL PROVEEDOR: ";
         }
    }
    }
    cin.ignore();


    /*cout<< "MARCA: ";
    cin.getline(nombreproveedor, 50);
    _proveedor.setMarca(nombreproveedor);*/



    cout<<"ID DEL PRODUCTO: ";
    cin>>idproducto;
    _producto.setIDProducto(idproducto);
    cin.ignore();



    cout<< "NOMBRE DEL PRODUCTO: ";
    cin.getline(nombreproducto, 50);
    _producto.setNombre(nombreproducto);



    cout<< "CANTIDAD DE PRODUCTOS COMPRADOS: ";
    cin>>_CantidadProductos;
    cout<< "PRECIO UNITARIO DEL PRODUCTO: $ ";
    cin>>_PrecioUnitario;
    SumaDeStock(producto);
}

void ComprasAlProveedor::mostrar(){
    cout<< "FECHA DE COMPRA AL PROVEEDOR: "<<getFechaDeCompra()<<endl;
    cout<< "ID DEL PROVEEDOR: "<<getIdProveedor()<<endl;
    cout<< "MARCA: "<<getMarca()<<endl;
    cout<< "ID DEL PRODUCTO: "<<getIdProducto()<<endl;
    cout<< "NOMBRE DEL PRODUCTO: "<<getNombreProducto()<<endl;
    cout<< "CANTIDAD DE PRODUCTOS COMPRADOS: "<<getCantidadProductos()<<endl;
    cout<< "PRECIO UNITARIO DEL PRODUCTO: $"<<getPrecioUnitario()<<endl;
    cout<< "PRECIO TOTAL: $"<<getPrecioTotal()<<endl;
}
