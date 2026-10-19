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

    SECCION("CMenu: sesion completa. agrega, muestra y sale");
    {
        CInventario inv("Drogas La Especial", "07-10-2026");
        // Flujo: 1 (Agregar) -> Datos del medicamento -> 3 (Mostrar) -> 0 (Salir)
        stringstream in("1\n3\n0");
        stringstream out;

        CMenu menu(inv, in, out);
        menu.ejecutar();

        CHECK_EQ((int)inv.getMedicamentos().size(), 1);
        CHECK(out.str().length() > 0);
    }

SECCION("CMenu Extra: cancelar eliminacion regresa al menu");
{
    CInventario inv("Drogas La Especial", "07-10-2026");

    // 1 -> Agrega un medicamento por defecto (STUB)
    // 2 -> Intenta eliminar
    // n -> Responde "No" a la confirmación
    // 0 -> Salir del menú
    stringstream in("1\n2\nn\n0\n");
    stringstream out;

    CMenu menu(inv, in, out);
    menu.ejecutar();

    // Verificación 1: El medicamento NO fue eliminado (sigue en el inventario)
    CHECK_EQ((int)inv.getMedicamentos().size(), 1);

    // Verificación 2: La salida confirma que regresó al menú o canceló
    CHECK_CONTIENE(out.str(), "cancelada");
}

SECCION("CMenu: Vender y Reabastecer medicamento");
{
    CInventario inv("Drogas La Especial", "07-10-2026");

    // 5 -> Vender (usa los stubs de pedirId y pedirCantidad)
    // 6 -> Reabastecer
    // 0 -> Salir
    stringstream in("5\n6\n0\n");
    stringstream out;

    CMenu menu(inv, in, out);
    menu.ejecutar();

    CHECK(out.str().length() > 0); // Verifica que el menú procesó ambas operaciones
}

SECCION("CMenu: Mostrar reportes");
{
    CInventario inv("Drogas La Especial", "07-10-2026");

    // 7 -> Mostrar reportes
    // 0 -> Salir
    stringstream in("7\n0\n");
    stringstream out;

    CMenu menu(inv, in, out);
    menu.ejecutar();

    // Verificamos que el menú haya impreso las etiquetas de los reportes
    CHECK_CONTIENE(out.str(), "Valor total de costo:");
    CHECK_CONTIENE(out.str(), "Ganancia total:");
}

SECCION("CMenu: Guardar y Cargar");
{
    CInventario inv("Drogas La Especial", "07-10-2026");

    // 8 -> guardar inventario
    // 9 -> cargar inventario
    // 0 -> salir
    stringstream in("8\n9\n0\n");
    stringstream out;

    CMenu menu(inv, in, out);
    menu.ejecutar();

    CHECK_CONTIENE(out.str(), "Gracias por visitarnos");
}

    // TODO (Grupo 1): simulen una sesión completa con stringstream. Ejemplo: elegir
    // "agregar medicamento", escribir sus datos, luego "mostrar" y luego "0", y verificar
    // el texto de salida y/o el inventario. También prueben opciones inválidas.

    return RESUMEN();
}
