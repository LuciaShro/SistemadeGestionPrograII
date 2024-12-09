#include "ArchivoVendedor.h"
#include "ArchivoVenta.h"
#include "ArchivoDetalleDeVenta.h"
#include <cstring>
#include <iostream>
#include <iomanip>
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
    /*cout << "INGRESE LA INFORMACION DEL VENDEDOR " << endl;*/
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
    return vendedor;
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
    FILE *pVendedor;
    Vendedor vendedor;

    pVendedor=fopen(_nombreArchivoVendedor, "rb");
    if(pVendedor==nullptr){
        cout<< "No se pudo abrir el archivo de vendedores"<<endl;
    }

    cout << left << setw(10) << "DNI"
         << setw(15) << "APELLIDO"
         << setw(15) << "NOMBRE"
         << setw(15) << "TELEFONO"
         << setw(30) << "MAIL"
         << setw (15) << "DOMICILIO"
         << setw(20) << "INGRESO"
         << setw(12) << "COMISION"
         << setw (15) << "ESTADO"
         << setw (15) << "NACIMIENTO"
         << endl;
    cout << string(148, '-') << endl;


    while(fread(&vendedor, sizeof(Vendedor), 1, pVendedor)==1){

             cout << left << setw(10) << vendedor.getId()
             << setw(15) << vendedor.getApellidos()
             << setw(15) << vendedor.getNombres()
             << setw(15) << vendedor.getTelefono()
             << setw(30) << vendedor.getMail()
            << setw(15) << vendedor.getDomicilio()
             << setw (20) << vendedor.getFechaIngreso()
             << setw(12)<< vendedor.getComisiones()
             << setw(15)<< vendedor.getEstado()
             << setw(15)<< vendedor.getNacimiento()
             << endl;
    }
    fclose(pVendedor);

    /*for(int i=0; i<archVendedor.getCantidadRegistros(); i++){
        archVendedor.mostrarVendedor(archVendedor.leerRegistro(i));
    } // Lo cambio por formato tabla

    cout << "--------------------------------------------" << endl;*/
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
        return -1; // retornar -1 porque si es 0 siempre va a ser verdadero
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
    char mail[100], telefono[11], domicilio[100];
    ArchivoVendedor archVendedor;
    Vendedor vendedor;

    cout << "INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR" << endl;
    cin >> id;

    pos = archVendedor.buscar(id);

    if(pos!= -1){
        vendedor = archVendedor.leerRegistro(pos);

        cout << "Procesando para la modificacion.... " << endl;
        system("pause");
        system("cls");
        cout << "INGRESE EL TELEFONO: ";
        cin >> telefono;
        vendedor.setTelefono(telefono);
        cout << "INGRESE EL MAIL: ";
        cin >> mail;
        vendedor.setMail(mail);
        cout<< "INGRESE EL DOMICILIO: ";
        cin.ignore();
        cin.getline(domicilio, 100);
        vendedor.setDomicilio(domicilio);

        cout << "INGRESE EL NUMERO TELEFONO "; cin >> telefono;
        vendedor.setTelefono(telefono);
        cout << "INGRESE EL MAIL "; cin >> mail;
        vendedor.setMail(mail);
        cout << "INGRESE EL DOMICILIO ";
        cin.ignore();
        cin.getline(domicilio, 100);
        vendedor.setDomicilio(domicilio);

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
    if(buscar(id)==-1){
        cout<< "El id vendedor indicado no existe."<<endl;
    }
    else{
        archVendedor.mostrarVendedor(archVendedor.leerRegistro(pos));
    }
}


///SETEA LA COMISION, SOLO REEMPLAZA NO ACUMULA TODAVIA
void ArchivoVendedor::SetComision(int idVenta, int idVendedor){
     ArchivoDetalleDeVenta archDetalle;
     detalleVenta detalle;
     int posDetalle = archDetalle.buscar(idVenta);
     if (posDetalle == -1) {
        cout << "Error: Detalle de venta no encontrado." << endl;
        return;
     }
     detalle = archDetalle.leerRegistro(posDetalle);

     Vendedor vendedor;

     int posVendedor = buscar(idVendedor);
     if (posVendedor == -1) {
        cout << "Error: Vendedor no encontrado." << endl;
        return;
     }

     vendedor = leerRegistro(posVendedor);

     vendedor.setComisiones(idVendedor, detalle);

     modificarRegistro(posVendedor,vendedor);
}
