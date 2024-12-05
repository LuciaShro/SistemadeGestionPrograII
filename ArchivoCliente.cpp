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

///MODIFICADO - 27/11/2024
int ArchivoCliente::FunGuardarRegistro(){
    cout << "INFORMACION DEL CLIENTE " << endl;
    /*ArchivoCliente  ArchCliente;*/
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
        cliente.setId(dni);
        break;
    }
    }

    bool registrado = VerificarRegistroExistente(dni);
    bool inactivo = ClienteEstadoInactivo(dni, cliente);

    if(registrado){
        if(inactivo){
            cout<< "El cliente se encuentra inactivo."<<endl;
            return -1;
        }
        else {
            cout << "EL USUARIO YA SE ENCUENTRA REGISTRADO EN EL SISTEMA" << endl;
            MostrarNombreyApellido(dni);
            cliente.agregarPuntos(10);
            ActualizacionPuntaje(cliente);
            return dni;
        }
    }

        cout<< "Cliente no registrado. Procedemos al registro..."<<endl;
        system("pause");
        system("cls");
        cliente.setId(dni);
        cliente.cargar();
        cliente.agregarPuntos(10);

     if(GuardarRegistro(cliente)){
        cout<< "CLIENTE CARGADO CON EXITO"<<endl;
        return dni;
     }
     else {
        cout<< "ERROR AL CARGAR EL CLIENTE"<<endl;
        return -1;
     }
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

void ArchivoCliente::MostrarNombreyApellido(int dni){
    Cliente cliente;
   int pos = buscar(dni);
   cliente = leerRegistro(pos);
   cout << cliente.getNombres() << endl;
   cout << cliente.getApellidos() << endl;
}

bool ArchivoCliente::ActualizacionPuntaje(Cliente& cliente){
    FILE *archivoClientes=fopen(_nombreArchivoCliente, "rb+");
    if(archivoClientes==nullptr){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }

    Cliente clientfile;
    bool encontrado=false;

    while(fread(&clientfile, sizeof(Cliente), 1, archivoClientes)==1){
        /*cout << "DNI en el archivo: " << clientfile.getId() << endl;
        cout << "DNI del cliente a actualizar: " << cliente.getId() << endl;*/
        if(clientfile.getId()==cliente.getId()){

            int puntajeActual=clientfile.getPuntaje();
            int nuevoPuntaje=puntajeActual+cliente.getPuntaje();
            clientfile.setPuntaje(nuevoPuntaje);

            long posicionactual = ftell(archivoClientes); // obtengo la posicion actual del puntero



            fseek(archivoClientes, posicionactual-sizeof(Cliente), SEEK_SET); // retrocede al inicio de la posicion actual
            fwrite(&clientfile, sizeof(Cliente), 1, archivoClientes);
            encontrado=true;
            break;
            /*fclose(archivoClientes);
            return true;*/
        }
    }
    fclose(archivoClientes);

     if (encontrado) {
        cout << "Puntaje actualizado con exito" << endl;
        cout << "Puntaje actual del cliente: "<<clientfile.getPuntaje()<<endl;
        clientfile.PuntajeMeta();
        return true;
    } else {
        cout << "Cliente no encontrado" << endl;
        return false;
    }
}

// Nueva funcion para actualizar el puntaje luego de la resta de Puntaje Meta

bool ArchivoCliente::ActualizacionPuntajeResta(Cliente& cliente){
    FILE *archivoClientes=fopen(_nombreArchivoCliente, "rb+");
    if(archivoClientes==nullptr){
        cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }

    Cliente clientfile;
    bool encontrado=false;

    while(fread(&clientfile, sizeof(Cliente), 1, archivoClientes)==1){
        /*cout << "DNI en el archivo: " << clientfile.getId() << endl;
        cout << "DNI del cliente a actualizar: " << cliente.getId() << endl;*/
        if(clientfile.getId()==cliente.getId()){

            int puntajeActual=clientfile.getPuntaje();
            int nuevoPuntaje=puntajeActual-100;
            clientfile.setPuntaje(nuevoPuntaje);

            long posicionactual = ftell(archivoClientes); // obtengo la posicion actual del puntero



            fseek(archivoClientes, posicionactual-sizeof(Cliente), SEEK_SET); // retrocede al inicio de la posicion actual
            fwrite(&clientfile, sizeof(Cliente), 1, archivoClientes);
            encontrado=true;
            break;
            /*fclose(archivoClientes);
            return true;*/
        }
    }
    fclose(archivoClientes);

     if (encontrado) {
        cout << "Puntaje restado y actualizado con exito" << endl;
        cout << "Puntaje actual del cliente: "<<clientfile.getPuntaje()<<endl;
        return true;
    } else {
        cout << "Cliente no encontrado" << endl;
        return false;
    }
}

bool ArchivoCliente::ClienteEstadoInactivo(int idCliente, Cliente& cliente){
    FILE *clienteEstado;
    clienteEstado=fopen(_nombreArchivoCliente, "rb");
    if(clienteEstado==nullptr){
        /*cout<< "No se pudo abrir el archivo"<<endl;*/
        return false;
    }
    Cliente clientPrueba;

    fseek(clienteEstado, 0, SEEK_SET);

    while(fread(&clientPrueba, sizeof(Cliente), 1, clienteEstado)==1){
        if(idCliente==clientPrueba.getId()){
            if(strcmp(clientPrueba.getEstado(), "INACTIVO")==0){
                fclose(clienteEstado);
                return true;
            }
        }
    }
    fclose(clienteEstado);
    return false;
}


