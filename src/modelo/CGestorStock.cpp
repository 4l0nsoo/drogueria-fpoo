/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Stock y ventas (GRUPO 7)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CGestorStock.h"
using namespace std;

CGestorStock::CGestorStock(CInventario& inventario_) : inventario(inventario_) {
}

ResultadoStock CGestorStock::vender(int id, int cantidad){
    // STUB (Grupo 7): implementar
    return ResultadoStock::NO_EXISTE;
}

ResultadoStock CGestorStock::reabastecer(int id, int cantidad){
    // STUB (Grupo 7): implementar
    return ResultadoStock::NO_EXISTE;
}

bool CGestorStock::esStockBajo(int id, int umbral) const{
    // STUB (Grupo 7): implementar
    return false;
}
