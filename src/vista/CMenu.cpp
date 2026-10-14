/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Menú principal (GRUPO 1)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CMenu.h"
using namespace std;

CMenu::CMenu(CInventario& inventario_, istream& entrada_, ostream& salida_)
    : inventario(inventario_), entrada(entrada_), salida(salida_) {
        int choice;
        salida <<"╔══════════════════════════════════════════╗\n"
               <<"          MENÚ OPCIONES - DROGUERÍA         \n"
               <<"╚══════════════════════════════════════════╝\n"<<endl;
        salida << "1. Agregar medicamento\n";
        salida << "2. Eliminar medicamento\n";
        salida << "3. Mostrar medicamentos\n";
        salida << "4. Buscar medicamento\n";
        salida << "5. Vender medicamento\n";
        salida << "6. Reestablecer\n";
        salida << "7. Mostrar reportes\n";
        salida << "8. Guardar\n";
        salida << "9. Cargar el inventario\n";
        salida << "0. Salir\n";
        salida << "Ingrese su elección: ";
        entrada >> choice;
}

void CMenu::ejecutar(){
    // STUB (Grupo 1): implementar
    salida << "[Grupo 1] El menu aun no esta implementado." << endl;
}
