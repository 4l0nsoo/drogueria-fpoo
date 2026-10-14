/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Búsqueda (GRUPO 6)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CBuscador.h"
using namespace std;

CBuscador::CBuscador(const CInventario& inventario_) : inventario(inventario_) {
}

const CMedicamento* CBuscador::porId(int id) const{
    // STUB (Grupo 6): implementar
    return nullptr;
}

vector<CMedicamento> CBuscador::porNombre(string texto) const{
    // STUB (Grupo 6): implementar
    return vector<CMedicamento>();
}

vector<CMedicamento> CBuscador::porRangoPrecio(float minimo, float maximo) const{
    // STUB (Grupo 6): implementar
    return vector<CMedicamento>();
}

vector<CMedicamento> CBuscador::conPocoStock(int umbral) const{
    // STUB (Grupo 6): implementar
    return vector<CMedicamento>();
}
