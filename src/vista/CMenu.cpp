/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Menú principal (GRUPO 1)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CMenu.h"
using namespace std;

CMenu::CMenu(CInventario& inventario_, istream& entrada_, ostream& salida_)
    : inventario(inventario_), entrada(entrada_), salida(salida_) {
}

void CMenu::ejecutar(){
    // STUB (Grupo 1): implementar
    salida << "[Grupo 1] El menu aun no esta implementado." << endl;
}
