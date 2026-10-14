// Pruebas de CReportes. Responsable: GRUPO 8
#include "minitest.h"
#include "CReportes.h"

int main(){
    CInventario inv("Drogas La Especial", "07-10-2026");
    inv.adicionarMedicamento(CMedicamento(1, "Acetaminofen 60Mg", 1, 100, 1000, 2000));
    inv.adicionarMedicamento(CMedicamento(2, "Ibuprofeno 30x20 Caja", 2, 10000, 500, 2500));
    inv.adicionarMedicamento(CMedicamento(3, "Amoxicilina", 1, 20, 300, 5000));
    CReportes reportes(inv);

    SECCION("CReportes: totales");
    // costo: 100*1000 + 10000*500 + 20*300 = 5.106.000
    CHECK_NEAR(reportes.valorTotalCosto(), 5106000.0, 1.0);
    // venta: 100*2000 + 10000*2500 + 20*5000 = 25.300.000
    CHECK_NEAR(reportes.valorTotalVenta(), 25300000.0, 1.0);
    CHECK_NEAR(reportes.gananciaPotencial(), 20194000.0, 1.0);

    SECCION("CReportes: margenPorUnidad");
    CHECK_NEAR(reportes.margenPorUnidad(1), 1000.0, 0.001);
    CHECK_NEAR(reportes.margenPorUnidad(99), 0.0, 0.001);

    SECCION("CReportes: masRentables");
    {
        vector<CMedicamento> top = reportes.masRentables(2);
        CHECK_EQ((int)top.size(), 2);
        if (top.size() == 2) {
            CHECK_EQ(top[0].getNombre(), "Amoxicilina");   // margen 4700
            CHECK_EQ(top[1].getNombre(), "Ibuprofeno 30x20 Caja");   // margen 2000
        }
    }

    SECCION("CReportes: ordenamientos");
    {
        vector<CMedicamento> porPrecio = reportes.ordenadosPorPrecio();
        CHECK_EQ((int)porPrecio.size(), 3);
        if (porPrecio.size() == 3) CHECK_EQ(porPrecio[0].getNombre(), "Acetaminofen 60Mg");

        vector<CMedicamento> porNombre = reportes.ordenadosPorNombre();
        if (porNombre.size() == 3) CHECK_EQ(porNombre[0].getNombre(), "Acetaminofen 60Mg");

        vector<CMedicamento> porCantidad = reportes.ordenadosPorCantidad();
        if (porCantidad.size() == 3) CHECK_EQ(porCantidad[0].getNombre(), "Amoxicilina");
    }

    // TODO (Grupo 8): inventario vacío, n mayor que la cantidad de medicamentos, n <= 0,
    // verificar que ordenar NO cambia el orden del inventario original, empates, etc.

    return RESUMEN();
}
