/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Validación de entradas (GRUPO 3)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
    (El STUB actual NO valida nada: solo lee la siguiente palabra.)
*/
#include "CValidador.h"
using namespace std;

CValidador::CValidador(istream& entrada_, ostream& salida_) : entrada(entrada_), salida(salida_) {
}

int CValidador::leerEntero(string mensaje, int minimo, int maximo){
    // STUB (Grupo 3): implementar
    int valor = 0;
    salida << mensaje;
    entrada >> valor;
    return valor;
}

float CValidador::leerFloatPositivo(string mensaje){
    // STUB (Grupo 3): implementar
    float valor = 0;
    salida << mensaje;
    entrada >> valor;
    return valor;
}

string CValidador::leerTextoNoVacio(string mensaje){
    // STUB (Grupo 3): implementar
    string texto;
    salida << mensaje;
    entrada >> texto;
    return texto;
}

string CValidador::leerFecha(string mensaje){
    // STUB (Grupo 3): implementar
    string texto;
    salida << mensaje;
    entrada >> texto;
    return texto;
}

bool CValidador::esFechaValida(string fecha){
    // STUB (Grupo 3): implementar
    return true;
}
