// Pruebas de CInventario (clase base). Responsable: GRUPO 4
#include "minitest.h"
#include "CInventario.h"

int main(){
    SECCION("CInventario: datos basicos");
    CInventario inv("Drogas La Especial", "07-10-2026");
    CHECK_EQ(inv.getNombre(), "Drogas La Especial");
    CHECK_EQ(inv.getFecha(), "07-10-2026");
    CHECK_EQ((int)inv.getMedicamentos().size(), 0);

    SECCION("CInventario: adicionarMedicamento");
    inv.adicionarMedicamento(CMedicamento(1, "Acetaminofen 60Mg", 1, 100, 1000, 2000));
    CHECK_EQ((int)inv.getMedicamentos().size(), 1);

    SECCION("CInventario: setFecha");
    inv.setFecha("08-10-2026");
    CHECK_EQ(inv.getFecha(), "08-10-2026");

    // TODO (Grupo 4): casos a cubrir en elimininarMedicamento (cuidado: imprime en pantalla):
    //   - eliminar un medicamento que existe
    //   - eliminar uno que no existe
    //   - eliminar de un inventario vacío
    //   - eliminar y verificar que los demás medicamentos siguen ahí
    //   - dos medicamentos con el mismo id
    // Si una prueba revela un error en el código existente, corríjanlo en CInventario.cpp
    // y expliquen en el PR qué encontraron.

    return RESUMEN();
}
