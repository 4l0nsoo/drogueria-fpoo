// Pruebas de CGestorStock. Responsable: GRUPO 7
#include "minitest.h"
#include "CGestorStock.h"

int main(){
    CInventario inv("Drogas La Especial", "07-10-2026");
    inv.adicionarMedicamento(CMedicamento(1, "Acetaminofen 60Mg", 1, 100, 1000, 2000));
    inv.adicionarMedicamento(CMedicamento(2, "Ibuprofeno 30x20 Caja", 2, 5, 500, 2500));
    CGestorStock gestor(inv);

    SECCION("CGestorStock: vender");
    CHECK(gestor.vender(1, 10) == ResultadoStock::OK);
    CHECK_EQ(inv.getMedicamentos()[0].getCantidadDisponible(), 90);

    CHECK(gestor.vender(2, 6) == ResultadoStock::STOCK_INSUFICIENTE);
    CHECK_EQ(inv.getMedicamentos()[1].getCantidadDisponible(), 5);   // no cambia

    CHECK(gestor.vender(1, 0) == ResultadoStock::CANTIDAD_INVALIDA);
    CHECK(gestor.vender(99, 1) == ResultadoStock::NO_EXISTE);

    SECCION("CGestorStock: reabastecer");
    CHECK(gestor.reabastecer(2, 20) == ResultadoStock::OK);
    CHECK_EQ(inv.getMedicamentos()[1].getCantidadDisponible(), 25);
    CHECK(gestor.reabastecer(2, -5) == ResultadoStock::CANTIDAD_INVALIDA);

    SECCION("CGestorStock: esStockBajo");
    CHECK(gestor.esStockBajo(1, 100));
    CHECK(!gestor.esStockBajo(1, 10));
    CHECK(!gestor.esStockBajo(99, 1000));

    // TODO (Grupo 7): vender exactamente todo el stock, vender dos veces seguidas,
    // reabastecer un id inexistente, etc.

    return RESUMEN();
}
