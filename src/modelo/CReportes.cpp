/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Reportes (GRUPO 8)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CReportes.h"
using namespace std;

CReportes::CReportes(const CInventario& inventario_) : inventario(inventario_) {
}

float CReportes::valorTotalCosto() const{
    // STUB (Grupo 8): implementar
    return 0;
}

float CReportes::valorTotalVenta() const{
    // STUB (Grupo 8): implementar
    return 0;
}

float CReportes::gananciaPotencial() const{
    // STUB (Grupo 8): implementar
    return 0;
}

float CReportes::margenPorUnidad(int id) const{
    // STUB (Grupo 8): implementar
    return 0;
}

vector<CMedicamento> CReportes::masRentables(int n) const{
    // STUB (Grupo 8): implementar
    return vector<CMedicamento>();
}

vector<CMedicamento> CReportes::ordenadosPorPrecio() const{
    // STUB (Grupo 8): implementar
    return vector<CMedicamento>();
}

vector<CMedicamento> CReportes::ordenadosPorNombre() const{
    // STUB (Grupo 8): implementar
    return vector<CMedicamento>();
}

vector<CMedicamento> CReportes::ordenadosPorCantidad() const{
    // STUB (Grupo 8): implementar
    return vector<CMedicamento>();
}
