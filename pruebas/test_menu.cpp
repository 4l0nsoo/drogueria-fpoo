// Pruebas de CMenu. Responsable: GRUPO 1
#include <sstream>
#include "minitest.h"
#include "CMenu.h"
using namespace std;

int main(){
    SECCION("CMenu: la opcion 0 sale del menu");
    {
        CInventario inv("Drogas La Especial", "07-10-2026");
        stringstream in("0\n");
        stringstream out;
        CMenu menu(inv, in, out);
        menu.ejecutar();
        CHECK_CONTIENE(out.str(), "Salir");
    }

    SECCION("CMenu: termina aunque la entrada se acabe (EOF)");
    {
        CInventario inv("Drogas La Especial", "07-10-2026");
        stringstream in("");
        stringstream out;
        CMenu menu(inv, in, out);
        menu.ejecutar();
        CHECK(true);   // si llegamos aqui, no se quedo en un ciclo infinito
    }

    // TODO (Grupo 1): simulen una sesión completa con stringstream. Ejemplo: elegir
    // "agregar medicamento", escribir sus datos, luego "mostrar" y luego "0", y verificar
    // el texto de salida y/o el inventario. También prueben opciones inválidas.

    return RESUMEN();
}
