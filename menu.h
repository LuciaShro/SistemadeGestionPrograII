#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "rlutil.h"

void menuPrincipal();
void menuClientes();
void menuVendedores();
void menuVentas();
void menuProductos();
void menuDevoluciones();
void menuProveedores();
void menuInformes();
void menuConfiguraciones();
bool ValidacionNumsEnteros(int &opcion);

void mostrarCentrado(std::string& texto, int fila);
#endif // MENU_H_INCLUDED
