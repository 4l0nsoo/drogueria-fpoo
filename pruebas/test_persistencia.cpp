// Pruebas de CPersistencia. Responsable: GRUPO 5
#include "minitest.h"
#include "CPersistencia.h"

int main(){
    const char* RUTA = "build/_tmp_persistencia.csv";

    CInventario original("Drogas La Especial", "07-10-2026");
    original.adicionarMedicamento(CMedicamento(1, "Acetaminofen 60Mg", 1, 100, 1000, 2000));
    original.adicionarMedicamento(CMedicamento(2, "Ibuprofeno 30x20 Caja", 2, 10000, 500, 2500));

    SECCION("CPersistencia: guardar");
    CPersistencia persistencia(RUTA);
    CHECK(persistencia.guardar(original));

    SECCION("CPersistencia: guardar y cargar (ida y vuelta)");
    {
        CInventario cargado("Otra drogueria", "01-01-2000");
        CHECK(persistencia.cargar(cargado));
        CHECK_EQ(cargado.getNombre(), "Drogas La Especial");
        CHECK_EQ(cargado.getFecha(), "07-10-2026");
        CHECK_EQ((int)cargado.getMedicamentos().size(), 2);
        if (cargado.getMedicamentos().size() == 2) {   // evita acceder fuera del vector
            CHECK_EQ(cargado.getMedicamentos()[1].getNombre(), "Ibuprofeno 30x20 Caja");
            CHECK_EQ(cargado.getMedicamentos()[1].getCantidadDisponible(), 10000);
        }
    }

    SECCION("CPersistencia: cargar un archivo que no existe");
    {
        CPersistencia inexistente("build/no_existe_este_archivo.csv");
        CInventario inv("Intacta", "01-01-2000");
        CHECK(!inexistente.cargar(inv));
        CHECK_EQ(inv.getNombre(), "Intacta");   // no debe quedar modificado
    }

    // TODO (Grupo 5): inventario vacío, archivo corrupto (líneas incompletas, números
    // inválidos), nombres con espacios, sobrescribir un archivo existente, etc.

    return RESUMEN();
}
