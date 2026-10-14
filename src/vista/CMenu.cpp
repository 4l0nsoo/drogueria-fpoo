/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Menú principal (GRUPO 1)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CMenu.h"
using namespace std;

CMenu::CMenu(CInventario& inventario_, istream& entrada_, ostream& salida_) //Función menú de clase menú
    : inventario(inventario_), entrada(entrada_), salida(salida_) {
        int choice;
        salida <<"╔══════════════════════════════════════════╗\n"
               <<"          MENÚ OPCIONES - DROGUERÍA         \n"
               <<"╚══════════════════════════════════════════╝\n"<<endl;
        salida << "1.  \n";
        salida << "2. \n";
        salida << "3. \n";
        salida << "4. \n";
        salida << "5. \n";
        salida << "6. \n";
        salida << "7. \n";
        salida << "8. \n";
        salida << "9. \n";
        salida << "0. Salir\n";
        salida << "Ingrese su elección: "; //entero
        entrada >> choice;
}

void CMenu::ejecutar(){
    // STUB (Grupo 1): implementar
    salida << "[Grupo 1] El menu aun no esta implementado." << endl;
}
