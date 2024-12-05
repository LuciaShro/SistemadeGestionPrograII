#include "Fecha.h"
#include <iostream>

Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

// MODIFICACION POR LU PAZ - PARA VALIDAR DIA SEGÚN MES

void Fecha::setDia(int dia) {
    while (true) {
        int diasMes;
        switch (_mes) {
            case 4: case 6: case 9: case 11:
            diasMes = 30;
            break;
            case 2:
            if(esBisiesto(_anio)){
                diasMes=29;
            }
            else{
                diasMes=28;
            }
            break;
            default:
            diasMes = 31;
        }

        if (dia >= 1 && dia <= diasMes) {
            _dia = dia;
            break;
        } else {
            std::cout << "Día inválido para el mes " << ". Intente nuevamente, ingresando el día correspondiente: ";
            std::cin >> dia;
        }
    }
}

//MODIFICACION POR LU PAZ - VALIDACIÓN DE MES
void Fecha::setMes(int mes){
    while(mes<1 || mes>12){
        std::cout<< "Mes invalido. Debe estar entre 1 y 12. Intente nuevamente, ingresando el mes correspondiente: ";
        std::cin>>mes;
    }
    _mes = mes;
}

void Fecha::setAnio(int anio){
    while(anio<1000 || anio>9999){
        std::cout<< "Anio invalido. Intente nuevamente: ";
        std::cin>>anio;
    }
    _anio = anio;
}

bool Fecha::esBisiesto(int anio){
    return (anio%4==0 && anio%100!=0) || (anio%400==0);
}

std::string Fecha::toString(){
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}
