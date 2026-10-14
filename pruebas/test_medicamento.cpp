// Pruebas de CMedicamento (clase base). Responsable: GRUPO 2
#include "minitest.h"
#include "CMedicamento.h"

int main(){
    CMedicamento m(1, "Acetaminofen 60Mg", 1, 100, 1000, 2000);

    SECCION("CMedicamento: getters");
    CHECK_EQ(m.getId(), 1);
    CHECK_EQ(m.getNombre(), "Acetaminofen 60Mg");
    CHECK_EQ(m.getFormaDePresentacion(), 1);
    CHECK_EQ(m.getCantidadDisponible(), 100);
    CHECK_NEAR(m.getCostoDeCompra(), 1000.0, 0.001);
    CHECK_NEAR(m.getPrecioDeVenta(), 2000.0, 0.001);

    SECCION("CMedicamento: setCantidadDisponible");
    m.setCantidadDisponible(50);
    CHECK_EQ(m.getCantidadDisponible(), 50);

    // TODO (Grupo 2): agreguen más casos. Ideas: cantidad 0, valores muy grandes,
    // nombre vacío, copiar un medicamento (¿la copia es independiente?), etc.

    return RESUMEN();
}
