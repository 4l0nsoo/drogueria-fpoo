// Pruebas de CBuscador. Responsable: GRUPO 6
#include "minitest.h"
#include "CBuscador.h"

int main(){
    CInventario inv("Drogas La Especial", "07-10-2026");
    inv.adicionarMedicamento(CMedicamento(1, "Acetaminofen 60Mg", 1, 100, 1000, 2000));
    inv.adicionarMedicamento(CMedicamento(2, "Ibuprofeno 30x20 Caja", 2, 10000, 500, 2500));
    inv.adicionarMedicamento(CMedicamento(3, "Jarabe de Ibuprofeno", 3, 5, 3000, 6000));
    CBuscador buscador(inv);

    SECCION("CBuscador: porId");
    CHECK(buscador.porId(2) != nullptr);
    if (buscador.porId(2) != nullptr) {
        CHECK_EQ(buscador.porId(2)->getNombre(), "Ibuprofeno 30x20 Caja");
    }
    CHECK(buscador.porId(99) == nullptr);

    SECCION("CBuscador: porNombre (parcial, sin importar mayusculas)");
    CHECK_EQ((int)buscador.porNombre("ibu").size(), 2);
    CHECK_EQ((int)buscador.porNombre("ACETA").size(), 1);
    CHECK_EQ((int)buscador.porNombre("xyz").size(), 0);

    SECCION("CBuscador: porRangoPrecio");
    CHECK_EQ((int)buscador.porRangoPrecio(2000, 2500).size(), 2);

    SECCION("CBuscador: conPocoStock");
    CHECK_EQ((int)buscador.conPocoStock(10).size(), 1);

    // TODO (Grupo 6): inventario vacío, texto vacío, rango invertido (minimo > maximo),
    // límites incluidos, que el orden se conserve, etc.

    return RESUMEN();
}
